//
// Created by Nick Semin on 12.12.2021.
//

#ifndef TRAFFIC_SIMULATOR_STARTWINDOW_H
#define TRAFFIC_SIMULATOR_STARTWINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class startWindow; }
QT_END_NAMESPACE

class startWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit startWindow(QWidget *parent = nullptr);

    ~startWindow() override;

private:
    Ui::startWindow *ui;
};


#endif //TRAFFIC_SIMULATOR_STARTWINDOW_H
