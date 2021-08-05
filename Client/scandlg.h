#ifndef SCANDLG_H
#define SCANDLG_H

#include <QDialog>

namespace Ui {
class ScanDlg;
}

class ScanDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ScanDlg(QString, int, QString, QWidget *parent = nullptr);
    ~ScanDlg();

private slots:
    void on_okBtn_clicked();

    void on_notOkBtn_clicked();

signals:
    void to_reScan(QString patn, QString angle, QString point);

private:
    Ui::ScanDlg *ui;
};

#endif // SCANDLG_H
