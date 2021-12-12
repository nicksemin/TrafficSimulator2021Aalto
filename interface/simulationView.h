//
// Created by Nick Semin on 12.12.2021.
//

#ifndef TRAFFIC_SIMULATOR_SIMULATIONVIEW_H
#define TRAFFIC_SIMULATOR_SIMULATIONVIEW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QWheelEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class SimulationView; }
QT_END_NAMESPACE

class SimulationView : public QMainWindow
{
    Q_OBJECT

public:
    SimulationView(QWidget *parent = nullptr);
    std::vector<std::pair<int, int>> crossRoads_;
    std::vector<std::pair<std::pair<int, int>,std::pair<int, int>>> roads_;
    ~SimulationView() override;

    void drawCity();


public slots:
            void getCross(std::vector<std::pair<int, int>>);
    void getRoads(std::vector<std::pair<std::pair<int, int>,std::pair<int, int>>>);

protected:
    virtual void wheelEvent(QWheelEvent* event);
    //bool eventFilter(QObject *obj, QGraphicsSceneWheelEvent *event);

private:

    QGraphicsScene *scene;
    QGraphicsRectItem *rectangle;
    QGraphicsEllipseItem *ellipse;
    QGraphicsLineItem *line;

    Ui::SimulationView *ui;
};
#endif //TRAFFIC_SIMULATOR_SIMULATIONVIEW_H
