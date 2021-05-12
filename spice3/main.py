import MNAElement
from MNACircuit import *

from Battery import Battery
from Resistor import Resistor

def dc_sweep(comps, bat, to_measure, start, end):
    for i in range(start, end):
        bat.value = i
        circ = MNACircuit(comps)
        circ_sol = circ.solve()
        cur = circ_sol.get_current_for_resistor(to_measure)
        print(i, cur)

if __name__ == '__main__':
    bat1 = Battery(0, 1, 9)
    res1 = Resistor(1, 2, 5)
    res2 = Resistor(1, 2, 10)
    res3 = Resistor(2, 0, 7)

    comps = [bat1, res1, res2, res3]

    cir = MNACircuit(comps)

    sol = cir.solve()

    print("\n\nSolutions:\n")

    for c in comps:
        print(c)
        if c.type == ElementType.RESISTOR:
            print(sol.get_current_for_resistor(c), "A")
        elif c.type == ElementType.BATTERY:
            print(c.current_solution, "A")

        print(sol.get_voltage(c), "V")
        print("\n\n")