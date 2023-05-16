#pragma once

#include <Functions.hpp>
#include <stdexcept>

using namespace std;

class Input
{
public:
    bool set_input()
    {
        string line;
        getline(cin, line);
        vector<string> temp = seperate_words(line, " ");

        if (temp.size() == 1)
        {
            cout << "" << endl;
            return false;
        }

        command = convert_command_to_code(temp[0]);

        for (int i = 1; i < temp.size(); i++)
            value.push_back(temp[i]);
        return true;
    }

    void input_clear()
    {
        int command = 0;
        value.clear();
    }

private:
    int command;
    vector<string> value;

    int convert_command_to_code(string);
}
