//
// Created by rhys on 16/04/2021.
//

#include "Component.h"

string Component::getName(){
    return name;
};

string Component::str(){
    stringstream ss;

    ss << name
        << " "
        << to_string(high)
        << " "
        << to_string(low)
        << " "
        << to_string(value);

    return ss.str();
}

Component::Component(Components id, string name, string high_str, string low_str, double value) {
    this->id = id;
    this->name = name;
    this->high_str = high_str;
    this->low_str = low_str;
    this->value = value;
}
