#include "Distance_mission.hpp"

bool Distance_mission::is_completed()
{
    return false;
}

Distance_mission::Distance_mission(int id, pair<long, long> time_, long dis_, long reward_)
    : Mission(id, time_, reward_)
{
    this->min_dis = dis_;
}

Distance_mission::~Distance_mission()
{
}