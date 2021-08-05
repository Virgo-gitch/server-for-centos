#include "startinterface.h"
#include "ui_startinterface.h"
#include <QDebug>

startInterface::startInterface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::startInterface)
{
    ui->setupUi(this);
    ui->progressBar->setValue(0);
}

startInterface::~startInterface()
{
    delete ui;
}


void startInterface::getCurrentValue(int value)
{
    qDebug()<<value;
    ui->progressBar->setValue(value);
    if(value == 100)
        close();
}
