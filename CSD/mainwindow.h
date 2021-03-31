#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "customwindow.h"

class MainWindow : public CustomWindow{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
