//
// Created by rhys on 04/01/2021.
//

#ifndef CIRCUITTESTER_COMPONENT_H
#define CIRCUITTESTER_COMPONENT_H

#include <QGraphicsPixmapItem>
#include <QPainter>
#include "arrow.h"

class Component : public QGraphicsPolygonItem{
private:

protected:
    static QPixmap loadResource(const QString& resource);

public:
    enum { Type = UserType + 15 };
    enum DiagramType { Step, Conditional, StartEnd, Io };

    Component(DiagramType diagramType, QMenu *contextMenu, QGraphicsItem *parent = nullptr);

    void removeArrow(Arrow *arrow);
    void removeArrows();
    DiagramType diagramType() const { return myDiagramType; }
    QPolygonF polygon() const { return myPolygon; }
    void addArrow(Arrow *arrow);
    QPixmap image() const;
    int type() const override { return Type; }

protected:
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

private:
    DiagramType myDiagramType;
    QPolygonF myPolygon;
    QMenu *myContextMenu;
    QList<Arrow *> arrows;
};


#endif //CIRCUITTESTER_COMPONENT_H
