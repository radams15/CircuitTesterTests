#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

#include "Arrow.h"
#include "Component.h"

using namespace std;

typedef map<Component*, vector<Component*>> Graph;
typedef vector<Component*> Path;

Component* bat;
Component* res4;

Graph get_graph(){
	bat = new Component("Battery");
	auto* res1 = new Component("Resistor1");
	auto* res2 = new Component("Resistor2");
	auto* res3 = new Component("Resistor3");
	res4 = new Component("Resistor4");

	map<Component*, vector<Component*>> out = {
		{bat, {res1, res2, res3}},
		{res1, {res4}},
		{res2, {res4}},
		{res3, {bat}},
		{res4, {bat}}
	};

	return out;
}

Path* find_shortest_path(Graph* graph, Component* start, Component* end, Path* path=new Path){
	path->push_back(start);
	
	if(start->equals(end)){
		return path;
	}
	
	if(graph->count(start) == 0){
		return nullptr;
	}
	
	
	Path* shortest = nullptr;
	for(auto node : graph->at(start)){
		if(! count(path->begin(), path->end(), node)){
			Path* newpath = find_shortest_path(graph, node, end, path);

			if(newpath != nullptr){
				if(shortest == nullptr || newpath->size() < shortest->size()){
					shortest = newpath;
				}
			}
		}
	}
	
	return shortest;		
}

void iterate(Graph* graph, Component* start_node){
	for(auto e : *graph){
		auto* path = find_shortest_path(graph, start_node, e.first);
		
		e.first->node = path->size();
		cout << e.first->node << endl;
	}
}

int main(){
	auto graph = get_graph();
	
	//iterate(&graph, bat);
	
	for(auto a : *find_shortest_path(&graph, bat, res4)){
		cout << a->str() << endl;
	}
	
	return 0;
}
