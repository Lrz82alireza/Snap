#pragma once

#include "Mission.hpp"

class Count_mission : public Mission
{
private:
    int min_count;
public:
    virtual bool is_completed();

    Count_mission(int id, pair<long, long> time_, int count_, long reward_);
    ~Count_mission();
};
