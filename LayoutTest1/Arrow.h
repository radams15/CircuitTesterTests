#ifndef ARROW_H
#define ARROW_H

#include <QGraphicsLineItem>

class SceneItem;


class Arrow : public QGraphicsLineItem{
public:
    enum { Type = UserType + 4 };

    Arrow(SceneItem *startItem, SceneItem *endItem, QGraphicsItem *parent = nullptr);

    int type() const override { return Type; }
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void setColor(const QColor &color) { myColor = color; }
    SceneItem *startItem() const { return myStartItem; }
    SceneItem *endItem() const { return myEndItem; }

    void updatePosition();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr) override;

private:
    SceneItem *myStartItem;
    SceneItem *myEndItem;
    QPolygonF arrowHead;
    QColor myColor = Qt::black;
};


#endif // ARROW_H
