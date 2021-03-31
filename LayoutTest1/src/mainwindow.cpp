#include "mainwindow.h"

#include <iostream>

MainWindow::MainWindow(){

    layout = new QHBoxLayout();
    widget = new QWidget;
    widget->setLayout(layout);

    createMenus();

    scene = new GraphicsScene(this);
    scene->setSceneRect(QRectF(0, 0, 1000, 1000));

    view = new QGraphicsView(scene);

    layout->addWidget(view);

    setCentralWidget(widget);

    setWindowTitle(tr("Circuit Tester"));
}

void MainWindow::createMenus() {

}

void MainWindow::itemDeleted() {
    printf("Item Deleted!\n");
}

void MainWindow::lineButtonPressed() {
    printf("Line Time!\n");
}

void MainWindow::buttonGroupClicked(QAbstractButton *button) {
    std::cout << "Adding: " << button->toolTip().toStdString() << "\n";
}
