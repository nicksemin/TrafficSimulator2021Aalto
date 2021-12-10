//
// Created by Nick Semin on 04.12.2021.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include <QPainter>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

void MainWindow::getValue(int value) {
    testValue = value;
}

void MainWindow::getCrossX(int x) {
    //crossX_.push_back(x);
    X = x;

}

void MainWindow::getCrossY(int y) {
   //crossX_.push_back(y);
   Y = y;
}

/*void MainWindow::addCrossRoads(int x, int y) {
    auto newPair = std::make_pair(x,y);
    crossroads_.push_back(newPair);
}*/

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
   /*for (auto i:crossX_){
      // auto myRect = QRect(i.first, i.second, 30, 20);
        //QGraphicsEllipseItem *elip = scene->addEllipse(myRect, blackPen, redBrush);
        */
       // QGraphicsRectItem *rect = scene->addRect(X, Y, 40, 50);
    //}
    for (auto i: crossRoads){
        QGraphicsRectItem *rect = scene->addRect(i.first, i.second, 30, 40);
    }
}

void MainWindow::getCross(std::vector<std::pair<int, int>> fromCity) {
    crossRoads = fromCity;
}
/*void MainWindow::paintEvent(QPaintEvent *e) {
    QPainter painter(this);

    QPen pointpen(Qt::red);
    pointpen.setWidth(10);

    QPen linepen(Qt::green);
    linepen.setWidth(5);

    painter.setPen(linepen);
    painter.drawRect(0, 0, 200, 150);

    painter.drawArc(10, 10, 200, 20, 20, 600);
    painter.setPen(Qt::green);
}*/