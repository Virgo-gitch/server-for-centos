#include "defectwarnthread.h"

defectWarnThread::defectWarnThread(QObject *parent) : QObject(parent)
{

}


void defectWarnThread::dealDefectWarnInfo(const QString& msg, const job_pos& oldJP)
{

    defect_pos_warn dpw;
    QVector<job_pos> jp;
    try {
        json j = json::parse(msg.toStdString());
        j.at("notification").get_to(dpw.noti);
        foreach(auto j, dpw.noti)
        {
            foreach(auto p, j.pos)
            {
                job_pos temp{j.job,p};
                jp.push_back(temp);
            }
        }
    }  catch (std::exception e) {
        qDebug()<<e.what();
        return;
    }
    int find = 0;
    if(oldJP.job != "")
    {
        for(int i=0; i<jp.size(); ++i)
        {

            if(jp.at(i).job == oldJP.job && jp.at(i).defects.x1 == oldJP.defects.x1 && jp.at(i).defects.x2 == oldJP.defects.x2 && jp.at(i).defects.y1 == oldJP.defects.y1 && jp.at(i).defects.y2 == oldJP.defects.y2)
            {
                find = i;
                break;
            }
            else if(i == jp.size()-1)
            {
                find = 0;
                jp.push_front(oldJP);
                break;
            }
            else
                continue;
        }
    }
    int job_pos_num = jp.size();
    emit sendResult(jp, job_pos_num, find);
    QThread::msleep(2000);

}
