from Component import Component
from Arrow import Arrow

# https://www.geeksforgeeks.org/iterative-preorder-traversal-of-a-n-ary-tree/

bat = Component("Battery")
res1 = Component("Resistor1")
res2 = Component("Resistor2")
res3 = Component("Resistor3")
res4 = Component("Resistor4")

components = [
	bat,
	res1,
	res2,
	res3,
	res4
]

arrows = [
	Arrow(bat, res1),
	Arrow(bat, res2),
	Arrow(bat, res3),
	Arrow(res1, res4),
	Arrow(res2, res4),
	Arrow(res4, bat),
	Arrow(res3, bat)
]

def traverse(arrows, n=0):
	for a in arrows:
		print(a)



traverse(arrows)
