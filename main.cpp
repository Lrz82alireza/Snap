#include <iostream>
#include <vector>
#include <string>

#include <Data_base.hpp>

using namespace std;

int main()
{
    Input input;
    Data_base data_base;

    while (input.is_running_())
    {
        try
        {
            input.set();
            data_base.manage_command(&input);
        }
        catch(exception& ex)
        {
            cout << ex.what() << '\n';
        }
        input.clear();
    }
}