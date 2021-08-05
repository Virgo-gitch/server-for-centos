#include "mytablewidget.h"
#include <QDateTime>
#include <QApplication>
#include <QDebug>



myTableWidget::myTableWidget(QWidget *parent):
    QTableWidget(parent)
{
    this->setMouseTracking(true);
    previouText = "0";
    item = nullptr;
    showPoint = QPoint(0,0);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timetest()));
}

myTableWidget::~myTableWidget()
{
    delete timer;
    delete item;
}

void myTableWidget::mousePressEvent(QMouseEvent *event)
{

    QTableWidget::mousePressEvent(event);
    if(event->button() == Qt::RightButton)
    {
        emit cellRightClick(this->currentItem());
    }

}

void myTableWidget::mouseMoveEvent(QMouseEvent *event)
{

//    QTableWidgetItem *item = this->itemAt(event->pos());
//    if(!item) return;
//    if(item->text() != previouText)
//    {
//        emit mouseHover(item);
//        previouText = item->text();
//    }

    item = this->itemAt(event->pos());
    if(!item) return;
    showPoint = event->globalPos();
    if(item->text() != previouText)
    {
        previouText = item->text();

        if(!timer->isActive())
            timer->start(2500);
    }
    QTableWidget::mouseMoveEvent(event);
}


void myTableWidget::enterEvent(QEvent *event)
{
    myTableWidget::blockSignals(false);
    QTableWidget::enterEvent(event);
}


void myTableWidget::leaveEvent(QEvent *event)
{
    myTableWidget::blockSignals(true);
    QTableWidget::leaveEvent(event);
}


void myTableWidget::timetest()
{
    if(!item)return;

    timer->stop();
    emit mouseHover(item, showPoint);

}
