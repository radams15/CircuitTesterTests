#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "SceneItem.h"

#include <QMainWindow>
#include <QAbstractButton>
#include <QComboBox>
#include <QFontComboBox>
#include <QToolBox>
#include <QToolButton>
#include <QGraphicsView>

#include "Scene.h"

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
   MainWindow();

private slots:
    void buttonGroupClicked(QAbstractButton *button);
    void deleteItem();
    void pointerGroupClicked();
    void itemInserted(Component *item);
    void sceneScaleChanged(const QString &scale);
    void about();
    void runSimulation();

private:
    void createToolBox();
    void createActions();
    void createMenus();
    void createToolbars();

    template<class T> QWidget *createCellWidget(const QString &text);

    Scene *scene;
    QGraphicsView *view;

    QAction *exitAction;
    QAction *deleteAction;
    QAction *runAction;
    QAction *aboutAction;

    QMenu *fileMenu;
    QMenu *itemMenu;
    QMenu *aboutMenu;
    QMenu *simMenu;

    QToolBar *pointerToolbar;

    QComboBox *sceneScaleCombo;

    QToolBox *toolBox;
    QButtonGroup *buttonGroup;
    QButtonGroup *pointerTypeGroup;
    QAction *lineAction;
};


#endif // MAINWINDOW_H
