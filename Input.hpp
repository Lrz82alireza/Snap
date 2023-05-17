#pragma once

#include <stdexcept>

#include "Functions.hpp"

using namespace std;

class Input
{
public:
    void set()
    {
        string line;
        getline(cin, line);
        if (line == "")
            return; ////////////////////////////

        vector<string> temp = seperate_words(line, " ");

        if (temp.size() == 1)
            throw runtime_error("INVALID_ARGUMENTS");

        command = temp[0];

        for (int i = 1; i < temp.size(); i++)
            value.push_back(temp[i]);
    }

    void clear()
    {
        command.clear();
        value.clear();
    }

    bool is_running_() { return is_running; }
    string* command_() { return &command; }
    vector<string>* value_() { return &value; }

private:
    string command;
    vector<string> value;
    bool is_running = true;
};
