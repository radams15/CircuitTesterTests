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


def find_shortest_path(graph, start, end, path=[]):
    path = path + [start]

    if start == end:
        return path

    if not start in graph:
        return None

    shortest = None
    for node in graph[start]:
        if node not in path:
            newpath = find_shortest_path(graph, node, end, path)
            if newpath:
                if not shortest or len(newpath) < len(shortest):
                    shortest = newpath
    return shortest



def iterate(graph, start_node):
	nodes = set(graph.keys())	

	for n in nodes:
		path = find_shortest_path(graph, start_node, n)

		node_num = len(path)-1

		print(n, node_num)

		

iterate(graph, bat)
print()
