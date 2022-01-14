#ifndef PRIORITY_TABLE_HPP
#define PRIORITY_TABLE_HPP

#include <unordered_map>
#include <string>

std::unordered_map<std::string, const int> PRIORITY_TABLE = {
    {"H", 1},
    {"C", 12},
    {"N", 14},
    {"O", 16},
    {"F", 19},
    {"P", 31},
    {"S", 32},
    {"Cl", 35},
    {"Br", 79},
    {"I", 126}
};

#endif