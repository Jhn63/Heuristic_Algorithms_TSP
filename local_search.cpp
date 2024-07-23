#include "local_search.h"

void VND(Solution &s) {
    std::vector<int> OP = {1,2,3};
    bool improved;

    while (!OP.empty()) {
        switch (OP.front()) {
            case 1:
                improved = best_swap(s);
                break;

            case 2:
                improved = best_two_opt(s);
                break;

            case 3:
                improved = best_oropt(s, 1);
                break;

            default:
                break;
        }
        if (improved)
            OP = {1,2,3};
        else
            OP.erase(OP.begin());
    }
}

void RVND(Solution &s) {
    std::vector<int> OP = {3};
    bool improved;

    while (!OP.empty()) {
        int n = rand() % OP.size();

        switch (OP[n]) {
            case 1:
                improved = best_swap(s);
                break;

            case 2:
                improved = best_two_opt(s);
                break;

            case 3:
                improved = best_oropt(s, 1);
                break;

            default:
                break;
        }

        if (improved)
            OP = {3};
        else
            OP.erase(OP.begin() + n);
    }
}


//to test
bool best_swap(Solution &s) {
    Data data = Data::getInstance();
    int i, j, best_i, best_j;
    double delta, best_delta = 0.0;
    bool improved = false;

    for (i = 1; i < data.n -1; i++) {
        for (j = i+1; j < data.n; j++) {
            
            delta = compute_swap(s,i,j);
            if (delta < best_delta) {
                best_i = i;
                best_j = j;
                best_delta = delta;
                improved = true;
            }
        }   
    }

    if (improved) {
        swap(s,best_i,best_j);
    }
    return improved;
}

//to test
bool best_two_opt(Solution &s) {
    Data data = Data::getInstance();
    int i, j, best_i, best_j;
    double delta, best_delta = 0.0;
    bool improved = false;

    for (i = 1; i < data.n -2; i++) {
        for (j = i+2; j < data.n; j++) {
            
            delta = compute_two_opt(s,i,j);
            if (delta < best_delta) {
                best_i = i;
                best_j = j;
                best_delta = delta;
                improved = true;
            }
        }   
    }

    if (improved) {
        two_opt(s,best_i,best_j);
    }
    return improved;
}

//to test
bool best_oropt(Solution &s, const int T) {
    Data data = Data::getInstance();
    int i, j, best_i, best_j;
    double delta, best_delta = 0.0;
    bool improved = false;

    for (i = 1; i <= data.n - T; i++) {
        for (j = 1; j <= data.n; j++) {
            
            delta = compute_oropt(s,i,j,T);
            if (delta < best_delta) {
                best_i = i;
                best_j = j;
                best_delta = delta;
                improved = true;
            }
        }   
    }

    if (improved) {
        oropt(s,best_i,best_j,T);
    }
    return improved;
}