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


def find_shortest_path(graph, start, goal):
    explored = []
     
    # Queue for traversing the
    # graph in the BFS
    queue = [[start]]
     
    # If the desired node is
    # reached
    if start == goal:
        print("Same Node")
        return []
     
    # Loop to traverse the graph
    # with the help of the queue
    while queue:
        path = queue.pop(0)
        node = path[-1]
         
        # Condition to check if the
        # current node is not visited
        if node not in explored:
            neighbours = graph[node]
             
            # Loop to iterate over the
            # neighbours of the node
            for neighbour in neighbours:
                new_path = list(path)
                new_path.append(neighbour)
                queue.append(new_path)
                 
                # Condition to check if the
                # neighbour node is the goal
                if neighbour == goal:
                    return new_path
            explored.append(node)
 
    return None


def iterate(graph, start_node):
	nodes = set(graph.keys())	 

	for n in nodes:
		path = find_shortest_path(graph, start_node, n)

		n.node = len(path) - 1

	for n in sorted(nodes, key=lambda x: x.node):
		for c in graph[n]:
			a = Arrow(n, c)
			n.connections.append(a)
		print(n, "=>", [x.to for x in n.connections])


iterate(graph, bat)
