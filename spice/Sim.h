//
// Created by rhys on 16/04/2021.
//

#ifndef SPICE_SIM_H
#define SPICE_SIM_H

#include <vector>

#include <Eigen/Core>

#include "NodeHashTable.h"
#include "Component.h"

using namespace std;

typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> matrixA;
typedef Eigen::Matrix<double, Eigen::Dynamic, 1> matrixB;

struct ABMatrix{
    matrixA A;
    matrixB b;
};

class Sim {
private:

public:
    NodeHashTable mapNodes(vector<Component*>* components);

    ABMatrix calculateMatrices(vector<Component*>* components, int nodeCount);

    matrixB solveSystem(ABMatrix mat);
};


#endif //SPICE_SIM_H
