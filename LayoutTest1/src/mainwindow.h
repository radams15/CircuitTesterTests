#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>
#include <QToolBox>

#include <QtWidgets>

#include "Component.h"

#include <src/Components/Resistor.h>

#include "Component.h"
#include "GraphicsScene.h"

class MainWindow : public QMainWindow{
    Q_OBJECT

private:
    void createToolbox();
    void createMenus();

    QHBoxLayout* layout;
    QWidget* widget;

    GraphicsScene* scene;
    QGraphicsView* view;

    QButtonGroup* buttonGroup;
    QToolBox* toolbox;

private slots:
    void itemDeleted();

    void lineButtonPressed();

    void buttonGroupClicked(QAbstractButton *button);

public:
    MainWindow();

};

#endif // MAINWINDOW_H
