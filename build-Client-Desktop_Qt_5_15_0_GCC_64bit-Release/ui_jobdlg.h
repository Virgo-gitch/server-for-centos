/********************************************************************************
** Form generated from reading UI file 'jobdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOBDLG_H
#define UI_JOBDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_JobDlg
{
public:
    QGridLayout *gridLayout;
    QTableWidget *tableWidget;
    QLineEdit *lineEdit;
    QTableWidget *tableWidget_2;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *searchBtn;
    QLabel *label;

    void setupUi(QDialog *JobDlg)
    {
        if (JobDlg->objectName().isEmpty())
            JobDlg->setObjectName(QString::fromUtf8("JobDlg"));
        JobDlg->resize(671, 610);
        gridLayout = new QGridLayout(JobDlg);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableWidget = new QTableWidget(JobDlg);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setMinimumSize(QSize(300, 0));
        tableWidget->setMaximumSize(QSize(300, 16777215));
        QFont font;
        font.setPointSize(12);
        tableWidget->setFont(font);

        gridLayout->addWidget(tableWidget, 1, 0, 3, 2);

        lineEdit = new QLineEdit(JobDlg);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 30));
        lineEdit->setMaximumSize(QSize(16777215, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(14);
        lineEdit->setFont(font1);

        gridLayout->addWidget(lineEdit, 0, 1, 1, 2);

        tableWidget_2 = new QTableWidget(JobDlg);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setMinimumSize(QSize(260, 0));
        tableWidget_2->setFont(font);
        tableWidget_2->setTextElideMode(Qt::ElideLeft);
        tableWidget_2->verticalHeader()->setProperty("showSortIndicator", QVariant(false));

        gridLayout->addWidget(tableWidget_2, 1, 2, 1, 1);

        frame = new QFrame(JobDlg);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(0, 70));
        frame->setMaximumSize(QSize(16777215, 70));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(80, 30));
        pushButton->setMaximumSize(QSize(80, 30));

        horizontalLayout->addWidget(pushButton);

        pushButton_3 = new QPushButton(frame);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(80, 30));
        pushButton_3->setMaximumSize(QSize(80, 30));

        horizontalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(80, 30));
        pushButton_2->setMaximumSize(QSize(80, 30));

        horizontalLayout->addWidget(pushButton_2);


        gridLayout->addWidget(frame, 3, 2, 1, 1);

        searchBtn = new QPushButton(JobDlg);
        searchBtn->setObjectName(QString::fromUtf8("searchBtn"));
        searchBtn->setMinimumSize(QSize(35, 35));
        searchBtn->setMaximumSize(QSize(35, 35));

        gridLayout->addWidget(searchBtn, 0, 0, 1, 1);

        label = new QLabel(JobDlg);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 200));
        label->setScaledContents(false);

        gridLayout->addWidget(label, 2, 2, 1, 1);


        retranslateUi(JobDlg);

        QMetaObject::connectSlotsByName(JobDlg);
    } // setupUi

    void retranslateUi(QDialog *JobDlg)
    {
        JobDlg->setWindowTitle(QCoreApplication::translate("JobDlg", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("JobDlg", "\344\277\256\346\224\271", nullptr));
        pushButton_3->setText(QCoreApplication::translate("JobDlg", "\345\210\240\351\231\244", nullptr));
        pushButton_2->setText(QCoreApplication::translate("JobDlg", "\345\256\214\346\210\220", nullptr));
        searchBtn->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class JobDlg: public Ui_JobDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOBDLG_H
