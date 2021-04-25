#include <iostream>

#include "MNAElement.h"
#include "MNACircuit.h"

int main() {
    auto bat1 = new MNAElement(0, 1, nullptr, -4);
    auto bat2 = new MNAElement(1, 2, nullptr, -4);
    auto res = new MNAElement(2,0, nullptr, 2);

    auto cir = new MNACircuit({bat1, bat2}, {res}, {});

    std::map<int, double> vmap = {
            {0, 0.0},
            {1, -4.0},
            {2, -8.0},
    };

    auto dessol = new MNASolution(vmap, {bat1->withCurrentSolution(-4), bat2->withCurrentSolution(-4)});

    auto sol = cir->solve();

    if(sol->approxEquals(*dessol)){
        std::cout << "Good\n";
    }else{
        std::cout << "Bad!\n";
    }

    for(auto v : sol->nodeVoltages){
        std::cout << v.first << ": " << v.second << std::endl;
    }

    return 0;
}
