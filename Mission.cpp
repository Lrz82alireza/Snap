#include "Mission.hpp"

Mission::Mission(int id, pair<long, long> time_)
{
    this->ID = id;
    this->time = time_; 
}

Mission::~Mission()
{
}
