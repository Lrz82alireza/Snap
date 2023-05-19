#include "Driver.hpp"

void Driver::set_mission(const Mission *mission_)
{
    missions.push_back(mission_->clone());
}

void Driver::record_ride(pair<long, long> &time_, const long &distance_)
{
    if (missions.size() == 0)
        return;

    sort_by_id<Mission>(missions);

    cout << "completed missions for driver " << this->ID << ":" << endl;

    for (auto mission_ : missions)
    {
        if (!mission_->has_timestamp(time_))
            continue;
        if (mission_->is_completed(time_, distance_))
        {
            mission_->status = true;
            mission_->print();
            cout << endl;
        }
    }
}

void Driver::show_missions_status()
{
    if (missions.size() == 0)
        throw runtime_error("DRIVER_MISSION_NOT_FOUND");

    sort_by_id<Mission>(missions);

    cout << "missions status for driver " << this->ID << endl;
    for (auto mission_ : missions)
    {
        mission_->print();
        cout << "status: ";
        if (mission_->status)
            cout << "completed" << endl;
        else
            cout << "ongoing" << endl;
        cout << endl;
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
    sort(Ts.begin(), Ts.end(), [](T *t1, T *t2) {
        return t1->get_ID() < t2->get_ID();
    });
}