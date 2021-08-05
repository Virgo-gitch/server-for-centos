
#-------------------------------------------------
#
# Project created by QtCreator 2021-03-09T09:05:36
#
#-------------------------------------------------

QT       += core gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets



TARGET = Client
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS, QT_MESSAGELOGCONTEXT

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++17
CONFIG += console

QMAKE_CXXFLAGS_RELEASE = $$QMAKE_CFLAGS_RELEASE_WITH_DEBUGINFO
QMAKE_LFLAGS_RELEASE = $$QMAKE_LFLAGS_RELEASE_WITH_DEBUGINFO

SOURCES += \
        celldlg.cpp \
        defectpreview.cpp \
        defectwarning.cpp \
        defectwarnthread.cpp \
        jobdlg.cpp \
        main.cpp \
        mainwindow.cpp \
        mydefectlab.cpp \
        mydefectposlab.cpp \
        mylabel.cpp \
        mylineedit.cpp \
        mylineedit1.cpp \
        mytablewidget.cpp \
        producer.cpp \
        scandlg.cpp \
        settingwidget.cpp \
        udpclient.cpp

HEADERS += \
        celldlg.h \
        defectpreview.h \
        defectwarning.h \
        defectwarnthread.h \
        jobdlg.h \
        jsonFun.h \
        mainwindow.h \
        mydefectlab.h \
        mydefectposlab.h \
        mylabel.h \
        mylineedit.h \
        mylineedit1.h \
        mytablewidget.h \
        producer.h \
        rdkafka.h \
        rdkafkacpp.h \
        scandlg.h \
        settingwidget.h \
        udpclient.h

FORMS += \
        celldlg.ui \
        defectpreview.ui \
        defectwarning.ui \
        jobdlg.ui \
        mainwindow.ui \
        scandlg.ui \
        settingwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

LIBS += /usr/local/rocksdb/lib/librocksdb.so
LIBS += /usr/local/lib/librdkafka.so
LIBS += /usr/local/lib/librdkafka++.so

