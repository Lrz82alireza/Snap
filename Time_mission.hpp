#pragma once

#include "Mission.hpp"

class Time_mission : public Mission
{
private:
    long min_time;

public:
    Time_mission(int id, pair<long, long> time_, long min_time_, long reward_);
    ~Time_mission();
    virtual bool is_completed();

    virtual Time_mission * clone() const { return new Time_mission(*this); }
};


