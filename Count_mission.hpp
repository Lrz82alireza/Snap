#pragma once

#include "Mission.hpp"

class Count_mission : public Mission
{
private:
    int min_count;
    int counted = 0;
public:
    virtual bool is_completed(pair<long, long> &time_, long distance_);

    virtual Count_mission * clone() const { return new Count_mission(*this); }
    Count_mission(int id, pair<long, long> time_, int count_, long reward_);
    ~Count_mission();
};
