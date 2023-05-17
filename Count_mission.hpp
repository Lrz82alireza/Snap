#pragma once

#include "Mission.hpp"

class Count_mission : public Mission
{
private:
    int min_count;
public:
    Count_mission(int id, pair<long, long> time_, int count_);
    ~Count_mission();
};
