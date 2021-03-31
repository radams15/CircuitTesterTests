#ifndef ARROW_H
#define ARROW_H

#include <QGraphicsLineItem>

class Component;

//! [0]
class Arrow : public QGraphicsLineItem
{
public:
    enum { Type = UserType + 4 };

    Arrow(Component *startItem, Component *endItem,
          QGraphicsItem *parent = nullptr);

    int type() const override { return Type; }
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void setColor(const QColor &color) { myColor = color; }
    Component *startItem() const { return myStartItem; }
    Component *endItem() const { return myEndItem; }

    void updatePosition();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr) override;

private:
    Component *myStartItem;
    Component *myEndItem;
    QPolygonF arrowHead;
    QColor myColor = Qt::black;
};
//! [0]

#endif // ARROW_H
