//
// Created by rhys on 08/04/2021.
//

#include "Component.h"

std::string Component::str() {
    return resourcePath.toStdString() + "(n" + std::to_string(n0) + ")";
}

bool Component::equals(Component *c) {
    return this == c;
}
