#include "apiDelay.hpp"
#include <unistd.h>
#include <QDebug>
#include <QDateTime>

unsigned long APIDelay::sleepFrom = 200;
unsigned long APIDelay::sleepTo = 1300;

APIDelay::APIDelay(){
}

void APIDelay::run(){
    delay();
}

void APIDelay::setSleepFrom(unsigned long msec){
    sleepFrom = msec;
}

void APIDelay::setSleepTo(unsigned long msec){
    sleepTo = msec;
}


void APIDelay::delay(){
    qsrand(QDateTime::currentDateTime().toTime_t());
    ::delay(qrand() % (sleepTo - sleepFrom + 1) + sleepFrom);
}
