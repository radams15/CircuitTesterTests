//
// Created by rhys on 04/01/2021.
//

#include "GraphicsScene.h"

#include <QGraphicsSceneMouseEvent>

//! [0]
GraphicsScene::GraphicsScene(QObject *parent)
        : QGraphicsScene(parent)
{
    myMode = MoveItem;
    myItemType = Component::Step;
    line = nullptr;
    myItemColor = Qt::white;
    myLineColor = Qt::black;
}
//! [0]

//! [1]
void GraphicsScene::setLineColor(const QColor &color)
{
    myLineColor = color;
    if (isItemChange(Arrow::Type)) {
        Arrow *item = qgraphicsitem_cast<Arrow *>(selectedItems().first());
        item->setColor(myLineColor);
        update();
    }
}
//! [2]

//! [3]
void GraphicsScene::setItemColor(const QColor &color)
{
    myItemColor = color;
    if (isItemChange(Component::Type)) {
        Component *item = qgraphicsitem_cast<Component *>(selectedItems().first());
        item->setBrush(myItemColor);
    }
}
//! [3]

//! [4]

void GraphicsScene::setMode(Mode mode)
{
    myMode = mode;
}

void GraphicsScene::setItemType(Component::DiagramType type)
{
    myItemType = type;
}

//! [5]

//! [6]
void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (mouseEvent->button() != Qt::LeftButton)
        return;

    Component *item;
    switch (myMode) {
        case InsertItem:
            item = new Component(myItemType, myItemMenu);
            item->setBrush(myItemColor);
            addItem(item);
            item->setPos(mouseEvent->scenePos());
            emit itemInserted(item);
            break;
//! [6] //! [7]
        case InsertLine:
            line = new QGraphicsLineItem(QLineF(mouseEvent->scenePos(),
                                                mouseEvent->scenePos()));
            line->setPen(QPen(myLineColor, 2));
            addItem(line);
            break;
//! [8] //! [9]
        default:
            ;
    }
    QGraphicsScene::mousePressEvent(mouseEvent);
}
//! [9]

//! [10]
void GraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (myMode == InsertLine && line != nullptr) {
        QLineF newLine(line->line().p1(), mouseEvent->scenePos());
        line->setLine(newLine);
    } else if (myMode == MoveItem) {
        QGraphicsScene::mouseMoveEvent(mouseEvent);
    }
}
//! [10]

//! [11]
void GraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (line != nullptr && myMode == InsertLine) {
        QList<QGraphicsItem *> startItems = items(line->line().p1());
        if (startItems.count() && startItems.first() == line)
            startItems.removeFirst();
        QList<QGraphicsItem *> endItems = items(line->line().p2());
        if (endItems.count() && endItems.first() == line)
            endItems.removeFirst();

        removeItem(line);
        delete line;
//! [11] //! [12]

        if (startItems.count() > 0 && endItems.count() > 0 &&
            startItems.first()->type() == Component::Type &&
            endItems.first()->type() == Component::Type &&
            startItems.first() != endItems.first()) {
            Component *startItem = qgraphicsitem_cast<Component *>(startItems.first());
            Component *endItem = qgraphicsitem_cast<Component *>(endItems.first());
            Arrow *arrow = new Arrow(startItem, endItem);
            arrow->setColor(myLineColor);
            startItem->addArrow(arrow);
            endItem->addArrow(arrow);
            arrow->setZValue(-1000.0);
            addItem(arrow);
            arrow->updatePosition();
        }
    }
//! [12] //! [13]
    line = nullptr;
    QGraphicsScene::mouseReleaseEvent(mouseEvent);
}
//! [13]

//! [14]
bool GraphicsScene::isItemChange(int type) const
{
    const QList<QGraphicsItem *> items = selectedItems();
    const auto cb = [type](const QGraphicsItem *item) { return item->type() == type; };
    return std::find_if(items.begin(), items.end(), cb) != items.end();
}