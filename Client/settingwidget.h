#ifndef SETTINGWIDGET_H
#define SETTINGWIDGET_H

#include <QWidget>
#include <QFile>
#include <QTableWidget>
#include <QHeaderView>
#include <QDir>
#include <QCompleter>
#include <jsonFun.h>

static int initDefectNum()
{
    QFile file("/home/wzm/Optima/setting.txt");
    int num = -1;
    if(file.open(QIODevice::ReadOnly))
    {
        QString str = file.readLine();
        num = str.trimmed().toInt();
    }
    file.close();
    return num;
}


//找到指定的文件名
static bool GetFileName(QString& findPath, QList<QString>& receiveFilePath, QString format )
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
    GetFileName(dirTmp, receiveFilePath, format);
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
class settingWidget;
}

class settingWidget : public QWidget
{
    Q_OBJECT

public:
    explicit settingWidget(QWidget *parent = nullptr);
    ~settingWidget();
    int oldValue;

private slots:
    void on_cancelBtn_clicked();

    void on_saveBtn_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_top_text_textChanged();

    void on_bot_text_textChanged();

    void on_lineEdit_textEdited(const QString &arg1);

    void on_lineEdit_2_textEdited(const QString &arg1);

    void tableItem_click(QTableWidgetItem*);


    void on_checkBox_2_toggled(bool checked);

signals:
    void defectSizeChange(int);

    void send_message(const std::string&, const std::string&, const bool&);

    void send_warning_generator_msg(const std::string&, const std::string&);

    void update_bank(QStringList);

public slots:
    void init_Ui(const parse_force_mode&, const warning_generator&);

private:
    Ui::settingWidget *ui;
    QTableWidget *table;
    QList<QStringList> result;
    void setControlsEnable(bool);
    void initTable();


};

#endif // SETTINGWIDGET_H
