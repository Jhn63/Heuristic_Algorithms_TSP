#include "construtive.h"

// 0 < init <= data.n
Solution Greedy(int init) {
    Data data = Data::getInstance();
    Solution s = Solution();
    double insert, best_insert;
    int i, j, best_j;

    std::vector<int> vtx(data.n);
    std::iota(vtx.begin(), vtx.end(), 1);

    s.route[0] = init;
    vtx.erase(vtx.begin() + init - 1);

    for (i = 1; i < data.n; i++) {
        best_insert = __DBL_MAX__;
        
        for (j = 0; j < vtx.size(); j++) {

            insert = data.matrizAdj[s.route[i-1]][vtx[j]];

            if (insert < best_insert) {
                best_j = j;
                best_insert = insert;
            }
        }

        s.route[i] = vtx[best_j];
        s.cost += data.matrizAdj[s.route[i]][s.route[i - 1]];
        vtx.erase(vtx.begin() + best_j);
    }
    s.route[i] = init;
    s.cost += data.matrizAdj[s.route[i]][s.route[i - 1]];

    return s;
}