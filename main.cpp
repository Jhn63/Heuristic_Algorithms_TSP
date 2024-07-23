#include "meta_heuristic.h"
#include <time.h>

int main() {
    
    char *argv[2];

    argv[0] = (char *) "TSP";
    argv[1] = (char *) "instancias/burma14.tsp";

    Data & data = Data::getInstance();
    data.read(2, argv);

    srand(time(NULL));
    
    Solution s = ILS(10,15);

    s.print();

    std::cout << "\n\ndefinitive = " << s.compute_route();
}