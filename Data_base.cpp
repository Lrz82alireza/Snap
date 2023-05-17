#include "Data_base.hpp"

// Private functions

// ADD_MISSION
Arg_add Data_base::make_add_arg(const vector<string> *arguments)
{
    Arg_add arg;

    arg.id = stoi((*arguments)[MISSION_ID_ADD]);
    arg.time_ = {stol((*arguments)[START_TIME_ADD]), stol((*arguments)[END_TIME_ADD])};
    arg.target = stol((*arguments)[TARGET_ADD]);
    arg.reward = stol((*arguments)[REWARD_ADD]);

    return arg;
}

void Data_base::check_add_arg(const vector<string> *arguments)
{
    if ((*arguments).size() != ADD_ARG_NUM)
        throw runtime_error("INVALID_ARGUMENTS");

    int id = stoi((*arguments)[MISSION_ID_ADD]);
    if (find_by_id<Mission>(id, this->missions) != NULL)
        throw runtime_error("DUPLICATE_MISSION_ID");

    pair<long, long> time_(stol((*arguments)[START_TIME_ADD]), stol((*arguments)[END_TIME_ADD]));

    if (!is_time_valid(&time_))
        throw runtime_error("INVALID_ARGUMENTS");

    long reward = stol((*arguments)[REWARD_ADD]);

    if (reward < 0)
        throw runtime_error("INVALID_ARGUMENTS");
}

void Data_base::add_time_mission(const vector<string> *arguments)
{
    this->add_mission<Time_mission>(arguments);

    cout << "OK" << endl;
}

void Data_base::add_distance_mission(const vector<string> *arguments)
{
    this->add_mission<Distance_mission>(arguments);

    cout << "OK" << endl;
}

void Data_base::add_count_mission(const vector<string> *arguments)
{
    this->add_mission<Count_mission>(arguments);

    cout << "OK" << endl;
}

template <typename T>
void Data_base::add_mission(const vector<string> *arguments)
{
    this->check_add_arg(arguments);

    Arg_add arg = make_add_arg(arguments);

    T *temp = new T(arg.id, arg.time_, arg.target, arg.reward);
    this->missions.push_back(temp);
}

// Accessories

void Data_base::assign_mission(const vector<string> *arguments)
{
}

void Data_base::check_assign_arg(const vector<string> *arguments)
{
    if ((*arguments).size() != ASSIGN_ARG_NUM)
        throw runtime_error("INVALID_ARGUMENTS");

    int mission_id = stoi((*arguments)[MISSION_ID_ASSIGN]);
    Mission *mission_ = find_by_id<Mission>(mission_id, this->missions);
    if (mission_ == NULL)
        throw runtime_error("MISSION_NOT_FOUND");

    int driver_id = stoi((*arguments)[DRIVER_ID_ASSIGN]);
    Driver *driver_ = find_by_id<Driver>(driver_id, this->drivers);
    if (driver_ == NULL)
        driver_ = new Driver(driver_id);

    
}

void Data_base::init_command_manager()
{
    command_manager[ADD_TIME_MISSION] = bind(&Data_base::add_time_mission, this, std::placeholders::_1);
    command_manager[ADD_DISTANCE_MISSION] = bind(&Data_base::add_distance_mission, this, std::placeholders::_1);
    command_manager[ADD_COUNT_MISSION] = bind(&Data_base::add_count_mission, this, std::placeholders::_1);

    command_manager[ASSIGN_MISSION] = bind(&Data_base::assign_mission, this, std::placeholders::_1);
}

bool Data_base::is_time_valid(const pair<long, long> *time_)
{
    if (time_->second <= time_->first)
        return false;
    if (time_->first < 0 || time_->second < 0)
        return false;
    return true;
}

// Public functions

void Data_base::manage_command(Input *input)
{
    this->command_manager[*(input->command_())](input->value_());
}

// constructors

Data_base::Data_base(/* args */)
{
    this->init_command_manager();
}

Data_base::~Data_base()
{
    for (vector<Mission *>::size_type i = 0; i < this->missions.size(); i++)
        delete missions[i];
}