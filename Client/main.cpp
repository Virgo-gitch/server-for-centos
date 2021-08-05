#include "mainwindow.h"
#include <QApplication>
#include <QDateTime>
#include <QMutex>
#include <QSplashScreen>
#include <QFile>
#include <QMetaType>

enum LOG_LEVLE
{
    LOG_DEBUG = 0,
    LOG_WARNING = 1,
    LOG_ERROR = 2,
    LOG_FATAL = 3
};

#define LOGLEVEL	LOG_DEBUG

void logViewOutPut(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    if (type < LOGLEVEL)
        return;

    QString strMsg;
    switch (type)
    {
    case QtDebugMsg:
        strMsg = QString("  Debug  ");
        break;
    case QtWarningMsg:
        strMsg = QString("  Warning  ");
        break;
    case QtCriticalMsg:
        strMsg = QString("  Critical  ");
        break;
    case QtFatalMsg:
        strMsg = QString("  Fatal  ");
        abort();
    default:
        break;
    }

    QByteArray localMsg = msg.toLocal8Bit();
    QString strTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

    QString message = QString("File:(%1) Line:(%2) Func:(%3)  MSG:(%4)").arg(context.file).arg(context.line).arg(QString(context.function)).arg(QString(localMsg.constData()));
    QString str = strTime + strMsg + message;


    static QMutex mutex;
    mutex.lock();
    QFile file("D:/log.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Append);

    QTextStream stream(&file);
    stream << str << "\r\n";

    file.flush();
    file.close();
    mutex.unlock();
}

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    qRegisterMetaType<std::string>("std::string");
    qRegisterMetaType<QVector<job_pos>>("QVector<job_pos>");
    qRegisterMetaType<job_pos>("job_pos");

//    QProcess process;
//    QStringList list;
//    bool ok = process.startDetached("C:/Users/16507/Desktop/test.bat",list);
//    qDebug()<<ok;

//    qInstallMessageHandler(logViewOutPut);
    QPixmap pixmap(":/pic/image/01.png");
    QSplashScreen *splash = new QSplashScreen(pixmap);
    splash->show();

    //启动第一阶段
    splash->showMessage(QString("正在加载资源......"), Qt::AlignHCenter|Qt::AlignBottom, Qt::red);
    MainWindow w;
    //启动第二阶段
    splash->showMessage(QString("加载完成......"), Qt::AlignHCenter|Qt::AlignBottom, Qt::red);
    QDateTime n=QDateTime::currentDateTime();
    QDateTime now;
    do{
        now=QDateTime::currentDateTime();
    } while (n.secsTo(now)<=1);//1为需要延时的秒数
    w.show();
    splash->finish(&w);
    delete splash;
    QFile styleFile(":/style1.qss");
    if(styleFile.open(QIODevice::ReadOnly))
    {
        QString setStyleSheet(styleFile.readAll());
        a.setStyleSheet(setStyleSheet);
        styleFile.close();
    }
    else
    {
        qDebug("open failed");
    }

    return a.exec();
}
