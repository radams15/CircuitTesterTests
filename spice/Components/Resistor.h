//
// Created by rhys on 19/01/2021.
//

#ifndef SPICE_RESISTOR_H
#define SPICE_RESISTOR_H


#include "../Component.h"

class Resistor : public Component{
protected:

public:
    Resistor();

    vector<Component> getConnected() override;
    info input(info i) override;
};


#endif //SPICE_RESISTOR_H
