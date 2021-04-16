//
// Created by rhys on 16/04/2021.
//

#ifndef SPICE_NODEHASHTABLE_H
#define SPICE_NODEHASHTABLE_H

#include <string>
#include <map>

using namespace std;


class NodeHashTable {
private:

public:
    int nodeCount = 0;

    map<string, int> nodes;

    int addToNodes(string nodeStr);

};


#endif //SPICE_NODEHASHTABLE_H
