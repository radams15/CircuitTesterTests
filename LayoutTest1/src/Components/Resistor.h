//
// Created by rhys on 04/01/2021.
//

#ifndef CIRCUITTESTER_RESISTOR_H
#define CIRCUITTESTER_RESISTOR_H

#include <src/Component.h>

class Resistor : public Component{
private:

public:
    static const int ID = 10;
    static constexpr const char* NAME = "Resistor";

    static QPixmap getImage();
};


#endif //CIRCUITTESTER_RESISTOR_H
