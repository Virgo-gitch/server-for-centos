#include "mylabel.h"
#include <QPainter>
#include <QTimer>
#include <QDateTime>
#include <QDebug>

MyLabel::MyLabel(QWidget *parent):
    QLabel(parent)
{
    setAttribute(Qt::WA_TranslucentBackground);

    maskWidth = 0;
    m_stop = false;

//    //歌词的线性渐变填充
    linegradient.setStart(0, 10);
    linegradient.setFinalStop(0, 40);
    linegradient.setColorAt(0.1, QColor(14, 179, 255));
    linegradient.setColorAt(0.5, QColor(114, 25, 255));
    linegradient.setColorAt(0.9, QColor(14, 179, 255));

    //遮罩的线性渐变填充
    masklinegradient.setStart(0, 10);
    masklinegradient.setFinalStop(0, 40);
    masklinegradient.setColorAt(0.1, QColor(4, 255, 4));
    masklinegradient.setColorAt(0.5, QColor(25, 245, 16));
    masklinegradient.setColorAt(0.9, QColor(4, 255, 4));

    //设置定时器
    QTimer *time = new QTimer(this);
    connect(time, &QTimer::timeout, this, &MyLabel::onTimeout);
    time->start(500);



}

MyLabel::~MyLabel()
{

}

void MyLabel::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    if(m_stop)
    {
        painter.setPen(QColor(255,0,0));
        painter.drawText(0, 0, width(), height(), Qt::AlignCenter, text());
        return;
    }

    if(!m_stop)
    {
        //绘制文字
        painter.setPen(QPen(linegradient, 0));
        painter.drawText(width()/2-font().pointSize()*2.5, 0, width(), height(), Qt::AlignVCenter, text());
        //设置歌词遮罩
        painter.setPen(QPen(masklinegradient, 0));
        painter.drawText(width()/2-font().pointSize()*2.5, 0, maskWidth, height(), Qt::AlignVCenter, text());
        return;
    }

}

void  MyLabel::onTimeout()
{
    if(!m_stop)
    {
        maskWidth += 38;
        if(maskWidth>38*4)
            maskWidth = 0;
        update();
    }

}
