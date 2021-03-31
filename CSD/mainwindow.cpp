#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : CustomWindow(parent){

    setCentralWidget(new QPushButton("main"));
}

MainWindow::~MainWindow(){

}

