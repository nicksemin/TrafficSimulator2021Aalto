#include "simulationview.h"
#include "./ui_simulationview.h"
#include <QPainter>
#include <QGraphicsScene>



SimulationView::SimulationView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SimulationView)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->scene()->installEventFilter(this);
    ui->graphicsView->scale(0.6, 0.6);

    QBrush redBrush(Qt::green);
    QPen blackPen(Qt::black);
    blackPen.setWidth(6);
}

SimulationView::~SimulationView()
{
    delete ui;
}

void SimulationView::drawCity() {
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

void SimulationView::getCross(std::vector<std::pair<int, int>> fromCity) {
    crossRoads_ = fromCity;
}

void SimulationView::getRoads(std::vector<std::pair<std::pair<int, int>,std::pair<int, int>>> fromCity) {
    roads_ = fromCity;
}

void SimulationView::wheelEvent(QWheelEvent *event){

    ui->graphicsView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    // Scale the view / do the zoom
    double scaleFactor = 1.15;
    if(event->delta() > 0) {
        // Zoom in
        ui->graphicsView-> scale(scaleFactor, scaleFactor);

    } else {
        // Zooming out
        ui->graphicsView->scale(1.0 / scaleFactor, 1.0 / scaleFactor);
    }


    //ui->graphicsView->setTransform(QTransform(h11, h12, h21, h22, 0, 0));
}

/*bool SimulationView::eventFilter(QObject *obj, QGraphicsSceneWheelEvent *event) {
    if (event->type() == QEvent::GraphicsSceneWheel) {
        handleWheelOnGraphicsScene(static_cast<QGraphicsSceneWheelEvent*> (event));

        // Don't propagate
        event->accept();
        return true;
    }
    return false;
}*/
