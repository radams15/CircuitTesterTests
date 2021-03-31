#include <iostream>
#include "Spice.h"

int main() {
    Spice* s = Spice::fromFile("../../example.cir");
    return 0;
}
