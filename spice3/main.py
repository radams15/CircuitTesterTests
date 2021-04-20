from MNACircuit import *
from MNASolution import *
from MNAElement import *

if __name__ == '__main__':
    bat = MNAElement(0, 1, None, 5)
    res1 = MNAElement(1, 2, None, 10)
    res2 = MNAElement(2, 0, None, 10)
    cir = MNACircuit([bat], [res1, res2], [])

    voltage_map = {
        0: 0,
        1: 5,
        2: 2.5
    }

    des_sol = MNASolution(voltage_map, [bat.with_current_solution( 5 / 20.0)])
    real_sol = cir.solve()

    print(real_sol.approx_equals(des_sol))