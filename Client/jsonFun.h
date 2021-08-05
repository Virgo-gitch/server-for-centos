#ifndef JSONFUN_H
#define JSONFUN_H
#include <string>
#include <nlohmann/json.hpp>
#include <chrono>
#include <date/date.h>
#include <QString>

using json = nlohmann::json;

typedef std::chrono::system_clock::time_point time_point;

struct config_info{

//    std::string name;
//    std::string ip;
    std::vector<std::string> kafkaIP;

    struct db_info{
        std::string jobs;
        std::string panels;
    };

    struct server_info{
        std::string vsbackup;
        std::string jobs;
        std::string res;
    };

    struct name_ip{
        std::string name;
        std::string ip;
    };

    struct slaves
    {
        std::vector<name_ip> top;
        std::vector<name_ip> bot;
    };

    db_info db;
    slaves s;
    server_info server;
//    slaves sv;

};



struct scanning_event {
    std::string slave;
    time_point timestamp;
};

struct scan_panel_info{

    int panel = 0;
    QString top;
    scanning_event se;

};



struct defect_id
{
    int defect_idx;
    int panel_num;
    bool top;
};

struct pos_defect
{
    int x1;
    int y1;
    int x2;
    int y2;
    std::vector<defect_id> defect_ids;
};

struct job_pos
{
    std::string job;
    pos_defect defects;
};

struct  defect_pos_warn
{
    struct job_pos_defect
    {
        std::string job;
        std::vector<pos_defect> pos;
    };

    std::vector<job_pos_defect> noti;
};



struct static_info {
    int panel_num;
    bool top;
    size_t start;
    size_t end;
    std::string job;
    std::string lot;
    int edge_x;
    int edge_y;
    int orient;
    int max_defs;
    int ee_version = -1;

    struct defect_info {
        std::string im_path;
        std::string txt_path;
        size_t cad_x;
        size_t cad_y;
        int defect_type;
    };

    // defect_idx, defect_info
    std::unordered_map<size_t, defect_info> defects;
};



struct scan_with_job
{
    std::string path;
    int angle;
    std::string point;
};

struct bank
{
  std::vector<std::string> jobs;
};



struct force_mode{

    std::string top_job;
    std::string bot_job;
    int top_orient;
    int bot_orient;
    bool enable;
};


struct warning_generator{
    bool enable;
    int last_n_panels;
    int number_defects_minimum;
};


struct parse_force_mode{

    struct top_info{
        std::string top_job;
        int top_orient=1;
    };

    struct bot_info{
        std::string bot_job;
        int bot_orient=1;
    };

    bool enabled = false;

    top_info ti;
    bot_info bi;

};


static int to_slave_number(int const panel_num)
{
    if (panel_num % 1000 == 0)
        return 1000;
    else
        return panel_num % 1000;
}


inline std::string  rescanMsg(int start, int end, bool top)
{
    json j;
    j["start"] = start;
    j["end"] = end;
    j["top"] = top;
    return j.dump();
}


inline std::string  rescanMsgJob(int start, int end, bool top, std::string job, int n)
{
    json j;
    j["start"] = start;
    j["end"] = end;
    j["top"] = top;
    j["job"] = job;
    j["orient"] = n;
    return j.dump();
}


inline  std::string stopScanMsg(int start, int end, bool top)
{
    json j;
    j["start"] = start;
    j["end"] = end;
    j["top"] = top;
    return j.dump();
}

inline std::string pauseScanMsg(bool pause)
{
    json j; 
    j["pause"] = pause;
    return j.dump();
}

inline std::string item_to_json(std::string name , int row)
{
    json j;
    j["name"] = name;
    j["row"] = row;
    return j.dump();
}

inline std::string job_bank_to_json(std::vector<std::string> bank)
{
    json j;
    j["bank"] = bank;
    return j.dump();
}


inline void string_to_timestamp(std::string const &timestamp, time_point &tp)
{
    std::stringstream ss{timestamp};
    ss >> date::parse("%D %T %Z", tp);
}

inline void from_json(json const &j, scanning_event &se)
{
    se.slave = j.at("slave").get<std::string>();
    string_to_timestamp(j.at("timestamp").get<std::string>(), se.timestamp);
}


inline void from_json(json const &j, bank &b)
{
    j.at("bank").get_to(b.jobs);
}


inline void from_json(json const& j, config_info::db_info &db)
{
    j.at("jobs").get_to(db.jobs);
    j.at("panels").get_to(db.panels);

}

inline void from_json(json const& j, config_info::server_info &server)
{
    j.at("vsbackup").get_to(server.vsbackup);
    j.at("jobs").get_to(server.jobs);
    j.at("res").get_to(server.res);
}

inline void from_json(json const& j, config_info::name_ip &ni)
{
    j.at("name").get_to(ni.name);
    j.at("IP").get_to(ni.ip);
}

inline void from_json(json const& j, config_info::slaves &sv)
{
    j.at("top").get_to(sv.top);
    j.at("bot").get_to(sv.bot);


}




inline void from_json(json const &j, config_info ci)
{
//    j.at("Kafka Brokers").get_to(ci.kafkaIP);
//    j.at("DB").get_to(ci.db);
//    j.at("name").get_to(ci.name);
//    j.at("IP").get_to(ci.ip);
}



inline void from_json(json const&j, defect_id &di)
{
    j.at("defect_idx").get_to(di.defect_idx);
    j.at("panel_num").get_to(di.panel_num);
    j.at("top").get_to(di.top);

}


inline void from_json(json const&j, pos_defect &pd)
{
    j.at("x1").get_to(pd.x1);
    j.at("y1").get_to(pd.y1);
    j.at("x2").get_to(pd.x2);
    j.at("y2").get_to(pd.y2);
    j.at("defect_ids").get_to(pd.defect_ids);
}


inline void from_json(json const& j, defect_pos_warn::job_pos_defect &jpd)
{
    j.at("job").get_to(jpd.job);
    j.at("positions").get_to(jpd.pos);
}


inline void from_json(json const& j, static_info::defect_info& d)
{

    j.at("im_path").get_to(d.im_path);
    j.at("txt_path").get_to(d.txt_path);
    j.at("cad_x").get_to(d.cad_x);
    j.at("cad_y").get_to(d.cad_y);
    j.at("type").get_to(d.defect_type);
}


inline void from_json(json const& j, static_info& s)
{

    j.at("panel").get_to(s.panel_num);
    j.at("top").get_to(s.top);
    j.at("start").get_to(s.start);
    j.at("end").get_to(s.end);
    j.at("job").get_to(s.job);
    j.at("lot").get_to(s.lot);
    j.at("edge_x").get_to(s.edge_x);
    j.at("edge_y").get_to(s.edge_y);
    j.at("orient").get_to(s.orient);
    j.at("max_defs").get_to(s.max_defs);
    j.at("ee_version").get_to(s.ee_version);
    j.at("defects").get_to(s.defects);
}


inline void from_json(json const&j, parse_force_mode::top_info &t)
{
    j.at("job").get_to(t.top_job);
    j.at("orient").get_to(t.top_orient);
}

inline void from_json(json const& j, parse_force_mode::bot_info &b)
{
    j.at("job").get_to(b.bot_job);
    j.at("orient").get_to(b.bot_orient);
}

inline void from_json(json const& j, parse_force_mode &m)
{
    j.at("top").get_to(m.ti);
    j.at("bot").get_to(m.bi);
    j.at("enabled").get_to(m.enabled);
}


inline void from_json(json const& j, warning_generator &wg)
{
    j.at("enabled").get_to(wg.enable);
    j.at("last_n_panels").get_to(wg.last_n_panels);
    j.at("number_defects_threshold").get_to(wg.number_defects_minimum);
}


inline void json_to_job(json const&j, scan_with_job& job)
{
    j.at("Name").get_to(job.path);
    j.at("Angle").get_to(job.angle);
    j.at("ContrastPoint").get_to(job.point);
}



inline std::string lot_to_json(std::string lot_name)
{
    json j;
    j["lot"] = lot_name;
    return j.dump();
}


inline std::string force_mode_to_json(force_mode mode)
{
    json j;
    j["top_job"] = mode.top_job;
    j["bot_job"] = mode.bot_job;
    j["top_orient"] = mode.top_orient;
    j["bot_orient"] = mode.bot_orient;
    j["enabled"] = mode.enable;
    return j.dump();
}

inline std::string force_mode_to_json(bool flag)
{
    json j;
    j["enabled"] = flag;
    return j.dump();
}


inline std::string warning_generator_to_json(warning_generator wg)
{
    json j;
    j["enabled"] = wg.enable;
    j["last_n_panels"] = wg.last_n_panels;
    j["number_defects_minimum"] = wg.number_defects_minimum;
    return j.dump();
}

inline std::string warning_generator_to_json(bool flag)
{
    json j;
    j["enabled"] = flag;
    return j.dump();
}


inline std::string job_file_to_json(std::string job, std::string set)
{
    json j;
    j["job"] = job;
    j["settings_file"] = set;
    return j.dump();
}


template <typename T>static void json_to_top_bot(json const &j, T &top, T &bot) {
  if (j.contains("top")) {
    j.at("top").get_to(top);
  }
  if (j.contains("bot")) {
    j.at("bot").get_to(bot);
  }
}



#endif // JSONFUN_H
