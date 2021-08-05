#include "mydefectposlab.h"
#include <QDebug>

myDefectPosLab::myDefectPosLab(QWidget *parent):
    QLabel(parent)
{
    X=Y=0;
    bDraw = false;
    m_orient = 0;
//    setMouseTracking(true);
}

myDefectPosLab::~myDefectPosLab()
{

}


void myDefectPosLab::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);
    QPainter painter = QPainter(this);
    if(!(X==0 && Y==0))
    {
        QRect rect(sp, ep);
        if(!rect.contains(X+180, Y+180))
        {
            //绘制坐标圆圈
            painter.save();
            painter.translate(QPoint(180, 180));
            painter.setPen(Qt::white);
            painter.drawEllipse(QPoint(X, Y), 8, 8);
            painter.restore();
        }

    }

    //绘制遮蔽区
    painter.save();
    QBrush b;
    QPen pen(Qt::white);
    b.setStyle(Qt::BDiagPattern);
    b.setColor(Qt::white);
    painter.setPen(pen);
    painter.setBrush(b);
    painter.drawRect(QRect(sp, ep));
    painter.restore();


}



void myDefectPosLab::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton && bDraw)
    {
        sp = event->pos();
    }

}


void myDefectPosLab::mouseMoveEvent(QMouseEvent *event)
{
    if(bDraw)
    {
        ep = event->pos();
        update();
    }

}


void myDefectPosLab::mouseReleaseEvent(QMouseEvent *event)
{
    if(!bDraw)
        return;
    QMessageBox::StandardButton bOk =  QMessageBox::information(this, "Save Mask", "Save the mask area", QMessageBox::Cancel, QMessageBox::Ok);
    int x1=0, y1=0, x2=0, y2=0;
    if(bOk == QMessageBox::Ok)
    {

        if(m_orient == 1)
        {
            x1 = 4*((m_gifX/360)*(sp.x())-125)/res3;
            x2 = 4*((m_gifX/360)*(ep.x())-125)/res3;
            y1 = outH*res1 - 4*(m_gifY-(m_gifY/360)*(360-sp.y())-125)/res3;
            y2 = outH*res1 - 4*(m_gifY-(m_gifY/360)*(360-ep.y())-125)/res3;

        }
        else if (m_orient == 3)
        {
            x1 = outW*res1 - 4*((m_gifX/360)*(sp.x())-125)/res3;
            x2 = outW*res1 - 4*((m_gifX/360)*(ep.x())-125)/res3;
            y1 = 4*(m_gifY - (m_gifY/360)*(360-sp.y()) -125)/res3;
            y2 = 4*(m_gifY - (m_gifY/360)*(360-ep.y()) -125)/res3;

        }
        else
        {
            x1 = x2 = 0;
            y1 = y2 = 0;
        }
        emit drawMaskEnd(sp, ep, x1, y1, x2, y2);

    }
    else
    {
        sp = ep = QPoint(-10, -10);

    }
    bDraw = false;


}


void myDefectPosLab::getDefectInfo(const int x, const int y, const int orient, const std::string job, const int gifX, const int gifY)
{
    m_orient = orient;
    m_gifX = gifX;
    m_gifY = gifY;
    QString path = QString::fromStdString(job);
    QFile file(path+"\\ghinfo1.txt");
    //读取res1
    bool open = file.open(QIODevice::ReadOnly);
    if(open)
    {
        QString temp = file.readLine();
        QStringList list = temp.split(" ");
        if(list.count()>=2)
        {
            outW = list[0].toInt();
            outH = list[1].toInt();
            res1 = list[2].toFloat();
        }
    }
    file.close();
    file.setFileName(path + "\\cadInfo.txt");
    open = file.open(QIODevice::ReadOnly);
    if(open)
    {
        while(!file.atEnd())
         {
          QString readCon = file.readLine();
          QStringList content = readCon.split(":");
          if(content.at(0).toLower() == "resolution")
          {
              QStringList con = readCon.split(",");
              res3 = con[1].replace("out","", Qt::CaseInsensitive).trimmed().toFloat();
              break;
          }
         }
    }
    file.close();

    if(orient == 1)
    {
        X = (x*res3/4 + 125)/(m_gifX/360)-180;
        Y = (gifY - ((outH*res1 - y)*res3/4 + 125))/(m_gifY/360)-180;
    }
    else if (orient == 3)
    {
        X = 180-(((outW*res1 - x)*res3/4 +125)/(m_gifX/360));
        Y = 180 - ((gifY - (y*res3/4 + 125))/(m_gifY/360));
    }
    else
    {
        X = (x*res3/4 + 125)/(m_gifX/360);
        Y = (y*res3/4 + 125)/(m_gifY/360);
    }
    update();

}

void myDefectPosLab::setDraw(const bool& flag)
{

}
