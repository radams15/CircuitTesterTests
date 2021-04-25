from MNACircuit import *

from Battery import Battery
from Resistor import Resistor
from Switch import Switch

if __name__ == '__main__':
    bat1 = Battery(1, 0, -4)
    res1 = Resistor(0, 1, 10)
    res2 = Resistor(0, 1, 10)

    comps = [bat1, res1, res2]

    cir = MNACircuit(comps)

    sol = cir.solve()

    for comp in comps:
        print(comp, end="")
        if issubclass(type(comp), Resistor):
            current = sol.get_current_for_resistor(comp)
            voltage = sol.get_voltage(comp)

            print(f" {current}A {voltage}V")
        elif type(comp) == Battery:
            voltage = sol.get_voltage(comp)
            print(f" {voltage}V")