//
// Created by rhys on 04/01/2021.
//

#ifndef CIRCUITTESTER_GRAPHICSSCENE_H
#define CIRCUITTESTER_GRAPHICSSCENE_H


#include <QGraphicsScene>
#include <QMenu>
#include "Component.h"

class GraphicsScene : public QGraphicsScene{
Q_OBJECT

public:
    enum Mode { InsertItem, InsertLine, MoveItem };

    explicit GraphicsScene(QObject *parent = nullptr);
    QColor itemColor() const { return myItemColor; }
    QColor lineColor() const { return myLineColor; }
    void setLineColor(const QColor &color);
    void setItemColor(const QColor &color);

public slots:
    void setMode(Mode mode);
    void setItemType(Component::DiagramType type);

signals:
    void itemInserted(Component *item);
    void itemSelected(QGraphicsItem *item);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) override;

private:
    bool isItemChange(int type) const;

    Component::DiagramType myItemType;
    Mode myMode;
    bool leftButtonDown;
    QPointF startPoint;
    QGraphicsLineItem *line;
    QColor myItemColor;
    QColor myLineColor;
};
//! [0]

#endif //CIRCUITTESTER_GRAPHICSSCENE_H
