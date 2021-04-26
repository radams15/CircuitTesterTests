#ifndef DIAGRAMITEM_H
#define DIAGRAMITEM_H

#include <QGraphicsPixmapItem>
#include <vector>
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

    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);

    QPixmap image(){ return pixmap; }

    QPointF centerpoint();

    std::vector<Arrow *> arrows;

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;
    QPixmap pixmap;

private:
    QPolygonF myPolygon;

    void loadPolygon(QString path);
};


#endif // DIAGRAMITEM_H
