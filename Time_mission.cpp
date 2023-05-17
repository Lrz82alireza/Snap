#include "Time_mission.hpp"

bool Time_mission::is_completed()
{
    return false;
}

Time_mission::Time_mission(int id, pair<long, long> time_, long min_time_, long reward_)
    : Mission(id, time_, reward_)
{
    this->min_time = min_time_;
}

Time_mission::~Time_mission()
{
}