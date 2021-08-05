/********************************************************************************
** Form generated from reading UI file 'defectwarning.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEFECTWARNING_H
#define UI_DEFECTWARNING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <mydefectposlab.h>

QT_BEGIN_NAMESPACE

class Ui_DefectWarning
{
public:
    QGridLayout *gridLayout;
    myDefectPosLab *label;
    QLabel *label_2;
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QListWidget *listWidget;

    void setupUi(QDialog *DefectWarning)
    {
        if (DefectWarning->objectName().isEmpty())
            DefectWarning->setObjectName(QString::fromUtf8("DefectWarning"));
        DefectWarning->resize(1110, 534);
        gridLayout = new QGridLayout(DefectWarning);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new myDefectPosLab(DefectWarning);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(360, 360));
        label->setMaximumSize(QSize(360, 360));
        label->setScaledContents(false);

        gridLayout->addWidget(label, 0, 1, 1, 1);

        label_2 = new QLabel(DefectWarning);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(360, 360));
        label_2->setMaximumSize(QSize(360, 360));
        label_2->setScaledContents(false);

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        groupBox = new QGroupBox(DefectWarning);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 140));
        groupBox->setMaximumSize(QSize(16777215, 140));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 36, 80, 80));
        pushButton->setMinimumSize(QSize(80, 80));
        pushButton->setMaximumSize(QSize(80, 80));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(12);
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(140, 36, 80, 80));
        pushButton_2->setMinimumSize(QSize(80, 80));
        pushButton_2->setMaximumSize(QSize(80, 80));
        pushButton_2->setFont(font);
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(270, 36, 80, 80));
        pushButton_3->setMinimumSize(QSize(80, 80));
        pushButton_3->setMaximumSize(QSize(80, 80));
        pushButton_3->setFont(font);
        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(410, 36, 105, 80));
        pushButton_5->setMinimumSize(QSize(105, 80));
        pushButton_5->setMaximumSize(QSize(105, 80));
        pushButton_5->setStyleSheet(QString::fromUtf8("border-image: url(:/pic/image/pre_defect.jpg);"));
        pushButton_6 = new QPushButton(groupBox);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(600, 36, 105, 80));
        pushButton_6->setMinimumSize(QSize(105, 80));
        pushButton_6->setMaximumSize(QSize(105, 80));
        pushButton_6->setStyleSheet(QString::fromUtf8("border-image: url(:/pic/image/next_defect.jpg);"));
        pushButton_7 = new QPushButton(groupBox);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(790, 36, 80, 80));
        pushButton_7->setMinimumSize(QSize(80, 80));
        pushButton_7->setMaximumSize(QSize(80, 80));
        pushButton_7->setStyleSheet(QString::fromUtf8("border-image: url(:/pic/image/warn.jpg);"));
        pushButton_8 = new QPushButton(groupBox);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(960, 36, 80, 80));
        pushButton_8->setMinimumSize(QSize(80, 80));
        pushButton_8->setMaximumSize(QSize(80, 80));
        pushButton_8->setStyleSheet(QString::fromUtf8("border-image: url(:/pic/image/nowarn.jpg);"));

        gridLayout->addWidget(groupBox, 1, 0, 1, 3);

        listWidget = new QListWidget(DefectWarning);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setMinimumSize(QSize(360, 360));
        listWidget->setMaximumSize(QSize(360, 360));
        QFont font1;
        font1.setPointSize(12);
        listWidget->setFont(font1);

        gridLayout->addWidget(listWidget, 0, 0, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 1);
        gridLayout->setColumnStretch(2, 1);

        retranslateUi(DefectWarning);

        QMetaObject::connectSlotsByName(DefectWarning);
    } // setupUi

    void retranslateUi(QDialog *DefectWarning)
    {
        DefectWarning->setWindowTitle(QCoreApplication::translate("DefectWarning", "Dialog", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        groupBox->setTitle(QString());
        pushButton->setText(QCoreApplication::translate("DefectWarning", "Real", nullptr));
        pushButton_2->setText(QString());
        pushButton_3->setText(QCoreApplication::translate("DefectWarning", "Mask", nullptr));
        pushButton_5->setText(QString());
        pushButton_6->setText(QString());
        pushButton_7->setText(QString());
        pushButton_8->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DefectWarning: public Ui_DefectWarning {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEFECTWARNING_H
