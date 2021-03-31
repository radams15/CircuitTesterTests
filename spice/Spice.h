//
// Created by rhys on 19/01/2021.
//

#ifndef SPICE_SPICE_H
#define SPICE_SPICE_H

#include <string>
#include <vector>
#include "Component.h"

using namespace std;

class Spice {
private:

    vector<Component*> parse(string data);

public:
    Spice(string data);
    static Spice* fromFile(string fileName);
};


#endif //SPICE_SPICE_H
