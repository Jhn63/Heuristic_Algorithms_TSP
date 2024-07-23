#include "neighborhood.h"

void swap(Solution &s, int i, int j) {
    std::vector<int>::iterator it1, it2;
    s.cost += compute_swap(s,i,j);
    
    it1 = s.route.begin() + i;
    it2 = s.route.begin() + j;
    std::swap(*it1, *it2);
}

double compute_swap(Solution &s, int i, int j) {
    Data data = Data::getInstance();
    double to_sum, to_sub;

    if (i+1 == j) {
        to_sub = data.matrizAdj[s.route[i]][s.route[i-1]] + data.matrizAdj[s.route[j]][s.route[j+1]];

        to_sum = data.matrizAdj[s.route[j]][s.route[i-1]] + data.matrizAdj[s.route[j+1]][s.route[i]];
        return to_sum - to_sub;
    }

    to_sub = data.matrizAdj[s.route[i]][s.route[i+1]] + data.matrizAdj[s.route[i]][s.route[i-1]]
            + data.matrizAdj[s.route[j]][s.route[j+1]] + data.matrizAdj[s.route[j]][s.route[j-1]];

    to_sum = data.matrizAdj[s.route[i+1]][s.route[j]] + data.matrizAdj[s.route[j]][s.route[i-1]]
            + data.matrizAdj[s.route[j+1]][s.route[i]] + data.matrizAdj[s.route[i]][s.route[j-1]];

    return to_sum - to_sub;
}

void two_opt(Solution &s, int i, int j) {
    std::vector<int>::iterator it1, it2;
    s.cost += compute_two_opt(s,i,j);
    
    it1 = s.route.begin() + i;
    it2 = s.route.begin() + j;
    std::reverse(it1, it2 + 1);
}

double compute_two_opt(Solution &s, int i, int j) {
    Data data = Data::getInstance();
    double to_sum, to_sub;

    to_sub = data.matrizAdj[s.route[i]][s.route[i-1]] + data.matrizAdj[s.route[j]][s.route[j+1]];
    to_sum = data.matrizAdj[s.route[i]][s.route[j+1]] + data.matrizAdj[s.route[j]][s.route[i-1]];

    return to_sum - to_sub;
}

void oropt(Solution &s, int i, int j, int size) {
    if (j <= i + size && j >= i) return;
    
    std::vector<int> aux(size);
    s.cost += compute_oropt(s,i,j,size);

    std::copy(s.route.begin() + i, s.route.begin() + i + size, aux.begin());
    s.route.erase(s.route.begin() + i, s.route.begin() + i + size);

    (i > j) ?
        s.route.insert(s.route.begin() + j, aux.begin(), aux.end()):
        s.route.insert(s.route.begin() + j - size, aux.begin(), aux.end());
}

double compute_oropt(Solution &s, int i, int j, int size) {
    Data data = Data::getInstance();
    double to_sum, to_sub;
    int i_ps = i + (size - 1);

    if (j <= i_ps + 1 && j >= i)
        return 0;
    
    to_sub = data.matrizAdj[s.route[i]][s.route[i-1]] + data.matrizAdj[s.route[i_ps]][s.route[i_ps + 1]]
            + data.matrizAdj[s.route[j]][s.route[j-1]];

    to_sum = data.matrizAdj[s.route[i - 1]][s.route[i_ps + 1]] + data.matrizAdj[s.route[i]][s.route[j-1]]
            + data.matrizAdj[s.route[i_ps]][s.route[j]];

    return to_sum - to_sub;
}

//always suppose j is a position greater and i_end
void double_bridge(Solution &s, int i, int i_end, int j, int j_end) {
    std::vector<int> aux_i(i_end - i), aux_j(j_end - j);
    s.cost += compute_double_bridge(s,i,i_end,j,j_end);

    std::copy(s.route.begin() + i, s.route.begin() + i_end, aux_i.begin());
    std::copy(s.route.begin() + j, s.route.begin() + j_end, aux_j.begin());

    s.route.erase(s.route.begin() + j, s.route.begin() + j_end);
    s.route.insert(s.route.begin() + j, aux_i.begin(), aux_i.end());

    s.route.erase(s.route.begin() + i, s.route.begin() + i_end);
    s.route.insert(s.route.begin() + i, aux_j.begin(), aux_j.end());
}

double compute_double_bridge(Solution &s, int i, int i_end, int j, int j_end) {
    Data data = Data::getInstance();
    double to_sum, to_sub;

    if (i_end == j) {
        to_sub = data.matrizAdj[s.route[i]][s.route[i - 1]] + data.matrizAdj[s.route[i_end - 1]][s.route[j]]
                + data.matrizAdj[s.route[j_end]][s.route[j_end - 1]];

        to_sum = data.matrizAdj[s.route[i - 1]][s.route[j]] + data.matrizAdj[s.route[j_end - 1]][s.route[i]]
                + data.matrizAdj[s.route[i_end - 1]][s.route[j_end]];

        return to_sum - to_sub;
    }
    to_sub = data.matrizAdj[s.route[i]][s.route[i - 1]] + data.matrizAdj[s.route[i_end]][s.route[i_end - 1]]
            + data.matrizAdj[s.route[j]][s.route[j - 1]] + data.matrizAdj[s.route[j_end]][s.route[j_end - 1]];
    
    to_sum = data.matrizAdj[s.route[i - 1]][s.route[j]] + data.matrizAdj[s.route[j_end - 1]][s.route[i_end]]
            + data.matrizAdj[s.route[j - 1]][s.route[i]] + data.matrizAdj[s.route[i_end - 1]][s.route[j_end]];

    return to_sum - to_sub;
}