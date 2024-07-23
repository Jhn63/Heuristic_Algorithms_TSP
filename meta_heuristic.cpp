#include "meta_heuristic.h"

Solution ILS(const int CT_ITER, const int LS_ITER) {
    Data data = Data::getInstance();
    Solution definitive, best, s;
    int iter, ls_iter;

    definitive.cost = __DBL_MAX__;
    for (iter = 0; iter < CT_ITER; iter++) {
        s = Greedy(rand() % data.n + 1);

        best = s;
        for (ls_iter = 0; ls_iter < LS_ITER; ls_iter++) {

            RVND(s);
            if (s.cost < best.cost) {
                
                best = s;
                ls_iter = 0;
            }
            double_bridge(s,3,7,8,10);
        }

        if (best.cost < definitive.cost)
            
            definitive = best;
    }
    return definitive;
}