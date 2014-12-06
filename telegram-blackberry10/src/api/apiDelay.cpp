/*
 * apiDelay.cpp
 *
 *  Created on: 5. 12. 2014.
 *      Author: Alfis
 */

#include "apiDelay.hpp"

unsigned long APIDelay::sleepFrom = 300;
unsigned long APIDelay::sleepTo = 700;

APIDelay::APIDelay(){
    QTime time = QTime::currentTime();
    qsrand(time.msec());
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
    ::delay(qrand() % (sleepTo - sleepFrom + 1) + sleepFrom);
}
