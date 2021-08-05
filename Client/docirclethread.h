#ifndef DOCIRCLETHREAD_H
#define DOCIRCLETHREAD_H

#include <QThread>
#include <jsonFun.h>

class doCircleThread : public QThread
{
    Q_OBJECT
public:
    explicit doCircleThread(QObject *parent=nullptr);
    ~doCircleThread();

private:
    void run();

    void getCoordinate(qreal, qreal, qreal&, qreal&, qreal&);

public:
    bool m_run;
    static_info SI;
    int rotateValue;
    qreal gifX, gifY;
};

#endif // DOCIRCLETHREAD_H
