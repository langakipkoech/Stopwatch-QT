#include "stopwatch.h"
#include "ui_stopwatch.h"

Stopwatch::Stopwatch(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Stopwatch),
    timer(new Qtimer(this)),
    timeElapsed(0,0),
    running(false)
{
    ui->setupUi(this);

    //connect the trigger buttons
    connect(ui->startButton, &QPushButton::clicked, this, &Stopwatch::startStopwatch);
    connect(ui->stopButton, &QPushButton::clicked, this, &Stopwatch::stopStopwatch);

    connect(ui->resetButton, &QPushButton::clicked, this, &Stopwatch::resetStopwatch);

    //update the display
     connect(timer, &QTimer::timeout, this, &Stopwatch::updateDisplay);

     //update timer every 10 secs
     timer->setInterval(10);

}

Stopwatch::~Stopwatch()
{
    delete ui;
}

//methods for starting stop watch
void Stopwatch::startStopwatch(){
    if(!running){
        running = true;
        timer->start();
    }
}

//method to stop the stop watch

void Stopwatch::stopStopwatch(){
    if(running){
        running = false;
        timer->stop();
    }
}

//reset stop watch
void Stopwatch::resetStopwatch(){
    timer->stop();
    timeElapsed.setHMS(0,0,0,0);
    running = false;
    updateDisplay();
}

//Update display
void Stopwatch::updateDisplay(){
    if(running){
        //increment by 10 milliseconds
        timeElapsed = timeElapsed.addMSecs(10);

    }
    ui->timeDisplay->setText(timeElapsed.toString("hh:mm:ss:zzz"));

}

