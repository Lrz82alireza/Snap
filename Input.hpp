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

        int int_command = read_command_convert_to_int(temp[0]);
        command = int_command;
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
};
