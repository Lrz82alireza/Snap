#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> seperate_words(const string line, string separate_char);

template <typename T>
T *find_by_id(int id, vector<T *> &Ts);