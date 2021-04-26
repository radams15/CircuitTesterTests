class Component:
	def __init__(self, comp_type):
		self.comp_type = comp_type
		self.node = None

	def __repr__(self):
		return f"{self.comp_type}"
