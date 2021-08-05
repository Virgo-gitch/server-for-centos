#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDateTime>
#include <QToolTip>
#include <QTimer>


//#pragma comment(lib,"Rpcrt4.lib")
//#pragma comment(lib,"shlwapi.lib")
//#pragma comment(lib,"zlib.lib")




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //初始化界面图标
    QIcon icon = QIcon(":/pic/image/01.png");
    setWindowIcon(icon);

//    config_info ci;
    readCfgFile(ci);
    panelPath = ci.db.panels;
    jobBankPath = ci.server.jobs;
    // 初始化tableWidget1(上面)
    initTable(ui->tableWidget);
    // 初始化tableWidget2(下面)
    initTable(ui->tableWidget_2);
    readDb = true;
    reScan = false;
    stopScan = false;
    flag = false;
    isJob = false;
    actualPanel = 0;
    m_slave = "";
    m_statu = "";
//    m_scanBotMaxPanel = m_scanBotMaxPanel = 0;
    defectSize = initDefectNum();

    options = rocksdb::Options();
    options.create_if_missing = true;

    setDlg = new settingWidget();
    QImage Image;
    Image.load(":/pic/image/01.png");
    QPixmap pixmap = QPixmap::fromImage(Image);
    pixmap = pixmap.scaled(380, 333, Qt::KeepAspectRatio, Qt::SmoothTransformation);  // 按比例缩放
    ui->upLab->setPixmap(pixmap);
    ui->downLab->setPixmap(pixmap);

    connect(this, &MainWindow::initSetWig, setDlg, &settingWidget::init_Ui);

    status = rocksdb::Status::IOError();
    QFile file(QString::fromStdString(ci.db.panels));
    if(file.exists())
        initPanels(options, ci.db.panels);

//    initJobBanks(options, ci.db.jobs);
    celarValue();
    ui->textEdit->setReadOnly(true);
//    QFont font = ui->textEdit->font();
//    font.setPixelSize(14);
//    ui->textEdit->setFont(font);
    ui->textEdit_2->setReadOnly(true);
    ui->lineEdit_2->setText(QString::fromStdString(set.lot));
    m_pause = set.pause;

    getServerdStatus();


    dwDlg = new DefectWarning(db);

    if(!m_pause)
    {
        ui->pauseBtn->setStyleSheet("border-image:url(:/pic/image/pause.png)");
        ui->stopLab->setText("停止");
        ui->stopLab->m_stop = true;
    }

    if(set.last_panel != 0)
    {
        initLastPanel(ui->tableWidget);
        initLastPanel(ui->tableWidget_2);
    }

    //消费者线程
    myThread = new udpclient(ci.kafkaIP[0], this);
    myThread->start();

    //生产者
    producer = new Producer(ci.kafkaIP[0], this);

    //创建定时器
    QTimer *timer = new QTimer(this);
    timer->start(2000);  //2s刷新一次

    QTimer *serverdTime = new QTimer(this);
    serverdTime->start(3500);

    setStyleSheet("QToolTip{border: 0px solid;background: rgb(0,255,255);color:rgb(0,0,0)}");

    //信号与槽函数的连接
    connect(ui->textEdit_2, SIGNAL(editDoubleClicked()), this, SLOT(onEditDoubleClick()));

    connect(myThread, &udpclient::valueUpdate, this, &MainWindow::getNewValue);

    connect(myThread, &udpclient::valueUpdate1, this, &MainWindow::getNewValue1);

    connect(ui->tableWidget, &myTableWidget::cellRightClick, this, &MainWindow::onTopCellRightClick);

    connect(ui->tableWidget_2, &myTableWidget::cellRightClick, this, &MainWindow::onBotCellRightClick);

    connect(this, &MainWindow::sendServer, producer, &Producer::getNewMessage);

    connect(timer, SIGNAL(timeout()), this, SLOT(updateScanningContent()));

    connect(serverdTime, SIGNAL(timeout()), this, SLOT(getServerdStatus()));

    connect(ui->tableWidget, &myTableWidget::mouseHover, this, &MainWindow::showTopItemInfo);

    connect(ui->tableWidget_2, &myTableWidget::mouseHover, this, &MainWindow::showBotItemInfo);

    connect(setDlg, &settingWidget::defectSizeChange, this, &MainWindow::getDefectNum);

    connect(setDlg, &settingWidget::send_message, this, &MainWindow::updateForceMode);

    connect(setDlg, &settingWidget::send_warning_generator_msg, this, &MainWindow::updateWarningGeneratorCfg);

    connect(setDlg, &settingWidget::update_bank, this, &MainWindow::appendJobs);

    connect(this, &MainWindow::updateDefectWarn, dwDlg, &DefectWarning::getDefectMsg);

    connect(dwDlg, &DefectWarning::update_settings_file, producer, &Producer::getNewMessage);
}

MainWindow::~MainWindow()
{
    myThread->setRun();
    myThread->wait();
    delete ui;
    delete sItem;
    delete eItem;
    delete producer;
    delete setDlg;
    if(!dwDlg)
        delete dwDlg;
    if(status.ok())
        delete db;
}


void MainWindow::readCfgFile(config_info& ci)
{
    QFile file;
    file.setFileName("/home/wzm/Optima/config_file.json");
    bool op = file.open(QIODevice::ReadOnly);
    if(op)
    {
        std::string msg = file.readAll().trimmed().toStdString();   
        try
        {
            json j = json::parse(msg);
            j.at("DB").get_to(ci.db);
            j.at("Kafka Brokers").get_to(ci.kafkaIP);
            j.at("Slaves").get_to(ci.s);
            j.at("Server").get_to(ci.server);
    //        std::cout<<ci.kafkaIP[0]<<ci.db.jobs<<ci.db.panels;
        }  catch (...)
        {
            qDebug()<<"parse config_file.json fail";
        }


    }
    else
        qDebug()<<"open /home/wzm/Optima/config_file.json fail";
}


void MainWindow::initTable(QTableWidget *tableWidget)
{
    //设置表格不可编辑
    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //设置表格为单选
//    tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
    //设置表格的单元格没有选中的虚线框及颜色
//    tableWidget->setFocusPolicy(Qt::NoFocus);
//    tableWidget->setStyleSheet("selection-color: rgb(255, 255, 255);selection-background-color:rgb(255, 255, 255);");
    //设置table统一的字体
    tableWidget->setFont(QFont("SimSun-ExtB", 10));
    //填充表格的内容
    for (int row=0;row<25;++row)
    {

        for (int col=0;col<40;++col)
        {
            QTableWidgetItem *item;
            item = new QTableWidgetItem;
            QString strText = QString::asprintf("%d",(row+1)+(col*25));
            item->setText(strText);
            //设置表格的内容为居中对齐
            item->setTextAlignment(Qt::AlignCenter);
            item->setBackground(Qt::white);
            tableWidget->setItem(row, col, item);

        }

    }

}

void MainWindow::initPanels(rocksdb::Options option, std::string path)
{
    std::string logDir = "/home/wzm/Optima/subDB/";
    QDir dir;
    if(!dir.exists(QString::fromStdString(logDir)))
    {
        if(dir.mkpath(QString::fromStdString(logDir)))
            qDebug()<<"Create folder success"<<QString::fromStdString(logDir);
        else
        {
            qDebug()<<"Create folder fail"<<QString::fromStdString(logDir);
            return;
        }
    }

    // 打开数据库
    status = rocksdb::DB::OpenAsSecondary(option, path, logDir, &db);//"C:/Optima/serverd/debug/DB/panels"

    qDebug()<<"initPanels打开数据库status code:"<<status.code();
    if(status.ok())
    {
        rocksdb::ReadOptions opts = rocksdb::ReadOptions();
        opts.fill_cache = false;  
        //获得settings信息
        std::string str_set;
        db->Get(opts, "settings", &str_set);
        if(!str_set.empty())
        {
            json j;
            parse_force_mode mode;
            warning_generator wg;
            try
            {
                j = json::parse(str_set);
                set.last_panel = j["last_panel"];
                set.pause = j["pause"];
                set.lot = j["lot"];
                mode = j["force_mode"];
                wg = j["repeated_defects_warning"];

            }  catch (...)
            {
                qDebug()<<"parse setting fail";
            }
            emit initSetWig(mode, wg);
            ui->textEdit_2->clear();
            ui->textEdit_2->setEnabled(!mode.enabled);
            if(mode.enabled)
                ui->textEdit_2->append("Force Mode Is on!");
            else
                initJobBanks(options, ci.db.jobs);


        }

        setI(set.last_panel);

        std::string key_str;
        int type;
        emit currentValue(10);
        //获取静态的stores
        for (int i=0;i<5 ; ++i)
        {
            switch (i)
            {

            case done_ok_panels:
                key_str = "done_ok_panels";
                type = 4;
                break;
            case done_not_ok_panels:
                key_str = "done_not_ok_panels";
                type = 5;
                break;
            case stopped_panels:
                key_str = "stopped_panels";
                type = 7;
                break;
            case arrival_not_ok_panels:
                key_str = "arrival_not_ok_panels";
                type = 0;
                break;
            case arrival_ok_panels:
                key_str = "arrival_ok_panels";
                type = 0;
                break;

            }
            std::string str;
            db->Get(opts, key_str, &str);

            if (!str.empty())
            {
                json j = json::parse(str);
                std::set<int> top, bot;
                json_to_top_bot(j, top, bot);
                if(!top.empty())
                {

                    foreach(int panel, top)
                    {

                        if((panel>=1000*I+1 && panel <= set.last_panel) || (panel>=1000*II+Number && panel <= 1000*(II+1)))
                        {
                            actualPanel = panel;
                            panel = to_slave_number(panel);
                            setCellColor(ui->tableWidget, panel, type);
        //                        qDebug()<<QString::fromStdString(key_str)<<panel<<true<<type;
                        }

                    }

                }

                if(!bot.empty())
                {
                    foreach(int panel, bot)
                    {
                        if((panel>=1000*I+1 && panel <= set.last_panel) || (panel>=1000*II+Number && panel <= 1000*(II+1)))
                        {
                            actualPanel = panel;
                            panel = to_slave_number(panel);
                            setCellColor(ui->tableWidget_2, panel, type);
    //                        qDebug()<<QString::fromStdString(key_str)<<"slave panel="<<panel<<"actual panel ="<<actualPanel<<false<<type;
                        }

                    }


                }

            }
        }

        //获取动态的stores
        std::string str1;
        db->Get(opts, scan_queued_key, &str1);
        if (!str1.empty())
        {
            json j;
            j = json::parse(str1);
            std::set<int> scan_queued_top, scan_queued_bot;
            json_to_top_bot(j, scan_queued_top, scan_queued_bot);
            if(!scan_queued_top.empty())
            {

                foreach(int panel, scan_queued_top)
                {
                    if((panel>=1000*I+1 && panel <= set.last_panel) || (panel>=1000*II+Number && panel <= 1000*(II+1)))
                    {
                        actualPanel = panel;
                        panel = to_slave_number(panel);
                        setCellColor(ui->tableWidget, panel, 1);
    //                    qDebug()<<"scan_queued"<<panel<<true;
                    }

                }


            }
            if(!scan_queued_bot.empty())
            {
                foreach(int panel, scan_queued_bot)
                {

                    if((panel>=1000*I+1 && panel <= set.last_panel) || (panel>=1000*II+Number && panel <= 1000*(II+1)))
                    {
                        actualPanel = panel;
                        panel = to_slave_number(panel);
                        setCellColor(ui->tableWidget_2, panel, 1);
    //                    qDebug()<<"scan_queued"<<panel<<false;

                    }

                }

            }
        }

        for(int i=0;i<2;++i)
        {
            std::string str2;
            if(i == 1)
            {
                key_str = scanning_key;
                type = 3;
            }
            if(i == 0)
            {
                key_str = slave_assignment_queue_key;
                type = 2;
            }

            db->Get(opts, key_str, &str2);
            if (!str2.empty())
            {
                json j;
                j = json::parse(str2);
                std::unordered_map<std::string, std::vector<int>> top, bot;
                json_to_top_bot(j, top, bot);
                for (auto iter = top.begin(); iter != top.end(); ++iter)
                {
                    std::vector panels = iter->second;
                    if(!panels.empty())
                    {

                        foreach(int panel, panels)
                        {
                            if((panel>=1000*I+1 && panel <= set.last_panel) || (panel>=1000*II+Number && panel <= 1000*(II+1)))
                            {
                                actualPanel = panel;
                                panel = to_slave_number(panel);
                                setCellColor(ui->tableWidget, panel, type);
                                if(key_str == scanning_key)
                                    initScanPanelInfo(option, path, actualPanel, "top");
    //                            qDebug()<<QString::fromStdString(key_str)<<panel<<true<<type;
                            }

                        }



                    }

                }

                for (auto iter = bot.begin(); iter != bot.end(); ++iter)
                {
                    std::vector panels = iter->second;
                    if(!panels.empty())
                    {

                        foreach(int panel, panels)
                        {
                            if((panel>=1000*I+1 && panel <= set.last_panel) || (panel>=1000*II+Number && panel <= 1000*(II+1)))
                            {
                                actualPanel = panel;
                                panel = to_slave_number(panel);
                                setCellColor(ui->tableWidget_2, panel, type);
                                if(key_str == scanning_key)
                                    initScanPanelInfo(option, path, actualPanel, "bot");
    //                            qDebug()<<QString::fromStdString(key_str)<<panel<<false<<type;
                            }

                        }

                    }

                }
            }
        }

    }

    readDb = false;
    return;
}


void MainWindow::initJobBanks(rocksdb::Options option, std::string path)
{
    rocksdb::DB *jobdb;
    // 打开数据库
    rocksdb::Status status = rocksdb::DB::OpenForReadOnly(option, path, &jobdb);    //"C:/Optima/serverd/debug/DB/jobbank"
    qDebug()<<"initJobBanks打开数据库status code:"<<status.code();
    if(status.ok())
    {
        rocksdb::ReadOptions opts = rocksdb::ReadOptions();
        opts.fill_cache = false;
        //获取job_bank
        std::string str;
        jobdb->Get(opts, "bank", &str);
        if(!str.empty())
        {
            json j;
            j = json::parse(str);
            bank b;

            from_json(j, b);
            foreach(std::string value, b.jobs)
            {
                QStringList temp = QString::fromStdString(value).split(QRegExp("/"));
                if(temp.count()>=3)
                {
                    ui->textEdit_2->append(temp[2] + "/" + temp[3]);
                    job_bank.append(temp[2] + "/" + temp[3]);
                }

            }

        }

    }
    delete jobdb;
    return;

}


void MainWindow::initLastPanel(QTableWidget *table)
{

    int panel = to_slave_number(set.last_panel);
    int row, col;
    QTableWidgetItem *item;
    //1->last_panel 字体bold
    getRowCol(panel, row, col);
    for (int i = 0; i< 25; ++i)
    {
        for (int j=0; j<col; ++j)
        {
            item = table->item(i, j);
            QFont font = item->font();
            font.setBold(true);
            item->setFont(font);
        }

    }
    for (int i=0; i<=row; ++i)
    {
        item = table->item(i, col);
        QFont font = item->font();
        font.setBold(true);
        item->setFont(font);
    }

    getRowCol(to_slave_number(panel+1), row, col);
    QTableWidgetItem *nextItem = table->item(row,col);
    if(nextItem)
    {
        //变黑色
        nextItem->setBackground(QColor(33,33,33));
        nextItem->setForeground(Qt::gray);
        table->setCurrentItem(nextItem);
        if(table == ui->tableWidget)
        {
            topBlackItem = nextItem;
            topBackColor = Qt::white;
            topForColor = QColor(33, 33, 33);
        }

        else
        {
            botBlackItem = nextItem;
            botBackColor = Qt::white;
            botForColor = QColor(33, 33, 33);
        }


    }
    setItemColorAlpha(table, to_slave_number(panel+2));

}


//inline void string_to_timestamp(std::string const &timestamp, time_point &tp)
//{
//    std::stringstream ss{timestamp};
//    ss >> date::parse("%D %T %Z", tp);
//}

//inline void from_json(json const &j, scanning_event &se)
//{
//    se.slave = j.at("slave").get<std::string>();
//    string_to_timestamp(j.at("timestamp").get<std::string>(), se.timestamp);
//}

void MainWindow::initScanPanelInfo(rocksdb::Options option, std::string path, int panel, QString top)
{

//    // 打开数据库
//    rocksdb::DB *db;
//    rocksdb::Status status = rocksdb::DB::OpenForReadOnly(option, path, &db);
    if(status.ok())
    {
        std::string key = QString("%1-%2-history").arg(top).arg(panel).toStdString();
        std::string value;
        db->Get(rocksdb::ReadOptions(), key, &value);
        json j;
        std::cout<<"key:"<<key<<"        "<<"value:"<<value<<std::endl;
        if(!value.empty())
        {
            j = json::parse(value);

            auto rit = j.rbegin();

            if (rit->contains("scanning"))
            {
                scan_panel_info spi;
                spi.panel = to_slave_number(panel);
                spi.top = top;
//                if(top == "top")
//                    m_scanTopMaxPanel = m_scanTopMaxPanel >= panel ? m_scanTopMaxPanel:panel;
//                else
//                    m_scanBotMaxPanel = m_scanBotMaxPanel >= panel ? m_scanBotMaxPanel:panel;
                spi.se = rit->at("scanning").get<scanning_event>();
//                spi.se.timestamp -= std::chrono::seconds(8*3600);
                scanPanelList.append(spi);
            }
            else {
                throw;
            }

        }
    }

//    delete  db;


}


void MainWindow::readRocksdbPanelInfo(rocksdb::Options option, std::string path, QString strKey)
{
//    rocksdb::DB *db;
//    rocksdb::Status status = rocksdb::DB::OpenForReadOnly(option, path, &db);
    clearSI();
//    if(db != nullptr)
//    {
        std::string value, value1;
        db->TryCatchUpWithPrimary();
        db->Get(rocksdb::ReadOptions(), strKey.toStdString(), &value);
        if(!value.empty())
        {
            json j = json::parse(value);
            sI = j;

        }
        strKey.replace("info", "history");
        db->Get(rocksdb::ReadOptions(), strKey.toStdString(), &value1);
        if(!value1.empty())
        {
            json j = json::parse(value1);

            json::reverse_iterator rt = j.rbegin();
            m_statu =  QString::fromStdString((*rt).items().begin().key());

            auto rit = j.rbegin();
            for (; rit != j.rend(); ++rit)
            {
                if (rit->contains("scanning"))
                {
                    auto se = rit->at("scanning").get<scanning_event>();
                    m_slave = QString::fromStdString(se.slave);
                    break;
                }
            }
        }
//    }
//    delete db;
}



int MainWindow::readDefectNum(rocksdb::Options option, std::string path, QString strKey)
{
//    rocksdb::DB *db;
//    rocksdb::Status status = rocksdb::DB::OpenForReadOnly(option, path, &db);
    if(status.ok())
    {
        std::string value;
        db->Get(rocksdb::ReadOptions(), strKey.toStdString(), &value);
        if(!value.empty())
        {
            json j = json::parse(value);
            static_info s = j;
//            delete db;
            return s.defects.size();
        }
    }
//    delete db;
    return 0;
}


//设置表格后面的item颜色变淡
void MainWindow::setItemColorAlpha(QTableWidget *table, int start)
{

    int row, col;
    getRowCol(start, row, col);
    QTableWidgetItem *item;
    QFont font;
    for (int i=row; i<25; ++i)
    {
        item = table->item(i, col);
//        if(item->background().color() == Qt::gray)
//        {
//            item->setForeground(QColor(104, 104, 104));
//            continue;
//        }
        font = item->font();
        font.setBold(false);
        item->setFont(font);
        item->setForeground(QColor(104, 104, 104));


    }

    for(int i=0; i<25; ++i)
    {
        for(int j=col+1; j<40; ++j)
        {
            item = table->item(i, j);            
//            if(item->background().color() == Qt::gray)
//            {
//                item->setForeground(QColor(104, 104, 104));
//                continue;
//            }
            font = item->font();
            font.setBold(false);
            item->setFont(font);
            item->setForeground(QColor(104, 104, 104));


        }
    }
}

//实现暂停扫描下一张按钮的功能
void MainWindow::on_pauseBtn_clicked(bool checked)
{
    Q_UNUSED(checked);

    if(m_pause)
    {
        //发送停止信号到kafkaf服务器
        std::string msg = pauseScanMsg(!m_pause);
        emit sendServer(msg, "update_pause_state");

        //切换按钮图标图标
        ui->pauseBtn->setStyleSheet("border-image:url(:/pic/image/pause.png)");
        ui->stopLab->setText("停止");
        ui->stopLab->m_stop = true;


    }
    else
    {
        //发送启动信号到kafka服务器，进入正常扫描状态
        std::string msg = pauseScanMsg(!m_pause);
        emit sendServer(msg, "update_pause_state");

        //切换按钮图标状态 
        ui->pauseBtn->setStyleSheet("border-image:url(:/pic/image/pause1.png)");
        ui->stopLab->setText("正在扫描");
        ui->stopLab->m_stop = false;

    }
    ui->stopLab->maskWidth = 0;
    m_pause = !m_pause;
}

//实现停止按钮的功能
void MainWindow::on_stopBtn_clicked(bool checked)
{
    Q_UNUSED(checked);
    flag = !flag;
    if(flag)
    {
        ui->stopBtn->setStyleSheet("border-image:url(:/pic/image/stop1.png)");
        //使按钮不可用
        ui->restartBtn->setEnabled(false);
        //设置停止扫描为true
        stopScan = true;
        //设置鼠标的形状
        this->setCursor(Qt::CrossCursor);
        //重置起始板号和结束板号
        clearItem();
    }
    else
    {
        ui->stopBtn->setStyleSheet("border-image:url(:/pic/image/stop.png)");
        ui->restartBtn->setEnabled(true);
        this->setCursor(Qt::CustomCursor);
        stopScan = false;
    }



}

//实现重新扫描按钮的功能
void MainWindow::on_restartBtn_clicked(bool checked)
{
    Q_UNUSED(checked);
    flag = !flag;
    if(flag)
    {
        ui->restartBtn->setStyleSheet("border-image:url(:/pic/image/restart1.png)");
        //使按钮不可用
        ui->stopBtn->setEnabled(false);
        //设置重新扫描为true
        reScan = true;
        //设置鼠标的形状为小手
        this->setCursor(Qt::PointingHandCursor);
        //重置起始板号和结束板号
        clearItem();
    }

    else
    {
        ui->restartBtn->setStyleSheet("border-image:url(:/pic/image/restart.png)");
        ui->stopBtn->setEnabled(true);
        this->setCursor(Qt::CustomCursor);
        reScan = false;
        isJob = false;

    }



}


void MainWindow::getRowCol(const int& num, int &row, int &col)
{
    if(num%25 == 0)
    {
        col = num / 25 -1;
        row = 24;
    }
    else
    {
        col = num / 25;
        row = num % 25 - 1;
    }
}

void MainWindow::findItem(QTableWidget *table, const int& panel, const QColor &color)
{

    if(panel == 1 && readDb == false)
    {
        setItemColorAlpha(table, panel+2);
    }
    int col, row;
    getRowCol(panel, row, col);
    QTableWidgetItem *item = table->item(row,col);
    if(item)
    {
        QFont font;
        font = item->font();
        item->setData(panel+1000, QVariant(actualPanel));
        //传过来的是white，使其字体加粗
        if(color == Qt::white)
        {

//            if(set.last_panel!=0 && !readDb)
//            {

//                getRowCol(to_slave_number(set.last_panel+1), row, col);
//                QTableWidgetItem *last = table->item(row,col);
//                if(last->background().color() != QColor(33, 33, 33))
//                    set.last_panel = 0;
//                last->setBackground(color);
////                last->setForeground(QColor(104, 104, 104));
//            }
            if(!readDb)
            {
                if(table == ui->tableWidget)
                {
                    topBlackItem->setBackground(topBackColor);
                    topBlackItem->setForeground(topForColor);
                }

                else
                {
                    botBlackItem->setBackground(botBackColor);
                    botBlackItem->setForeground(botForColor);
                }

            }
            font.setBold(true);
            item->setFont(font);
            item->setBackground(color);
            item->setForeground(Qt::black);
            if(readDb) return;
            getRowCol(to_slave_number(panel+1), row, col);
            QTableWidgetItem *nextItem = table->item(row,col);
            if(nextItem)
            {

                if(table == ui->tableWidget)
                {
                    topBackColor = nextItem->background().color();
                    topForColor = nextItem->foreground().color();
                    topBlackItem = nextItem;
                }
                else
                {
                    botBackColor = nextItem->background().color();
                    botForColor = nextItem->foreground().color();
                    botBlackItem = nextItem;
                }

                 //变黑色
                font.setBold(false);
                nextItem->setFont(font);
                nextItem->setBackground(QColor(33,33,33));
                nextItem->setForeground(Qt::gray);

            }
            return;
        }

        else if(color == Qt::darkBlue || color == QColor(128, 0, 128))
        {

            item->setBackground(color);
            item->setForeground(Qt::white);

        }
        else
        {
            item->setBackground(color);
            item->setForeground(Qt::black);
        }
        font.setBold(true);
        item->setFont(font);

    }

}

void MainWindow::setCellColor(QTableWidget *table, const int &panel, const int &type, int ds)
{

    switch (type)
    {
        case 0:
        findItem(table, panel, Qt::white);
        break;
        case 1:
        findItem(table, panel, QColor(255, 165, 0));  //orange
        break;
        case 2:
        findItem(table, panel, Qt::darkBlue);
        break;
        case 3:
        findItem(table, panel, QColor(128, 0, 128));
        break;
        case 4:    
        if(ds==-1)
            ds = readDefectNum(options, panelPath, QString("%1-%2-info").arg((table == ui->tableWidget ? "top":"bot")).arg(actualPanel));
        if(ds>defectSize)
            findItem(table, panel, QColor(0, 100, 0));
        else
            findItem(table, panel, QColor(144, 238, 144));
        break;
        case 5:
        findItem(table, panel, Qt::red);
        break;
        case 6:
        findItem(table, panel, QColor(159, 218, 248));
        break;
        case 7:
        findItem(table, panel, Qt::gray);
        break;
    }
}


void MainWindow::clearItem()
{
    sItem = nullptr;
    eItem = nullptr;
    sItem1 = nullptr;
    eItem1 = nullptr;

}


//编辑框被双击的槽
void MainWindow::onEditDoubleClick()
{

    JobDlg *dlg = new JobDlg(jobBankPath, this);
    QString text = ui->textEdit_2->toPlainText().trimmed();
    connect(dlg, &JobDlg::updateBank, this, &MainWindow::updateJobBank);
    connect(this, &MainWindow::initJob, dlg, &JobDlg::getInitInfo);
    emit initJob(text);
    dlg->exec();   //模态弹出
    delete dlg;

}

//响应点击jobdlg中的完成按钮给kafka发送更新bank信息
void MainWindow::updateJobBank(QStringList strList)
{

    //更新ui_textEdit
    ui->textEdit_2->clear();
    job_bank.clear();
    if(strList.count()>=1 && strList[0] != "")
    {
        foreach(QString str, strList)
        {
            str.replace("\\", "/");
            str.replace("c:/jobs/","", Qt::CaseInsensitive);
            job_bank.append(str);
            ui->textEdit_2->append(str);
        }
    }


    //给kafka发送信息
    std::vector<std::string> msg;
    if(strList.count()<=0)
    {
        msg.push_back("");
        producer->getNewMessage(job_bank_to_json(msg), "update_bank");
        return;
    }

    foreach(QString str1, strList)
    {
        msg.push_back(str1.toStdString());
    }
    producer->getNewMessage(job_bank_to_json(msg), "update_bank");

}



//往job bank中追加jobs
void MainWindow::appendJobs(QStringList list)
{
    std::vector<std::string> msg;
    foreach(auto str, list)
    {
        if(str.isEmpty()) continue;
        bool find = false;
        str.replace("\\", "/");
        str.replace("c:/jobs/","",Qt::CaseInsensitive);
        for (int i=0; i<job_bank.count(); ++i)
        {
            if(job_bank[i].toLower() == str.toLower())
            {
                find = true;
                break;
            }
            find = false;

        }
        if(!find)
            ui->textEdit_2->append(str);
        msg.push_back(str.toStdString());
    }
    producer->getNewMessage(job_bank_to_json(msg), "update_bank");

}

//给kafka发送消息更新force_mode
void MainWindow::updateForceMode(const std::string& msg, const std::string &key, const bool &flag)
{
    producer->getNewMessage(msg, key);
    ui->textEdit_2->setEnabled(!flag);
    ui->textEdit_2->clear();
    if(flag)
    {
        ui->textEdit_2->append("Force Mode Is On!");
    }
    else
    {
        initJobBanks(options, ci.db.jobs);
    }
}

//给kafka发送消息更新warning_generator_config
void MainWindow::updateWarningGeneratorCfg(const std::string& msg, const std::string& key)
{
    producer->getNewMessage(msg, key);
}

//上面单元格被右击
void MainWindow::onTopCellRightClick(QTableWidgetItem *item)
{
    setItemActuallValue(item);

    QColor color = item->background().color();

    if(color == QColor(0, 100, 0) || color == QColor(144, 238, 144))
    {
        if(status.ok())
        {
            db->TryCatchUpWithPrimary();
            DefectPreview *DP = new DefectPreview("top", item->data(item->text().toInt()+1000).toInt(), db, this);
            DP->exec();   //模态弹出
            delete DP;
        }
    }
//    else if(color == Qt::gray)
//    {
//        QStringList strlist;
//        strlist<<item->text()<<"0"<<"1";
//        activateImageView(strlist);
//    }
    else
    {
        QStringList strlist;
        strlist<<item->data(item->text().toInt()+1000).toString()<<"0"<<"1";
        activateImageView(strlist);

//        QString info = "The board scan failed! Please RESCAN the board! Erroe code 001(pic numbers are 0)";
//        QMessageBox::critical(this, "Server", info, QMessageBox::Ok);
    }


}

//下面单元格被右击
void MainWindow::onBotCellRightClick(QTableWidgetItem *item)
{
    setItemActuallValue(item);

    QColor color = item->background().color();
    if(color == QColor(0, 100, 0) || color == QColor(144, 238, 144))
    {
        if(status.ok())
        {
            db->TryCatchUpWithPrimary();
            DefectPreview *DP = new DefectPreview("bot", item->data(item->text().toInt()+1000).toInt(), db, this);
            DP->exec();   //模态弹出
            delete DP;
        }
    }
//    else if(color == Qt::gray)
//    {
//        QStringList strlist;
//        strlist<<item->text()<<"1"<<"0";
//        activateImageView(strlist);
//    }
    else
    {
        QStringList strlist;
        strlist<<item->data(item->text().toInt()+1000).toString()<<"1"<<"0";
        activateImageView(strlist);
//        QString info = "The board scan failed! Please RESCAN the board! Erroe code 001(pic numbers are 0)";
//        QMessageBox::critical(this, "Server", info, QMessageBox::Ok);
    }


//    QStringList strlist;
//    strlist<<item->text()<<"1"<<"0";
//    activateImageView(strlist);

}

//上面的单元格被双击
void MainWindow::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{
    if(!reScan && !stopScan)
    {
        cellDlg *celldlg = new cellDlg;
        QString imgPath = QString("C:/res/pics/top/%1/Composed_serv_%2.jpeg").arg(item->text()).arg(item->text());
        celldlg->initUi(imgPath);
        //显示上面单元格的图片
//        ui->upLab->setPixmap(QPixmap("C:\\res\\pics\\top\\111\\test.jpeg"));
        ui->viewNumLab->setText(item->text());
        celldlg->exec();   //采用模态对话框的模式弹出
    }

}

//下面的单元格被双击
void MainWindow::on_tableWidget_2_itemDoubleClicked(QTableWidgetItem *item)
{

    if(!reScan && !stopScan)
    {

        cellDlg *celldlg = new cellDlg;
        QString imgPath = QString("C:/res/pics/bot/%1/Composed_serv_%2.jpeg").arg(item->text()).arg(item->text());
        celldlg->initUi(imgPath);
        //显示上面单元格的图片
//        ui->upLab->setStyleSheet("border-image:url()");
        ui->viewNumLab->setText(item->text());
        celldlg->exec();   //采用模态对话框的模式弹出

    }
}


//鼠标悬浮在top item上
void MainWindow::showTopItemInfo(QTableWidgetItem *item, QPoint& point)
{
    if(status.ok())
        readRocksdbPanelInfo(options, panelPath, "top-"+item->data(item->text().toInt()+1000).toString()+"-info");
    showToolTip(item, "top", point);

}



//鼠标悬浮在bot item上
void MainWindow::showBotItemInfo(QTableWidgetItem *item, QPoint& point)
{
    if(status.ok())
        readRocksdbPanelInfo(options, panelPath, "bot-"+item->data(item->text().toInt()+1000).toString()+"-info");
    showToolTip(item, "bot", point);

}



void MainWindow::showToolTip(QTableWidgetItem* item, QString top, QPoint& point)
{
    if(sI.job.empty())return;


    QString msg = "-----"+item->text() + " on " + top + "-----";
    //读取Rocksdb中的信息
    if(sI.job == "AUTO")
    {

        msg = msg + QString("\nstatus:%1\nJob:%2\nOrientation:%3\nSlave:").arg(m_statu).arg(QString::fromStdString(sI.job)).arg(sI.orient);
        if(!m_slave.isEmpty())
            msg = msg + m_slave;
//        item->setToolTip(msg);
        QToolTip::showText(point, msg, ui->tableWidget, QRect(0, 0, 0, 0), 3000);
        return;

    }
    else
    {

        msg = msg + QString("\nstatus:%1\nJob:%2\nOrientation:%3\nSlave:").arg(m_statu).arg(QString::fromStdString(sI.job)).arg(sI.orient);
        if(!m_slave.isEmpty())
            msg = msg + m_slave;
        msg = msg + QString("\nPanel on VS:%1\nLot:%2\ndefect number:%3").arg(sI.panel_num).arg(QString::fromStdString(sI.lot)).arg(sI.defects.size());
//        item->setToolTip(msg);
        QToolTip::showText(point, msg, ui->tableWidget, QRect(0, 0, 0, 0), 3000);
        return;
    }
}


void MainWindow::activateImageView(QStringList strlist)
{
    QProcess process;
    process.startDetached("C:/Optima/imageviewer/ImageViewer.exe", strlist);

}



void MainWindow::getNewValue(const QString& str, const std::string& str1)
{
    if(str.isEmpty()) return;
    if(str1 == "JOB_BANK")
    {
        update_bank(str);
        return;
    }
    if(str1 == "UPDATE_LOT")
    {
        update_lot(str);
        return;
    }
    if(str1 == "REPEATED_POSITION_WARNING")
    {
        if(status.ok())
            emit updateDefectWarn(str);
        return;
    }

    bool top;
    int panel;
    json j;
    try
    {
       j = json::parse(str.toStdString());
       panel = j["panel"];
//       if(!((panel>=1000*I+1 && panel <= last+1) || (panel>=1000*II+Number && panel <= 1000*(II+1))))
//           return;
       actualPanel  = panel;

       top = j["top"];
    }
    //捕获所有异常
    catch (...)
    {
        return;
    }

    int num = to_slave_number(actualPanel);
    int type=-1;
    int defect_num = -1;
    QString pic;
    if(str1 == "PANEL_ARRIVED_OK")
    {
        type = 0;
        setI(actualPanel);
        pic = QString::fromStdString(j["composed_serv"]);
    }
    else if(str1 == "PANEL_ARRIVED_NOT_OK")
    {
        type = 0;
        setI(actualPanel);
    }
    else if(str1 == "PANEL_QD_SCAN_AUTO")
    {
        if(!((panel>=1000*I+1 && panel <= last+1) || (panel>=1000*II+Number && panel <= 1000*(II+1))))
            return;
        type = 1;
    }
    else if (str1 == "PANEL_SLAVE_ASSIGNED")
    {
        if(!((panel>=1000*I+1 && panel <= last+1) || (panel>=1000*II+Number && panel <= 1000*(II+1))))
            return;
        type = 2;
//        try
//        {
//            std::string slave_name = j["slave"];
//        }  catch (...)
//        {
//            std::cout<<"parse PANEL_SLAVE_ASSIGNED key slave fail";
//        }

    }
    else if(str1 == "PANEL_SCANNING")

    {
        if(!((panel>=1000*I+1 && panel <= last+1) || (panel>=1000*II+Number && panel <= 1000*(II+1))))
            return;
        type = 3;
        update_scanning_panel(str, num, top);

    }
    else if(str1 == "PANEL_DONE_OK")
    {
        if(!((panel>=1000*I+1 && panel <= last+1) || (panel>=1000*II+Number && panel <= 1000*(II+1))))
            return;
        type = 4;
        try {
            defect_num = j["defect_num"];
        }  catch (std::exception e) {
            qDebug()<<"parse PANEL_DONE_OK key defect_num fail";
        }
        remove_panel_in_list(num, top);
    }
    else if(str1 == "PANEL_DONE_NOT_OK")
    {
        if(!((panel>=1000*I+1 && panel <= last+1) || (panel>=1000*II+Number && panel <= 1000*(II+1))))
            return;
        type = 5;
        remove_panel_in_list(num, top);
    }
    else if(str1 == "PANEL_QD_SCAN_MANUAL")
    {
        if(!((panel>=1000*I+1 && panel <= last+1) || (panel>=1000*II+Number && panel <= 1000*(II+1))))
            return;
        type = 6;
    }
    else if(str1 == "PANEL_STOPPED")
    {
        if(!((panel>=1000*I+1 && panel <= last+1) || (panel>=1000*II+Number && panel <= 1000*(II+1))))
            return;
        type = 7;
        remove_panel_in_list(num, top);
    }
    else
        return;

    if(top)
    {
        setCellColor(ui->tableWidget, num, type, defect_num);
        if(!pic.isNull())
        {
            QImage Image;
            Image.load(pic);
            QPixmap pixmap = QPixmap::fromImage(Image);
            QPixmap fitpixmap = pixmap.scaled(380, 333, Qt::KeepAspectRatio, Qt::SmoothTransformation);  // 按比例缩放
            ui->upLab->setPixmap(fitpixmap);
            ui->viewNumLab->setText(QString::asprintf("%d",num));
        }

    }
    else
    {
        setCellColor(ui->tableWidget_2, num, type, defect_num);
        if(!pic.isNull())
        {
            QImage Image;
            Image.load(pic);
            QPixmap pixmap = QPixmap::fromImage(Image);
            QPixmap fitpixmap = pixmap.scaled(380, 333, Qt::KeepAspectRatio, Qt::SmoothTransformation);  // 按比例缩放
            ui->downLab->setPixmap(fitpixmap);
            ui->viewNumLab->setText(QString::asprintf("%d",num));
        }

    }


}

//更新job_bank
void MainWindow::update_bank(QString str)
{

    try
    {
       json j = json::parse(str.toStdString());
       std::vector<std::string> t = j["jobs"];
       ui->textEdit_2->clear();
       foreach(auto v, job_bank)
       {
           ui->textEdit_2->append(v);
       }
       QString str;

       foreach(std::string value, t)
       {
           bool find = false;
//           QStringList strList = QString::fromStdString(value).split(QRegExp("/"));
//           if(strList.count()>=1)
//                ui->textEdit_2->append(strList[1]);
           str = QString::fromStdString(value).replace("\\", "/");
           str.replace("c:/jobs/","",Qt::CaseInsensitive);
           for (int i=0; i<job_bank.count(); ++i)
           {
               if(job_bank[i].toLower() == str.toLower())
               {
                   find = true;
                   break;
               }
               find = false;

           }
           if(!find)
                ui->textEdit_2->append(str);

       }
    }
    catch (std::exception e)
    {
        qDebug()<<"update job bank fail";
        return;
    }

}


//更新lot_name
void MainWindow::update_lot(QString str)
{
    json j = json::parse(str.toStdString());
    try
    {
        std::string lot_name = j["lot"];
        ui->lineEdit_2->clear();
        ui->lineEdit_2->setText(QString::fromStdString(lot_name));
    }  catch (...)
    {
        qDebug()<<"解析lot错误";
        return;
    }
}



//更新scanning信息
void MainWindow::update_scanning_panel(QString msg, int& panel, bool& top)
{

    QString temp;
    if(top) temp = "top";
    else temp = "bot";

    for (int i=0; i<scanPanelList.count(); ++i)
    {
        if(scanPanelList[i].panel == panel && scanPanelList[i].top == temp)
            return;
    }
    scan_panel_info spi;
    spi.panel = panel;
    spi.top = temp;
    spi.se.timestamp = std::chrono::system_clock::now();
    json j;
    try
    {
        j = json::parse(msg.toStdString()); 
        spi.se.slave = j["slave"];
//        QString info = QString("%1,%2,%3").arg(panel).arg(temp).arg(QString::fromStdString(se.slave));
//        scanPanelList.append(std::tuple<QString, time_point>(info, se.timestamp));
        scanPanelList.append(spi);
//        if(temp == "top")
//            m_scanTopMaxPanel = m_scanTopMaxPanel >= panel ? m_scanTopMaxPanel:panel;
//        else
//            m_scanBotMaxPanel = m_scanBotMaxPanel >= panel ? m_scanBotMaxPanel:panel;
    }  catch (...)
    {
        qDebug()<<"parse scanning box panel fail";
        return;
    }

}


//移除list中scanning的panel
void MainWindow::remove_panel_in_list(int panel, bool top)
{
    if(scanPanelList.count()<=0)
        return;
    QString temp;
    if(top)
    {
        temp = "top";
    }
    else
    {
        temp = "bot";
    }
    int find=-1;
    for (int i=0; i<scanPanelList.count(); ++i)
    {
//        QString msg;
//        std::tie(msg, std::ignore) = scanPanelList[i];
//        QStringList strList = msg.split(QRegExp(","));
//        if(strList.count()<=2) continue;
//        if(panel == strList[0].toInt() && temp == strList[1])
//        {
//            find = i;
//            break;
//        }
        if(scanPanelList[i].panel == panel && scanPanelList[i].top == temp)
        {
            find = i;
            break;
        }
    }
    if(find>=0)
        scanPanelList.removeAt(find);

}


//处理从imageViewer得到的信息
void MainWindow::getNewValue1(const QString& str)
{

    scan_with_job job_info;
    try
    {
       json j = json::parse(str.toStdString());
       json_to_job(j, job_info);
    }  catch (...)
    {
        return;
    }
    ScanDlg *scanDlg = new ScanDlg(QString::fromStdString(job_info.path), job_info.angle, QString::fromStdString(job_info.point));
    connect(scanDlg, &ScanDlg::to_reScan, this, &MainWindow::responseOk);
    scanDlg->show();

}

void MainWindow::responseOk(QString str, QString angle, QString point)
{

    flag = false;
    path = str;
    orient = angle.toInt();
    isJob = true;
    on_restartBtn_clicked(false);

}

//点击了绿色按钮
void MainWindow::on_greenBtn_clicked()
{

    if(ui->lineEdit_2->isReadOnly())
        return;
    //发送消息给kafka
    QString msg = ui->lineEdit_2->text();
    producer->getNewMessage(lot_to_json(msg.toStdString()), "update_lot");


}

//点击了红色按钮
void MainWindow::on_redBtn_clicked(bool checked)
{
    if(checked)
    {
        ui->batchLab->setStyleSheet("color:rgb(255,0,0)");
        ui->lineEdit_2->setReadOnly(checked);
        ui->lineEdit_2->setStyleSheet("color:rgb(166,166,166)");

    }
    else
    {
        ui->batchLab->setStyleSheet("color:rgb(0,255,0)");
        ui->lineEdit_2->setReadOnly(checked);
        ui->lineEdit_2->setStyleSheet("color:rgb(0, 0, 0)");
    }
    ui->greenBtn->setEnabled(!checked);
}

//点击了上面单元格的响应事件
void MainWindow::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    setItemActuallValue(item);
    if(sItem1 || eItem1)
    {
        return;
    }
    //表示点击了重新开始扫描按钮
    if(reScan)
    {
        if(sItem == nullptr)
        {
            //记录起始板号
            sItem = item;

            return;
        }
        else if (eItem == nullptr && sItem)
        {
            //记录结束板号
            eItem = item;

            //设置单元格取消选中
            eItem->setSelected(false);

            //发送申请扫描请求给kafka服务器
            std::string msg;

            if(isJob)
            {
                if(sItem->data(sItem->text().toInt()+1000).toInt() > eItem->data(eItem->text().toInt()+1000).toInt())
                {

                   msg = rescanMsgJob(eItem->data(eItem->text().toInt()+1000).toInt(), sItem->data(sItem->text().toInt()+1000).toInt(), true, path.toStdString(), orient);
                }
                else
                {
                   msg = rescanMsgJob(sItem->data(sItem->text().toInt()+1000).toInt(), eItem->data(eItem->text().toInt()+1000).toInt(), true, path.toStdString(), orient);
                }
                emit sendServer(msg, "scan_panel_with_job");
                isJob = false;
                celarValue();
            }
            else
            {
                if(sItem->data(sItem->text().toInt()+1000).toInt() > eItem->data(eItem->text().toInt()+1000).toInt())
                {

                   msg = rescanMsg(eItem->data(eItem->text().toInt()+1000).toInt(), sItem->data(sItem->text().toInt()+1000).toInt(), true);
                }
                else
                {
                   msg = rescanMsg(sItem->data(sItem->text().toInt()+1000).toInt(), eItem->data(eItem->text().toInt()+1000).toInt(), true);
                }
                emit sendServer(msg, "scan_panel");
            }

            //改变重新扫描按钮的状态
            flag = true;
            on_restartBtn_clicked(false);
            ui->stopBtn->setEnabled(true);
            reScan = false;
            return;
        }

    }

    //表示点击了停止扫描按钮
    if(stopScan)
    {
        if(sItem == nullptr)
        {
            //记录起始板号
            sItem = item;

            return;
        }
        else if (eItem == nullptr && sItem)
        {
            //记录结束板号
            eItem = item;

            //设置单元格取消选中
            eItem->setSelected(false);

            //发送停止扫描请求给kafka服务器
            std::string msg;
            if(sItem->data(sItem->text().toInt()+1000).toInt() > eItem->data(eItem->text().toInt()+1000).toInt())
            {

               msg = stopScanMsg(eItem->data(eItem->text().toInt()+1000).toInt(), sItem->data(sItem->text().toInt()+1000).toInt(), true);
            }
            else
            {
               msg = stopScanMsg(sItem->data(sItem->text().toInt()+1000).toInt(), eItem->data(eItem->text().toInt()+1000).toInt(), true);
            }

            emit sendServer(msg, "stop_panel");

            //改变停止扫描按钮的状态
            flag = true;
            on_stopBtn_clicked(false);
            ui->restartBtn->setEnabled(true);
            stopScan = false;
            return;
        }
    }

}

void MainWindow::on_tableWidget_2_itemClicked(QTableWidgetItem *item)
{
    setItemActuallValue(item);
    if(sItem || eItem)
    {
        return;
    }
    if(reScan)
    {
        if(sItem1 == nullptr)
        {
            //记录起始板号
            sItem1 = item;

            return;
        }
        else if (eItem1 == nullptr && sItem1)
        {
            //记录结束板号
            eItem1 = item;

            //设置单元格取消选中
            eItem1->setSelected(false);

            //发送申请扫描请求给kafka服务器
            std::string msg;
            if(isJob)
            {
                if(sItem1->data(sItem1->text().toInt()+1000).toInt() > eItem1->data(eItem1->text().toInt()+1000).toInt())
                {

                   msg = rescanMsgJob(eItem1->data(eItem1->text().toInt()+1000).toInt(), sItem1->data(sItem1->text().toInt()+1000).toInt(), false, path.toStdString(), orient);
                }
                else
                {
                   msg = rescanMsgJob(sItem1->data(sItem1->text().toInt()+1000).toInt(), eItem1->data(eItem1->text().toInt()+1000).toInt(), false, path.toStdString(), orient);
                }
                emit sendServer(msg, "scan_panel_with_job");
                isJob = false;
                celarValue();
            }
            else
            {
                if(sItem1->data(sItem1->text().toInt()+1000).toInt() > eItem1->data(eItem1->text().toInt()+1000).toInt())
                {

                   msg = rescanMsg(eItem1->data(eItem1->text().toInt()+1000).toInt(), sItem1->data(sItem1->text().toInt()+1000).toInt(), false);
                }
                else
                {
                   msg = rescanMsg(sItem1->data(sItem1->text().toInt()+1000).toInt(), eItem1->data(eItem1->text().toInt()+1000).toInt(), false);
                }
                emit sendServer(msg, "scan_panel");
            }

            //改变重新扫描按钮的状态
            flag = true;
            on_restartBtn_clicked(false);
            ui->stopBtn->setEnabled(true);
            reScan = false;
            return;
        }

    }

    //表示点击了停止扫描按钮
    if(stopScan)
    {
        if(sItem1 == nullptr)
        {
            //记录起始板号
            sItem1 = item;

            return;
        }
        else if (eItem1 == nullptr && sItem1)
        {
            //记录结束板号
            eItem1 = item;

            //设置单元格取消选中
            eItem1->setSelected(false);

            //发送停止扫描请求给kafka服务器
            std::string msg;
            if(sItem1->data(sItem1->text().toInt()+1000).toInt() > eItem1->data(eItem1->text().toInt()+1000).toInt())
            {

               msg = stopScanMsg(eItem1->data(eItem1->text().toInt()+1000).toInt(), sItem1->data(sItem1->text().toInt()+1000).toInt(), false);
            }
            else
            {
               msg = stopScanMsg(sItem1->data(sItem1->text().toInt()+1000).toInt(), eItem1->data(eItem1->text().toInt()+1000).toInt(), false);
            }

            emit sendServer(msg, "stop_panel");

            //改变停止扫描按钮的状态
            flag = true;
            on_stopBtn_clicked(false);
            ui->restartBtn->setEnabled(true);
            stopScan = false;
            return;
        }
    }
}


void MainWindow::updateScanningContent()
{

    ui->textEdit->clear();
    if(scanPanelList.count()<=0)
        return;
    for (int i=0; i<scanPanelList.count(); ++i)
    {
        QString msg;
        QTime time(0,0,0);
//        std::tie(msg, sT) = scanPanelList[i];
//        uint t = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now()-sT).count()+8*3600;
        uint t = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now()-scanPanelList[i].se.timestamp).count();
        QTime delayTime = time.addSecs(t);
        msg = QString("%1,%2,%3,").arg(scanPanelList[i].panel).arg(scanPanelList[i].top).arg(QString::fromStdString(scanPanelList[i].se.slave)) + delayTime.toString("hh:mm:ss");
        ui->textEdit->append(msg);
    }
    ui->textEdit->moveCursor(QTextCursor::Start);
}


void MainWindow::on_exit_Btn_clicked()
{
    this->close();
}



void MainWindow::setItemActuallValue(QTableWidgetItem *item)
{
    if(item->data(item->text().toInt()+1000).toInt() == 0)
    {
        int value;
        if(item->text().toInt()<Number)
            value = 1000*I+item->text().toInt();
        else
            value = 1000*II+item->text().toInt();
        item->setData(item->text().toInt()+1000, value);
    }
}


void MainWindow::getDefectNum(int n)
{
    defectSize = n;
    setDlg->oldValue = n;
//    updateGreenStatus();

}



void MainWindow::updateGreenStatus()
{
    std::string str;
    db->TryCatchUpWithPrimary();
    db->Get(rocksdb::ReadOptions(), "done_ok_panels", &str);
    if (!str.empty())
    {
        json j = json::parse(str);
        std::set<int> top, bot;
        json_to_top_bot(j, top, bot);
        if(!top.empty())
        {

            foreach(int panel, top)
            {
                if((panel>=1000*I+1 && panel < last) || (panel>1000*II+Number && panel <= 1000*(II+1)))
                {
                    panel = to_slave_number(panel);
                    setCellColor(ui->tableWidget, panel, 4);
                }

            }

        }

        if(!bot.empty())
        {
            foreach(int panel, bot)
            {
                if((panel>=1000*I+1 && panel < last) || (panel>1000*II+Number && panel <= 1000*(II+1)))
                {
                    panel = to_slave_number(panel);
                    setCellColor(ui->tableWidget_2, panel, 4);
                }

            }


        }
    }
}


void MainWindow::getServerdStatus()
{
//    QProcess process;
//    process.start("tasklist.exe");
//    if(process.waitForFinished())
//    {
//        QString result = process.readAll();
//        if(result.contains("serverd.exe"))
//        {
//            ui->serverdLab->setText("Serverd Running");
//            ui->serverdLab->setStyleSheet("color:green");
//        }
//        else
//        {
//            ui->serverdLab->setText("Serverd Not Running");
//            ui->serverdLab->setStyleSheet("color:red");
//        }

//    }
}


void MainWindow::on_actionPreferences_triggered()
{
    setDlg->show();
}


void MainWindow::on_action_defect_warning_triggered()
{
    dwDlg->show();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    setDlg->close();
    dwDlg->close();
    QFile file("C:/Optima/server-gui/setting.txt");
    if(file.open(QFile::WriteOnly|QFile::Truncate))
    {
        QString content = QString("%1").arg(defectSize);
        QTextStream in(&file);
        in << content << "\n";
    }
    file.close();
    QMainWindow::closeEvent(event);
}

