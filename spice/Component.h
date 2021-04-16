//
// Created by rhys on 19/01/2021.
//

#ifndef SPICE_COMPONENT_H
#define SPICE_COMPONENT_H

#include <string>
#include <vector>
#include <sstream>
#include "Components.h"

using namespace std;

class Component{
protected:


public:
    string name;
    Components id;

    string high_str;
    string low_str;

    long high = -1;
    long low = -1;

    double value;

    Component(Components id, string name, string high_str, string low_str, double value);

    string getName();

    string str();
};

#endif //SPICE_COMPONENT_H
