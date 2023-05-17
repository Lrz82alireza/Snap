#include "Count_mission.hpp"

Count_mission::Count_mission(int id, pair<long, long> time_, int count_)
    : Mission(id, time_)
{
    this->min_count = count_;
}

Count_mission::~Count_mission()
{
}