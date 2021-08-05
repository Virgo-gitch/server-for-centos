#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QThread>
#include "rdkafkacpp.h"

class udpclient : public QThread
{
    Q_OBJECT

public:
    explicit udpclient(std::string, QObject *parent = nullptr);
    ~udpclient();

public:
    void msg_consume(RdKafka::Message* message, void* opaque);

    void msg_consume1(RdKafka::Message* message, void* opaque);

    void setRun();


private:
    //重写线程执行函数
    void run();
    std::string m_kafkaIp;

signals:
    void valueUpdate(const QString& str, const std::string str1);

    void valueUpdate1(const QString& str);

};

#endif // UDPCLIENT_H
