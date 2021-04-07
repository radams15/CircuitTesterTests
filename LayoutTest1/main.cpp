#include "MainWindow.h"

#include <QApplication>

int main(int argv, char *args[]){
    Q_INIT_RESOURCE(layouttest1);

    QApplication app(argv, args);
    MainWindow mainWindow;
    mainWindow.setGeometry(100, 100, 800, 500);
    mainWindow.show();

    return app.exec();
}
