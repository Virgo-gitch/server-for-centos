#ifndef MYPANELS_H
#define MYPANELS_H
#include <set>
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;


inline std::string const scanning_key = "scanning";
inline std::string const scan_queued_key = "scan_queued";
inline std::string const slave_assignment_queue_key = "slave_assignment_queue";

enum keyType{
    arrival_ok_panels = 0,
    arrival_not_ok_panels,
    done_ok_panels,
    done_not_ok_panels,
    stopped_panels,
    scan_queued,
    slave_assignment_queue,
    scanning,
};


template <typename T>static void json_to_top_bot(json const &j, T &top, T &bot) {
  if (j.contains("top")) {
    j.at("top").get_to(top);
  }
  if (j.contains("bot")) {
    j.at("bot").get_to(bot);
  }
}


class MyPanels
{
public:
    MyPanels();
    ~MyPanels();
    void initPanels();
};

#endif // MYPANELS_H
