//
// Created by rhys on 18/04/2021.
//

#include "Equation.h"

Term::Term(double coefficient, Unknown *variable) {
    this->coefficient = coefficient;
    this->variable = variable;
}

std::string Term::str() {
    std::string prefix = coefficient == 1? "" : coefficient == -1? "-" : std::to_string(coefficient);

    return prefix + variable->toTermName();
}

UnknownCurrent::UnknownCurrent(MNAElement *element) {
    this->element = element;
}

std::string UnknownCurrent::toTermName() {
    return "I$"+std::to_string(element->n0)+"_$"+std::to_string(element->n1);
}

bool UnknownCurrent::equals(Unknown* other) {
    auto* c = (UnknownCurrent*) other; // yes, it's an unchecked cast. Sue me.
    return c->element == element;
}

UnknownVoltage::UnknownVoltage(int node) {
    this->node = node;
}

std::string UnknownVoltage::toTermName() {
    return "V$"+std::to_string(node);
}

bool UnknownVoltage::equals(Unknown *other) {
    auto* c = (UnknownVoltage*) other; // yes, it's another unchecked cast.
    return c->node == node;
}

Equation::Equation(double value, std::vector<Term*> terms) {
    this->value = value;
    this->terms = terms;
}

void Equation::stamp(int row, Eigen::MatrixXd* a, Eigen::MatrixXd* z, std::function<int(Unknown*)> getIndexFunc) {
    (*z)(row, 0) = value;

    for(auto t : terms){
        int index = getIndexFunc(t->variable);
        (*a)(row, index) = t->coefficient + (*a)(row, index);
    }
}

std::string Equation::str() {
    std::stringstream termList;

    for(auto t : terms){
        termList << t->str() << " +";
    }

    return "${"+termList.str()+"} = " + std::to_string(value);
}
