//
// Created by Nick Semin on 04.12.2021.
//

#ifndef TRAFFIC_SIMULATOR_MAINWINDOW_H
#define TRAFFIC_SIMULATOR_MAINWINDOW_H

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
    int X;
    int Y;
    std::vector<int> crossX_;
    std::vector<int> crossY_;
    ~MainWindow() override;

    void drawCity();

public slots:
  //  void addCrossRoads(int, int);

    void getCrossX(int);

    void getCrossY(int);

    void getValue(int);

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;
    QGraphicsRectItem *rectangle;
    QGraphicsRectItem *line;
   // QVector<std::pair<int,int>> crossroads_;
    QVector<std::pair<int,int>> roads_;
/*protected:
    void paintEvent(QPaintEvent *e) override;*/
};


#endif //TRAFFIC_SIMULATOR_MAINWINDOW_H
