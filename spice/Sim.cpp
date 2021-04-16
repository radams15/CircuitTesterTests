//
// Created by rhys on 16/04/2021.
//

#include "Sim.h"

#include <Eigen/Dense>


NodeHashTable Sim::mapNodes(vector<Component*>* components) {
    NodeHashTable out;

    out.addToNodes("0");

    for(Component* c : *components){
        c->high = out.addToNodes(c->high_str);
        c->low = out.addToNodes(c->low_str);
    }

    return out;
}

ABMatrix Sim::calculateMatrices(vector<Component*> *components, int nodeCount) {
    int g2Count;
    for(auto c : *components){
        if(c->id == VOLTAGE_SRC) g2Count++;
    }

    int matrixSize = nodeCount + g2Count - 1;

    auto* out = new ABMatrix{
            matrixA::Zero(matrixSize, matrixSize),
            matrixB::Zero(matrixSize)
    };

    int g2Index = matrixSize - g2Count;

    for(auto c : *components){
        long high = c->high;
        long low = c->low;

        double value = c->value;

        if(c->id == RESISTOR){
            if(high != 0){
                out->A(high - 1, high - 1) = out->A(high - 1, high - 1) + 1 / value;
            }

            if(low != 0){
                out->A(low - 1, low - 1) = out->A(low - 1, low - 1) + 1/value;
            }

            if(high != 0 && low != 0){
                out->A(high - 1, low - 1) = out->A(high - 1, low - 1) - 1/value;
                out->A(low - 1, high - 1) = out->A(low - 1, high - 1) - 1/value;
            }

        }else if(c->id == VOLTAGE_SRC){
            if(high != 0){
                out->A(high - 1, g2Index) = out->A(high - 1, g2Index) + 1;
                out->A(g2Index, high - 1) = out->A(g2Index, high - 1) + 1;
            }

            if(low != 0){
                out->A(low - 1, g2Index) = out->A(low - 1, g2Index) - 1;
                out->A(g2Index, low - 1) = out->A(g2Index, low - 1) - 1;
            }

            out->b(g2Index) = value;
            g2Index += 1;

        }else if(c->id == CURRENT_SRC){
            if(high != 0) {
                out->b(high - 1) = out->b(high - 1) - value;
            }

            if(low != 0){
                out->b(low - 1) = out->b(low - 1) + value;
            }
        }
    }

    return *out;
}

matrixB Sim::solveSystem(ABMatrix mat) {
    return mat.A.ldlt().solve(mat.b);
}
