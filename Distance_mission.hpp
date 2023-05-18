#pragma once

#include "Mission.hpp"

class Distance_mission : public Mission
{
private:
    long min_dis;

public:
    virtual bool is_completed();

    virtual Distance_mission *clone() const { return new Distance_mission(*this); }
    Distance_mission(int id, pair<long, long> time_, long dis_, long reward_);
    ~Distance_mission();
};