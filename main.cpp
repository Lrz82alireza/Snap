#include <iostream>
#include <vector>
#include <string>

#include <Input.hpp>

using namespace std;

int main()
{
    bool is_running = true;

    while (is_running)
    {
        try
        {
            /* code */
        }
        catch(exception& ex)
        {
            cout << ex.what() << '\n';
        }
        
    }
}