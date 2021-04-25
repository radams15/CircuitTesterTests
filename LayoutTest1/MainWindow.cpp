#include "Arrow.h"
#include "SceneItem.h"
#include "Scene.h"
#include "SceneText.h"
#include "MainWindow.h"

#include <QtWidgets>
#include <Components/Resistor.h>
#include <iostream>
#include <Components/Battery.h>

const int InsertTextButton = 10;

MainWindow::MainWindow() {
    createActions();
    createToolBox();
    createMenus();

    scene = new Scene(itemMenu, this);
    scene->setSceneRect(QRectF(0, 0, 5000, 5000));

    connect(scene, &Scene::itemInserted,
            this, &MainWindow::itemInserted);

    createToolbars();

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(toolBox);
    view = new QGraphicsView(scene);
    layout->addWidget(view);

    QWidget *widget = new QWidget;
    widget->setLayout(layout);

    setCentralWidget(widget);
    setWindowTitle(tr("Layout Test 1"));

    setUnifiedTitleAndToolBarOnMac(true);
}


void MainWindow::buttonGroupClicked(QAbstractButton *button) {
    const QList<QAbstractButton *> buttons = buttonGroup->buttons();
    for (QAbstractButton *myButton : buttons) {
        if (myButton != button)
            button->setChecked(false);
    }
    const int id = buttonGroup->id(button);

    if (id == InsertTextButton) {
        scene->setMode(Scene::InsertText);
    } else {
        if(id == Resistor::ID){
            scene->setItemType(new Resistor);
        }else if(id == Battery::ID){
            scene->setItemType(new Battery);
        }else{
            return;
        }

        scene->setMode(Scene::InsertItem);

    }
}



void MainWindow::deleteItem() {
    QList<QGraphicsItem *> selectedItems = scene->selectedItems();
    for (QGraphicsItem *item : qAsConst(selectedItems)) {
        if (item->type() == Arrow::Type) {
            scene->removeItem(item);
            Arrow *arrow = qgraphicsitem_cast<Arrow *>(item);
            arrow->startItem()->removeArrow(arrow);
            arrow->endItem()->removeArrow(arrow);
            delete item;
        }
    }

    selectedItems = scene->selectedItems();
    for (QGraphicsItem *item : qAsConst(selectedItems)) {
         if (item->type() == SceneItem::Type)
             qgraphicsitem_cast<SceneItem *>(item)->removeArrows();
         scene->removeItem(item);
         delete item;
     }
}


void MainWindow::pointerGroupClicked() {
    scene->setMode(Scene::Mode(pointerTypeGroup->checkedId()));
}


void MainWindow::itemInserted(Component *c) {
    pointerTypeGroup->button(int(Scene::MoveItem))->setChecked(true);
    scene->setMode(Scene::Mode(pointerTypeGroup->checkedId()));
    buttonGroup->button(c->getId())->setChecked(false);
}


void MainWindow::sceneScaleChanged(const QString &scale) {
    double newScale = scale.left(scale.indexOf(tr("%"))).toDouble() / 100.0;
    QTransform oldMatrix = view->transform();
    view->resetTransform();
    view->translate(oldMatrix.dx(), oldMatrix.dy());
    view->scale(newScale, newScale);
}


void MainWindow::about() {
    QMessageBox::about(this, tr("About"),
                       tr("This is the <b>first</b> layout test."));
}


void MainWindow::createToolBox() {
    buttonGroup = new QButtonGroup(this);
    buttonGroup->setExclusive(false);
    connect(buttonGroup, QOverload<QAbstractButton *>::of(&QButtonGroup::buttonClicked),
            this, &MainWindow::buttonGroupClicked);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(createCellWidget<Resistor>(tr("Resistor")), 0, 0);
    layout->addWidget(createCellWidget<Battery>(tr("Battery")), 0, 1);

    layout->setRowStretch(3, 10);
    layout->setColumnStretch(2, 10);

    QWidget *itemWidget = new QWidget;
    itemWidget->setLayout(layout);


    toolBox = new QToolBox;
    toolBox->setSizePolicy(QSizePolicy(QSizePolicy::Maximum, QSizePolicy::Ignored));
    toolBox->setMinimumWidth(itemWidget->sizeHint().width());
    toolBox->addItem(itemWidget, tr("Basic Components"));
}


void MainWindow::createActions() {
    deleteAction = new QAction(QIcon(":/res/delete.png"), tr("&Delete"), this);
    deleteAction->setShortcut(tr("Delete"));
    deleteAction->setStatusTip(tr("Delete item from diagram"));
    connect(deleteAction, &QAction::triggered, this, &MainWindow::deleteItem);

    exitAction = new QAction(tr("E&xit"), this);
    exitAction->setShortcuts(QKeySequence::Quit);
    exitAction->setStatusTip(tr("Quit the circuit simulator"));
    connect(exitAction, &QAction::triggered, this, &QWidget::close);

    runAction = new QAction(tr("R&un"), this);
    runAction->setShortcut(tr("F5"));
    runAction->setStatusTip(tr("Run the circuit"));
    connect(runAction, &QAction::triggered, this, &MainWindow::runSimulation);

    aboutAction = new QAction(tr("A&bout"), this);
    aboutAction->setShortcut(tr("F1"));
    connect(aboutAction, &QAction::triggered, this, &MainWindow::about);
}


void MainWindow::createMenus() {
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(exitAction);

    simMenu = menuBar()->addMenu(tr("&Sim"));
    simMenu->addAction(runAction);

    itemMenu = menuBar()->addMenu(tr("&Item"));
    itemMenu->addAction(deleteAction);
    itemMenu->addSeparator();

    aboutMenu = menuBar()->addMenu(tr("&Help"));
    aboutMenu->addAction(aboutAction);
}


void MainWindow::createToolbars() {
    QToolButton *pointerButton = new QToolButton;
    pointerButton->setCheckable(true);
    pointerButton->setChecked(true);
    pointerButton->setIcon(QIcon(":/res/pointer.png"));
    QToolButton *linePointerButton = new QToolButton;
    linePointerButton->setCheckable(true);
    linePointerButton->setIcon(QIcon(":/res/linepointer.png"));

    pointerTypeGroup = new QButtonGroup(this);
    pointerTypeGroup->addButton(pointerButton, int(Scene::MoveItem));
    pointerTypeGroup->addButton(linePointerButton, int(Scene::InsertLine));
    connect(pointerTypeGroup, QOverload<QAbstractButton *>::of(&QButtonGroup::buttonClicked),
            this, &MainWindow::pointerGroupClicked);

    sceneScaleCombo = new QComboBox;
    QStringList scales;
    scales << tr("50%") << tr("75%") << tr("100%") << tr("125%") << tr("150%");
    sceneScaleCombo->addItems(scales);
    sceneScaleCombo->setCurrentIndex(2);
    connect(sceneScaleCombo, &QComboBox::currentTextChanged,
            this, &MainWindow::sceneScaleChanged);

    pointerToolbar = addToolBar(tr("Pointer type"));
    pointerToolbar->addWidget(pointerButton);
    pointerToolbar->addWidget(linePointerButton);
    pointerToolbar->addWidget(sceneScaleCombo);

}


template<class T>
QWidget *MainWindow::createCellWidget(const QString &text) {
    T item;

    QIcon icon(item.getPixmap());

    QToolButton *button = new QToolButton;
    button->setIcon(icon);
    button->setIconSize(QSize(50, 50));
    button->setCheckable(true);
    buttonGroup->addButton(button, item.getId());

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(button, 0, 0, Qt::AlignHCenter);
    layout->addWidget(new QLabel(text), 1, 0, Qt::AlignCenter);

    QWidget *widget = new QWidget;
    widget->setLayout(layout);

    return widget;
}

void MainWindow::runSimulation() {
    std::vector<Component*> components;
    std::vector<Arrow*> arrows;

    for(QGraphicsItem *i : scene->items()){
        if(dynamic_cast<Component*>(i) != nullptr) { // is a Component
            components.push_back((Component*) i);
        } else if(dynamic_cast<Arrow*>(i) != nullptr) { // is an Arrow
            arrows.push_back((Arrow*) i);
        }
    }

    std::cout << arrows.size() << ", " << components.size() << std::endl;

    int min_x, min_y = INT_MAX;

    for(auto c : components){
        if(c->pos().x() < min_x){
            min_x = c->pos().x();
        }
        if(c->pos().y() < min_y){
            min_y = c->pos().y();
        }
    }

    int node = 0;
    QList<Arrow*>* as;
    for(auto c : components){

    }
}
