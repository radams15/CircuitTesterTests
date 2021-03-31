//
// Created by rhys on 12/02/2021.
//

#include "Resistor.h"

Resistor::Resistor(float resistance) : Component(1){
    this->resistance = resistance;
}

PowerData Resistor::output  (PowerData input) { // V = IR
    return {
        input.current * resistance,
        input.current
    };
}
