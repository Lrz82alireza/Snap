#pragma once

#include "Mission.hpp"

class Distance_mission : public Mission
{
private:
    long min_dis;
public:
    Distance_mission(int id, pair<long, long> time_, long dis_);
    ~Distance_mission();
};