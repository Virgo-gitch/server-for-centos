#ifndef JOBDLG_H
#define JOBDLG_H

#include <QDialog>
#include <QTableWidget>
#include <QFileDialog>
#include <QStringList>
#include <QDate>
#include <QMap>

//找到指定的文件名
static bool GetAllFormatFilePath(QString& findPath, QList<QString>& receiveFilePath, QString format )
{
    QDir* dir = new QDir(findPath);
    if (!dir->exists())
    return false;

    QStringList filter;
    filter << format;

    QList<QFileInfo>* dirInfoList = new QList<QFileInfo>(dir->entryInfoList(QDir::Dirs));
    QList<QFileInfo>* fomatInfoList = new QList<QFileInfo>(dir->entryInfoList(filter));

    for (int i = 0; i < dirInfoList->count(); i++) {
    if (dirInfoList->at(i).fileName() == "." || dirInfoList->at(i).fileName() == "..")
    continue;
    QString dirTmp = dirInfoList->at(i).filePath();
    GetAllFormatFilePath(dirTmp, receiveFilePath, format);
    }
    for (int i = 0; i < fomatInfoList->count(); i++)
    {
        receiveFilePath << fomatInfoList->at(i).filePath();
    }
    delete dirInfoList;
    delete dir;
    return true;
}


namespace Ui {
class JobDlg;
}

class JobDlg : public QDialog
{
    Q_OBJECT

public:
    explicit JobDlg(std::string path, QWidget *parent = nullptr);
    ~JobDlg();


signals:
    void updateBank(QStringList);

private slots:
    void on_searchBtn_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_tableWidget_itemClicked(QTableWidgetItem *item);

    void on_tableWidget_currentItemChanged(QTableWidgetItem *current, QTableWidgetItem *previous);

    void on_lineEdit_textEdited(const QString &arg1);

    void on_tableWidget_2_itemClicked(QTableWidgetItem *item);

public slots:
    void getInitInfo(QString);

    void showSubItems(QTableWidgetItem *item);
private:
    Ui::JobDlg *ui;
    QString jobPath;
    int rowCount, colCount;
    QStringList startItem;
    void initTable(QTableWidget *table, int row, int col, QStringList strList);
    QStringList getAllFolderName(QString path);  //获取指定路径的所有文件夹名
    QString getAllFileName(QString path);  //获取指定路径的所有文件名
    void readLayerStatu(QStringList &,int n);
    void clearItemText(int n);
    int getRow(QString, QString);
    int getCurrentRows();
    QStringList modifyItem(QStringList, QStringList);
    QTableWidget *table;
    QTableWidgetItem *oldItem;
    bool first;

};

#endif // JOBDLG_H
