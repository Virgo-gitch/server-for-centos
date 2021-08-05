#include "scandlg.h"
#include "ui_scandlg.h"

ScanDlg::ScanDlg(QString path, int angle, QString point, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScanDlg)
{
    ui->setupUi(this);
    //设置固定的尺寸
    this->setFixedSize(400, 320);
    this->setAttribute(Qt::WA_DeleteOnClose);

    ui->nameLab->setText(path);
    ui->angleLab->setText(QString::asprintf("%d", angle));
    ui->siteLab->setText(point);

}


ScanDlg::~ScanDlg()
{
    delete ui;
}

//确定按钮的实现
void ScanDlg::on_okBtn_clicked()
{
    emit to_reScan(ui->nameLab->text(), ui->angleLab->text(), ui->siteLab->text());
    close();
}

//取消按钮的实现
void ScanDlg::on_notOkBtn_clicked()
{
    close();
}
