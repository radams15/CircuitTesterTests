//
// Created by rhys on 04/01/2021.
//

#include "graphicsscene.h"

#include <QObject>

GraphicsScene::GraphicsScene(QObject *parent) : QGraphicsScene(parent) {

}

void GraphicsScene::setState(State newState) {
    this->currentState = newState;
}
