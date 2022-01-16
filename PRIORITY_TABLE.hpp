#ifndef PRIORITY_TABLE_HPP
#define PRIORITY_TABLE_HPP

#include <unordered_map>
#include <string>

// PRIORITY_TABLE maps atomic symbols to their priorities (atomic masses)
std::unordered_map<std::string, int> PRIORITY_TABLE = {
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