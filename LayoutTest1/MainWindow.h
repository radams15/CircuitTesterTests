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
    void itemSelected(QGraphicsItem *item);
    void about();

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

    QAction *aboutAction;

    QMenu *fileMenu;
    QMenu *itemMenu;
    QMenu *aboutMenu;

    QToolBar *pointerToolbar;

    QComboBox *sceneScaleCombo;
    QComboBox *fontSizeCombo;
    QFontComboBox *fontCombo;

    QToolBox *toolBox;
    QButtonGroup *buttonGroup;
    QButtonGroup *pointerTypeGroup;
    QButtonGroup *backgroundButtonGroup;
    QAction *boldAction;
    QAction *underlineAction;
    QAction *italicAction;
    QAction *lineAction;
};


#endif // MAINWINDOW_H
