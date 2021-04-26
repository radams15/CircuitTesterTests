class Arrow:
	def __init__(self, frm, to):
		self.frm = frm
		self.to = to

	def __repr__(self):
		return f"({self.frm} => {self.to})"
