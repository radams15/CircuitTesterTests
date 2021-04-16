//
// Created by rhys on 19/01/2021.
//

#ifndef SPICE_RESISTOR_H
#define SPICE_RESISTOR_H


#include "../Component.h"
#include "../Components.h"

class Resistor : public Component{
protected:

public:
    Resistor(string high_str, string low_str, double resistance);
};


#endif //SPICE_RESISTOR_H
