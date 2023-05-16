#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Mission
{
private:
    pair<long, long> time;
    int ID;

public:
    Mission(int id, pair<long, long> time_);
    ~Mission();
};

Mission::Mission(int id, pair<long, long> time_)
{
    this->ID = id;
    this->time = time_; 
}

Mission::~Mission()
{
}
