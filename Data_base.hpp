#pragma once

#include <map>
#include <functional>

#include "Input.hpp"
#include "Driver.hpp"
#include "Travel.hpp"
#include "Time_mission.hpp"
#include "Distance_mission.hpp"
#include "Count_mission.hpp"
#include "Mission.hpp"

// add_arguments_placement
enum
{
    MISSION_ID_ADD,
    START_TIME_ADD,
    END_TIME_ADD,
    TARGET_ADD,
    REWARD_ADD
};

// assign_arguments_placement
enum
{
    MISSION_ID_ASSIGN,
    DRIVER_ID_ASSIGN
};

// record_arguments_placement
enum
{
    START_TIME_REC,
    END_TIME_REC,
    DRIVER_ID_REC,
    DISTANCE_REC
};

// show_mission_status argument placement
enum
{
    DRIVER_ID_SHOW,
};

const int ADD_ARG_NUM = 5;
const int ASSIGN_ARG_NUM = 2;
const int REC_ARG_NUM = 4;
const int SHOW_ARG_NUM = 1;

const string ADD_TIME_MISSION = "add_time_mission";
const string ADD_DISTANCE_MISSION = "add_distance_mission";
const string ADD_COUNT_MISSION = "add_count_mission";
const string ASSIGN_MISSION = "assign_mission";
const string RECORD_RIDE = "record_ride";
const string SHOW_MISSIONS_STATUS = "show_missions_status";

//////////////////////////////////////////////////////
typedef void (*command_func)(vector<string>); ////////
//////////////////////////////////////////////////////

typedef struct ARG_ASSIGN
{
    int mission_id;
    int driver_id;
} Arg_assign;

typedef struct ARG_ADD
{
    int id;
    pair<long, long> time_;
    long target;
    long reward;
} Arg_add;

typedef struct ARG_REC
{
    int driver_id;
    pair<long, long> time_;
    long distance;
}Arg_rec;


class Data_base
{
private:
    vector<Driver *> drivers;
    vector<Mission *> missions;

    map<string, function<void(const vector<string> *)>> command_manager;
    void init_command_manager();

    bool is_time_valid(const pair<long, long> *time_);

    // ADD_MISSION
    Arg_add make_add_arg(const vector<string> *arguments);
    void check_add_arg(const vector<string> *arguments);
    void add_time_mission(const vector<string> *arguments);
    void add_distance_mission(const vector<string> *arguments);
    void add_count_mission(const vector<string> *arguments);
    template <typename T>
    void add_mission(const vector<string> *arguments);

    // ASSIGN_MISSION
    Arg_assign make_assign_arg(const vector<string> *arguments);
    void assign_mission(const vector<string> *arguments);
    void check_assign_arg(const vector<string> *arguments);

    // RECORD_RIDE
    Arg_rec make_record_arg(const vector<string> *arguments);
    void record_ride(const vector<string> *arguments);
    void check_record_arg(const vector<string> *arguments);

    // SHOW_MISSION_STATUS
    void check_show_arg(const vector<string> *arguments);
    void show_missions_status(const vector<string> *arguments);
    
    template <typename T>
    T *find_by_id(int id,const vector<T *> &Ts);

public:
    void manage_command(Input *input);

    Data_base(/* args */);
    ~Data_base();
};
