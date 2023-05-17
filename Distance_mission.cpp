#include "Distance_mission.hpp"

Distance_mission::Distance_mission(int id, pair<long, long> time_, long dis_)
    : Mission(id, time_)
{
    this->min_dis = dis_;
}

Distance_mission::~Distance_mission()
{
}