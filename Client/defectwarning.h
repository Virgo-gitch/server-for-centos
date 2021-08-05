#ifndef DEFECTWARNING_H
#define DEFECTWARNING_H

#include <QDialog>
#include <rocksdb/db.h>
#include <jsonFun.h>
#include <QDateTime>
#include <QListWidget>
#include <mydefectposlab.h>
#include <QMessageBox>
#include <defectwarnthread.h>
#include <QThread>

namespace Ui {
class DefectWarning;
}

class DefectWarning : public QDialog
{
    Q_OBJECT

    QThread workThread;


public:
    explicit DefectWarning(rocksdb::DB*, QWidget *parent = nullptr);
    ~DefectWarning();

public slots:
    void getDefectMsg(const QString&);

    void getMaskInfo(const QPoint&, const QPoint&, const int, const int, const int, const int);

    void getResult(const QVector<job_pos>&, const int, const int);

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    void setTitleAndLineText(const int, const int);
    void readPanelInfo(const int&, const QString&, const int&);
    time_point getScanTime(const QString& top, const int& panel);

signals:
    void sendInfoToThread(const QString&, const job_pos&);

    void sendDefectInfo(const int, const int, const int, const std::string, const int, const int);

    void startDraw(const bool&);

    void update_settings_file(std::string, std::string);

private:
    Ui::DefectWarning *ui;
    rocksdb::DB* DB;
    int job_pos_num, curPos;
    QVector<job_pos> jp;
    QString path;
    int cad_x, cad_y;
    int pixX, pixY;
    job_pos oldJP;
    int curIdx;



};

#endif // DEFECTWARNING_H
