#include "docirclethread.h"
#include <QFile>

doCircleThread::doCircleThread(QObject *parent):
    QThread(parent)
{
    m_run = false;
    rotateValue = 0;
    gifX = 0;
    gifY = 0;
}


doCircleThread::~doCircleThread()
{

}


void doCircleThread::run()
{
    qreal res1 = 1.8, res2 =1.8, res3 = 0.43;
    qreal x_cad0=0.0, y_cad0=0.0;
    QString temp = "bot";
    while(m_run)
    {
        if(SI.top) temp = "top";
        QString path = QString::fromStdString(SI.job);
        QFile file(path+"\\ghinfo1.txt");
        //读取res1
        bool open = file.open(QIODevice::ReadOnly);
        if(open)
        {
            QString temp = file.readLine();
            QStringList list = temp.split(" ");
            if(list.count()>=2)
                res1 = list[2].toFloat();
        }
        file.close();
        //读取res2
        file.setFileName(path + "\\bmOut_HR.txt");
        open = file.open(QIODevice::ReadOnly);
        if(open)
        {
            QString temp = file.readLine().trimmed();
            if(!temp.isEmpty())
                res2 = temp.toFloat();
            temp = file.readLine().trimmed();
            if(!temp.isEmpty())
                x_cad0 = temp.toFloat();
            temp = file.readLine().trimmed();
            if(!temp.isEmpty())
                y_cad0 = temp.toFloat();
        }
        file.close();
        file.setFileName("C:/services/machineSettings.txt");
        open = file.open(QIODevice::ReadOnly);
        if(open)
        {
            QString temp = file.readLine();
            temp.replace("Cad resolution", "").trimmed();
            if(!temp.isEmpty())
                res3 = temp.toFloat();
        }
        file.close();
    //    qDebug()<<"x_cad0="<<x_cad0<<"y_cad0="<<y_cad0;
    //    qDebug()<<"res1="<<res1<<"res2="<<res2<<"res3="<<res3;
        qreal y_cad = y_cad0 * res1 * res2 * res3/4;
        qreal x_cad = x_cad0 * res1 * res2 * res3/4;
    //    qDebug()<<y_cad;

        getCoordinate(x_cad, y_cad, gifX, gifY, res3);
    }
}


void doCircleThread::getCoordinate(qreal x_cad, qreal y_cad, qreal & x, qreal & y, qreal &res3)
{
    QString path, temp;
    QFile file;
    int sX = x/352;
    int sY = y/362;
    bool open;
    rotateValue = (SI.orient-1)*90;
    for (int i=1; i<=SI.defects.size(); ++i)
    {
        path = QString::fromStdString(SI.defects[i].txt_path);
        file.setFileName(path);
        open = file.open(QIODevice::ReadOnly);
        if(open)
        {
            temp = file.readLine().trimmed();
            QStringList strList = temp.split(" ");
            if(strList.count()>=7)
            {
                qreal X = 0.0, Y = 0.0;
                if(SI.orient == 1)
                {
                    X = (strList[5].toFloat()*res3/4.0 + 125)/sX;
                    Y = (y - (y_cad - strList[6].toFloat()*res3/4.0) + 125)/sY;
                }
                else if (SI.orient == 3)
                {
                    X = (x - (x_cad - strList[5].toFloat()*res3/4.0 +125))/sX;
                    Y = (strList[6].toFloat()*res3/4.0 + 125)/sY;
                }
                else
                {
//                    X = strList[5].toFloat()*res3/4.0;
//                    Y = (x_cad - strList[6].toFloat()*res3/4.0) + 125;

                    X = (y - (y_cad - strList[5].toFloat()*res3/4 + 125))/sX;
                    Y = (x- (x_cad - strList[6].toFloat()*res3/4) + 125)/sY;
                }
//                cood.append(QPointF(X ,Y));

            }

        }
        file.close();

    }

}
