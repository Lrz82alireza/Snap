#pragma once

#include <vector>
#include <functional>

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
    void record_ride(pair<long, long> &time_, const long &distance_);
    void show_missions_status();

    Driver(int id);
    ~Driver();
};

template <typename T>
void sort_by_id(vector<T *> &Ts);