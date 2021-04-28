#include <iostream>
#include <map>
#include <vector>

#include "Arrow.h"
#include "Component.h"

using namespace std;

map<Component*, vector<Component*>> get_graph(){
	auto* bat = new Component("Battery");
	auto* res1 = new Component("Resistor1");
	auto* res2 = new Component("Resistor2");
	auto* res3 = new Component("Resistor3");
	auto* res4 = new Component("Resistor4");

	map<Component*, vector<Component*>> out = {
		{bat, {res1, res2, res3}
	};

	return out;
}

int main(){
	return 0;
}
