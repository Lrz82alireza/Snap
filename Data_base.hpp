#pragma once

#include <Driver.hpp>
#include <Travel.hpp>
#include <Mission.hpp>

class Data_base
{
private:
    vector<Driver> drivers;
    vector<Travel *> travels;
    vector<Mission *> missions;

public:
    Data_base(/* args */);
    ~Data_base();
};

Data_base::Data_base(/* args */)
{
}

Data_base::~Data_base()
{
}
