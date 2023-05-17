#include <Data_base.hpp>

// Private functions

void Data_base::add_time_mission(const vector<string> *arguments)
{
    // check input

    int id = stoi((*arguments)[0]);
    pair<long, long> time(stol((*arguments)[1]), stol((*arguments)[2]));
    long min_time = stol((*arguments)[3]);

    Time_mission *temp = new Time_mission(id, time, min_time);
    this->missions.push_back(temp);
}

void Data_base::init_command_manager()
{
    command_manager[ADD_TIME_MISSION] = bind(&Data_base::add_time_mission, this, std::placeholders::_1);
}

// Public functions

void Data_base::manage_command(Input * input)
{
    this->command_manager[*(input->command_())](input->value_());
}