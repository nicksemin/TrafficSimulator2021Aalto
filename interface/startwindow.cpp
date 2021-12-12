//
// Created by Nick Semin on 12.12.2021.
//

// You may need to build the project (run Qt uic code generator) to get "ui_startWindow.h" resolved

#include "startwindow.h"
#include "ui_startWindow.h"


startWindow::startWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::startWindow) {
    ui->setupUi(this);
}

startWindow::~startWindow() {
    delete ui;
}

