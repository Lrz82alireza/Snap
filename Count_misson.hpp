#pragma once

#include <Mission.hpp>

class Count_misson : public Mission
{
private:
    int min_count;
public:
    Count_misson(int id, pair<long, long> time_, int count_);
    ~Count_misson();
};

Count_misson::Count_misson(int id, pair<long, long> time_, int count_)
    : Mission(id, time_)
{
    this->min_count = count_;
}

Count_misson::~Count_misson()
{
}
