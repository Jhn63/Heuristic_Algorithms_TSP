#ifndef NEIGHBORHOOD_H_
#define NEIGHBORHOOD_H_

#include "solution.h"

void swap(Solution &s, int i, int j);
double compute_swap(Solution &s, int i, int j);

void two_opt(Solution &s, int i, int j);
double compute_two_opt(Solution &s, int i, int j);

void oropt(Solution &s, int i, int j, int size);
double compute_oropt(Solution &s, int i, int j, int size);

void double_bridge(Solution &s, int i, int i_end, int j, int j_end);
double compute_double_bridge(Solution &s, int i, int i_end, int j, int j_end);

#endif