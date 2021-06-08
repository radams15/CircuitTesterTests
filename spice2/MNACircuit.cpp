//
// Created by rhys on 18/04/2021.
//

#include "MNACircuit.h"

#include <Eigen/Dense>
#include <iostream>


template<typename T>
T vec_pop_front(std::vector<T>& vec){
    std::reverse(vec.begin(),vec.end()); // first becomes last, reverses the vector
    T out = vec.back();
    vec.pop_back(); // pop last
    std::reverse(vec.begin(),vec.end()); // reverses it again, so the elements are in the same order as before

    return out;
}

MNACircuit::MNACircuit(std::vector<MNAElement *> batteries, std::vector<MNAElement *> resistors, std::vector<MNAElement *> currentSources) {
    this->batteries = batteries;
    this->resistors = resistors;
    this->currentSources = currentSources;

    elements.insert(elements.end(), this->batteries.begin(), this->batteries.end());
    elements.insert(elements.end(), this->resistors.begin(), this->resistors.end());
    elements.insert(elements.end(), this->currentSources.begin(), this->currentSources.end());

    for(auto e : elements){
        nodeSet.insert(std::pair<int, int>{e->n0, e->n0});
        nodeSet.insert(std::pair<int, int>{e->n1, e->n1});
        std::cout << e->n0 << ": " << e->n1 << "\n";
    }
    std::cout << "\n";

    nodeCount = nodeSet.size();

    for(auto n : nodeSet){
        nodes.push_back(n.second);
    }

    for(auto n : nodes){
        std::cout << n << ", ";
    }
    std::cout << "\n";
}

int MNACircuit::getCurrentCount() {
    int freeResistors = 0;
    for(auto r : resistors){
        if(r->value == 0){
            freeResistors++;
        }
    }

    return batteries.size()-freeResistors;
}

int MNACircuit::getNumVars() {
    return nodeCount+getCurrentCount();
}

double MNACircuit::getCurrentSourceTotal(int nodeIndex) {
    double numCurrentSources = 0.0;

    for(auto c : currentSources){
        if(c->n1 == nodeIndex){
            numCurrentSources -= c->value;
        }

        if(c->n0 == nodeIndex){
            numCurrentSources += c->value;
        }
    }

    return numCurrentSources;
}

std::vector<Term *>* MNACircuit::getCurrentTerms(int node, int side, int sign) {
    auto* out = new std::vector<Term*>;

    for(auto b : batteries){
        int bside = side == 0? b->n0 : b->n1;

        if(bside == node) {
            out->push_back(new Term(sign, new UnknownCurrent(b)));
        }
    }

    for(auto r : resistors) {
        int rside = side == 0 ? r->n0 : r->n1;

        if (rside == node && r->value == 0) {
            out->push_back(new Term(sign, new UnknownCurrent(r)));
        }

        if(rside == node && r->value != 0){
            out->push_back(new Term(-sign / r->value, new UnknownVoltage(r->n1 )));
            out->push_back(new Term(sign / r->value, new UnknownVoltage(r->n0 )));
        }
    }

    return out;
}

std::vector<int>* MNACircuit::getReferenceNodeIds() {
    auto* out = new std::vector<int>;

    std::vector<int> toVisit;
    for(auto n : nodeSet){
        toVisit.push_back(n.second);
    }

    while(! toVisit.empty()){
        int refNodeId = toVisit.at(0);

        out->push_back(refNodeId);

        std::vector<int>* connectedNodes = getConnectedNodeIds(refNodeId);

        for(auto c : *connectedNodes){
            toVisit.erase(std::remove_if(toVisit.begin(), toVisit.end(), [c](int i){
                return i == c;
            }));
        }
    }

    return out;
}

std::vector<int> *MNACircuit::getConnectedNodeIds(int node) {
    auto* visited = new std::vector<int>;
    std::vector<int> toVisit = {node};

    while(! toVisit.empty()){
        int nodeToVisit = vec_pop_front<int>(toVisit);

        visited->push_back(nodeToVisit);

        for(auto e : elements){
            if(e->containsNode(nodeToVisit)){
                int oppositeNode = e->getOppositeNode(nodeToVisit);
                if(! std::count(visited->begin(), visited->end(), oppositeNode)){
                    toVisit.push_back(oppositeNode);
                }
            }
        }
    }

    visited->erase(unique( visited->begin(), visited->end() ), visited->end());
    return visited;
}

std::vector<Equation *>* MNACircuit::getEquations() {
    auto* equations = new std::vector<Equation *>;

    std::vector<int>* refNodeIds = getReferenceNodeIds();

    for(auto r : *refNodeIds){
        equations->push_back(new Equation(0, {
            new Term(1, new UnknownVoltage(r))
        }));
    }

    for(auto n : nodes){
        if(! std::count(refNodeIds->begin(), refNodeIds->end(), n)){
            std::vector<Term *>* incoming = getCurrentTerms(n, 1, -1);
            std::vector<Term *>* outgoing = getCurrentTerms(n, 0, +1);

            auto* conserved = new std::vector<Term *>;
            conserved->insert(conserved->end(), incoming->begin(), incoming->end());
            conserved->insert(conserved->end(), outgoing->begin(), outgoing->end());

            equations->push_back(new Equation(getCurrentSourceTotal(n), *conserved));
        }
    }

    for(auto b : batteries){
        equations->push_back(new Equation(b->value, {
            new Term(-1, new UnknownVoltage(b->n0)),
            new Term(1, new UnknownVoltage(b->n1))
        }));
    }

    for(auto r : resistors){
        if(r->value == 0){
            equations->push_back(new Equation(r->value, {
                    new Term(1, new UnknownVoltage(r->n0)),
                    new Term(-1, new UnknownVoltage(r->n1))
            }));
        }
    }

    return equations;
}

std::vector<UnknownCurrent *> *MNACircuit::getUnknownCurrents() {
    auto* out = new std::vector<UnknownCurrent*>;

    for(auto b : batteries){
        out->push_back(new UnknownCurrent(b));
    }

    for(auto r : resistors){
        if(r->value == 0) {
            out->push_back(new UnknownCurrent(r));
        }
    }

    return out;
}

MNASolution *MNACircuit::solve() {
    std::vector<Equation *>* equations = getEquations();
    std::vector<UnknownCurrent*>* unknownCurrents = getUnknownCurrents();
    auto* unknownVoltages = new std::vector<UnknownVoltage*>;

    for(auto v : nodes){
        unknownVoltages->push_back(new UnknownVoltage(v));
    }

    auto* unknowns = new std::vector<Unknown*>(unknownCurrents->begin(), unknownCurrents->end());

    unknowns->insert(unknowns->end(), unknownVoltages->begin(), unknownVoltages->end());


    auto A = Eigen::MatrixXd(equations->size(), getNumVars());
    auto z = Eigen::MatrixXd(equations->size(), 1);

    for(int i=0 ; i<equations->size() ; i++){
        equations->at(i)->stamp(i, &A, &z, [this, unknowns](Unknown* u) {
            return getIndexByEquals(unknowns, u);
        });
    }

    Eigen::MatrixXd x = A.fullPivLu().solve(z); // https://eigen.tuxfamily.org/dox/group__TutorialLinearAlgebra.html

    std::cout << "A:\n" << A << "\n\nz: \n" << z << "\n\nx:" << x << "\n\n\n";

    auto* voltageMap = new std::map<int, double>;

    for(auto v : *unknownVoltages){
        auto rhs = x(getIndexByEquals(unknowns, v));

        voltageMap->insert(std::pair<int, double>(v->node, rhs));
    }

    std::vector<MNAElement*> elems;

    for(auto c : *unknownCurrents){
        c->element->currentSolution = x(getIndexByEquals(unknowns, c), 0);
        elems.push_back(c->element);

    }

    return new MNASolution(*voltageMap, elems);
}

int MNACircuit::getIndexByEquals(std::vector<Unknown*>* array, Unknown* element) {
    for(int i=0 ; i<array->size() ; i++){
        if(array->at(i)->equals(element)){
            return i;
        }
    }

    return -1;
}
