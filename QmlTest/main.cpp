#include "graphicsscene.h"

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "widgetitem.h"
#include <QProgressBar>
#include <QPushButton>
#include <QTimer>

int main(int argc, char *argv[]){
    QApplication app(argc, argv);

        QQmlApplicationEngine engine;
        qmlRegisterType<WidgetItem>("WidgetItem", 1, 0, "WidgetItem");

        const QUrl url(QStringLiteral("qrc:/main.qml"));

        WidgetItem* widgetItem = nullptr;

        QGraphicsScene scene;
        scene.addRect(QRectF(0, 0, 10, 10));

        QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                         [&scene, &widgetItem](QObject* object, const QUrl /*&url*/) {
            widgetItem = object->findChild<WidgetItem*>();
            Q_ASSERT(widgetItem);
            widgetItem->setWidget(&scene);
        });

        engine.load(url);

        return app.exec();
}
