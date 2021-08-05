#include "mypanels.h"
#include <rocksdb/db.h>

MyPanels::MyPanels()
{

}

MyPanels::~MyPanels()
{

}

void MyPanels::initPanels()
{
    rocksdb::DB *db;
    rocksdb::Options options;
    options.create_if_missing = true;
    // 打开数据库
    rocksdb::Status status = rocksdb::DB::Open(options, "D:/testdb", &db);
    assert(status.ok());
    auto opts = rocksdb::ReadOptions();
    opts.fill_cache = false;
    std::string key_str, str;
    int type;
    //获取静态的stores
    for (int i=0;i<5 ; ++i)
    {
        switch (i)
        {
        case arrival_ok_panels:
            key_str = "arrival_ok_panels";
            type = 0;
            break;
        case arrival_not_ok_panels:
            key_str = "arrival_not_ok_panels";
            type = 0;
            break;
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

        }
        db->Get(opts, key_str, &str);
        if (str.empty()) continue;
        json j = json::parse(str);
        std::set<int> top, bot;
        json_to_top_bot(j, top, bot);
        if(top.empty()) continue;
        foreach (var, container) {

        }
//        {
//            setCellColor(ui->tableWidget, panel, type);
//        }
//        if(bot.empty()) continue;
//        foreach(int panel, bot)
//        {
//            setCellColor(ui->tableWidget_2, panel, type);
//        }
    }

    //获取动态的stores
//    json j;
//    db->Get(opts, scanning_key, &str);
//    if (str.empty())return;
//    j = json::parse(str);
//    std::unordered_map<std::string, std::vector<int>> scanning_top, scanning_bot;
//    json_to_top_bot(j, scanning_top, scanning_bot);
//    for (auto iter = scanning_top.begin(); iter != scanning_top.end(); ++iter)
//    {
////        qDebug()<<QString::fromStdString(iter->first)<<iter->second;
//        std::vector panels = iter->second;
//        foreach(int panel, panels)
//        {
//            qDebug()<<panel;
//            setCellColor(ui->tableWidget, panel, 3);
//        }

//    }

//    db->Get(opts, scan_queued_key, &str);
//    if (str.empty()) return;
//    j = json::parse(str);
//    std::set<int> scan_queued_top, scan_queued_bot;
//    json_to_top_bot(j, scan_queued_top, scan_queued_bot);


//    db->Get(opts, slave_assignment_queue_key, &str);
//    if (str.empty()) return;
//    j = json::parse(str);
//    std::unordered_map<std::string, std::vector<int>> slave_assignment_queue_top, slave_assignment_queue_bot;
//    json_to_top_bot(j, slave_assignment_queue_top, slave_assignment_queue_bot);
//    for (auto iter = slave_assignment_queue_top.begin(); iter != slave_assignment_queue_top.end(); ++iter)
//    {
////        qDebug()<<QString::fromStdString(iter->first)<<iter->second;
//        std::vector panels = iter->second;
//        foreach(int panel, panels)
//        {
//            qDebug()<<panel;
//            setCellColor(ui->tableWidget, panel, 2);
//        }

//    }


    delete db;
    return;
}
