#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <celldlg.h>
#include <jobdlg.h>
#include <QProcess>
#include <producer.h>
#include <udpclient.h>
#include <jsonFun.h>
#include <scandlg.h>
#include <defectpreview.h>
#include <settingwidget.h>
#include <defectwarning.h>
#include <rocksdb/db.h>
#include <rocksdb/status.h>
//#include <date/date.h>
#include <set>

#pragma execution_character_set("utf-8")

//typedef std::chrono::system_clock::time_point time_point;

inline std::string const scanning_key = "scanning";
inline std::string const scan_queued_key = "scan_queued";
inline std::string const slave_assignment_queue_key = "slave_assignment_queue";


enum keyType{
    done_ok_panels =0,
    done_not_ok_panels,
    stopped_panels,
    arrival_not_ok_panels,
    arrival_ok_panels,

    scan_queued,
    slave_assignment_queue,
    scanning,
};

struct Settings{

    int last_panel = 0;
    bool pause = true;
    std::string lot = "";
};


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    enum tableColor{

        PANEL_ARRIVED_NOT_OK = 0,
        PANEL_ARRIVED_OK = 1,
        PANEL_QD_SCAN_AUTO = 2,

    };

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:

    void on_pauseBtn_clicked(bool checked);

    void on_stopBtn_clicked(bool checked);

    void on_restartBtn_clicked(bool checked);

    void on_tableWidget_itemClicked(QTableWidgetItem *item);   

    void on_tableWidget_2_itemClicked(QTableWidgetItem *item);

    void on_tableWidget_itemDoubleClicked(QTableWidgetItem *item);

    void on_tableWidget_2_itemDoubleClicked(QTableWidgetItem *item);


    void on_greenBtn_clicked();

    void on_redBtn_clicked(bool checked);

    void on_exit_Btn_clicked();

    void on_actionPreferences_triggered();

    void on_action_defect_warning_triggered();


signals:
    //退出扫描状态
    void unactiveScan();
    //给kafka服务器发消息
    void sendServer(std::string msg, std::string key);
    //初始化Job
    void initJob(QString);
    //改变设置缺陷个数大小
    void defectNumChange(int);
    //改变启动界面当前的进度
    void currentValue(int);
    //初始化settingWidget
    void initSetWig(const parse_force_mode&, const warning_generator&);
    //更新defect postion warning Ui
    void updateDefectWarn(const QString&);


private:
    void readCfgFile(config_info &);
    void initTable(QTableWidget *tableWidget);
    void initPanels(rocksdb::Options op, std::string path);
    void initJobBanks(rocksdb::Options op, std::string path);
    void initScanPanelInfo(rocksdb::Options op, std::string path, int panel, QString top);
    void initLastPanel(QTableWidget *table);
    void setCellColor(QTableWidget *table, const int &panel, const int &type, int ds=-1);
    void clearItem();
    void findItem(QTableWidget *table, const int &, const QColor &color);
    void activateImageView(QStringList strlist);  //启动外部程序ImageView
    void getRowCol(const int &num, int &row, int &col);   //获得row col
    void setItemColorAlpha(QTableWidget *table, int start);  //设置item颜色变淡
    void update_bank(QString);
    void update_lot(QString);
    void update_scanning_panel(QString, int&, bool&);
    void remove_panel_in_list(int, bool);
    void readRocksdbPanelInfo(rocksdb::Options, std::string, QString);
    void showToolTip(QTableWidgetItem *, QString, QPoint&);
    int readDefectNum(rocksdb::Options, std::string, QString);
    void setItemActuallValue(QTableWidgetItem*);
    void updateGreenStatus();
    inline void celarValue()
    {
        path = "";
        orient = 0;
    }

    inline void setI(const int &panel)
    {
//        if(last > panel)
//            return;
//        if(panel/1000 == 9 && last/1000 == 0)
//            return;
//        II = 0;
        I = panel/1000;
        if(I-1>=0)
            II = I -1;
        else
            II = 9;
        last = panel;
        Number = panel%1000+1;

    }

    inline void clearSI()
    {
        sI.panel_num = 0;
        sI.top = false;
        sI.start = 0;
        sI.end = 0;
        sI.job = "";
        sI.lot = "";
        sI.edge_x = 0;
        sI.edge_y = 0;;
        sI.orient = 0;
        sI.max_defs = 0;
        sI.ee_version = -1;

        sI.defects.clear();
    }


private:
    Ui::MainWindow *ui;
    int actualPanel;  //实际panel
    bool reScan;  //标识重新扫描
    bool stopScan;  //标识停止扫描
    bool flag, m_pause;
    bool readDb, isJob;
    QTableWidgetItem *sItem = nullptr;
    QTableWidgetItem *eItem = nullptr;
    QTableWidgetItem *sItem1 = nullptr;
    QTableWidgetItem *eItem1 = nullptr;
    udpclient *myThread = nullptr;  //消费者线程
    Producer *producer = nullptr;   //生产者
    QString path;
    config_info ci;
    std::string panelPath;
    std::string jobBankPath;
    int orient;
    Settings set;
//    QList<std::tuple<scan_panel_info, time_point>> scanPanelList;
    QList<scan_panel_info> scanPanelList;
    rocksdb::Options options;
    settingWidget *setDlg;
    DefectWarning *dwDlg;
    static_info sI;
    QString m_slave;
    QString m_statu;
    int defectSize;
    int I, II, Number, last=0;
    QStringList job_bank;
    rocksdb::DB *db;
    QTableWidgetItem *topBlackItem=nullptr;
    QTableWidgetItem *botBlackItem=nullptr;
    QColor topBackColor, botBackColor, topForColor, botForColor;
    rocksdb::Status status;


protected:
    void closeEvent(QCloseEvent *event);


protected slots:
    void onEditDoubleClick();

    void onTopCellRightClick(QTableWidgetItem *item);  //上面单元格被右击

    void onBotCellRightClick(QTableWidgetItem *item);  //下面单元格被右击
    //接收到kafka服务器发送过来的信息
    void getNewValue(const QString& str, const std::string& str1);
    //接受ImageVierer客户端发送过来的消息
    void getNewValue1(const QString& str);
    //接受ScanDlg对话框点击确定按钮
    void responseOk(QString patn, QString angle, QString point);
    //更新job_bank的信息
    void updateJobBank(QStringList);
    //往job_bank text中追加jobs
    void appendJobs(QStringList);
    //更新force_mode
    void updateForceMode(const std::string&, const std::string&, const bool&);
    //更新warning_generator_config
    void updateWarningGeneratorCfg(const std::string&, const std::string&);
    //更新正在扫描文本编辑框的内容
    void updateScanningContent();
    //鼠标悬浮top item上时显示item信息
    void showTopItemInfo(QTableWidgetItem*, QPoint&);
    //鼠标悬浮bot item上时显示item信息
    void showBotItemInfo(QTableWidgetItem*, QPoint&);
    //获取当前设置缺陷个数的设置
    void getDefectNum(int);
    //获取serverd程序的运行状态
    void getServerdStatus();

};

#endif // MAINWINDOW_H
