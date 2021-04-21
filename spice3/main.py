from MNACircuit import *
from MNASolution import *
from Battery import Battery
from Resistor import Resistor

if __name__ == '__main__':
    bat = Battery(0, 1, 9)
    res1 = Resistor(1, 0, 5)
    res2 = Resistor(1, 0, 15)

    comps = [bat, res1, res2]

    cir = MNACircuit(comps)

    sol = cir.solve()

    for comp in comps:
        print(comp, end="")
        if type(comp) == Resistor:
            current = sol.get_current_for_resistor(comp)
            voltage = sol.get_voltage(comp)

            print(f" {current}A {voltage}V")
        elif type(comp) == Battery:
            voltage = sol.get_voltage(comp)
            print(f" {voltage}V")