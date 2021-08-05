#include "celldlg.h"
#include "ui_celldlg.h"
#include <QGraphicsPixmapItem>
#include <QDebug>



cellDlg::cellDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cellDlg)
{
    ui->setupUi(this);
    //设置对象在窗口关闭后自动销毁
    this->setAttribute(Qt::WA_DeleteOnClose, true);
    //设置对话框除掉？按钮
    Qt::WindowFlags flags= this->windowFlags() | Qt::WindowMaximizeButtonHint;
    setWindowFlags(flags&~Qt::WindowContextHelpButtonHint);
    //初始化场景scene
    scene = new QGraphicsScene(0, 0, 660, 540, this);
    ui->graphicsView->setScene(scene);
//    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //初始化界面上的spinbox
    ui->spinBox->setRange(0, 180);
    ui->spinBox->setSingleStep(1);
    ui->spinBox->setWrapping(true);

    imageItem = new QGraphicsPixmapItem(QPixmap(":/pic/image/01.png"));
    imageItem->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsSelectable);
    scene->addItem(imageItem);
}

cellDlg::~cellDlg()
{
    delete ui;
}


void cellDlg::initUi(QString path)
{

    QPixmap img = QPixmap(path);
    img = img.scaled(scene->width(), scene->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    imageItem->setPixmap(img);
    setWindowTitle(path);
}

void cellDlg::mouseMoveEvent(QMouseEvent *event)
{
    QDialog::mouseMoveEvent(event);
}

//滚轮事件，实现图片的缩放
void cellDlg::wheelEvent(QWheelEvent *event)
{

    if(event->delta() > 0)
    {
        ui->graphicsView->scale(1.1, 1.1);
    }
    else
    {
        ui->graphicsView->scale(0.9, 0.9);
    }

}

//左旋转按钮的实现
void cellDlg::on_pushButton_clicked()
{
//    int cnt = scene->selectedItems().count();
//    if(cnt == 1)
//    {
//        QGraphicsItem *item = scene->selectedItems().at(0);
//        int rotate = ui->spinBox->text().toInt();
//        item->setRotation(-rotate+item->rotation());

//    }
    int rotate = ui->spinBox->text().toInt();
    ui->graphicsView->rotate(-rotate);
}

//右旋转按钮的实现
void cellDlg::on_pushButton_2_clicked()
{
//    int cnt = scene->selectedItems().count();
//    if(cnt == 1)
//    {
//        QGraphicsItem *item = scene->selectedItems().at(0);
//        int rotate = ui->spinBox->text().toInt();
//        item->setRotation(rotate+item->rotation());

//    }
    int rotate = ui->spinBox->text().toInt();
    ui->graphicsView->rotate(rotate);
}

//退出按钮的实现
void cellDlg::on_pushButton_3_clicked()
{
    this->close();
}
