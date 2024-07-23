#ifndef SOLUTION_H_
#define SOLUTION_H_

#include <vector>
#include <iostream>
#include <algorithm>

#include "data.h"

struct Solution {
    std::vector<int> route;
    double cost;

    Solution(int n) : route(std::vector<int>(n + 1)), cost(0) {};
    Solution() : route(std::vector<int>(Data::getInstance().n + 1)), cost(0) {};

    void print();
    double compute_route();
};

#endif