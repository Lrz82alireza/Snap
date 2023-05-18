#pragma once

#include <vector>

#include "Travel.hpp"
#include "Mission.hpp"
#include "Functions.hpp"

using namespace std;

class Driver
{
private:
    int ID;
    vector<Mission *> missions;
    vector<Travel *> travels;

public:
    int get_ID() { return ID; }
    const vector<Mission *> &get_missions() { return missions; }
    void set_mission(const Mission * mission_);

    Driver(int id);
    ~Driver();
};

