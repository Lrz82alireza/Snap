#include "Count_mission.hpp"

bool Count_mission::is_completed(pair<long, long> &time_, long distance_)
{
    this->counted += 1;
    if (counted >= min_count)
        return true;
    return false;
}

Count_mission::Count_mission(int id, pair<long, long> time_, int count_, long reward_)
    : Mission(id, time_, reward_)
{
    this->min_count = count_;
}

Count_mission::~Count_mission()
{
}