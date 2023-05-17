#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Travel
{
private:
    pair<long, long> time;
    int driver_ID;
    long distance;

public:
    int get_ID() { return driver_ID; }

    Travel(/* args */);
    ~Travel();
};


