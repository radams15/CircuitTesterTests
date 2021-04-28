class Component:
	def __init__(self, comp_type):
		self.comp_type = comp_type
		self.node = -1
		self.connections = []

	def __repr__(self):
		return self.comp_type
		#return f"{self.comp_type} (n{self.node})"
