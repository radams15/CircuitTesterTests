#include <iostream>
#include <map>
#include <vector>
#include <queue>
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

Path* find_shortest_path(Graph* graph, Component* start, Component* end){
	vector<Component*> explored;
	
	queue<vector<Component*>*> q;
	
	auto v = new vector<Component*>;
	v->push_back(start);
	q.emplace(v);
	
	if(start == end){
		auto out = new Path;
		out->push_back(end);
		return out;
	}
	
	while(! q.empty()){
		Path* path = q.front();
		q.pop();
		
		Component* node = path->at(path->size()-1);
		
		if(find(explored.begin(), explored.end(), node) == explored.end()){
			auto neighbors = graph->at(node);
			
			for(auto neighbor : neighbors){
				Path* new_path = new Path;
				copy(path->begin(), path->end(), back_inserter(*new_path));
				new_path->push_back(neighbor);
				q.emplace(new_path);
				
				if(neighbor == end){
					return new_path;
				}
			}
			
			explored.push_back(node);
		}
	}
	
	return new Path;
}

void iterate(Graph* graph, Component* start_node){
	for(auto n : *graph){
		auto* path = find_shortest_path(graph, start_node, n.first);
		
		n.first->node = path->size()-1;
		cout << n.first->node << endl;
	}
	
	
	for(auto n : *graph){
		for(auto c : graph->at(n.first)){
			auto* a = new Arrow(n.first, c);
			n.first->connections.push_back(a);
		}
		
		cout << n.first->str() << "=>[";
		
		for(auto x : n.first->connections){
			cout << x->to->str() << ",";
		}
		cout << "]\n";
	}
}

int main(){
	auto graph = get_graph();
	
	iterate(&graph, bat);
	
	return 0;
}
