#include <iostream>

#include "components/components.h"

int main() {
    PowerData input = {
            9
            -1
    };

    Resistor r(2);

    PowerData out = r.output({});

    return 0;
}
