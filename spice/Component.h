//
// Created by rhys on 19/01/2021.
//

#ifndef SPICE_COMPONENT_H
#define SPICE_COMPONENT_H

#include <string>
#include <vector>

struct info{
    float current;
    float voltage;
    float resistance;
};

using namespace std;

class Component{
protected:
    string name;
    int id;

public:
    inline string getName(){
        return name;
    };

    virtual vector<Component> getConnected() = 0;
    virtual info input(info i) = 0;
};

#endif //SPICE_COMPONENT_H
