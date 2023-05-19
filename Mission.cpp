#include "Mission.hpp"

void Mission::print()
{
    cout << "mission " << this->ID << ":"<< endl <<
    "start timestamp: " << this->time.first << endl <<
    "end timestamp: " << this->time.second << endl <<
    "reward: " << this->reward << endl;
}

bool Mission::has_timestamp(const pair<long, long> &time_)
{
    if (this->time.first <= time_.first &&
        this->time.second >= time_.second)
        return true;
    return false;
}

Mission::Mission(int id, pair<long, long> time_, long reward_)
{
    this->ID = id;
    this->time = time_; 
    this->reward = reward_;
}

Mission::~Mission()
{
}
