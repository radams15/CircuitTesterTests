//
// Created by rhys on 19/01/2021.
//

#include "Spice.h"
#include "Components/Resistor.h"

#include <fstream>
#include <sstream>
#include <iostream>

Spice::Spice(string data) {
    vector<Component*> components = parse(data);
    for (auto i = components.begin(); i != components.end(); ++i) {
        Component *c = *i;
        cout << c->getName() << " => " << c->input({1,2,3}).current << "A ";
    }
}

Spice *Spice::fromFile(string fileName) {
    ifstream in(fileName);

    stringstream buf;
    buf << in.rdbuf();

    return new Spice(buf.str());
}

vector<Component*> Spice::parse(string data) {
    vector<Component*> out;

    auto* r = new Resistor();

    out.push_back(r);

    return out;
}
