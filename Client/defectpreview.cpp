#include "defectpreview.h"
#include "ui_defectpreview.h"
#include <string>
#include <unordered_map>
#include <QProcess>
#include <QDebug>


DefectPreview::DefectPreview(QString top, int panel, rocksdb::DB *db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DefectPreview)
{
    ui->setupUi(this);
    //设置对话框除掉？按钮
    Qt::WindowFlags flags= Qt::Dialog;
    flags |= Qt::WindowCloseButtonHint;
    setWindowFlags(flags);
    setFixedSize(1100, 615);
    curdfec = 1;
    m_panel = panel;
    curPanle = to_slave_number(panel);
    m_top = top;
    m_statu = "";
    DB = db;

    scene = new QGraphicsScene(0, 0, 500, 400);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->centerOn(0, 0);
    imgItem = new QGraphicsPixmapItem();
    scene->addItem(imgItem);
    ui->minordefectLab->setScaledContents(true);
    ui->defectLab->setScaledContents(true);
    ui->panelLab->setStyleSheet("background-color:rgb(210,210,210);color:rgb(85, 170, 255)");
    //初始化lab
    ui->curdefectLab->setStyleSheet("color:rgb(0, 255, 0)");
    connect(this, &DefectPreview::currentPanelChange, ui->defectLab, &MyDefectLab::getDefectCoordinates);

    connect(this, &DefectPreview::showNextCircle, ui->defectLab, &MyDefectLab::getNextCricle);

//    readRocksdbInfo(panel, top);
    initWidget(top, m_panel);
    initTable(ui->tableWidget, curPanle);


}

DefectPreview::~DefectPreview()
{
    delete ui;
}


void DefectPreview::readRocksdbInfo(int panel, QString top)
{
//    rocksdb::DB *db;
    s.defects.clear();
    rocksdb::Status status;
    m_statu = "";
    if(m_panel>10000) m_panel = 10000;
    if(m_panel<1) m_panel = 1;
    // 打开数据库
//    rocksdb::Status status = rocksdb::DB::OpenForReadOnly(option, "C:\\Optima\\serverd\\debug\\DB\\panels", &db);
//    if (status.ok())
//    {
        std::string strKey = QString("%1-%2-info").arg(top).arg(m_panel).toStdString();
        std::string value;
        status = DB->Get(rocksdb::ReadOptions(), strKey, &value);
        qDebug()<<"key"<<QString::fromStdString(strKey);
        qDebug()<<"value"<<QString::fromStdString(value);
        if(value.empty()) return;
        if (status.ok())
        {

            json j = json::parse(value);
            s = j;
//            int size = j["defects"].size();

//            static_info::defect_info dd;
//            for (int i = 0; i < size; ++i)
//            {

//                 std::string str2 = j["defects"][i][1].dump();
//                 json j2 = json::parse(str2);
//                 dd = j2;
//                 s.defects.insert(std::pair<size_t, static_info::defect_info>(atoi(j["defects"][i][0].dump().c_str()), dd));
//            }
        }

//    }
//    delete db;


}


void DefectPreview::initWidget(QString top, int panel)
{

    readRocksdbInfo(panel, top);
    setWindowTitle("Mini Image Viewer: " + QString::fromStdString(s.job) + QString(" and orientation %1. Panel number %2,on %3 Lot:").arg(s.orient).arg(panel).arg(top) + QString::fromStdString(s.lot));
    ui->defectLab->coordinates.clear();
    defectPath.clear();
    ui->minordefectLab->setPixmap(QPixmap(":/pic/image/ok.jpg"));
//    ui->defectLab->setPixmap(QPixmap(""));

    QString path = QString::fromStdString(s.job).replace("c:\\Jobs", "C:\\jobs", Qt::CaseInsensitive);
    QString fileName = "bmScaleMask.gif";
    QMatrix matrix;
    matrix.rotate((s.orient-1)*90);
    QPixmap defePix = QPixmap(path + "\\" + fileName).transformed(matrix, Qt::SmoothTransformation);
    qDebug()<<"defectLab path"<<path + "\\" + fileName;
    ui->defectLab->setPixmap(defePix);

    imgItem->setPixmap(QPixmap(""));

    ui->bmpcountLab->setText("0");
    //初始化显示titleLab
    ui->titleLab->setText(QString::asprintf("%dA",m_panel));
    ui->comboBox->clear();
    curdfec = 1;

    //初始化显示panel的lab
    ui->panelLab->setText(QString::asprintf("%d",panel));

    QString camPath = QString("C:\\res\\pics\\%1\\%2\\Composed_serv_%3.jpeg").arg(top).arg(panel).arg(panel);
    QPixmap comImg = QPixmap(camPath);
    comImg = comImg.scaled(500, 400, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    qDebug()<<"QGraphicsView path:"<<camPath;
    imgItem->setPixmap(comImg);

    ui->curdefectLab->setText(QString::asprintf("%d",curdfec));
    if(s.defects.size()<=0)
    {
        ui->defectLab->clearPoly();
        return;
    }



    //初始化image
    QString imgPath = QString::fromStdString(s.defects.at(curdfec).im_path).replace("/", "\\");
    ui->minordefectLab->setPixmap(QPixmap(imgPath));

    //初始化image
    qreal gifW, gifH;
    gifW = qreal(ui->defectLab->pixmap()->width());
    gifH = qreal(ui->defectLab->pixmap()->height());
    readFileInfo(s, gifW, gifH);
    //初始化combox
    ui->comboBox->addItem(path.replace("C:\\jobs\\", ""));
    ui->bmpcountLab->setText(QString::asprintf("%d",defectPath.size()));


}


void DefectPreview::readFileInfo(static_info& s, int gifX, int gifY)
{

    sX = gifX/360;
    sY = gifY/360;
    float res1 = 1.8, res2 =1.8, res3 = 0.00;
//    int x_cad0=0, y_cad0=0;
    int outW=0, outH=0;
    QString temp = "bot";
    if(s.top) temp = "top";
    QString path = QString::fromStdString(s.job);
    QFile file(path+"\\ghinfo1.txt");
    //读取res1
    bool open = file.open(QIODevice::ReadOnly);
    if(open)
    {
        QString temp = file.readLine();
        QStringList list = temp.split(" ");
        if(list.count()>=2)
        {
            outW = list[0].toInt();
            outH = list[1].toInt();
            res1 = list[2].toFloat();
        }
    }
    file.close();
    //读取res2
    file.setFileName(path + "\\bmOut_HR.txt");
    open = file.open(QIODevice::ReadOnly);
    if(open)
    {
        QString temp = file.readLine().trimmed();
        if(!temp.isEmpty())
            res2 = temp.toFloat();
        temp = file.readLine().trimmed();
//        if(!temp.isEmpty())
//            x_cad0 = temp.toInt();
//        temp = file.readLine().trimmed();
//        if(!temp.isEmpty())
//            y_cad0 = temp.toInt();
    }
    file.close();
    file.setFileName(path + "\\cadInfo.txt");
    open = file.open(QIODevice::ReadOnly);
    if(open)
    {
        while(!file.atEnd())
         {
          QString readCon = file.readLine();
          QStringList content = readCon.split(":");
          if(content.at(0).toLower() == "resolution")
          {
              QStringList con = readCon.split(",");
              res3 = con[1].replace("out","", Qt::CaseInsensitive).trimmed().toFloat();
              break;
          }
         }
    }
    file.close();
    qDebug()<<"mask_points path:"<<path+"\\mask_points.txt";
    file.setFileName(path+"\\mask_points.txt");
    QVector<QPolygon> polygon;
    if(file.open(QIODevice::ReadOnly))
    {
        int polycut = file.readLine().trimmed().toInt();
        for (int i=0; i<polycut; ++i)
        {
            QPolygon p;
            int n = file.readLine().trimmed().toInt();
            for(int i=0; i<n; ++i)
            {

                QStringList temp = QString(file.readLine()).split(" ");
                if(temp.count()>1)
                {
                    p.append(QPoint(temp[0].toInt()/sX, temp[1].toInt()/sY));

                }

            }
            polygon.append(p);
        }

    }
    file.close();
//    qDebug()<<"x_cad0="<<x_cad0<<"y_cad0="<<y_cad0;
//    qDebug()<<"res1="<<res1<<"res2="<<res2<<"res3="<<res3;
//    int y_cad = y_cad0 * res1 * res2 * res3/4;
//    int x_cad = x_cad0 * res1 * res2 * res3/4;
//    qDebug()<<y_cad;

//    getCoordinate(s, x_cad, y_cad, gifX, gifY, res3);
    getCoordinate(s, outW, outH, gifX, gifY, res1, res3, polygon);

}


void DefectPreview::getCoordinate(static_info& s, int outW, int outH, int x, int y, float res1, float res3, const QVector<QPolygon>& poly)
{

    int X = 0, Y = 0;
    QList<QPoint> coordinates;
    for (int i=1; i<=s.defects.size(); ++i)
    {
        bool find = false;
        if(s.orient == 1)
        {

            X = (s.defects[i].cad_x*res3/4 + 125)/sX-180;
            Y = (y - ((outH*res1 - s.defects[i].cad_y)*res3/4 + 125))/sY-180;
            foreach(auto p, poly)
            {
                if(p.containsPoint(QPoint(180+X, Y+180), Qt::WindingFill))
                {
                    find = true;
                    break;
                }
                else
                    find = false;
            }


        }
        else if (s.orient == 3)
        {

            X = 180-(((outW*res1 - s.defects[i].cad_x)*res3/4 +125)/sX);
            Y = 180 - ((y - (s.defects[i].cad_y*res3/4 + 125))/sY);
            foreach(auto p, poly)
            {

                if(p.containsPoint(QPoint(180+X, Y+180), Qt::WindingFill))
                {
                    find = true;
                    break;
                }
                else
                    find = false;

            }
        }
        else
        {

            X = (s.defects[i].cad_x*res3/4 + 125)/sX;
            Y = (s.defects[i].cad_y*res3/4 + 125)/sY;
        }
        if(!find)
        {
            coordinates.append(QPoint(X ,Y));
            defectPath.append(s.defects[i].im_path);
        }


    }
    emit currentPanelChange(coordinates, s.orient, poly);
}


void DefectPreview::initTable(QTableWidget *table, int panel)
{


   table->setShowGrid(false); //设置显示格子线
   table->setStyleSheet("selection-background-color:rgb(255,209,128)");
   table->verticalHeader()->setHidden(true);
   table->setEditTriggers(QAbstractItemView::NoEditTriggers); //禁止编辑
   table->setSelectionBehavior(QAbstractItemView::SelectRows);
   table->setSelectionMode(QAbstractItemView::SingleSelection);
   table->setRowCount(5); //设置行数
   table->setColumnCount(6); //设置列数
//   table->horizontalHeader()->setDefaultSectionSize(43);  //设置默认宽度
//   table->verticalHeader()->setDefaultSectionSize(10);   //设置一行默认高度
   table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);    //x先自适应宽度
   table->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);     //然后设置要根据内容使用宽度的列
   QStringList header;
   header<<"panel"<<"VS"<<"STatus"<<"TOP"<<"status"<<"BOT";
   table->setHorizontalHeaderLabels(header);

   for (int i = 0; i<5; ++i)
   {
       for (int j=0; j<6; ++j)
       {
           QTableWidgetItem *item = new QTableWidgetItem();
           item->setText("");
           //设置表格的内容为居中对齐
           item->setTextAlignment(Qt::AlignCenter);
           table->setItem(i, j, item);
       }

   }
   updateTable(table, panel);

}


void DefectPreview::updateTable(QTableWidget *table, int panel)
{
//    if(panel >= 998) panel = 998;
//    if(panel <= 3) panel = 3;
//    rocksdb::DB *db;
//    rocksdb::Status status;
    std::string value;
    QString strKey;
    static_info si;
//    status = rocksdb::DB::OpenForReadOnly(options, "C:\\Optima\\serverd\\debug\\DB\\panels", &db);
    //填充内容
    for (int i=0; i<5; ++i)
    {
        m_statu = "";
        si.defects.clear();
        table->item(i, 0)->setText(QString::asprintf("%d",to_slave_number(panel-2+i)));
        table->item(i, 1)->setText(QString::asprintf("%d",m_panel-2+i));
        strKey = QString("%1-%2-history").arg(m_top).arg(m_panel-2+i);
        DB->Get(rocksdb::ReadOptions(), strKey.toStdString(), &value);
        if(!value.empty())
        {
            json j = json::parse(value);
            json::reverse_iterator rt = j.rbegin();
            m_statu =  QString::fromStdString((*rt).items().begin().key());
        }
        strKey = QString("%1-%2-info").arg(m_top).arg(m_panel-2+i);
        DB->Get(rocksdb::ReadOptions(), strKey.toStdString(), &value);
        if(!value.empty())
        {
            si = json::parse(value);

        }
        table->item(i, 2)->setText(m_statu);
        if(m_top == "top")
        {
            table->item(i, 5)->setText("-");
            table->item(i, 3)->setText(QString("%1").arg(si.defects.size()));
        }
        if(m_top == "bot")
        {
            table->item(i, 3)->setText("-");

            table->item(i, 5)->setText(QString("%1").arg(si.defects.size()));
        }
    }

//    delete db;
    QList<QTableWidgetItem*> items = table->findItems(ui->panelLab->text(), Qt::MatchFixedString);
    if(items.count()<=0)return;
    else
    {
        table->setCurrentItem(items[0]);
    }


}


void DefectPreview::on_forward_btn_clicked()
{
    if(ui->bmpcountLab->text() == "0")return;
    if(defectPath.size()<=0) return;
    curdfec -= 1;
    if(curdfec == 0)
    {
//        curdfec = minidfec.count();
        curdfec = defectPath.size();
    }
//    QString path = QString("%1%2.bmp").arg(minoPath).arg(curdfec);
    QString path = QString::fromStdString(defectPath.at(curdfec-1)).replace("/", "\\");
//    skipMaskIndex(-1);
    ui->minordefectLab->setPixmap(path);
    ui->curdefectLab->setText(QString::asprintf("%d",curdfec));
    emit showNextCircle(curdfec);

}

void DefectPreview::on_behind_btn_clicked()
{
    if(ui->bmpcountLab->text() == "0")return;
    if(s.defects.size()<=0) return;
    curdfec += 1;
    if(curdfec > defectPath.size())
    {
        curdfec = 1;
    }
//    QString path = QString("%1%2.bmp").arg(minoPath).arg(curdfec);
//    skipMaskIndex(1);

    QString path = QString::fromStdString(defectPath.at(curdfec-1)).replace("/", "\\");
    ui->minordefectLab->setPixmap(path);
    ui->curdefectLab->setText(QString::asprintf("%d",curdfec));
    emit showNextCircle(curdfec);
}


int DefectPreview::skipMaskIndex(int n)
{
//    for(int i=0; i<m_index.count(); ++i)
//    {
//        if(m_index.at(i) == curdfec)
//        {
//            curdfec += n;
//            if(curdfec > s.defects.size())
//            {
//                curdfec = 1;
//            }
//            if(curdfec == 0)
//            {
//                curdfec = s.defects.size();
//            }
//            skipMaskIndex(n);
//            return 0;
//        }
//        else if(i == m_index.count()-1)
//            return 0;
//        else
//            continue;
//    }
    return 0;
}


void DefectPreview::on_again_btn_clicked()
{

}

void DefectPreview::on_set_btn_clicked()
{

}

void DefectPreview::on_page_btn_clicked()
{

}

void DefectPreview::on_find_btn_clicked()
{
    QStringList strlist;
    QString temp;
    if(m_top == "top") temp = "0";
    else
        temp = "1";
    strlist<<ui->titleLab->text()<<temp<<"0";
    activateImageView(strlist);
    close();
}


void DefectPreview::on_exit_btn_clicked()
{
    close();
}

void DefectPreview::on_before_btn_clicked()
{
    curPanle -= 1;
    if(curPanle <= 2)
    {
        curPanle =3;
        return;
    }
    ui->panelLab->setText(QString::asprintf("%d",curPanle));
    m_panel -= 1;
    initWidget(m_top, m_panel);
    updateTable(ui->tableWidget, curPanle);
//    if(minidfec.count() <=0)
//        ui->defectLab->coordinates.clear();
    emit showNextCircle(1);
}

void DefectPreview::on_after_btn_clicked()
{
    curPanle += 1;
    if(curPanle >= 1001)
    {
        curPanle = 1000;
        return;
    }
    ui->panelLab->setText(QString::asprintf("%d",curPanle));
    m_panel += 1;
    initWidget(m_top, m_panel);
    updateTable(ui->tableWidget, curPanle);
//    if(minidfec.count()<=0)
//        ui->defectLab->coordinates.clear();
    emit showNextCircle(1);
}

void DefectPreview::on_up_btn_clicked()
{
    if(curPanle+1>=1001)curPanle = 1000;
    if(curPanle<=1)curPanle = 1;
    //当前点击的为top
    if(m_top == "top")
    {
        m_top = "bot";
        initWidget(m_top, m_panel);
        updateTable(ui->tableWidget, curPanle);
        return;
    }
    //当前点击的bot
    if(m_top == "bot")
    {
        m_top = "top";
        curPanle += 1;
        m_panel += 1;
        initWidget(m_top, m_panel);
        updateTable(ui->tableWidget, curPanle);
        return;
    }
}

void DefectPreview::on_refrush_btn_clicked()
{

}

void DefectPreview::on_modify_btn_clicked()
{

}


void DefectPreview::activateImageView(QStringList strlist)
{
    QProcess process;
    process.startDetached("C:/Optima/imageviewer/ImageViewer.exe", strlist);

}
