#ifndef DIAGRAMITEM_H
#define DIAGRAMITEM_H

#include <QGraphicsPixmapItem>
#include <QList>
#include <QIcon>

class Arrow;


class SceneItem : public QGraphicsPolygonItem {
public:
    enum { Type = UserType + 15 };

    SceneItem(QString resourcePath, QGraphicsItem *parent = nullptr);

    void removeArrow(Arrow *arrow);
    void removeArrows();

    QPolygonF getPolygon() const { return myPolygon; }
    inline QPixmap getPixmap() { return pixmap; }

    void addArrow(Arrow *arrow);
    int type() const override { return Type; }

    QPixmap image();

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;
    QPixmap pixmap;

private:
    QPolygonF myPolygon;
    QList<Arrow *> arrows;

    void loadPolygon(QString path);
};


#endif // DIAGRAMITEM_H
