//
// Created by Nick Semin on 12.12.2021.
//

#ifndef TRAFFIC_SIMULATOR_CUSTOMVIEW_H
#define TRAFFIC_SIMULATOR_CUSTOMVIEW_H

#include <QGraphicsView>
#include <QWidget>
#include <QtWidgets>

class CustomView : public QGraphicsView{
public:
    CustomView(QWidget* parent = 0);

protected:
    virtual void wheelEvent(QWheelEvent *event);
};


#endif //TRAFFIC_SIMULATOR_CUSTOMVIEW_H
