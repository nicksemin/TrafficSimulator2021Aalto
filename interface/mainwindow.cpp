//
// Created by Nick Semin on 04.12.2021.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include <QPainter>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

/*void MainWindow::getValue(int value) {
    testValue = value;
}
*/

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    QBrush redBrush(Qt::green);
    QPen blackPen(Qt::black);
    blackPen.setWidth(6);




}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::drawCity() {
    QBrush redBrush(Qt::green);
    QPen blackPen(Qt::black);
    blackPen.setWidth(6);

    for (auto i: crossRoads_){
        ellipse = scene->addEllipse(i.first, i.second, 10, 10, blackPen, redBrush);
    }
    for (auto i: roads_){
       line = scene->addLine(i.first.first, i.first.second, i.second.first, i.second.second);
    }
}

void MainWindow::getCross(std::vector<std::pair<int, int>> fromCity) {
    crossRoads_ = fromCity;
}

void MainWindow::getRoads(std::vector<std::pair<std::pair<int, int>,std::pair<int, int>>> fromCity) {
    roads_ = fromCity;
}
