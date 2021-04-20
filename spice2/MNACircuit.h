//
// Created by rhys on 18/04/2021.
//

#ifndef SPICE2_MNACIRCUIT_H
#define SPICE2_MNACIRCUIT_H

#include <vector>
#include <map>
#include <string>

#include "MNAElement.h"
#include "Equation.h"
#include "MNASolution.h"

class MNACircuit {
private:

public:
    std::vector<MNAElement*> batteries;
    std::vector<MNAElement*> resistors;
    std::vector<MNAElement*> currentSources;

    std::vector<MNAElement*> elements;

    std::map<int, int> nodeSet;
    int nodeCount;
    std::vector<int> nodes;

    MNACircuit(std::vector<MNAElement*> batteries, std::vector<MNAElement*> resistors, std::vector<MNAElement*> currentSources);

    int getCurrentCount();

    int getNumVars();
    double getCurrentSourceTotal(int nodeIndex);

    std::vector<Term*>* getCurrentTerms(int node, int side, int sign);

    std::vector<int>* getReferenceNodeIds();

    std::vector<int>* getConnectedNodeIds(int node);

    std::vector<Equation*>* getEquations();

    std::vector<UnknownCurrent*>* getUnknownCurrents();

    int getIndexByEquals(std::vector<Unknown*>* array, Unknown* element);

    MNASolution* solve();
};


#endif //SPICE2_MNACIRCUIT_H
