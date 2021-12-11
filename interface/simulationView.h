//
// Created by Nick Semin on 04.12.2021.
//

#ifndef TRAFFIC_SIMULATOR_SIMULATIONVIEW_H
#define TRAFFIC_SIMULATOR_SIMULATIONVIEW_H

#include <QMainWindow>
#include <QGraphicsScene>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    int testValue;
    std::vector<std::pair<int, int>> crossRoads_;
    std::vector<std::pair<std::pair<int, int>,std::pair<int, int>>> roads_;
    ~MainWindow() override;

    void drawCity();

public slots:
    void getCross(std::vector<std::pair<int, int>>);
    void getRoads(std::vector<std::pair<std::pair<int, int>,std::pair<int, int>>>);

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;
    QGraphicsRectItem *rectangle;
    QGraphicsEllipseItem *ellipse;
    QGraphicsLineItem *line;
/*protected:
    void paintEvent(QPaintEvent *e) override;*/
};


#endif //TRAFFIC_SIMULATOR_SIMULATIONVIEW_H
