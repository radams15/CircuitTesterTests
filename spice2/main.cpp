#include <iostream>

#include "MNAElement.h"
#include "MNACircuit.h"

int main() {
    auto bat = new MNAElement(0, 1, nullptr, 9);
    auto res1 = new MNAElement(1, 0, nullptr, 5);
    auto res2 = new MNAElement(1, 0, nullptr, 10);
    //auto res3 = new MNAElement(2, 0, nullptr, 7);

    auto cir = new MNACircuit({bat}, {res1, res2}, {});
    
    auto sol = cir->solve();

    std::cout << bat->currentSolution << " A" << std::endl;
    std::cout << bat->value << " V" << std::endl << std::endl;

    for(auto c : {res1, res2}){
        std::cout << sol->getCurrentForResistor(*c) << " A" << std::endl;
        std::cout << sol->getVoltage(*c) << " V" << std::endl << std::endl;
    }

    return 0;
}
