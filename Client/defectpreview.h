#ifndef DEFECTPREVIEW_H
#define DEFECTPREVIEW_H

#include <QDialog>
#include <QTableWidget>
#include <rocksdb/db.h>
#include <jsonFun.h>
#include <jobdlg.h>
#include <QMatrix>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <mydefectlab.h>


namespace Ui {
class DefectPreview;
}

class DefectPreview : public QDialog
{
    Q_OBJECT

public:
    explicit DefectPreview(QString str, int panel, rocksdb::DB *db, QWidget *parent = nullptr);
    ~DefectPreview();



private slots:
    void on_forward_btn_clicked();

    void on_behind_btn_clicked();

    void on_again_btn_clicked();

    void on_set_btn_clicked();

    void on_page_btn_clicked();

    void on_find_btn_clicked();

    void on_exit_btn_clicked();

    void on_before_btn_clicked();

    void on_after_btn_clicked();

    void on_up_btn_clicked();

    void on_refrush_btn_clicked();

    void on_modify_btn_clicked();


public slots:


signals:
    void currentPanelChange(const QList<QPoint>& coord, const int, const QVector<QPolygon>&);
    void showNextCircle(int);

protected:
    void initWidget(QString, int);
    void initTable(QTableWidget *, int);
    void updateTable(QTableWidget*, int);
    void activateImageView(QStringList);
    void readRocksdbInfo(int, QString);
    void readFileInfo(static_info& s, int gifX, int gifY);
    void getCoordinate(static_info& s, int outW, int outH, int x, int y, float res1, float res3, const QVector<QPolygon>&);
    int skipMaskIndex(int);

private:
    Ui::DefectPreview *ui;
    QStringList minidfec;
    QString minoPath;
    int curdfec;
    int curPanle;
    int m_panel;   //实际面板号
    QString m_top;
    static_info s;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *imgItem;
    rocksdb::DB* DB;
    QString m_statu; 
    int sX, sY;
    QList<std::string> defectPath;


};

#endif // DEFECTPREVIEW_H
