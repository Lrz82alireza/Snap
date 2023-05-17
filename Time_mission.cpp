#include "Time_mission.hpp"

bool Time_mission::is_completed()
{
    cout << "fuck" << endl;
    return false;
}

Time_mission::Time_mission(int id, pair<long, long> time_, long min_time_)
    : Mission(id, time_)
{
    this->min_time = min_time_;
}

Time_mission::~Time_mission()
{
}