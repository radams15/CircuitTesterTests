//
// Created by rhys on 04/01/2021.
//

#ifndef CIRCUITTESTER_GRAPHICSSCENE_H
#define CIRCUITTESTER_GRAPHICSSCENE_H


#include <QGraphicsScene>

class GraphicsScene : public QGraphicsScene{
public:
    enum State{
        InsertLine,
        InsertItem,
        MoveItem
    };

private:
    State currentState;

public:
    GraphicsScene(QObject *parent = nullptr);

    void setState(State newState);
};


#endif //CIRCUITTESTER_GRAPHICSSCENE_H
