#include "Driver.hpp"

void Driver::set_mission(const Mission *mission_)
{
    missions.push_back(mission_->clone());
}

void Driver::record_ride(const pair<long, long> &time_, const long &distance_)
{
    sort_by_id<Mission>(missions);

    for (auto mission_ : missions)
    {
        if (mission_->is_completed())
        {

        }
    }
}

Driver::Driver(int id)
{
    this->ID = id;
}

Driver::~Driver()
{
}


template <typename T>
void sort_by_id(vector<T *> &Ts)
{
    sort(Ts.begin(), Ts.end(), [](const T *t1, const T *t2) {
        return t1->get_ID() < t2->get_ID();
    });
}