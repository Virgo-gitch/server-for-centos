#include "defectwarning.h"
#include "ui_defectwarning.h"
#include <QDebug>

DefectWarning::DefectWarning(rocksdb::DB *db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DefectWarning)
{
    ui->setupUi(this);
    Qt::WindowFlags flags= Qt::Dialog;
    flags |= Qt::WindowCloseButtonHint;
    setWindowFlags(flags);
    setWindowTitle("Fixed Defect");
    setFixedSize(1110, 540);
    ui->label->setScaledContents(true);
    ui->label_2->setScaledContents(true);
    ui->pushButton_2->setEnabled(false);
    curPos = curIdx = 0;
    cad_x = cad_y = 0;
    oldJP.job = "";
    DB = db;
    defectWarnThread *dwt = new defectWarnThread;
    dwt->moveToThread(&workThread);

    connect(this, &DefectWarning::sendInfoToThread, dwt, &defectWarnThread::dealDefectWarnInfo);

    connect(dwt, &defectWarnThread::sendResult, this, &DefectWarning::getResult);

    connect(&workThread, &QThread::finished, dwt, &defectWarnThread::deleteLater);

    connect(this, &DefectWarning::sendDefectInfo, ui->label, &myDefectPosLab::getDefectInfo);

    connect(this, &DefectWarning::startDraw, ui->label, &myDefectPosLab::setDraw);

    connect(ui->label, &myDefectPosLab::drawMaskEnd, this, &DefectWarning::getMaskInfo);

    workThread.start();
}

DefectWarning::~DefectWarning()
{
    delete ui;
}


void DefectWarning::getDefectMsg(const QString& msg)
{
    emit sendInfoToThread(msg, oldJP);
}


void DefectWarning::getResult(const QVector<job_pos>& j, const int count, const int cur)
{
    jp.clear();
    jp = j;
    job_pos_num = count;
    curPos = cur;
    setTitleAndLineText(curPos, curIdx);
}


void DefectWarning::setTitleAndLineText(const int i, const int idx)
{
    ui->listWidget->clear();
    oldJP = jp.at(i);
    QString job = QString::fromStdString(jp.at(i).job);
    path = job;
    job.replace("\\","/");
    job.replace("c:/jobs/","",Qt::CaseInsensitive);
    setWindowTitle(QString("%1 on %2.%3.%4.%5").arg(job).arg(jp.at(i).defects.x1).arg(jp.at(i).defects.y1)
            .arg(jp.at(i).defects.x2).arg(jp.at(i).defects.y2));
    foreach(auto ds, jp.at(i).defects.defect_ids)
    {
//        QString t = date.currentDateTime().toString("MM/dd hh:mm");
        time_point t = getScanTime(ds.top?"top":"bot", ds.panel_num);
        std::time_t now_c = std::chrono::system_clock::to_time_t(t);
        QString scanTime = QDateTime::fromTime_t(now_c).toString("MM/dd hh:mm");
        ui->listWidget->addItem(QString("%1 %2 on %3 defect index of %4").arg(ds.panel_num).arg((ds.top?"top":"bot")).arg(scanTime).arg(ds.defect_idx));
    }
    try {
        ui->listWidget->setCurrentRow(idx);
        QListWidgetItem *item = ui->listWidget->item(idx);
        on_listWidget_itemClicked(item);
    }  catch (std::exception e) {
        qDebug()<<e.what();
    }


}


void DefectWarning::readPanelInfo(const int& panel, const QString& top, const int& inx)
{
    std::string strKey = QString("%1-%2-info").arg(top).arg(panel).toStdString();
    std::string value;

    rocksdb::Status status = DB->Get(rocksdb::ReadOptions(), strKey, &value);
//    qDebug()<<"key"<<QString::fromStdString(strKey);
//    qDebug()<<"value"<<QString::fromStdString(value);
    ui->label_2->setPixmap(QPixmap(""));
    if(value.empty()) return;
    if (status.ok())
    {
        try {
            json j = json::parse(value);
            static_info s = j;
            QString path = QString::fromStdString(s.job);
            QString fileName = "bmScaleMask.gif";
            QMatrix matrix;
            matrix.rotate((s.orient-1)*90);
            QPixmap defePix = QPixmap(path + "\\" + fileName).transformed(matrix, Qt::SmoothTransformation);
            ui->label->setPixmap(defePix);
            pixX = 0, pixY = 0;
            cad_x = cad_y = 0;
            pixX = ui->label->pixmap()->width();
            pixY = ui->label->pixmap()->height();
            ui->label_2->setPixmap(QString::fromStdString(s.defects.at(inx).im_path));
            cad_x = s.defects.at(inx).cad_x;
            cad_y = s.defects.at(inx).cad_y;
            emit sendDefectInfo(cad_x,cad_y,s.orient,s.job,pixX,pixY);
        }  catch (std::exception e) {
            qDebug()<<e.what();
        }

    }
}


time_point DefectWarning::getScanTime(const QString& top, const int& panel)
{
    std::string key = QString("%1-%2-history").arg(top).arg(panel).toStdString();
    std::string value;
    DB->Get(rocksdb::ReadOptions(), key, &value);
//    qDebug()<<"key"<<QString::fromStdString(key);
//    qDebug()<<"value"<<QString::fromStdString(value);
    if(!value.empty())
    {
        try {
            json j = json::parse(value);

            auto rit = j.rbegin();

            if (rit->contains("scanning"))
            {
                scan_panel_info spi;
                spi.se = rit->at("scanning").get<scanning_event>();
                return spi.se.timestamp;
    //                spi.se.timestamp -= std::chrono::seconds(8*3600);
            }
        }  catch (std::exception e) {
            qDebug()<<e.what();
        }
    }
    return time_point();
}


//上一点
void DefectWarning::on_pushButton_5_clicked()
{
    if(curPos<1 || job_pos_num == 0 || !ui->listWidget->currentItem())
        return;
    curPos -= 1;
    setTitleAndLineText(curPos, 0);
}

//下一点
void DefectWarning::on_pushButton_6_clicked()
{
    if(curPos+1>=job_pos_num || !ui->listWidget->currentItem())
        return;
    curPos += 1;
    setTitleAndLineText(curPos, 0);
}


void DefectWarning::on_listWidget_itemClicked(QListWidgetItem *item)
{
    Q_UNUSED(item);
    int curRow = ui->listWidget->currentRow();
    curIdx = curRow;
    int panel = jp.at(curPos).defects.defect_ids.at(curRow).panel_num;
    QString top = jp.at(curPos).defects.defect_ids.at(curRow).top?"top":"bot";
    int defect_index = jp.at(curPos).defects.defect_ids.at(curRow).defect_idx;
    ui->label->X = 0;
    ui->label->Y = 0;
    readPanelInfo(panel, top, defect_index);
}

//real defect create AddPoints.txt file
void DefectWarning::on_pushButton_clicked()
{
//    if(jp.size()<1)
//        return;
//    int curRow = ui->listWidget->currentRow();
//    int panel = jp.at(curPos).defects.defect_ids.at(curRow).panel_num;
//    QString top = jp.at(curPos).defects.defect_ids.at(curRow).top?"top":"bot";
//    int index = jp.at(curPos).defects.defect_ids.at(curRow).defect_idx;
//    std::string strKey = QString("%1-%2-info").arg(top).arg(panel).toStdString();
//    std::string value;
//    DB->Get(rocksdb::ReadOptions(), strKey, &value);
//    static_info s;
//    if(!value.empty())
//    {
//        s = json::parse(value);
//    }
    if(!ui->listWidget->currentItem())
        return;
    QString msg = "Do you want to add the current defect point?";
    QMessageBox::StandardButton bOk = QMessageBox::information(this, "add point", msg, QMessageBox::Cancel, QMessageBox::Ok);
    if(bOk == QMessageBox::Ok)
    {
        QFile file(path+"\\addPoints.txt");
        if(file.open(QIODevice::WriteOnly | QIODevice::Append))
        {
            QTextStream out(&file);
            out<<0<<" "<<cad_x<<" "<<cad_y;
            out<<"\n";
            emit update_settings_file(job_file_to_json(path.toStdString(),path.toStdString()+"\\addPoints.txt"), "update_job_settings");
        }
        file.close();
    }



}

//update data
void DefectWarning::on_pushButton_2_clicked()
{
//    updateUi(newMag);
//    ui->pushButton_2->setEnabled(false);
}

//mask defect
void DefectWarning::on_pushButton_3_clicked()
{
    if(!ui->listWidget->currentItem())
        return;
    ui->label->bDraw = true;

}


void DefectWarning::getMaskInfo(const QPoint& p1, const QPoint& p2, const int x1, const int y1, const int x2, const int y2)
{
//    ui->pushButton_3->setEnabled(true);
//    path = "D:\\jobs\\test\\gtl";
    QFile file(path+"\\ghmasks_polygon_user.txt");
    int count = 0;
    QString con;
    if(file.open(QIODevice::ReadOnly))
    {
        count = file.readLine().toInt();
        con = file.readAll();
    }
    file.close();
    file.setFileName(path+"\\ghmasks_polygon_user.txt");
    if(file.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        QTextStream out(&file);
        out<<count+1<<"\n"<<con;
        out<<"5"<<"\n"<<x1<<" "<<y1<<"\n";
        out<<x2<<" "<<y1<<"\n"<<x2<<" "<<y2<<"\n";
        out<<x1<<" "<<y2<<"\n"<<x1<<" "<<y1<<"\n";
        emit  update_settings_file(job_file_to_json(path.toStdString(), path.toStdString()+"\\mask.txt"), "update_job_settings");
    }
    file.close();
    file.setFileName(path+"\\mask_points.txt");
    count = 0;
    con = "";
    if(file.open(QIODevice::ReadOnly))
    {
        count = file.readLine().toInt();
        con = file.readAll();
    }
    file.close();
    file.setFileName(path+"\\mask_points.txt");
    if(file.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        QTextStream out(&file);
        out<<count+1<<"\n"<<con;
        out<<"5"<<"\n"<<p1.x()*(pixX/360)<<" "<<p1.y()*(pixY/360)<<"\n";
        out<<p2.x()*(pixX/360)<<" "<<p1.y()*(pixY/360)<<"\n";
        out<<p2.x()*(pixX/360)<<" "<<p2.y()*(pixY/360)<<"\n";
        out<<p1.x()*(pixX/360)<<" "<<p2.y()*(pixY/360)<<"\n";
        out<<p1.x()*(pixX/360)<<" "<<p1.y()*(pixY/360)<<"\n";
    }
    file.close();
    qDebug()<<"mask path"<<path+"\\mask_points.txt";
}
