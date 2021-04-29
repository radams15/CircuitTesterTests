//
// Created by rhys on 08/04/2021.
//

#ifndef LAYOUTTEST1_COMPONENT_H
#define LAYOUTTEST1_COMPONENT_H

#include <QIcon>
#include <utility>

#include "../SceneItem.h"

class Component : public SceneItem{
protected:
    int ID;

    explicit Component(int id, QString resourcePath): ID(id), SceneItem(std::move(resourcePath)){};

private:

public:
    inline int getId() { return ID; }

    int n0 = -1;
    int n1 = -1;

    std::vector<Arrow*> connections;

    std::string str();

    bool equals(Component* c);
};


#endif //LAYOUTTEST1_COMPONENT_H
