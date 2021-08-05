#include "mydefectlab.h"
#include <QFile>
#include <QDebug>


MyDefectLab::MyDefectLab(QWidget *parent):
    QLabel(parent)
{
    curCricle = 1;
    rotateValue = 0; 
//    workThread = new doCircleThread;
//    workThread->start();
}


MyDefectLab::~MyDefectLab()
{
//    workThread->m_run = false;
//    workThread->quit();
//    workThread->wait();
}


void MyDefectLab::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);
    QPainter painter = QPainter(this);

    if(m_polygon.size() > 0)
    {
        //绘制遮蔽矩形
        painter.save();
        QBrush b;
        b.setStyle(Qt::BDiagPattern);
        b.setColor(Qt::white);
        painter.setPen(Qt::white);
        painter.setBrush(b);
        foreach(auto p, m_polygon)
        {
            painter.drawPolygon(p);
        }
        painter.restore();
    }

    if(coordinates.count()<=0)return;
    //绘制坐标圆圈
    painter.save();

    painter.translate(180, 180);
    painter.setPen(Qt::white);
    for (int i=0; i<coordinates.count(); ++i)
    {
        painter.drawEllipse(coordinates[i], 7, 7);
    }
    painter.restore();

    painter.save();

    painter.translate(180, 180);
    QPen pen = QPen();
    pen.setWidth(2);
    pen.setColor(Qt::blue);
    painter.setPen(pen);
    painter.drawEllipse(coordinates[curCricle-1], 7, 7);
    painter.restore();
}


void MyDefectLab::getInfo(static_info& s, int gifX, int gifY, QRect& rect)
{
//    maskRect = rect;
//    sX = gifX/360;
//    sY = gifY/360;
//    float res1 = 1.8, res2 =1.8, res3 = 0.00;
////    int x_cad0=0, y_cad0=0;
//    int outW=0, outH=0;
//    QString temp = "bot";
//    if(s.top) temp = "top";
//    QString path = QString::fromStdString(s.job);
//    QFile file(path+"\\ghinfo1.txt");
//    //读取res1
//    bool open = file.open(QIODevice::ReadOnly);
//    if(open)
//    {
//        QString temp = file.readLine();
//        QStringList list = temp.split(" ");
//        if(list.count()>=2)
//        {
//            outW = list[0].toInt();
//            outH = list[1].toInt();
//            res1 = list[2].toFloat();
//        }
//    }
//    file.close();
//    //读取res2
//    file.setFileName(path + "\\bmOut_HR.txt");
//    open = file.open(QIODevice::ReadOnly);
//    if(open)
//    {
//        QString temp = file.readLine().trimmed();
//        if(!temp.isEmpty())
//            res2 = temp.toFloat();
//        temp = file.readLine().trimmed();
////        if(!temp.isEmpty())
////            x_cad0 = temp.toInt();
////        temp = file.readLine().trimmed();
////        if(!temp.isEmpty())
////            y_cad0 = temp.toInt();
//    }
//    file.close();
//    file.setFileName(path + "\\cadInfo.txt");
//    open = file.open(QIODevice::ReadOnly);
//    if(open)
//    {
//        while(!file.atEnd())
//         {
//          QString readCon = file.readLine();
//          QStringList content = readCon.split(":");
//          if(content.at(0).toLower() == "resolution")
//          {
//              QStringList con = readCon.split(",");
//              res3 = con[1].replace("out","", Qt::CaseInsensitive).trimmed().toFloat();
//              break;
//          }
//         }
//    }
//    file.close();
////    qDebug()<<"x_cad0="<<x_cad0<<"y_cad0="<<y_cad0;
////    qDebug()<<"res1="<<res1<<"res2="<<res2<<"res3="<<res3;
////    int y_cad = y_cad0 * res1 * res2 * res3/4;
////    int x_cad = x_cad0 * res1 * res2 * res3/4;
////    qDebug()<<y_cad;

////    getCoordinate(s, x_cad, y_cad, gifX, gifY, res3);
//    getCoordinate(s, outW, outH, gifX, gifY, res1, res3);

}


void MyDefectLab::getCoordinate(static_info& s, int outW, int outH, int x, int y, float res1, float res3)
{
//    rotateValue = (s.orient-1)*90;
//    int X = 0, Y = 0;
//    for (int i=1; i<=s.defects.size(); ++i)
//    {
//        if(s.orient == 1)
//        {

//            X = (s.defects[i].cad_x*res3/4 + 125)/sX-180;
//            Y = (y - ((outH*res1 - s.defects[i].cad_y)*res3/4 + 125))/sY-180;

//        }
//        else if (s.orient == 3)
//        {

//            X = 180-(((outW*res1 - s.defects[i].cad_x)*res3/4 +125)/sX);
//            Y = 180 - ((y - (s.defects[i].cad_y*res3/4 + 125))/sY);
//        }
//        else
//        {

//            X = (s.defects[i].cad_x*res3/4 + 125)/sX;
//            Y = (s.defects[i].cad_y*res3/4 + 125)/sY;
//        }

//        coordinates.append(QPoint(X ,Y));


//    }
//    if(coordinates.count() == s.defects.size())
//    {
//        update();
//    }

}


void MyDefectLab::getDefectCoordinates(const QList<QPoint>& coord, const int orient, const QVector<QPolygon>& ploy)
{
    coordinates = coord;
    m_polygon = ploy;
    rotateValue = (orient-1)*90;
    update();
}


void MyDefectLab::clearPoly()
{
    m_polygon.clear();
}


void MyDefectLab::getNextCricle(int curNum)
{
    curCricle = curNum;
    update();
}
