#pragma once

#include <vector>
#include <Travel.hpp>
#include <Mission.hpp>

using namespace std;

class Driver
{
private:
    int ID;
    vector<Mission *> missions;
    vector<Travel *> travels;

public:
    Driver(/* args */);
    ~Driver();
};

Driver::Driver(/* args */)
{
}

Driver::~Driver()
{
}
