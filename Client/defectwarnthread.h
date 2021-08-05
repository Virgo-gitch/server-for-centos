#ifndef DEFECTWARNTHREAD_H
#define DEFECTWARNTHREAD_H

#include <QObject>
#include <QDebug>
#include <jsonFun.h>
#include <QThread>


class defectWarnThread : public QObject
{
    Q_OBJECT


public:
    explicit defectWarnThread(QObject *parent = nullptr);


signals:
    void sendResult(const QVector<job_pos>&, const int, const int);

public slots:
    void dealDefectWarnInfo(const QString&, const job_pos&);

private:

};

#endif // DEFECTWARNTHREAD_H
