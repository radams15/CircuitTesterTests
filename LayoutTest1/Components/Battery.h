//
// Created by rhys on 21/04/2021.
//

#ifndef LAYOUTTEST1_BATTERY_H
#define LAYOUTTEST1_BATTERY_H


#include "Component.h"

class Battery : public Component {
private:

public:
    enum{
        ID = 2
    };

    Battery() : Component(ID, ":/res/battery.png") {};
};


#endif //LAYOUTTEST1_BATTERY_H
