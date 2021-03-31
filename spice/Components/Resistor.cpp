//
// Created by rhys on 19/01/2021.
//

#include "Resistor.h"


Resistor::Resistor() {
    name = "Resistor";
    id = 1;
}


vector<Component> Resistor::getConnected() {
    vector<Component> out;

    return out;
}

info Resistor::input(info i) {
    return {
        1,
        12,
        0.5
    };
}