/********************************************************************************
** Form generated from reading UI file 'defectpreview.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEFECTPREVIEW_H
#define UI_DEFECTPREVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <mydefectlab.h>

QT_BEGIN_NAMESPACE

class Ui_DefectPreview
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QLabel *label_5;
    QPushButton *modify_btn;
    QLabel *titleLab;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout;
    QLabel *minordefectLab;
    MyDefectLab *defectLab;
    QGraphicsView *graphicsView;
    QFrame *frame_3;
    QPushButton *forward_btn;
    QPushButton *behind_btn;
    QPushButton *again_btn;
    QPushButton *set_btn;
    QPushButton *page_btn;
    QPushButton *find_btn;
    QPushButton *exit_btn;
    QPushButton *before_btn;
    QPushButton *after_btn;
    QPushButton *up_btn;
    QPushButton *refrush_btn;
    QLabel *label;
    QLabel *label_2;
    QLabel *bmpcountLab;
    QComboBox *comboBox;
    QTableWidget *tableWidget;
    QLabel *label_4;
    QLabel *curdefectLab;
    QLabel *panelLab;

    void setupUi(QDialog *DefectPreview)
    {
        if (DefectPreview->objectName().isEmpty())
            DefectPreview->setObjectName(QString::fromUtf8("DefectPreview"));
        DefectPreview->resize(1112, 613);
        verticalLayout = new QVBoxLayout(DefectPreview);
        verticalLayout->setSpacing(3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(DefectPreview);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(0, 50));
        frame->setMaximumSize(QSize(16777215, 50));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(1, 10, 281, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(14);
        label_5->setFont(font);
        modify_btn = new QPushButton(frame);
        modify_btn->setObjectName(QString::fromUtf8("modify_btn"));
        modify_btn->setGeometry(QRect(290, 10, 36, 35));
        modify_btn->setStyleSheet(QString::fromUtf8("image: url(:/pic/image/modify.png);"));
        titleLab = new QLabel(frame);
        titleLab->setObjectName(QString::fromUtf8("titleLab"));
        titleLab->setGeometry(QRect(510, 0, 101, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(20);
        titleLab->setFont(font1);
        titleLab->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(frame);

        frame_2 = new QFrame(DefectPreview);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        minordefectLab = new QLabel(frame_2);
        minordefectLab->setObjectName(QString::fromUtf8("minordefectLab"));
        minordefectLab->setMinimumSize(QSize(360, 360));
        minordefectLab->setMaximumSize(QSize(360, 360));

        horizontalLayout->addWidget(minordefectLab);

        defectLab = new MyDefectLab(frame_2);
        defectLab->setObjectName(QString::fromUtf8("defectLab"));
        defectLab->setMinimumSize(QSize(360, 360));
        defectLab->setMaximumSize(QSize(360, 360));

        horizontalLayout->addWidget(defectLab);

        graphicsView = new QGraphicsView(frame_2);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setMinimumSize(QSize(360, 360));
        graphicsView->setMaximumSize(QSize(360, 360));

        horizontalLayout->addWidget(graphicsView);


        verticalLayout->addWidget(frame_2);

        frame_3 = new QFrame(DefectPreview);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setMinimumSize(QSize(0, 177));
        frame_3->setMaximumSize(QSize(16777215, 177));
        frame_3->setFrameShape(QFrame::NoFrame);
        frame_3->setFrameShadow(QFrame::Plain);
        forward_btn = new QPushButton(frame_3);
        forward_btn->setObjectName(QString::fromUtf8("forward_btn"));
        forward_btn->setGeometry(QRect(10, 0, 77, 71));
        forward_btn->setStyleSheet(QString::fromUtf8("background-image: url(:/pic/image/forward.png);\n"
""));
        behind_btn = new QPushButton(frame_3);
        behind_btn->setObjectName(QString::fromUtf8("behind_btn"));
        behind_btn->setGeometry(QRect(280, 0, 77, 71));
        behind_btn->setStyleSheet(QString::fromUtf8("background-image: url(:/pic/image/back.png);"));
        again_btn = new QPushButton(frame_3);
        again_btn->setObjectName(QString::fromUtf8("again_btn"));
        again_btn->setGeometry(QRect(380, 0, 77, 71));
        again_btn->setStyleSheet(QString::fromUtf8("background-image: url(:/pic/image/again.png);"));
        set_btn = new QPushButton(frame_3);
        set_btn->setObjectName(QString::fromUtf8("set_btn"));
        set_btn->setGeometry(QRect(650, 0, 77, 71));
        set_btn->setStyleSheet(QString::fromUtf8("background-image: url(:/pic/image/set.png);"));
        page_btn = new QPushButton(frame_3);
        page_btn->setObjectName(QString::fromUtf8("page_btn"));
        page_btn->setGeometry(QRect(750, 0, 77, 71));
        page_btn->setStyleSheet(QString::fromUtf8("background-image: url(:/pic/image/page.png);"));
        find_btn = new QPushButton(frame_3);
        find_btn->setObjectName(QString::fromUtf8("find_btn"));
        find_btn->setGeometry(QRect(880, 0, 77, 71));
        find_btn->setStyleSheet(QString::fromUtf8("background-image: url(:/pic/image/find.png);"));
        exit_btn = new QPushButton(frame_3);
        exit_btn->setObjectName(QString::fromUtf8("exit_btn"));
        exit_btn->setGeometry(QRect(1010, 0, 77, 71));
        exit_btn->setStyleSheet(QString::fromUtf8("background-image: url(:/pic/image/delete.png);"));
        before_btn = new QPushButton(frame_3);
        before_btn->setObjectName(QString::fromUtf8("before_btn"));
        before_btn->setGeometry(QRect(10, 100, 77, 71));
        before_btn->setStyleSheet(QString::fromUtf8("background-image: url(:/pic/image/before.png);"));
        after_btn = new QPushButton(frame_3);
        after_btn->setObjectName(QString::fromUtf8("after_btn"));
        after_btn->setGeometry(QRect(280, 100, 77, 71));
        after_btn->setStyleSheet(QString::fromUtf8("background-image: url(:/pic/image/after.png);"));
        up_btn = new QPushButton(frame_3);
        up_btn->setObjectName(QString::fromUtf8("up_btn"));
        up_btn->setGeometry(QRect(380, 100, 77, 71));
        up_btn->setStyleSheet(QString::fromUtf8("background-image: url(:/pic/image/up.png);"));
        refrush_btn = new QPushButton(frame_3);
        refrush_btn->setObjectName(QString::fromUtf8("refrush_btn"));
        refrush_btn->setGeometry(QRect(1010, 100, 77, 71));
        refrush_btn->setStyleSheet(QString::fromUtf8("background-image: url(:/pic/image/refresh.png);"));
        label = new QLabel(frame_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 10, 31, 61));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(16);
        label->setFont(font2);
        label_2 = new QLabel(frame_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(150, 30, 51, 20));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial"));
        font3.setPointSize(9);
        font3.setBold(false);
        font3.setWeight(50);
        label_2->setFont(font3);
        bmpcountLab = new QLabel(frame_3);
        bmpcountLab->setObjectName(QString::fromUtf8("bmpcountLab"));
        bmpcountLab->setGeometry(QRect(210, 10, 71, 61));
        bmpcountLab->setFont(font2);
        comboBox = new QComboBox(frame_3);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(470, 21, 171, 31));
        tableWidget = new QTableWidget(frame_3);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(460, 80, 281, 91));
        tableWidget->setTextElideMode(Qt::ElideMiddle);
        tableWidget->verticalHeader()->setMinimumSectionSize(15);
        tableWidget->verticalHeader()->setDefaultSectionSize(15);
        label_4 = new QLabel(frame_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(160, 80, 54, 31));
        label_4->setAlignment(Qt::AlignCenter);
        curdefectLab = new QLabel(frame_3);
        curdefectLab->setObjectName(QString::fromUtf8("curdefectLab"));
        curdefectLab->setGeometry(QRect(150, 12, 54, 20));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Arial"));
        font4.setPointSize(11);
        curdefectLab->setFont(font4);
        curdefectLab->setAlignment(Qt::AlignCenter);
        panelLab = new QLabel(frame_3);
        panelLab->setObjectName(QString::fromUtf8("panelLab"));
        panelLab->setGeometry(QRect(140, 120, 91, 31));
        panelLab->setFont(font2);
        panelLab->setFrameShape(QFrame::Panel);
        panelLab->setFrameShadow(QFrame::Raised);
        panelLab->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(frame_3);


        retranslateUi(DefectPreview);

        QMetaObject::connectSlotsByName(DefectPreview);
    } // setupUi

    void retranslateUi(QDialog *DefectPreview)
    {
        DefectPreview->setWindowTitle(QCoreApplication::translate("DefectPreview", "Dialog", nullptr));
        label_5->setText(QCoreApplication::translate("DefectPreview", "<html><head/><body><p><span style=\" font-size:12pt;\">Type: 126 - Pattern -&gt; Settings: Shorts</span></p></body></html>", nullptr));
        modify_btn->setText(QString());
        titleLab->setText(QString());
        minordefectLab->setText(QString());
        defectLab->setText(QString());
        forward_btn->setText(QString());
        behind_btn->setText(QString());
        again_btn->setText(QString());
        set_btn->setText(QString());
        page_btn->setText(QString());
        find_btn->setText(QString());
        exit_btn->setText(QString());
        before_btn->setText(QString());
        after_btn->setText(QString());
        up_btn->setText(QString());
        refrush_btn->setText(QString());
        label->setText(QCoreApplication::translate("DefectPreview", "1", nullptr));
        label_2->setText(QCoreApplication::translate("DefectPreview", "-----------", nullptr));
        bmpcountLab->setText(QCoreApplication::translate("DefectPreview", "16", nullptr));
        label_4->setText(QCoreApplication::translate("DefectPreview", "PANEL", nullptr));
        curdefectLab->setText(QCoreApplication::translate("DefectPreview", "1", nullptr));
        panelLab->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DefectPreview: public Ui_DefectPreview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEFECTPREVIEW_H
