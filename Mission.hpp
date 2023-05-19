#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Mission
{
private:
    pair<long, long> time;
    int ID;
    long reward;

public:
    bool status = false;

    int get_ID() { return ID; }
    pair<long, long> get_time() { return time; }

    void print();
    bool has_timestamp(const pair<long, long> &time_);
    virtual Mission * clone() const = 0;

    Mission(int id, pair<long, long> time_, long reward_);

    virtual ~Mission();
    virtual bool is_completed(pair<long, long> &time_, long distance_) = 0;
};

