#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QMainWindow>
#include<QWidget>
#include<QTimer>
#include<QTime>

namespace Ui {
class Stopwatch;
}

class Stopwatch : public QMainWindow
{
    Q_OBJECT

public:
    explicit Stopwatch(QWidget *parent = 0);
    ~Stopwatch();

private slots:
    void startStopwatch();
    void stopStopwatch();
    void resetStopwatch();
    void updateDisplay();

    void on_pushButton_clicked();

private:
    Ui::Stopwatch *ui;
    QTimer* timer;
    QTime timeElapsed;
    bool running;
};

#endif // STOPWATCH_H
