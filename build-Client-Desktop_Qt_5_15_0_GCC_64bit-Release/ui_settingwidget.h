/********************************************************************************
** Form generated from reading UI file 'settingwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGWIDGET_H
#define UI_SETTINGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include <mylineedit1.h>

QT_BEGIN_NAMESPACE

class Ui_settingWidget
{
public:
    QPushButton *cancelBtn;
    QPushButton *saveBtn;
    QSpinBox *spinBox;
    QLabel *label;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QTextEdit *bot_text;
    QLabel *label_2;
    QSpinBox *top_spin;
    QSpinBox *bot_spin;
    myLineEdit1 *lineEdit;
    myLineEdit1 *lineEdit_2;
    QCheckBox *checkBox;
    QTextEdit *top_text;
    QLabel *label_3;
    QTableWidget *tableWidget;
    QTableWidget *tableWidget_2;
    QCheckBox *checkBox_2;
    QLabel *label_4;
    QSpinBox *panel_spin;
    QLabel *label_5;
    QSpinBox *defect_spin;

    void setupUi(QWidget *settingWidget)
    {
        if (settingWidget->objectName().isEmpty())
            settingWidget->setObjectName(QString::fromUtf8("settingWidget"));
        settingWidget->resize(610, 597);
        cancelBtn = new QPushButton(settingWidget);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
        cancelBtn->setGeometry(QRect(110, 530, 121, 51));
        cancelBtn->setMaximumSize(QSize(1677215, 16777215));
        saveBtn = new QPushButton(settingWidget);
        saveBtn->setObjectName(QString::fromUtf8("saveBtn"));
        saveBtn->setGeometry(QRect(400, 530, 121, 51));
        saveBtn->setMaximumSize(QSize(1677215, 16777215));
        spinBox = new QSpinBox(settingWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(160, 360, 141, 38));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy);
        spinBox->setMinimumSize(QSize(0, 38));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(14);
        spinBox->setFont(font);
        label = new QLabel(settingWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 360, 125, 38));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(settingWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 591, 341));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        bot_text = new QTextEdit(layoutWidget);
        bot_text->setObjectName(QString::fromUtf8("bot_text"));
        bot_text->setMaximumSize(QSize(16777215, 80));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(13);
        bot_text->setFont(font2);

        gridLayout->addWidget(bot_text, 3, 2, 1, 2);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 5, 0, 1, 1);

        top_spin = new QSpinBox(layoutWidget);
        top_spin->setObjectName(QString::fromUtf8("top_spin"));
        top_spin->setMinimumSize(QSize(0, 38));
        top_spin->setFont(font);
        top_spin->setMinimum(1);
        top_spin->setMaximum(4);

        gridLayout->addWidget(top_spin, 5, 1, 1, 1);

        bot_spin = new QSpinBox(layoutWidget);
        bot_spin->setObjectName(QString::fromUtf8("bot_spin"));
        bot_spin->setMinimumSize(QSize(0, 38));
        bot_spin->setFont(font);
        bot_spin->setMinimum(1);
        bot_spin->setMaximum(4);

        gridLayout->addWidget(bot_spin, 5, 3, 1, 1);

        lineEdit = new myLineEdit1(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 30));
        lineEdit->setFont(font2);

        gridLayout->addWidget(lineEdit, 2, 0, 1, 2);

        lineEdit_2 = new myLineEdit1(layoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setMinimumSize(QSize(0, 30));
        lineEdit_2->setFont(font2);

        gridLayout->addWidget(lineEdit_2, 2, 2, 1, 2);

        checkBox = new QCheckBox(layoutWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setFont(font);

        gridLayout->addWidget(checkBox, 1, 0, 1, 1);

        top_text = new QTextEdit(layoutWidget);
        top_text->setObjectName(QString::fromUtf8("top_text"));
        top_text->setMaximumSize(QSize(16777215, 80));
        top_text->setFont(font2);

        gridLayout->addWidget(top_text, 3, 0, 1, 2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 5, 2, 1, 1);

        tableWidget = new QTableWidget(layoutWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setMinimumSize(QSize(0, 150));
        tableWidget->setMaximumSize(QSize(16777215, 16777215));
        QFont font3;
        font3.setPointSize(11);
        tableWidget->setFont(font3);

        gridLayout->addWidget(tableWidget, 4, 0, 1, 2);

        tableWidget_2 = new QTableWidget(layoutWidget);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setMinimumSize(QSize(0, 150));
        tableWidget_2->setMaximumSize(QSize(16777215, 16777215));
        tableWidget_2->setFont(font3);

        gridLayout->addWidget(tableWidget_2, 4, 2, 1, 2);

        checkBox_2 = new QCheckBox(settingWidget);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(20, 410, 261, 26));
        checkBox_2->setFont(font);
        label_4 = new QLabel(settingWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 450, 171, 38));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignCenter);
        panel_spin = new QSpinBox(settingWidget);
        panel_spin->setObjectName(QString::fromUtf8("panel_spin"));
        panel_spin->setGeometry(QRect(210, 450, 90, 38));
        sizePolicy.setHeightForWidth(panel_spin->sizePolicy().hasHeightForWidth());
        panel_spin->setSizePolicy(sizePolicy);
        panel_spin->setMinimumSize(QSize(0, 38));
        panel_spin->setFont(font);
        panel_spin->setMinimum(10);
        panel_spin->setMaximum(200);
        label_5 = new QLabel(settingWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(340, 450, 161, 38));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignCenter);
        defect_spin = new QSpinBox(settingWidget);
        defect_spin->setObjectName(QString::fromUtf8("defect_spin"));
        defect_spin->setGeometry(QRect(510, 450, 90, 38));
        sizePolicy.setHeightForWidth(defect_spin->sizePolicy().hasHeightForWidth());
        defect_spin->setSizePolicy(sizePolicy);
        defect_spin->setMinimumSize(QSize(0, 38));
        defect_spin->setFont(font);
        defect_spin->setMinimum(5);
        defect_spin->setMaximum(100);

        retranslateUi(settingWidget);

        QMetaObject::connectSlotsByName(settingWidget);
    } // setupUi

    void retranslateUi(QWidget *settingWidget)
    {
        settingWidget->setWindowTitle(QCoreApplication::translate("settingWidget", "Form", nullptr));
        cancelBtn->setText(QCoreApplication::translate("settingWidget", "\345\217\226\346\266\210", nullptr));
        saveBtn->setText(QCoreApplication::translate("settingWidget", "\344\277\235\345\255\230", nullptr));
        label->setText(QCoreApplication::translate("settingWidget", "\347\274\272\351\231\267\344\270\252\346\225\260", nullptr));
        bot_text->setPlaceholderText(QCoreApplication::translate("settingWidget", "Bot Job", nullptr));
        label_2->setText(QCoreApplication::translate("settingWidget", "Top Orient", nullptr));
        checkBox->setText(QCoreApplication::translate("settingWidget", "Force Mode", nullptr));
        top_text->setPlaceholderText(QCoreApplication::translate("settingWidget", "Top Job", nullptr));
        label_3->setText(QCoreApplication::translate("settingWidget", "Bot Orient", nullptr));
        checkBox_2->setText(QCoreApplication::translate("settingWidget", "Warning Generator Settings", nullptr));
        label_4->setText(QCoreApplication::translate("settingWidget", "\346\243\200\346\237\245\347\232\204\351\235\242\346\235\277\346\225\260\351\207\217", nullptr));
        label_5->setText(QCoreApplication::translate("settingWidget", "\346\234\200\345\260\217\347\274\272\351\231\267\346\225\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class settingWidget: public Ui_settingWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGWIDGET_H
