#include <iostream>

#include "MNAElement.h"
#include "MNACircuit.h"

int main() {
    auto bat = new MNAElement(0, 1, nullptr, 4);
    auto res = new MNAElement(1,0, nullptr, 4);

    auto cir = new MNACircuit({bat}, {res}, {});

    std::map<int, double> vmap = {{0, 0.0}, {1, 4.0}};

    auto dessol = new MNASolution(vmap, {bat});

    auto sol = cir->solve();

    if(sol->approxEquals(*dessol)){
        std::cout << "Good\n";
    }

    return 0;
}
