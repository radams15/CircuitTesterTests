//
// Created by rhys on 18/04/2021.
//

#ifndef SPICE2_MNAELEMENT_H
#define SPICE2_MNAELEMENT_H

#include <cmath>
#include "Component.h"

class MNAElement {
private:

public:
    int n0;
    int n1;
    Component* comp;
    double value;
    double currentSolution;

    MNAElement(int n0, int n1, Component* comp, double value, double currentSolution=NAN);

    MNAElement withCurrentSolution(double newCurrentSolution);

    bool containsNode(int n);

    int getOppositeNode(int n);
};


#endif //SPICE2_MNAELEMENT_H
