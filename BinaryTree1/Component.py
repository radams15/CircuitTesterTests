class Component:
	def __init__(self, comp_type):
		self.comp_type = comp_type
		self.n0 = None
		self.n1 = None

	def __repr__(self):
		return f"{self.comp_type}"
