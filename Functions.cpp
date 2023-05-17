#include "Functions.hpp"

vector<string> seperate_words(const string line, string separate_char)
{
    vector<string> words;
    string temp = line;
    size_t pos = 0;
    while ((pos = temp.find(separate_char)) != string::npos)
    {
        words.push_back(temp.substr(0, pos));
        temp.erase(0, pos + separate_char.length());
    }
    words.push_back(temp);
    return words;
}

template <typename T>
T *find_by_id(int id, vector<T *> &Ts)
{
    for (typename vector<T *>::size_type i = 0; i < Ts.size(); i++)
    {
        if (Ts[i]->get_ID() == id)
            return missions[i];
    }
    return NULL;
}