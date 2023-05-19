#pragma once

#include "Mission.hpp"

class Distance_mission : public Mission
{
private:
    long min_dis;
    long passed_dis = 0;
public:
    virtual bool is_completed(pair<long, long> &time_, long distance_);

    virtual Distance_mission *clone() const { return new Distance_mission(*this); }
    Distance_mission(int id, pair<long, long> time_, long dis_, long reward_);
    ~Distance_mission();
};