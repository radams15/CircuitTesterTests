from Element import Element

class MNAElement:
    def __init__(self, n0: int, n1: int, circuit_element: Element, value: float, current_solution: float=None):
        self.n0: int = n0
        self.n1: int = n1
        self.circuit_element = circuit_element
        self.value = value
        self.current_solution = current_solution

    def with_current_solution(self, current_solution):
        return MNAElement(self.n0, self.n1, self.circuit_element, self.value, current_solution)

    def contains_node_id(self, node_id: int):
        return self.n0 == node_id or self.n1 == node_id

    def get_opposite_node(self, node_id: int):
        return self.n1 if node_id == self.n0 else self.n0

