from MNAElement import MNAElement

class UnknownCurrent:
    def __init__(self, element: MNAElement):
        assert(issubclass(type(element), MNAElement))
        self.element = element

    def __str__(self):
        return f"I(N{self.element.n0}=>N{self.element.n1})"

    def __eq__(self, other):
        assert(type(other) == UnknownCurrent)
        return self.element == other.element

class UnknownVoltage:
    def __init__(self, node: int):
        assert (type(node) == int)
        self.node = node

    def __str__(self):
        return f"V(N{self.node})"

    def __eq__(self, other):
        assert (type(other) == UnknownVoltage)
        return self.node == other.node
