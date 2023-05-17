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
    bool status = false;

public:
    int get_ID() { return ID; }

    Mission(int id, pair<long, long> time_, long reward_);
    ~Mission();
    virtual bool is_completed() = 0;
};

