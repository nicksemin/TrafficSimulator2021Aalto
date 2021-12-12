#include "progressbar.h"
#include "./ui_progressbar.h"

ProgressBar::ProgressBar(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ProgressBar)
{
    ui->setupUi(this);
}

void ProgressBar::getStatus(int newValue){
    ui->progressBar->setValue(newValue);
    qApp->processEvents();
}

ProgressBar::~ProgressBar()
{
    delete ui;
}

void ProgressBar::setNewValue(int newValue) {
    ui->progressBar->setValue(newValue);
}

