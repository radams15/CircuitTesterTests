from MNACircuit import *

from Battery import Battery
from Resistor import Resistor
from Switch import Switch

if __name__ == '__main__':
    bat1 = Battery(0, 1, -4)
    bat2 = Battery(1, 2, -4)
    res = Resistor(2, 0, 2)

    comps = [bat1, bat2, res]
    vmap = {
        0:0,
        1:-4,
        2:-8
    }

    cir = MNACircuit(comps)

    desol = MNASolution(vmap, [bat1.with_current_solution(-4), bat2.with_current_solution(-4)])
    sol = cir.solve()

    print(sol.approx_equals(desol))

    for comp in comps:
        print(comp, end="")
        if issubclass(type(comp), Resistor):
            current = sol.get_current_for_resistor(comp)
            voltage = sol.get_voltage(comp)

            print(f" {current}A {voltage}V")
        elif type(comp) == Battery:
            voltage = sol.get_voltage(comp)
            print(f" {voltage}V")