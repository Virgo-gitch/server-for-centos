/********************************************************************************
** Form generated from reading UI file 'celldlg.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CELLDLG_H
#define UI_CELLDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_cellDlg
{
public:
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *cellDlg)
    {
        if (cellDlg->objectName().isEmpty())
            cellDlg->setObjectName(QString::fromUtf8("cellDlg"));
        cellDlg->setWindowModality(Qt::NonModal);
        cellDlg->resize(674, 594);
        verticalLayout = new QVBoxLayout(cellDlg);
        verticalLayout->setSpacing(1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        graphicsView = new QGraphicsView(cellDlg);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        verticalLayout->addWidget(graphicsView);

        groupBox = new QGroupBox(cellDlg);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 50));
        groupBox->setMaximumSize(QSize(16777215, 50));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(100, 0));
        label->setMaximumSize(QSize(100, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(14);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimumSize(QSize(80, 27));
        spinBox->setMaximumSize(QSize(80, 27));
        spinBox->setFont(font);

        horizontalLayout->addWidget(spinBox);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(80, 27));
        pushButton->setMaximumSize(QSize(80, 27));
        pushButton->setFont(font);

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(80, 27));
        pushButton_2->setMaximumSize(QSize(80, 27));
        pushButton_2->setFont(font);

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(80, 27));
        pushButton_3->setMaximumSize(QSize(80, 27));
        pushButton_3->setFont(font);

        horizontalLayout->addWidget(pushButton_3);


        verticalLayout->addWidget(groupBox);


        retranslateUi(cellDlg);

        QMetaObject::connectSlotsByName(cellDlg);
    } // setupUi

    void retranslateUi(QDialog *cellDlg)
    {
        cellDlg->setWindowTitle(QCoreApplication::translate("cellDlg", "Dialog", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("cellDlg", "\346\227\213\350\275\254\350\247\222\345\272\246", nullptr));
        pushButton->setText(QCoreApplication::translate("cellDlg", "\345\267\246\346\227\213\350\275\254", nullptr));
        pushButton_2->setText(QCoreApplication::translate("cellDlg", "\345\217\263\346\227\213\350\275\254", nullptr));
        pushButton_3->setText(QCoreApplication::translate("cellDlg", "exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class cellDlg: public Ui_cellDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CELLDLG_H
