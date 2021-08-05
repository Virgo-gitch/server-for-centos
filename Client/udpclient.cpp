#include "udpclient.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <signal.h>
#include <QDebug>
#include "rdkafkacpp.h"

static bool m_run = true;
static bool exit_eof = true;
static int eof_cnt = 0;
static int partition_cnt = 0;
static int verbosity = 1;
static long msg_cnt = 0;
static int64_t msg_bytes = 0;

static long msg_cnt1 = 0;
static int64_t msg_bytes1 = 0;

static void sigterm (int sig) {
    m_run = false;
}


class ExampleEventCb : public RdKafka::EventCb {
public:
    void event_cb (RdKafka::Event &event) {
        switch (event.type())
        {
        case RdKafka::Event::EVENT_ERROR:
            std::cerr<<"ERROR (" << RdKafka::err2str(event.err()) << "): " <<
                         event.str();
            if (event.err() == RdKafka::ERR__ALL_BROKERS_DOWN)
                m_run = false;
            break;

        case RdKafka::Event::EVENT_STATS:
            std::cerr << "\"STATS\": " << event.str() << std::endl;
            break;

        case RdKafka::Event::EVENT_LOG:
            fprintf(stderr, "LOG-%i-%s: %s\n",
                    event.severity(), event.fac().c_str(), event.str().c_str());
            break;

        case RdKafka::Event::EVENT_THROTTLE:
            std::cerr << "THROTTLED: " << event.throttle_time() << "ms by " <<
                         event.broker_name() << " id " << (int)event.broker_id() << std::endl;
            break;

        default:
            std::cerr << "EVENT " << event.type() <<
                         " (" << RdKafka::err2str(event.err()) << "): " <<
                         event.str() << std::endl;
            break;
        }
    }
};



class ExampleConsumeCb : public RdKafka::ConsumeCb {
public:

    void msg_consume(RdKafka::Message* message, void* opaque) {
//        switch (message->err()) {
//        case RdKafka::ERR__TIMED_OUT:
//            //std::cerr << "RdKafka::ERR__TIMED_OUT"<<std::endl;
//            break;

//        case RdKafka::ERR_NO_ERROR:
//            /* Real message */
//            msg_cnt++;
//            msg_bytes += message->len();
//            if (verbosity >= 3)
//                std::cerr << "Read msg at offset " << message->offset() << std::endl;
//            RdKafka::MessageTimestamp ts;
//            ts = message->timestamp();
//            if (verbosity >= 2 &&
//                    ts.type != RdKafka::MessageTimestamp::MSG_TIMESTAMP_NOT_AVAILABLE) {
//                std::string tsname = "?";
//                if (ts.type == RdKafka::MessageTimestamp::MSG_TIMESTAMP_CREATE_TIME)
//                    tsname = "create time";
//                else if (ts.type == RdKafka::MessageTimestamp::MSG_TIMESTAMP_LOG_APPEND_TIME)
//                    tsname = "log append time";
//                std::cout << "Timestamp: " << tsname << " " << ts.timestamp << std::endl;
//            }
//            if (verbosity >= 2 && message->key()) {
//                std::cout << "Key: " << *message->key() << std::endl;
//            }
//            if (verbosity >= 1) {
//    //            printf("%.*s\n",
//    //                   static_cast<int>(message->len()),
//    //                   static_cast<const char *>(message->payload()));
//                std::cout<<*message->key()<<std::endl;


//            }
//            break;

//        case RdKafka::ERR__PARTITION_EOF:
//            /* Last message */
//            if (exit_eof && ++eof_cnt == partition_cnt) {
//                std::cerr << "%% EOF reached for all " << partition_cnt <<
//                             " partition(s)" << std::endl;
//                run = false;
//            }
//            break;

//        case RdKafka::ERR__UNKNOWN_TOPIC:
//        case RdKafka::ERR__UNKNOWN_PARTITION:
//            std::cerr << "Consume failed: " << message->errstr() << std::endl;
//            run = false;
//            break;

//        default:
//            /* Errors */
//            std::cerr << "Consume failed: " << message->errstr() << std::endl;
//            run = false;
//        }
    }

    void consume_cb (RdKafka::Message &msg, void *opaque) {
//        msg_consume(&msg, opaque);
    }
};

udpclient::udpclient(std::string ip, QObject *parent):
    QThread(parent)
{
    m_kafkaIp = ip;
}

udpclient::~udpclient()
{

}

void udpclient::msg_consume(RdKafka::Message* message, void* opaque) {
    switch (message->err()) {
    case RdKafka::ERR__TIMED_OUT:
        //std::cerr << "RdKafka::ERR__TIMED_OUT"<<std::endl;
        break;

    case RdKafka::ERR_NO_ERROR:
        /* Real message */
        msg_cnt++;
        msg_bytes += message->len();
        if (verbosity >= 3)
            std::cerr << "Read msg at offset " << message->offset() << std::endl;
        RdKafka::MessageTimestamp ts;
        ts = message->timestamp();
        if (verbosity >= 2 &&
                ts.type != RdKafka::MessageTimestamp::MSG_TIMESTAMP_NOT_AVAILABLE) {
            std::string tsname = "?";
            if (ts.type == RdKafka::MessageTimestamp::MSG_TIMESTAMP_CREATE_TIME)
                tsname = "create time";
            else if (ts.type == RdKafka::MessageTimestamp::MSG_TIMESTAMP_LOG_APPEND_TIME)
                tsname = "log append time";
            std::cout << "Timestamp: " << tsname << " " << ts.timestamp << std::endl;
        }
        if (verbosity >= 2 && message->key()) {
            std::cout << "Key: " << *message->key() << std::endl;
        }
        if (verbosity >= 1) {


//             qDebug()<<QString::fromStdString(*message->key())<<static_cast<const char *>(message->payload());
            emit valueUpdate(static_cast<const char *>(message->payload()), *message->key());

        }
        break;

    case RdKafka::ERR__PARTITION_EOF:
        /* Last message */
        if (exit_eof && ++eof_cnt == partition_cnt) {
            std::cerr << "%% EOF reached for all " << partition_cnt <<
                         " partition(s)" << std::endl;
            m_run = false;
        }
        break;

    case RdKafka::ERR__UNKNOWN_TOPIC:
    case RdKafka::ERR__UNKNOWN_PARTITION:
        std::cerr << "Consume failed: " << message->errstr() << std::endl;
        m_run = false;
        break;

    default:
        /* Errors */
        std::cerr << "Consume failed: " << message->errstr() << std::endl;
        m_run = false;
    }
}

void udpclient::msg_consume1(RdKafka::Message* message, void* opaque) {
    switch (message->err()) {
    case RdKafka::ERR__TIMED_OUT:
        //std::cerr << "RdKafka::ERR__TIMED_OUT"<<std::endl;
        break;

    case RdKafka::ERR_NO_ERROR:
        /* Real message */
        msg_cnt1++;
        msg_bytes1 += message->len();
        if (verbosity >= 3)
            std::cerr << "Read msg at offset " << message->offset() << std::endl;
        RdKafka::MessageTimestamp ts;
        ts = message->timestamp();
        if (verbosity >= 2 &&
                ts.type != RdKafka::MessageTimestamp::MSG_TIMESTAMP_NOT_AVAILABLE) {
            std::string tsname = "?";
            if (ts.type == RdKafka::MessageTimestamp::MSG_TIMESTAMP_CREATE_TIME)
                tsname = "create time";
            else if (ts.type == RdKafka::MessageTimestamp::MSG_TIMESTAMP_LOG_APPEND_TIME)
                tsname = "log append time";
            std::cout << "Timestamp: " << tsname << " " << ts.timestamp << std::endl;
        }
        if (verbosity >= 2 && message->key()) {
            std::cout << "Key: " << *message->key() << std::endl;
        }
        if (verbosity >= 1) {
//            qDebug()<<static_cast<const char *>(message->payload());
            emit valueUpdate1(static_cast<const char *>(message->payload()));


        }
        break;

    case RdKafka::ERR__PARTITION_EOF:
        /* Last message */
        if (exit_eof && ++eof_cnt == partition_cnt) {
            std::cerr << "%% EOF reached for all " << partition_cnt <<
                         " partition(s)" << std::endl;
            m_run = false;
        }
        break;

    case RdKafka::ERR__UNKNOWN_TOPIC:
    case RdKafka::ERR__UNKNOWN_PARTITION:
        std::cerr << "Consume failed: " << message->errstr() << std::endl;
        m_run = false;
        break;

    default:
        /* Errors */
        std::cerr << "Consume failed: " << message->errstr() << std::endl;
        m_run = false;
    }
}

void udpclient::setRun()
{
    m_run = false;
}

//重写线程执行函数
void udpclient::run()
{

    std::string brokers = m_kafkaIp;
    std::string errstr;
    std::string topic_str="ui-responses";
    std::string topic_str1 = "requests";
    std::vector<std::string> topics, topics1;
    std::string group_id="1212";
    RdKafka::Conf *conf = RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL);
    RdKafka::Conf *tconf = RdKafka::Conf::create(RdKafka::Conf::CONF_TOPIC);

    //group.id必须设置
    if (conf->set("group.id", group_id, errstr) != RdKafka::Conf::CONF_OK) {
           std::cerr << errstr << std::endl;
           exit(1);
         }

    topics.push_back(topic_str);
    topics1.push_back(topic_str1);
   //bootstrap.servers可以替换为metadata.broker.list
    conf->set("bootstrap.servers", brokers, errstr);
    ExampleConsumeCb ex_consume_cb;
    conf->set("consume_cb", &ex_consume_cb, errstr);

    ExampleEventCb ex_event_cb;
    conf->set("event_cb", &ex_event_cb, errstr);
    conf->set("default_topic_conf", tconf, errstr);

    signal(SIGINT, sigterm);
    signal(SIGTERM, sigterm);

    RdKafka::KafkaConsumer *consumer = RdKafka::KafkaConsumer::create(conf, errstr);
    RdKafka::KafkaConsumer *consumer1 = RdKafka::KafkaConsumer::create(conf, errstr);
    if (!consumer) {
        std::cerr << "Failed to create consumer: " << errstr << std::endl;
        exit(1);
    }
    if (!consumer1) {
        std::cerr << "Failed to create consumer: " << errstr << std::endl;
        exit(1);
    }
    std::cout << "% Created consumer " << consumer->name() << std::endl;
    std::cout << "% Created consumer1 " << consumer1->name() << std::endl;
    RdKafka::ErrorCode err = consumer->subscribe(topics);
    RdKafka::ErrorCode err1 = consumer1->subscribe(topics1);
    if (err) {
        std::cerr << "Failed to subscribe to " << topics.size() << " topics: "
                  << RdKafka::err2str(err) << std::endl;
        exit(1);
    }
    while (m_run)
    {

        //0毫秒未订阅到消息，触发RdKafka::ERR__TIMED_OUT
        RdKafka::Message *msg = consumer->consume(0);
        RdKafka::Message *msg1 = consumer1->consume(0);
        consumer->commitSync();
        msg_consume(msg, NULL);
        msg_consume1(msg1,NULL);
        delete msg;
        delete msg1;
        msleep(50);

    }

    consumer->close();
    consumer1->close();
    delete conf;
    delete tconf;
    delete consumer;
    delete consumer1;

    std::cerr << "% Consumed " << msg_cnt << " messages ("
              << msg_bytes << " bytes)" << std::endl;

    std::cerr << "% Consumed1 " << msg_cnt1 << " messages ("
              << msg_bytes1 << " bytes)" << std::endl;
    //应用退出之前等待rdkafka清理资源
    RdKafka::wait_destroyed(2000);
    quit();

}



