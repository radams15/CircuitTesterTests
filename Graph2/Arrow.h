#ifndef ARROW_H
#define ARROW_H

#include <string>

#include "Component.h"

class Arrow{
private:

public:
	Component* frm;
	Component* to;

	Arrow(Component* frm, Component* to){
		this->frm = frm;
		this->to = to;
	}

	std::string str(){
		return frm->str() + " => " + to->str();
	}
};

#endif
