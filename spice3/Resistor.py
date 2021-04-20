from MNAElement import *

class Resistor(MNAElement):
    def __init__(self, n0: int, n1: int, value: float, current_solution: float=None):
        super().__init__(ElementType.RESISTOR, n0, n1, value, current_solution)

    def with_current_solution(self, current_solution):
        return super()._with_current_solution(type(self), current_solution)