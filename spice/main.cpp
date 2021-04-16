#include <iostream>

#include "Sim.h"
#include "Components/Resistor.h"

int main() {
    Sim s;

    vector<Component*> components;

    components.push_back(new Resistor("1", "2", 4));
    components.push_back(new Resistor("2", "0", 2));
    components.push_back(new Component(VOLTAGE_SRC, "V", "1", "0", 3));
    components.push_back(new Component(CURRENT_SRC, "I", "0", "2", 2));

    NodeHashTable nodeHashTable = s.mapNodes(&components);

    ABMatrix abm = s.calculateMatrices(&components, nodeHashTable.nodeCount);

    matrixB solved = s.solveSystem(abm);

    for(auto it : nodeHashTable.nodes){
        cout << "\"" << it.first << "\": " << it.second << endl;
    }

    cout << endl << endl;

    for(auto c : components){
        cout << c->str() << endl;
    }

    cout << endl;

    cout << abm.A << endl << endl;

    cout << abm.b << endl << endl;

    cout << solved << endl;

    return 0;
}
