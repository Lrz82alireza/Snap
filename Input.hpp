#pragma once

#include <stdexcept>

#include "Functions.hpp"

using namespace std;

class Input
{
public:
    void set();
    void clear();

    bool get_line();
    string* command_() { return &command; }
    vector<string>* value_() { return &value; }
private:
    string line;
    string command;
    vector<string> value;
};
