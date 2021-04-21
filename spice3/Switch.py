from Resistor import Resistor

class Switch(Resistor):
    CLOSED_VAL = 0
    OPEN_VAL = 1E10

    def __init__(self, n0: int, n1, closed=True, current_solution=None):
        super().__init__(n0, n1, self.CLOSED_VAL, current_solution)

        if closed:
            self.close()
        else:
            self.open()

    def open(self):
        self.value = self.OPEN_VAL

    def close(self):
        self.value = self.CLOSED_VAL