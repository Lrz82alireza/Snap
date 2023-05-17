#include "Mission.hpp"

Mission::Mission(int id, pair<long, long> time_, long reward_)
{
    this->ID = id;
    this->time = time_; 
    this->reward = reward_;
}

Mission::~Mission()
{
}
