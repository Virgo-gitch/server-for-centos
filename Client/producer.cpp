#include "producer.h"



std::string errstr;
std::string topic_str="ui-requests";
int32_t partition = RdKafka::Topic::PARTITION_UA;


Producer::Producer(std::string ip, QObject *parent):
    QObject(parent)
{
    std::string brokers = ip;
    conf = RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL);
    tconf = RdKafka::Conf::create(RdKafka::Conf::CONF_TOPIC);

    conf->set("bootstrap.servers", brokers, errstr);

    conf->set("event_cb", &ex_event_cb, errstr);

//    signal(SIGINT, sigterm);
//    signal(SIGTERM, sigterm);


    conf->set("dr_cb", &ex_dr_cb, errstr);

    producer = RdKafka::Producer::create(conf, errstr);
    if (!producer) {
        std::cerr << "Failed to create producer: " << errstr << std::endl;
        exit(1);
    }
    std::cout << "% Created producer " << producer->name() << std::endl;

    topic = RdKafka::Topic::create(producer, topic_str,
                                                   tconf, errstr);
    if (!topic) {
        std::cerr << "Failed to create topic: " << errstr << std::endl;
        exit(1);
    }
}

Producer::~Producer()
{

    m_run = true;
    // 退出前处理完输出队列中的消息
    while (m_run && producer->outq_len() > 0) {
//        qDebug()<< "Waiting for " << producer->outq_len();
        producer->poll(1000);
    }
    RdKafka::wait_destroyed(1000);

    delete conf;
    delete tconf;
    delete topic;
    delete producer;

}


void Producer::getNewMessage(std::string msg, std::string key)
{
    produceMessage(msg, key);

}

void Producer::produceMessage(std::string message, std::string key)
{

    RdKafka::ErrorCode resp =
            producer->produce(topic, partition,
                              RdKafka::Producer::RK_MSG_COPY /* Copy payload */,
                              const_cast<char *>(message.c_str()), message.size(),
                              const_cast<char *>(key.c_str()), key.size(),
                              NULL);

    if (resp != RdKafka::ERR_NO_ERROR)
        qDebug()<< "% Produce failed: " <<QString::fromStdString(RdKafka::err2str(resp));
    else
//        qDebug()<< "% Produced message (" << message.size() << " bytes)";
    qDebug()<<QString::fromStdString(message)<<QString::fromStdString(key);
    producer->poll(0);
}

