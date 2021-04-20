from MNACircuit import *
from MNASolution import *
from Battery import Battery
from Resistor import Resistor

if __name__ == '__main__':
    bat = Battery(0, 1, 5)
    res1 = Resistor(1, 2, 10)
    res2 = Resistor(2, 0, 10)

    cir = MNACircuit([bat, res1, res2])

    voltage_map = {
        0: 0,
        1: 5,
        2: 2.5
    }

    real_sol = cir.solve()
    des_sol = MNASolution(voltage_map, [bat.with_current_solution(5/20)])