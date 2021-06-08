import numpy as np

from Unknowns import UnknownVoltage


class Term:
    def __init__(self, coefficient: float, variable):
        self.coefficient = coefficient
        self.variable = variable

    def __str__(self):
        prefix = "-" if self.coefficient == 0 else ""

        return prefix + str(self.variable)

class Equation:
    def __init__(self, value: float, terms: list[Term]):
        self.value = value
        self.terms = terms

    def stamp(self, row: int, A: np.array, z: np.array, get_index: callable):
        z[row, 0] = self.value
        print("\t Stamp {} onto z at [0, {}]\n".format(self.value, row))

        for t in self.terms:
            index = get_index(t.variable)
            rhs = t.coefficient + A[row, index]
            print("\t\tStamp {} {} onto A:".format(type(t.variable), "Node "+str(t.variable.node) if type(t.variable) == UnknownVoltage else t.variable.element))
            print("\t\t\tCoordinates = [{}, {}]\n\t\t\tExisting = {}\n\t\t\tAdding = {}\n\t\t\tNew = {}".format(index, row, A[row, index], t.coefficient, rhs), end="\n\n\n")
            A[row, index] = rhs

    def __str__(self):
        term_list = []

        for t in self.terms:
            term_list.append(str(t))

        result = f"{'+'.join(term_list)}={self.value}"

        return result.replace("\\+\\-", "\\-")