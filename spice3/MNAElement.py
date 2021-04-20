from enum import Enum

class ElementType(Enum):
    BATTERY = 0
    RESISTOR = 1
    CURRENT_SOURCE = 2

class MNAElement:
    def __init__(self, element_type: ElementType, n0: int, n1: int, value: float, current_solution: float=None):
        self.type = element_type

        self.n0: int = n0
        self.n1: int = n1
        self.value = value
        self.current_solution = current_solution

    def _with_current_solution(self, _class: callable, current_solution: float):
        return _class(self.n0, self.n1, self.value, current_solution)

    def contains_node_id(self, node_id: int):
        return self.n0 == node_id or self.n1 == node_id

    def get_opposite_node(self, node_id: int):
        return self.n1 if node_id == self.n0 else self.n0

