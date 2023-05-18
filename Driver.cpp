#include "Driver.hpp"

void Driver::set_mission(const Mission *mission_)
{
    missions.push_back(mission_->clone());
}

Driver::Driver(int id)
{
    this->ID = id;
}

Driver::~Driver()
{
}
