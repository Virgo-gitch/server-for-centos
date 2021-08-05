/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <mylabel.h>
#include <mylineedit.h>
#include <mytablewidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionPreferences;
    QAction *action_defect_warning;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    myTableWidget *tableWidget;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout;
    QLabel *SLab;
    MyLabel *stopLab;
    QLabel *XLab;
    myTableWidget *tableWidget_2;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *scanConLab;
    QLabel *label_2;
    QLabel *previewLab;
    QLabel *viewNumLab;
    QLabel *label_6;
    QLabel *listLab;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_7;
    QPushButton *stopBtn;
    QPushButton *pauseBtn;
    QPushButton *restartBtn;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *scanRunLab;
    QTextEdit *textEdit;
    QGroupBox *groupBox_6;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_8;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *upLab;
    QLabel *downLab;
    QGroupBox *groupBox_2;
    QLabel *batchLab;
    QLineEdit *lineEdit_2;
    QLabel *lastNumLab;
    QLabel *alarmInfLab;
    QPushButton *exit_Btn;
    QLabel *errorLab;
    myLineEdit *textEdit_2;
    QPushButton *greenBtn;
    QPushButton *redBtn;
    QLabel *serverdLab;
    QMenuBar *menuBar;
    QMenu *menufile;
    QMenu *menuFixed_Defects;
    QMenu *menuFilter;
    QMenu *menuRepair;
    QMenu *menuStatistics;
    QMenu *menuSettings_protected;
    QMenu *menuHelp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1276, 957);
        actionPreferences = new QAction(MainWindow);
        actionPreferences->setObjectName(QString::fromUtf8("actionPreferences"));
        action_defect_warning = new QAction(MainWindow);
        action_defect_warning->setObjectName(QString::fromUtf8("action_defect_warning"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tableWidget = new myTableWidget(centralWidget);
        if (tableWidget->columnCount() < 40)
            tableWidget->setColumnCount(40);
        if (tableWidget->rowCount() < 25)
            tableWidget->setRowCount(25);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setMinimumSize(QSize(0, 495));
        tableWidget->setMaximumSize(QSize(16777215, 495));
        tableWidget->setStyleSheet(QString::fromUtf8(""));
        tableWidget->setRowCount(25);
        tableWidget->setColumnCount(40);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setMinimumSectionSize(25);
        tableWidget->horizontalHeader()->setDefaultSectionSize(35);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setMinimumSectionSize(15);
        tableWidget->verticalHeader()->setDefaultSectionSize(19);

        gridLayout->addWidget(tableWidget, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(0, 50));
        groupBox_3->setMaximumSize(QSize(16777215, 50));
        horizontalLayout = new QHBoxLayout(groupBox_3);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        SLab = new QLabel(groupBox_3);
        SLab->setObjectName(QString::fromUtf8("SLab"));
        QFont font;
        font.setPointSize(12);
        SLab->setFont(font);
        SLab->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(SLab);

        stopLab = new MyLabel(groupBox_3);
        stopLab->setObjectName(QString::fromUtf8("stopLab"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(28);
        stopLab->setFont(font1);
        stopLab->setScaledContents(false);
        stopLab->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(stopLab);

        XLab = new QLabel(groupBox_3);
        XLab->setObjectName(QString::fromUtf8("XLab"));
        XLab->setFont(font);
        XLab->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(XLab);


        gridLayout->addWidget(groupBox_3, 0, 0, 1, 2);

        tableWidget_2 = new myTableWidget(centralWidget);
        if (tableWidget_2->columnCount() < 40)
            tableWidget_2->setColumnCount(40);
        if (tableWidget_2->rowCount() < 25)
            tableWidget_2->setRowCount(25);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setMinimumSize(QSize(0, 495));
        tableWidget_2->setMaximumSize(QSize(16777215, 495));
        tableWidget_2->setRowCount(25);
        tableWidget_2->setColumnCount(40);
        tableWidget_2->horizontalHeader()->setVisible(false);
        tableWidget_2->horizontalHeader()->setDefaultSectionSize(35);
        tableWidget_2->verticalHeader()->setVisible(false);
        tableWidget_2->verticalHeader()->setMinimumSectionSize(15);
        tableWidget_2->verticalHeader()->setDefaultSectionSize(19);

        gridLayout->addWidget(tableWidget_2, 1, 1, 1, 1);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setMinimumSize(QSize(0, 30));
        groupBox_4->setMaximumSize(QSize(16777215, 30));
        horizontalLayout_2 = new QHBoxLayout(groupBox_4);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        scanConLab = new QLabel(groupBox_4);
        scanConLab->setObjectName(QString::fromUtf8("scanConLab"));
        QFont font2;
        font2.setPointSize(10);
        scanConLab->setFont(font2);
        scanConLab->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(scanConLab);

        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        previewLab = new QLabel(groupBox_4);
        previewLab->setObjectName(QString::fromUtf8("previewLab"));
        previewLab->setFont(font2);
        previewLab->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(previewLab);

        viewNumLab = new QLabel(groupBox_4);
        viewNumLab->setObjectName(QString::fromUtf8("viewNumLab"));
        viewNumLab->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(viewNumLab);

        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font2);
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_6);

        listLab = new QLabel(groupBox_4);
        listLab->setObjectName(QString::fromUtf8("listLab"));
        listLab->setFont(font2);
        listLab->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(listLab);


        gridLayout->addWidget(groupBox_4, 2, 0, 1, 2);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_3 = new QHBoxLayout(groupBox);
        horizontalLayout_3->setSpacing(3);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(1, 1, 1, 1);
        groupBox_5 = new QGroupBox(groupBox);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setMinimumSize(QSize(243, 70));
        groupBox_5->setMaximumSize(QSize(243, 16777215));
        verticalLayout = new QVBoxLayout(groupBox_5);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox_7 = new QGroupBox(groupBox_5);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setMinimumSize(QSize(0, 92));
        groupBox_7->setMaximumSize(QSize(1677215, 92));
        stopBtn = new QPushButton(groupBox_7);
        stopBtn->setObjectName(QString::fromUtf8("stopBtn"));
        stopBtn->setGeometry(QRect(10, 0, 65, 65));
        stopBtn->setMinimumSize(QSize(65, 65));
        stopBtn->setMaximumSize(QSize(65, 65));
        stopBtn->setCheckable(true);
        stopBtn->setFlat(true);
        pauseBtn = new QPushButton(groupBox_7);
        pauseBtn->setObjectName(QString::fromUtf8("pauseBtn"));
        pauseBtn->setGeometry(QRect(90, 0, 65, 65));
        pauseBtn->setMinimumSize(QSize(65, 65));
        pauseBtn->setMaximumSize(QSize(65, 65));
        pauseBtn->setCheckable(true);
        pauseBtn->setChecked(false);
        pauseBtn->setFlat(true);
        restartBtn = new QPushButton(groupBox_7);
        restartBtn->setObjectName(QString::fromUtf8("restartBtn"));
        restartBtn->setGeometry(QRect(170, 0, 65, 65));
        restartBtn->setMinimumSize(QSize(65, 65));
        restartBtn->setMaximumSize(QSize(65, 65));
        restartBtn->setCheckable(true);
        restartBtn->setFlat(true);
        label_7 = new QLabel(groupBox_7);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 60, 41, 31));
        label_7->setFont(font2);
        label_7->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(groupBox_7);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(50, 60, 131, 31));
        label_9->setFont(font2);
        label_9->setAlignment(Qt::AlignCenter);
        label_10 = new QLabel(groupBox_7);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(180, 60, 61, 31));
        label_10->setFont(font2);
        label_10->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(groupBox_7);

        scanRunLab = new QLabel(groupBox_5);
        scanRunLab->setObjectName(QString::fromUtf8("scanRunLab"));
        scanRunLab->setMinimumSize(QSize(0, 30));
        scanRunLab->setMaximumSize(QSize(15555557, 30));
        scanRunLab->setFont(font2);
        scanRunLab->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(scanRunLab);

        textEdit = new QTextEdit(groupBox_5);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setMinimumSize(QSize(0, 130));
        textEdit->setMaximumSize(QSize(16777215, 130));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial"));
        font3.setPointSize(13);
        textEdit->setFont(font3);
        textEdit->setReadOnly(false);

        verticalLayout->addWidget(textEdit);

        groupBox_6 = new QGroupBox(groupBox_5);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        label = new QLabel(groupBox_6);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 10, 60, 20));
        label->setMinimumSize(QSize(60, 20));
        label->setMaximumSize(QSize(60, 20));
        label->setFont(font2);
        label->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(groupBox_6);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 40, 31, 31));
        label_3->setStyleSheet(QString::fromUtf8("image: url(:/pic/image/lose.jpg);"));
        label_4 = new QLabel(groupBox_6);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 40, 31, 31));
        label_4->setStyleSheet(QString::fromUtf8("image: url(:/pic/image/lose.jpg);"));
        label_5 = new QLabel(groupBox_6);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(60, 40, 31, 31));
        label_5->setStyleSheet(QString::fromUtf8("image: url(:/pic/image/lose.jpg);"));
        label_8 = new QLabel(groupBox_6);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(90, 40, 31, 31));
        label_8->setStyleSheet(QString::fromUtf8("image: url(:/pic/image/lose.jpg);"));
        label_11 = new QLabel(groupBox_6);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(120, 40, 31, 31));
        label_11->setStyleSheet(QString::fromUtf8("image: url(:/pic/image/lose.jpg);"));
        label_12 = new QLabel(groupBox_6);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(150, 40, 31, 31));
        label_12->setStyleSheet(QString::fromUtf8("image: url(:/pic/image/lose.jpg);"));
        label_13 = new QLabel(groupBox_6);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(180, 40, 31, 31));
        label_13->setStyleSheet(QString::fromUtf8("image: url(:/pic/image/lose.jpg);"));
        label_14 = new QLabel(groupBox_6);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(210, 40, 31, 31));
        label_14->setStyleSheet(QString::fromUtf8("image: url(:/pic/image/lose.jpg);"));

        verticalLayout->addWidget(groupBox_6);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 1);

        horizontalLayout_3->addWidget(groupBox_5);

        upLab = new QLabel(groupBox);
        upLab->setObjectName(QString::fromUtf8("upLab"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(upLab->sizePolicy().hasHeightForWidth());
        upLab->setSizePolicy(sizePolicy);
        upLab->setMinimumSize(QSize(380, 333));
        upLab->setMaximumSize(QSize(380, 333));
        QFont font4;
        font4.setPointSize(24);
        font4.setBold(true);
        font4.setWeight(75);
        upLab->setFont(font4);
        upLab->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        upLab->setScaledContents(false);
        upLab->setAlignment(Qt::AlignCenter);
        upLab->setWordWrap(true);

        horizontalLayout_3->addWidget(upLab);

        downLab = new QLabel(groupBox);
        downLab->setObjectName(QString::fromUtf8("downLab"));
        sizePolicy.setHeightForWidth(downLab->sizePolicy().hasHeightForWidth());
        downLab->setSizePolicy(sizePolicy);
        downLab->setMinimumSize(QSize(380, 333));
        downLab->setMaximumSize(QSize(380, 333));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Arial"));
        font5.setPointSize(24);
        downLab->setFont(font5);
        downLab->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        downLab->setScaledContents(false);
        downLab->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(downLab);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(260, 0));
        groupBox_2->setMaximumSize(QSize(260, 16777215));
        groupBox_2->setFont(font2);
        batchLab = new QLabel(groupBox_2);
        batchLab->setObjectName(QString::fromUtf8("batchLab"));
        batchLab->setGeometry(QRect(2, 51, 57, 31));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Arial"));
        font6.setPointSize(14);
        batchLab->setFont(font6);
        batchLab->setAlignment(Qt::AlignCenter);
        lineEdit_2 = new QLineEdit(groupBox_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(65, 55, 131, 25));
        lineEdit_2->setMinimumSize(QSize(0, 25));
        lineEdit_2->setFont(font6);
        lineEdit_2->setAlignment(Qt::AlignCenter);
        lastNumLab = new QLabel(groupBox_2);
        lastNumLab->setObjectName(QString::fromUtf8("lastNumLab"));
        lastNumLab->setGeometry(QRect(16, 90, 201, 21));
        QFont font7;
        font7.setPointSize(11);
        lastNumLab->setFont(font7);
        lastNumLab->setAlignment(Qt::AlignCenter);
        alarmInfLab = new QLabel(groupBox_2);
        alarmInfLab->setObjectName(QString::fromUtf8("alarmInfLab"));
        alarmInfLab->setGeometry(QRect(10, 249, 201, 21));
        QFont font8;
        font8.setFamily(QString::fromUtf8("Arial"));
        font8.setPointSize(11);
        alarmInfLab->setFont(font8);
        alarmInfLab->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        exit_Btn = new QPushButton(groupBox_2);
        exit_Btn->setObjectName(QString::fromUtf8("exit_Btn"));
        exit_Btn->setGeometry(QRect(200, 270, 41, 41));
        exit_Btn->setStyleSheet(QString::fromUtf8("border-image: url(:/pic/image/exit.png);"));
        exit_Btn->setIconSize(QSize(33, 40));
        errorLab = new QLabel(groupBox_2);
        errorLab->setObjectName(QString::fromUtf8("errorLab"));
        errorLab->setGeometry(QRect(30, 270, 151, 41));
        errorLab->setFont(font2);
        errorLab->setFrameShape(QFrame::Panel);
        errorLab->setFrameShadow(QFrame::Raised);
        textEdit_2 = new myLineEdit(groupBox_2);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(10, 120, 241, 121));
        textEdit_2->setFont(font3);
        textEdit_2->setReadOnly(false);
        greenBtn = new QPushButton(groupBox_2);
        greenBtn->setObjectName(QString::fromUtf8("greenBtn"));
        greenBtn->setGeometry(QRect(200, 51, 33, 33));
        greenBtn->setMinimumSize(QSize(33, 33));
        greenBtn->setMaximumSize(QSize(33, 33));
        greenBtn->setStyleSheet(QString::fromUtf8("border-image: url(:/pic/image/green.png);"));
        redBtn = new QPushButton(groupBox_2);
        redBtn->setObjectName(QString::fromUtf8("redBtn"));
        redBtn->setGeometry(QRect(230, 51, 33, 33));
        redBtn->setMinimumSize(QSize(33, 33));
        redBtn->setMaximumSize(QSize(33, 33));
        redBtn->setStyleSheet(QString::fromUtf8("border-image: url(:/pic/image/red.png);"));
        redBtn->setCheckable(true);
        serverdLab = new QLabel(groupBox_2);
        serverdLab->setObjectName(QString::fromUtf8("serverdLab"));
        serverdLab->setGeometry(QRect(10, 10, 241, 31));
        serverdLab->setFont(font6);
        serverdLab->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(groupBox_2);


        gridLayout->addWidget(groupBox, 3, 0, 1, 2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1276, 23));
        menufile = new QMenu(menuBar);
        menufile->setObjectName(QString::fromUtf8("menufile"));
        menuFixed_Defects = new QMenu(menuBar);
        menuFixed_Defects->setObjectName(QString::fromUtf8("menuFixed_Defects"));
        menuFilter = new QMenu(menuBar);
        menuFilter->setObjectName(QString::fromUtf8("menuFilter"));
        menuRepair = new QMenu(menuBar);
        menuRepair->setObjectName(QString::fromUtf8("menuRepair"));
        menuStatistics = new QMenu(menuBar);
        menuStatistics->setObjectName(QString::fromUtf8("menuStatistics"));
        menuSettings_protected = new QMenu(menuBar);
        menuSettings_protected->setObjectName(QString::fromUtf8("menuSettings_protected"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menufile->menuAction());
        menuBar->addAction(menuFixed_Defects->menuAction());
        menuBar->addAction(menuFilter->menuAction());
        menuBar->addAction(menuRepair->menuAction());
        menuBar->addAction(menuStatistics->menuAction());
        menuBar->addAction(menuSettings_protected->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFixed_Defects->addAction(action_defect_warning);
        menuSettings_protected->addAction(actionPreferences);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Optima Server", nullptr));
        actionPreferences->setText(QCoreApplication::translate("MainWindow", "Preferences", nullptr));
#if QT_CONFIG(tooltip)
        actionPreferences->setToolTip(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\347\274\272\351\231\267\344\270\252\346\225\260", nullptr));
#endif // QT_CONFIG(tooltip)
        action_defect_warning->setText(QCoreApplication::translate("MainWindow", "Warning", nullptr));
#if QT_CONFIG(tooltip)
        action_defect_warning->setToolTip(QCoreApplication::translate("MainWindow", "\351\207\215\345\244\215\347\274\272\351\231\267\344\275\215\347\275\256\350\255\246\345\221\212", nullptr));
#endif // QT_CONFIG(tooltip)
        groupBox_3->setTitle(QString());
        SLab->setText(QCoreApplication::translate("MainWindow", "\344\270\212\351\235\242", nullptr));
        stopLab->setText(QCoreApplication::translate("MainWindow", "\346\255\243\345\234\250\346\211\253\346\217\217", nullptr));
        XLab->setText(QCoreApplication::translate("MainWindow", "\344\270\213\351\235\242", nullptr));
        groupBox_4->setTitle(QString());
        scanConLab->setText(QCoreApplication::translate("MainWindow", "\346\211\253\346\217\217\346\216\247\345\210\266:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\344\270\212\351\235\242", nullptr));
        previewLab->setText(QCoreApplication::translate("MainWindow", "\351\242\204\350\247\210:", nullptr));
        viewNumLab->setText(QCoreApplication::translate("MainWindow", "\342\200\224\342\200\224", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\344\270\213\351\235\242", nullptr));
        listLab->setText(QCoreApplication::translate("MainWindow", "\346\226\231\345\217\267\346\270\205\345\215\225:", nullptr));
        groupBox->setTitle(QString());
        groupBox_5->setTitle(QString());
        groupBox_7->setTitle(QString());
        stopBtn->setText(QString());
        pauseBtn->setText(QString());
        restartBtn->setText(QString());
        label_7->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\346\232\202\345\201\234\346\211\253\346\217\217\344\270\213\344\270\200\345\274\240", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\351\207\215\346\226\260\346\211\253\346\217\217", nullptr));
        scanRunLab->setText(QCoreApplication::translate("MainWindow", "\346\255\243\345\234\250\346\211\253\346\217\217:", nullptr));
        groupBox_6->setTitle(QString());
        label->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245\347\212\266\346\200\201:", nullptr));
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        label_8->setText(QString());
        label_11->setText(QString());
        upLab->setText(QString());
        downLab->setText(QString());
        groupBox_2->setTitle(QString());
        batchLab->setText(QCoreApplication::translate("MainWindow", "\346\211\271\351\207\217\345\217\267", nullptr));
        lastNumLab->setText(QCoreApplication::translate("MainWindow", "\344\270\212\344\270\200\344\270\252\346\226\231\345\217\267", nullptr));
        alarmInfLab->setText(QCoreApplication::translate("MainWindow", "\346\212\245\350\255\246\344\277\241\346\201\257", nullptr));
        exit_Btn->setText(QString());
        errorLab->setText(QCoreApplication::translate("MainWindow", "error:", nullptr));
        greenBtn->setText(QString());
        redBtn->setText(QString());
        serverdLab->setText(QString());
        menufile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuFixed_Defects->setTitle(QCoreApplication::translate("MainWindow", "Fixed defects", nullptr));
        menuFilter->setTitle(QCoreApplication::translate("MainWindow", "Filter", nullptr));
        menuRepair->setTitle(QCoreApplication::translate("MainWindow", "Repair", nullptr));
        menuStatistics->setTitle(QCoreApplication::translate("MainWindow", "Statistics", nullptr));
        menuSettings_protected->setTitle(QCoreApplication::translate("MainWindow", "Settings(protected)", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
