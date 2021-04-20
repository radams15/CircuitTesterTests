from typing import Union

import numpy as np

from MNAElement import MNAElement
from MNASolution import MNASolution

class UnknownCurrent:
    def __init__(self, element: MNAElement):
        assert(type(element) == MNAElement)
        self.element = element

    def __str__(self):
        return f"{self.element.n0}_{self.element.n1}"

    def __eq__(self, other):
        assert(type(other) == UnknownCurrent)
        return self.element == other.element

class UnknownVoltage:
    def __init__(self, node: int):
        assert (type(node) == int)
        self.node = node

    def __str__(self):
        return f"V{self.node}"

    def __eq__(self, other):
        assert (type(other) == UnknownVoltage)
        return self.node == other.node


class Term:
    def __init__(self, coefficient: float, variable: Union[UnknownCurrent,UnknownCurrent]):
        self.coefficient = coefficient
        self.variable = variable

    def __str__(self):
        prefix = "-" if self.coefficient == 0 else ""

        return prefix + str(self.variable)

class Equation:
    def __init__(self, value: float, terms: list[Term]):
        self.value = value
        self.terms = terms

    def stamp(self, row: int, a: np.array, z: np.array, get_index: callable):
        z[row, 0] = self.value

        for t in self.terms:
            index = get_index(t.variable)
            a[row, index] = t.coefficient + a[row, index]

    def __str__(self):
        term_list = []

        for t in self.terms:
            term_list.append(str(t))

        result = f"{'+'.join(term_list)}={self.value}"

        return result.replace("\\+\\-", "\\-")

def get_index_by_equals(array, element) -> int:
    for i in range(len(array)):
        if (type(array[i]) == type(element)) and (array[i] == element):
            return i

    return -1

class MNACircuit:
    def __init__(self, batteries, resistors: list[MNAElement], current_sources: list[MNAElement]):
        self.batteries: list[MNAElement] = batteries
        self.resistors: list[MNAElement] = resistors
        self.current_sources: list[MNAElement] = current_sources

        self.elements = self.batteries + self.resistors + self.current_sources

        self.node_set = {}

        for e in self.elements:
            self.node_set[e.n0] = e.n0
            self.node_set[e.n1] = e.n1

        self.node_count = len(self.node_set)

        self.nodes = self.node_set.values()


    def __str__(self):
        return f"resistors: {map(str, self.resistors)}\nbatteries: {map(str, self.batteries)}\ncurrent sources: {map(str, self.current_sources)}"

    def get_current_count(self):
        free_resistors = 0

        for r in self.resistors:
            if r.value == 0:
                free_resistors += 1

        return len(self.batteries) + free_resistors

    def get_num_vars(self):
        return self.node_count + self.get_current_count()

    def get_current_source_total(self, node_index):
        total = 0.0

        for c in self.current_sources:
            if c.n1 == node_index:
                total -= c.value
            if c.n0 == node_index:
                total += c.value

        return total

    def get_current_terms(self, node: int, side: int, sign: int) -> list[Term]:
        node_terms: list[Term] = []

        for b in self.batteries:
            bside = b.n0 if side == 0 else b.n1

            if bside == node:
                node_terms.append(Term(sign, UnknownCurrent(b)))

        for r in self.resistors:
            rside = r.n0 if side == 0 else r.n1

            if rside == node and r.value == 0:
                node_terms.append(Term(UnknownCurrent(r)))

            if rside == node and r.value != 0:
                node_terms.append(Term(-sign/r.value, UnknownVoltage(r.n1)))
                node_terms.append(Term(sign/r.value, UnknownVoltage(r.n0)))

        return node_terms

    def get_ref_node_ids(self) -> list[int]:
        to_visit: list[int] = list(self.node_set.values())

        ref_node_ids: list[int] = []

        while len(to_visit) > 0:
            ref_node_id = to_visit[0]
            ref_node_ids.append(ref_node_id)
            connected = self.get_connected_node_ids(ref_node_id)

            for c in connected:
                to_visit.remove(c)

        return ref_node_ids


    def get_connected_node_ids(self, node: int):
        visited = []
        to_visit = [node]

        while len(to_visit) > 0:
            node_to_visit = to_visit.pop(0)

            visited.append(node_to_visit)

            for e in self.elements:
                if e.contains_node_id(node_to_visit):
                    opposite = e.get_opposite_node(node_to_visit)
                    if opposite not in visited:
                        to_visit.append(opposite)

        return list(set(visited))

    def get_equations(self) -> list[Equation]:
        equations = []

        ref_node_ids = self.get_ref_node_ids()

        for r in ref_node_ids:
            equations.append(Equation(0, [
                Term(1, UnknownVoltage(r))
            ]))


        nodes = self.nodes

        for n in nodes:

            if n not in ref_node_ids:
                incoming = self.get_current_terms(n, 1, -1)
                outgoing = self.get_current_terms(n, 0, +1)

                terms = incoming + outgoing

                equations.append(Equation(self.get_current_source_total(n), terms))

        for b in self.batteries:
            equations.append(Equation(b.value, [
                Term(-1, UnknownVoltage(b.n0)),
                Term(1, UnknownVoltage(b.n1))
            ]))

        for r in self.resistors:
            if r.value == 0:
                equations.append(Equation(r.value, [
                    Term(1, UnknownVoltage(b.n0)),
                    Term(-1, UnknownVoltage(b.n1))
                ]))

        return equations


    def get_unknown_currents(self) -> list:
        unknown_currents = []

        for b in self.batteries:
            unknown_currents.append(UnknownCurrent(b))

        for r in self.resistors:
            if r.value == 0:
                unknown_currents.append(UnknownCurrent(r))

        return unknown_currents


    def solve(self):
        equations = self.get_equations()
        unknown_currents: list[UnknownCurrent] = self.get_unknown_currents()
        unknown_voltages: list[UnknownVoltage] = list(map(lambda x: UnknownVoltage(x), self.nodes))

        unknowns = unknown_currents + unknown_voltages

        A = np.zeros((len(equations), self.get_num_vars()), dtype=float)
        z = np.zeros((len(equations), 1), dtype=float)

        for i in range(len(equations)):
            equations[i].stamp(i, A, z, lambda x: get_index_by_equals(unknowns, x))

        x: np.array = None
        try:
            x = np.linalg.solve(A, z)
        except:
            x = np.zeros((len(equations), 1), dtype=float) # A.n, 1 original

        voltage_map = {}

        for v in unknown_voltages:
            rhs = x[get_index_by_equals(unknowns, v), 0]
            voltage_map[v.node] = rhs

        for c in unknown_currents:
            c.element.current_solution = x[get_index_by_equals(unknowns, c), 0]

        return MNASolution(voltage_map, list(map(lambda x: x.element, unknown_currents)))