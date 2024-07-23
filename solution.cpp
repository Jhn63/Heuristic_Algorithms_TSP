#include "solution.h"

void Solution::print() {
    int i;
    for (i = 0; i < route.size() -1; i++)
        std::cout << route[i] << " - ";
    std::cout << route[i] << "\n\n";

    std::cout << "cost = " << cost << "\n";
}

double Solution::compute_route() {
    Data data = Data::getInstance();
    double cost = 0;
    for (int i = 1; i < route.size(); i++) {
        cost += data.matrizAdj[route[i]][route[i-1]];
    }
    return cost;
}