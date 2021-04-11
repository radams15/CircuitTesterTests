//
// Created by rhys on 08/04/2021.
//

#ifndef LAYOUTTEST1_RESISTOR_H
#define LAYOUTTEST1_RESISTOR_H

#include "Component.h"

class Resistor : public Component {
private:

public:
    enum{
        ID = 1
    };


    Resistor() : Component(ID, ":/images/delete.png") {};
};


#endif //LAYOUTTEST1_RESISTOR_H
