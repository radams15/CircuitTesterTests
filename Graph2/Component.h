#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include <vector>

class Component{
private:
	
public:
	std::string comp_type;

	int node = -1;

	std::vector<Component*>* connections;

	Component(std::string comp_type){
		this->comp_type = comp_type;
	}

	std::string str(){
		return comp_type + " (n" + std::to_string(node) + ")";
	}
	
	bool equals(Component* c){
		return this == c;
	}
};

#endif
