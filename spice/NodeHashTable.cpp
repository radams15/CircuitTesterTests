//
// Created by rhys on 16/04/2021.
//

#include <algorithm>

#include "NodeHashTable.h"

int NodeHashTable::addToNodes(string nodeStr) {
    auto it = nodes.find(nodeStr);

    if (it == nodes.end()){
        nodes.insert(pair<string, int>(nodeStr, nodeCount));
        nodeCount++;
    }

    return nodes.at(nodeStr);
}
