#include "jobdlg.h"
#include "ui_jobdlg.h"
#include <QDebug>


JobDlg::JobDlg(std::string path, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JobDlg)
{
    ui->setupUi(this);
    //设置对话框除掉？按钮
    Qt::WindowFlags flags= Qt::Dialog;
    flags |= Qt::WindowCloseButtonHint;
    setWindowFlags(flags);
    //设置窗口标题
    this->setWindowTitle(QString::fromStdString(path));
    jobPath = QString::fromStdString(path);

}



JobDlg::~JobDlg()
{
    delete ui;
    delete oldItem;
    oldItem = nullptr;
}

void JobDlg::initTable(QTableWidget *table, int row, int col, QStringList strList)
{
    //设置单选
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    //设置选中时默认选择一行
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    //禁止编辑
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //设置table为多行多列
    table->setRowCount(row);
    table->setColumnCount(col);
    table->setColumnWidth(0,10);
    table->verticalHeader()->setDefaultSectionSize(10);   //设置一行默认高度
    //设置水平表头的标题
    table->setHorizontalHeaderLabels(strList);
    //设置垂直表头不可见
    table->verticalHeader()->setHidden(true);

    for (int crowCount = 0; crowCount < row; ++crowCount)
    {
        //插入数据
        QTableWidgetItem *check=new QTableWidgetItem();
        check->setCheckState(Qt::Unchecked);  //是否设置选中框 
        table->insertRow(crowCount);
        if(table == ui->tableWidget_2)
            table->setItem(crowCount,0,check); //插入复选框
        for (int j=1;j<col ; ++j)
        {
            table->setItem(crowCount,j,new QTableWidgetItem(""));
        }
    }

    //设置样式表
    QString qssTV = "QTableWidget::item:hover{background-color:rgb(92,188,227)}"
                       "QTableWidget::item:selected{background-color:#1B89A1}"
                       "QHeaderView::section,QTableCornerButton:section{ \
               padding:3px; margin:0px; color:#DCDCDC;  border:1px solid #242424; \
       border-left-width:0px; border-right-width:1px; border-top-width:0px; border-bottom-width:1px; \
   background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #646464,stop:1 #525252); }"
   "QTableWidget{background-color:white;border:none;color:#000000}";
    table->setStyleSheet(qssTV);

}


void JobDlg::getInitInfo(QString info)
{
    startItem = info.split(QRegExp("\n"));
    rowCount = getAllFolderName(jobPath).count() + startItem.count();
    colCount = 3;
    first = false;
    oldItem = nullptr;
    QStringList list, list1;
    list<<" "<<"Jobs";
    list1<<" "<<"Layers"<<"Date";
    initTable(ui->tableWidget, rowCount, colCount-1, list);
    initTable(ui->tableWidget_2, rowCount, colCount, list1);
    ui->tableWidget->setColumnWidth(1, 250);
    ui->tableWidget_2->setColumnWidth(1, 100);
    ui->tableWidget_2->setColumnWidth(2, 200);
    for (int i=0;i<rowCount ; ++i)
    {
        for (int j=0;j<colCount ; ++j)
        {
            ui->tableWidget_2->item(i,j)->setFlags(ui->tableWidget_2->item(i,j)->flags() & ~Qt::ItemIsEnabled);
        }
    }
    ui->label->setPixmap(QPixmap(":/pic/image/01.png"));
    ui->label->setScaledContents(true);
    QFont font = ui->tableWidget->horizontalHeaderItem(1)->font();
    font.setBold(true);
    font.setPixelSize(15);
    ui->tableWidget_2->horizontalHeaderItem(1)->setFont(font);
    ui->tableWidget_2->horizontalHeaderItem(2)->setFont(font);
    ui->tableWidget->horizontalHeaderItem(1)->setFont(font);

    table = new QTableWidget(this);
    connect(table, &QTableWidget::itemClicked, this, &JobDlg::showSubItems);
    table->resize(300, 800);
    table->move(10, 50);
    table->setFont(QFont("song", 14));
    table->verticalHeader()->setHidden(true);
    table->horizontalHeader()->setHidden(true);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->horizontalHeader()->setDefaultSectionSize(290);
    table->setShowGrid(false);
    table->setColumnCount(1);
    table->setRowCount(rowCount);
    for (int i=0; i<rowCount; ++i)
    {
        table->setItem(i, 0, new QTableWidgetItem());
    }
    table->setHidden(true);




    int num = 0;
    QString path;
//    isFirst = true;
    if(startItem.count()>=1 && startItem[0] != "")
    {
        for (int i=0; i<startItem.count(); ++i)
        {
            path = jobPath + "/" + startItem[i];

            QStringList text = startItem[i].split(QRegExp("/"));
            int n = getRow(path, jobPath + "/" + text[0]);
            if(ui->tableWidget->findItems(text[0], Qt::MatchFixedString).count() != 0)
            {
                int row = num - ui->tableWidget->findItems(text[0], Qt::MatchFixedString)[0]->row();
                if(n != -1)
                    ui->tableWidget_2->item(n, 0)->setData(num+1000-row, QVariant(true));
                continue;
            }
            ui->tableWidget->item(num, 1)->setText(text[0]);
            ui->tableWidget->item(num, 1)->setBackground(Qt::yellow);
            if(n != -1)
                ui->tableWidget_2->item(n, 0)->setData(num+1000, QVariant(true));
            num += 1;
        }
    }

    QStringList result;
    GetAllFormatFilePath(jobPath, result, "cadInfo.txt");

    for (int i=0; i<result.count(); ++i)
    {
        QStringList jobs = result[i].split(QRegExp("/"));
        //消除重复显示的项
        if(ui->tableWidget->findItems(jobs[2], Qt::MatchFixedString).count() != 0) continue;
        ui->tableWidget->item(num, 1)->setText(jobs[2]);
        ui->tableWidget->item(num, 1)->setData(num+1000, QVariant(false));
        num += 1;
    }
    for (int i=num;i<rowCount ; ++i)
    {
        ui->tableWidget->item(i,1)->setFlags(ui->tableWidget->item(i,1)->flags() & ~Qt::ItemIsEnabled);
    }
    ui->tableWidget->item(0,1)->setSelected(true);

    on_tableWidget_currentItemChanged(ui->tableWidget->item(0, 1), nullptr);
    on_tableWidget_itemClicked(ui->tableWidget->item(0, 1));
}




int JobDlg::getRow(QString str, QString str1)
{
    QStringList temp;
    GetAllFormatFilePath(str1, temp, "cadInfo.txt");
    for (int i=0;i<temp.count() ; ++i)
    {
        if(temp[i].split(QRegExp("/cadInfo.txt"))[0] == str)
        {     
            return i;
        }

    }
    return -1;

}

//获取table1中的当前有内容的行数
int JobDlg::getCurrentRows()
{
    int num = 0;
    for (int i=0; i<ui->tableWidget->rowCount(); ++i)
    {
        if(ui->tableWidget->item(i, 1)->text().isEmpty())
            return num;
        num += 1;
    }
    return num;
}

void JobDlg::on_searchBtn_clicked()
{
//    table->setHidden(true);
//    ui->lineEdit->clear();
//    //清空表格中选中的items
//    ui->tableWidget->clearSelection();
//    //获取到编辑框中的内容
//    if(table->selectedItems().count()<=0) return;
//    QString str = table->selectedItems()[0]->text();
//    if(str.isEmpty())
//    {
//        return;
//    }
//    //搜索表格中的内容并高亮显示
//    else
//    {
//        QList<QTableWidgetItem*> items = ui->tableWidget->findItems(str, Qt::MatchFixedString);
//        if(items.count()<=0)return;
//        auto item = items[0];
//        on_tableWidget_currentItemChanged(item, oldItem);
//        on_tableWidget_itemClicked(item);
//        item->setSelected(true);
//    }

}


void JobDlg::showSubItems(QTableWidgetItem *item)
{
    if(!item) return;
    if(item->text().isEmpty()) return;
    QList<QTableWidgetItem*> items = ui->tableWidget->findItems(item->text(), Qt::MatchFixedString);
    if(items.count()<=0)return;
    auto subItem = items[0];
    on_tableWidget_currentItemChanged(subItem, oldItem);
    on_tableWidget_itemClicked(subItem);


}

//获取指定文件夹下的所有文件夹
QStringList JobDlg::getAllFolderName(QString path)
{
    QDir dir(path);
    QStringList mFloderNames;
    if (!dir.exists()) mFloderNames = QStringList("");
    dir.setFilter(QDir::Dirs | QDir::NoDotAndDotDot);
    dir.setSorting(QDir::Name);
    mFloderNames = dir.entryList();
//    for (int i = 0; i < mImgNames.size(); ++i)
//    {
//        qDebug() << "entryList: " << i << "-" << mImgNames[i];
//    }
    return mFloderNames;
}

//获取指定文件夹下的所有文件
QString JobDlg::getAllFileName(QString path)
{
    QDir dir(path);
    QStringList mFileNames;
    if (!dir.exists()) mFileNames = QStringList("");
    dir.setFilter(QDir::Files);
    dir.setSorting(QDir::Name);
    dir.setNameFilters(QString("*.jpg;*.txt;*.py").split(";"));
    mFileNames = dir.entryList();
//    for (int i = 0; i < mFileNames.size(); ++i)
//    {
//        qDebug() << "entryList: " << i << "-" << path + "/" +mFileNames[i];
//    }
    return 0;
}

void JobDlg::clearItemText(int n)
{
    if(n==0)
    {
        return;
    }
    for (int i=0;i<n ; ++i)
    {

        for (int j=1;j<colCount ; ++j)
        {
            ui->tableWidget_2->item(i,j)->setText(NULL);
        }
        ui->tableWidget_2->item(i, 0)->setCheckState(Qt::Unchecked);

    }

}


//取消按钮的实现
void JobDlg::on_pushButton_clicked()
{
    close();
}

//确定按钮的实现
void JobDlg::on_pushButton_2_clicked()
{
    QStringList res;
    QTableWidgetItem *item = ui->tableWidget->currentItem();
    on_tableWidget_currentItemChanged(ui->tableWidget->item(0, 1), item);
    int rows = getCurrentRows();
    //获取结束后所有被勾选的item
    readLayerStatu(res, rows);
    //获得所有修改的item
//    res1 = modifyItem(startItem, res);
    emit updateBank(res);
    close();
}


void JobDlg::on_tableWidget_itemClicked(QTableWidgetItem *item)
{

    if(!first)
        on_tableWidget_currentItemChanged(item, oldItem);
    first = false;

}


void JobDlg::on_tableWidget_currentItemChanged(QTableWidgetItem *current, QTableWidgetItem *previous)
{
    first = true;
    previous = oldItem;
//    qDebug()<<"current"<<current->text()<<current<<"previous"<<previous;
    oldItem = current;
    if(current == nullptr) return;
    if(current->text().isEmpty()) return;

    QString path;
    bool flag = false;
    if(previous != nullptr)
    {
        if(previous->data(previous->row()+1000) == true)
            flag = true;
        path = jobPath + "/" + previous->text();
        QStringList res;
        GetAllFormatFilePath(path, res, "cadInfo.txt");
        QVector<int> temp;
        for (int i=0; i<res.count(); ++i)
        {
            ui->tableWidget_2->item(i, 0)->setFlags(ui->tableWidget_2->item(i,0)->flags() & ~Qt::ItemIsEnabled);
            if(ui->tableWidget_2->item(i,0)->checkState() == Qt::Checked)
            {
                ui->tableWidget_2->item(i,0)->setData(previous->row()+1000, QVariant(true));
                flag = true;
            }
            else
            {
                ui->tableWidget_2->item(i,0)->setData(previous->row()+1000, QVariant(false));
            }


        }
        if(flag)
            previous->setBackground(Qt::yellow);
        else
            previous->setBackground(Qt::white);
        clearItemText(res.count());


    }

    path = jobPath + "/" + current->text();
    QStringList res1;
    GetAllFormatFilePath(path, res1, "cadInfo.txt");
    for (int i=0; i<res1.count(); ++i)
    {
        QStringList layers = res1[i].split(QRegExp("/"));
        //消除重复显示的项
        if(ui->tableWidget_2->findItems(layers[layers.count()-2], Qt::MatchFixedString).count() != 0) continue;
        ui->tableWidget_2->item(i, 1)->setText(layers[layers.count()-2]);
        ui->tableWidget_2->item(i, 2)->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss"));
        ui->tableWidget_2->item(i, 0)->setFlags(Qt::ItemIsEnabled | Qt::ItemIsUserCheckable);
    }
    //
    if(current->background().color() == Qt::yellow)
    {
        bool flag = false;
        for (int i=0; i<res1.count(); ++i)
        {
            if(ui->tableWidget_2->item(i, 0)->data(current->row()+1000) == true)
            {
                ui->tableWidget_2->item(i, 0)->setCheckState(Qt::Checked);
                flag = true;
                continue;
            }
        }
        if(flag == false)
            current->setData(current->row()+1000,QVariant(flag));

    }


}


QStringList JobDlg::modifyItem(QStringList start, QStringList end)
{
    QStringList temp;
    QString path = jobPath + "/";
    if(start[0] == "")
        return end;

    for (int i=0; i<start.count(); ++i)
    {
        start[i] = path + start[i];
        for (int j=0; j<end.count(); ++j)
        {
            if(start[i] == end[j])
            {
                temp.append(end[j]);
            }

        }
    }

    foreach(QString str, temp)
    {
        start.removeOne(str);
        end.removeOne(str);
    }
    start = start + end;
    return start;
}


void JobDlg::readLayerStatu(QStringList &list, int n)
{

    QTableWidgetItem *item;

    for (int i=0; i<=n; ++i)
    {
        item = ui->tableWidget->item(i, 1);
        if(item->text() == "") return;
        QString path = jobPath + "/" + item->text();
        QStringList res;
        GetAllFormatFilePath(path, res, "cadInfo.txt");
        for (int j=0; j<res.count(); ++j)
        {

            if(ui->tableWidget_2->item(j,0)->data(item->row()+1000) == true)
            {
//                QStringList temp = res[j].split(QRegExp("/"));
//                list.append(temp[2] + "/" + temp[3]);
                QStringList temp = res[j].split(QRegExp("/cadInfo.txt"));
                list.append(temp[0]);

            }
        }


    }

}


void JobDlg::on_lineEdit_textEdited(const QString &arg1)
{
    for (int i=0; i<rowCount; ++i)
    {
        table->item(i, 0)->setText("");
    }
    if(arg1.isEmpty())
    {
        on_tableWidget_itemClicked(ui->tableWidget->item(0, 1));
        table->hide();
        return;
    }
    QList<QTableWidgetItem*> items = ui->tableWidget->findItems(arg1, Qt::MatchRegularExpression);
    if(items.count()<=0) return;
    table->setHidden(false);
    for(int i=0; i<items.count(); ++i)
    {
        table->item(i, 0)->setText(items[i]->text());
    }

}

void JobDlg::on_tableWidget_2_itemClicked(QTableWidgetItem *item)
{
    if(item)
    {
        if(item->text().isEmpty())return;
        Qt::CheckState statu = ui->tableWidget_2->item(item->row(),0)->checkState();
        if(statu == Qt::Checked)
            statu = Qt::Unchecked;
        else
            statu = Qt::Checked;
        ui->tableWidget_2->item(item->row(),0)->setCheckState(statu);
    }
}
