#include "settingwidget.h"
#include "ui_settingwidget.h"
#include <QDebug>

settingWidget::settingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::settingWidget)
{
    ui->setupUi(this);
    this->setFixedSize(610, 600);
    this->setWindowTitle("Settings");
    int defeSize = initDefectNum();
    if(defeSize < 0)
    {
        defeSize = 20;
        qDebug()<<"Read defect num fail";
    }
    ui->spinBox->setValue(defeSize);
    oldValue = ui->spinBox->value();
    initTable();
//    ui->panel_spin->hide();
//    ui->defect_spin->hide();
//    ui->checkBox_2->hide();
//    ui->label_4->hide();
//    ui->label_5->hide();


}

settingWidget::~settingWidget()
{
    delete ui;
}


void settingWidget::init_Ui(const parse_force_mode& mode, const warning_generator& wg)
{
   ui->top_text->append(QString::fromStdString(mode.ti.top_job));
   ui->bot_text->append(QString::fromStdString(mode.bi.bot_job));
   ui->top_spin->setValue(mode.ti.top_orient);
   ui->bot_spin->setValue(mode.bi.bot_orient);
   ui->checkBox->setChecked(mode.enabled);
   ui->checkBox_2->setChecked(wg.enable);
   ui->panel_spin->setValue(wg.last_n_panels);
   ui->defect_spin->setValue(wg.number_defects_minimum);

   ui->top_text->setReadOnly(!mode.enabled);
   ui->bot_text->setReadOnly(!mode.enabled);
   ui->panel_spin->setEnabled(wg.enable);
   ui->defect_spin->setEnabled(wg.enable);
   setControlsEnable(mode.enabled);
}

void settingWidget::initTable()
{
    QString filename = "C:/jobs/";
    QStringList res;
    GetFileName(filename, res, "cadInfo.txt");


    table = new QTableWidget(this);
    connect(table, &QTableWidget::itemClicked, this, &settingWidget::tableItem_click);
    table->resize(240, 200);
    table->setFont(QFont("song", 12));
    table->verticalHeader()->setHidden(true);
    table->horizontalHeader()->setHidden(true);
    ui->tableWidget->verticalHeader()->setHidden(true);
    ui->tableWidget->horizontalHeader()->setHidden(true);
    ui->tableWidget_2->verticalHeader()->setHidden(true);
    ui->tableWidget_2->horizontalHeader()->setHidden(true);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->horizontalHeader()->setDefaultSectionSize(290);
    ui->tableWidget->horizontalHeader()->setDefaultSectionSize(260);
    ui->tableWidget_2->horizontalHeader()->setDefaultSectionSize(260);
    table->setShowGrid(false);
    ui->tableWidget->setShowGrid(false);
    ui->tableWidget_2->setShowGrid(false);
    table->setColumnCount(1);
    ui->tableWidget->setColumnCount(1);
    ui->tableWidget_2->setColumnCount(1);
    table->setRowCount(res.count());
    ui->tableWidget->setRowCount(res.count());
    ui->tableWidget_2->setRowCount(res.count());
    for (int i=0; i<res.count(); ++i)
    {
        QStringList jobs = res[i].split(QRegExp("/"));
        if(jobs.count()<3)continue;
        result.append(jobs);
    }

    for (int i=0;i<result.count(); ++i)
    {
        table->setItem(i, 0, new QTableWidgetItem());
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(result[i][2]+"/"+result[i][3]));
        ui->tableWidget_2->setItem(i, 0, new QTableWidgetItem(result[i][2]+"/"+result[i][3]));
    }
    table->setHidden(true);

}


void settingWidget::on_cancelBtn_clicked()
{
    ui->spinBox->setValue(oldValue);
    close();
}

void settingWidget::on_saveBtn_clicked()
{

    emit defectSizeChange(ui->spinBox->value());
    if(ui->checkBox->isChecked())
    {
        force_mode forceMode;
        forceMode.top_job = ui->top_text->toPlainText().toStdString();
        forceMode.bot_job = ui->bot_text->toPlainText().toStdString();
        forceMode.top_orient = ui->top_spin->value();
        forceMode.bot_orient = ui->bot_spin->value();
        forceMode.enable = true;
        emit send_message(force_mode_to_json(forceMode), "update_force_mode", true);
//        QStringList list;
//        list.append(ui->top_text->toPlainText());
//        list.append(ui->bot_text->toPlainText());
//        emit update_bank(list);

    }
    else
       emit send_message(force_mode_to_json(false), "update_force_mode", false);

    if(ui->checkBox_2->isChecked())
    {
        warning_generator wg;
        wg.enable = true;
        wg.last_n_panels = ui->panel_spin->value();
        wg.number_defects_minimum = ui->defect_spin->value();
        emit send_warning_generator_msg(warning_generator_to_json(wg), "update_warning_generator_config");
    }
    else
        emit send_warning_generator_msg(warning_generator_to_json(false), "update_warning_generator_config");
    close();
}

void settingWidget::on_checkBox_stateChanged(int arg1)
{
    //Force Mode 勾选
    if(arg1 != 0)
    {
       setControlsEnable(true);
    }
    //Force Mode 没有勾选
    else
    {
        setControlsEnable(false);
    }
}


void settingWidget::setControlsEnable(bool flag)
{
    ui->top_text->setEnabled(flag);
    ui->bot_text->setEnabled(flag);
    ui->top_spin->setEnabled(flag);
    ui->bot_spin->setEnabled(flag);
    ui->lineEdit->setEnabled(flag);
    ui->lineEdit_2->setEnabled(flag);
}

void settingWidget::on_top_text_textChanged()
{
//    QPoint pos = QWidget::mapFromGlobal(ui->top_text->cursor().pos());
//    table->move(100, 55);
//    table->setHidden(false);
    return;
}

void settingWidget::on_bot_text_textChanged()
{
//    QPoint pos = QWidget::mapFromGlobal(ui->bot_text->cursor().pos());
//    table->move(200, 55);
//    table->setHidden(false);
    return;
}


//top搜素
void settingWidget::on_lineEdit_textEdited(const QString &arg1)
{
    table->move(10, 80);
    for (int i=0; i<result.count(); ++i)
    {
        table->item(i, 0)->setText("");
    }
    if(arg1.isEmpty())
    {

        table->hide();
        return;
    }
    table->setHidden(false);
    int num = 0;
    for(int i=0; i<result.count(); ++i)
    {
        if(result[i][2].contains(arg1))
        {
            table->item(num, 0)->setText(result[i][2]+"/"+result[i][3]);
            num += 1;
        }

    }
}

//bot搜素
void settingWidget::on_lineEdit_2_textEdited(const QString &arg1)
{
    table->move(275, 80);

    for (int i=0; i<result.count(); ++i)
    {
        table->item(i, 0)->setText("");
    }
    if(arg1.isEmpty())
    {
        table->hide();
        return;
    }
    table->setHidden(false);
    int num = 0;
    for(int i=0; i<result.count(); ++i)
    {
        if(result[i][2].contains(arg1))
        {
            table->item(num, 0)->setText(result[i][2]+"/"+result[i][3]);
            num += 1;
        }

    }
}


void settingWidget::tableItem_click(QTableWidgetItem *item)
{
    if(table->pos() == QPoint(10, 80))
    {
        ui->lineEdit->clear();
        ui->top_text->clear();
        ui->top_text->append("C:/jobs/" + item->text());
    }

    else
    {
        ui->lineEdit_2->clear();
        ui->bot_text->clear();
        ui->bot_text->append("C:/jobs/" + item->text());
    }
    table->setHidden(true);
}



void settingWidget::on_checkBox_2_toggled(bool checked)
{
    ui->panel_spin->setEnabled(checked);
    ui->defect_spin->setEnabled(checked);
}
