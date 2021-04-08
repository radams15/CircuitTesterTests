//
// Created by rhys on 08/04/2021.
//

#ifndef LAYOUTTEST1_COMPONENT_H
#define LAYOUTTEST1_COMPONENT_H

#include <QIcon>

#include "../SceneItem.h"

class Component : public SceneItem{
protected:
    int ID;

    explicit Component(int id): ID(id), SceneItem(":/images/delete.png"){};
private:

public:
    inline int getId() { return ID; }
};


#endif //LAYOUTTEST1_COMPONENT_H
