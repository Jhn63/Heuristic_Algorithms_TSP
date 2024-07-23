#ifndef LOCAL_SEARCH_H_
#define LOCAL_SEARCH_H_

#include "solution.h"
#include "neighborhood.h"

void VND(Solution &s);
void RVND(Solution &s);

bool best_swap(Solution &s);
bool best_two_opt(Solution &s);
bool best_oropt(Solution &s, const int T);

#endif