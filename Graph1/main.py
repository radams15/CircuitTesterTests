from Component import Component
from Arrow import Arrow

# https://www.tutorialspoint.com/python_data_structure/python_graphs.htm

bat = Component("Battery")
res1 = Component("Resistor1")
res2 = Component("Resistor2")
res3 = Component("Resistor3")
res4 = Component("Resistor4")

graph = {
	bat: [res1, res2, res3], # 0
	res1: [res4], # 1
	res2: [res4], # 1
	res3: [bat],  # 1
	res4: [bat] # 2
}




def bfs(graph, start_node):
	visited = []
	queue = []
	
	visited.append(start_node)
	queue.append(start_node)

	i = 0
	
	while queue:
		s = queue.pop(0)
				
		print(f"Nodes From {s} (n{i}):")

		for neighbour in graph[s]:
			i += 1
		
			print("\t", neighbour)
			
			if neighbour not in visited:
				visited.append(neighbour)
				queue.append(neighbour)

bfs(graph, bat)
print()
