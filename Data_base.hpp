#pragma once

#include <map>
#include <functional>

#include "Driver.hpp"
#include "Travel.hpp"
#include "Time_mission.hpp"
#include "Mission.hpp"
#include "Input.hpp"

const string ADD_TIME_MISSION = "add_time_mission";
const string ADD_DISTANCE_MISSION = "ADD_DISTANCE_MISSION";
const string ADD_COUNT_MISSION = "ADD_COUNT_MISSION";
const string ASSIGN_MISSION = "ASSIGN_MISSION";
const string RECORD_RIDE = "RECORD_RIDE";
const string SHOW_MISSIONS_STATUS = "SHOW_MISSIONS_STATUS";

//////////////////////////////////////////////////////
typedef void (*command_func)(vector<string>); ////////
//////////////////////////////////////////////////////

class Data_base
{
private:
    vector<Driver> drivers;
    vector<Travel *> travels;
    vector<Mission *> missions;

    map<string, function<void(const vector<string> *)>> command_manager;
    void init_command_manager();

    void add_time_mission(const vector<string> *arguments);

public:
    void manage_command(Input * input);

    Data_base(/* args */);
    ~Data_base();
};


