#ifndef DIAGRAMITEM_H
#define DIAGRAMITEM_H

#include <QGraphicsPixmapItem>
#include <QList>
#include <QIcon>

class Arrow;


class SceneItem : public QGraphicsPixmapItem {
public:
    enum { Type = UserType + 15 };

    SceneItem(QString resourcePath, QGraphicsItem *parent = nullptr);

    void removeArrow(Arrow *arrow);
    void removeArrows();

    inline QPixmap getPixmap() { return pixmap; }

    void addArrow(Arrow *arrow);
    int type() const override { return Type; }

    QPixmap image(){ return pixmap; }

    QPointF centerpoint();

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;
    QPixmap pixmap;

private:
    QPolygonF myPolygon;
    QList<Arrow *> arrows;

    void loadPolygon(QString path);
};


#endif // DIAGRAMITEM_H
