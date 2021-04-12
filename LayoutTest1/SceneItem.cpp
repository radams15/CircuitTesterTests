#include "SceneItem.h"
#include "Arrow.h"

#include <QGraphicsScene>
#include <QGraphicsSceneContextMenuEvent>
#include <QMenu>
#include <QPainter>
#include <QResource>
#include <QFile>
#include <QMessageBox>
#include <iostream>


SceneItem::SceneItem(QString resourcePath, QGraphicsItem *parent)
    : QGraphicsPolygonItem(parent){

    loadPolygon(resourcePath);

    this->pixmap = image();

    setPolygon(myPolygon);

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

void SceneItem::loadPolygon(QString path) {
    myPolygon.clear();

    QResource fileRes(path);

    QFile file(fileRes.absoluteFilePath());

    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0,"error",file.errorString());
    }

    QString content = file.readAll();


    for(const QString line : content.split("\n")){
        QStringList points = line.split(",");
        if(points.length() != 2) continue;

        QPointF point(points[0].toDouble(), points[1].toDouble());

        myPolygon << point;
    }

    std::cout << myPolygon.length() << std::endl;

}


QPixmap SceneItem::image() {
    QPixmap p(250, 250);
    p.fill(Qt::transparent);

    QPainter painter(&p);
    painter.setPen(QPen(Qt::black, 8));
    painter.translate(125, 125);

    painter.drawPolyline(myPolygon);

    return p;
}