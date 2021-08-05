#ifndef CELLDLG_H
#define CELLDLG_H

#include <QDialog>
#include <QGraphicsScene>
#include <QWheelEvent>

namespace Ui {
class cellDlg;
}

class cellDlg : public QDialog
{
    Q_OBJECT

public:
    explicit cellDlg(QWidget *parent = nullptr);
    void initUi(QString str);
    ~cellDlg();

protected:
    void mouseMoveEvent(QMouseEvent *event) override;

    void wheelEvent(QWheelEvent *event) override;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::cellDlg *ui;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *imageItem;
};

#endif // CELLDLG_H
