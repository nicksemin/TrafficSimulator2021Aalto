#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ProgressBar; }
QT_END_NAMESPACE

class ProgressBar : public QMainWindow
{
    Q_OBJECT
public:
    ProgressBar(QWidget *parent = nullptr);
    void setNewValue(int);
    ~ProgressBar();

public slots:
            void getStatus(int);

private:
    Ui::ProgressBar *ui;
};
#endif // PROGRESSBAR_H
