#include "SceneItem.h"
#include "Arrow.h"

#include <QGraphicsScene>
#include <QGraphicsSceneContextMenuEvent>
#include <QMenu>
#include <QPainter>


SceneItem::SceneItem(QString resourcePath, QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent){

    this->pixmap = QPixmap(resourcePath);
    setPixmap(this->pixmap);

    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
}


void SceneItem::removeArrow(Arrow *arrow){
    arrows.removeAll(arrow);
}


void SceneItem::removeArrows(){
    // need a copy here since removeArrow() will
    // modify the arrows container
    const auto arrowsCopy = arrows;
    for (Arrow *arrow : arrowsCopy) {
        arrow->startItem()->removeArrow(arrow);
        arrow->endItem()->removeArrow(arrow);
        scene()->removeItem(arrow);
        delete arrow;
    }
}


void SceneItem::addArrow(Arrow *arrow){
    arrows.append(arrow);
}

QVariant SceneItem::itemChange(GraphicsItemChange change, const QVariant &value){
    if (change == QGraphicsItem::ItemPositionChange) {
        for (Arrow *arrow : qAsConst(arrows))
            arrow->updatePosition();
    }

    return value;
}
