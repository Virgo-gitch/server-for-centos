/********************************************************************************
** Form generated from reading UI file 'scandlg.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCANDLG_H
#define UI_SCANDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ScanDlg
{
public:
    QPushButton *okBtn;
    QPushButton *notOkBtn;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *nameLab;
    QLabel *angleLab;
    QLabel *siteLab;

    void setupUi(QDialog *ScanDlg)
    {
        if (ScanDlg->objectName().isEmpty())
            ScanDlg->setObjectName(QString::fromUtf8("ScanDlg"));
        ScanDlg->resize(404, 317);
        okBtn = new QPushButton(ScanDlg);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));
        okBtn->setGeometry(QRect(50, 250, 75, 31));
        notOkBtn = new QPushButton(ScanDlg);
        notOkBtn->setObjectName(QString::fromUtf8("notOkBtn"));
        notOkBtn->setGeometry(QRect(280, 250, 75, 31));
        label = new QLabel(ScanDlg);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 130, 381, 91));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(26);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(ScanDlg);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(31, 6, 64, 18));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(12);
        label_2->setFont(font1);
        label_3 = new QLabel(ScanDlg);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(31, 50, 64, 18));
        label_3->setFont(font1);
        label_4 = new QLabel(ScanDlg);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(31, 90, 80, 18));
        label_4->setFont(font1);
        nameLab = new QLabel(ScanDlg);
        nameLab->setObjectName(QString::fromUtf8("nameLab"));
        nameLab->setGeometry(QRect(150, 6, 241, 18));
        nameLab->setFont(font1);
        angleLab = new QLabel(ScanDlg);
        angleLab->setObjectName(QString::fromUtf8("angleLab"));
        angleLab->setGeometry(QRect(150, 50, 91, 18));
        angleLab->setFont(font1);
        siteLab = new QLabel(ScanDlg);
        siteLab->setObjectName(QString::fromUtf8("siteLab"));
        siteLab->setGeometry(QRect(150, 90, 111, 18));
        siteLab->setFont(font1);

        retranslateUi(ScanDlg);

        QMetaObject::connectSlotsByName(ScanDlg);
    } // setupUi

    void retranslateUi(QDialog *ScanDlg)
    {
        ScanDlg->setWindowTitle(QCoreApplication::translate("ScanDlg", "Dialog", nullptr));
        okBtn->setText(QCoreApplication::translate("ScanDlg", "\346\230\257", nullptr));
        notOkBtn->setText(QCoreApplication::translate("ScanDlg", "\345\220\246", nullptr));
        label->setText(QCoreApplication::translate("ScanDlg", "\346\230\257\345\220\246\351\234\200\350\246\201\351\207\215\346\226\260\346\211\253\346\217\217!", nullptr));
        label_2->setText(QCoreApplication::translate("ScanDlg", "\350\265\204\346\226\231\345\220\215\347\247\260", nullptr));
        label_3->setText(QCoreApplication::translate("ScanDlg", "\350\265\204\346\226\231\350\247\222\345\272\246", nullptr));
        label_4->setText(QCoreApplication::translate("ScanDlg", "\350\265\204\346\226\231\345\257\271\344\275\215\347\202\271", nullptr));
        nameLab->setText(QCoreApplication::translate("ScanDlg", "Djob\\", nullptr));
        angleLab->setText(QCoreApplication::translate("ScanDlg", "0", nullptr));
        siteLab->setText(QCoreApplication::translate("ScanDlg", "N", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ScanDlg: public Ui_ScanDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCANDLG_H
