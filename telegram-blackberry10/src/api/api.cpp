/*
 * api.cpp
 *
 *  Created on: 5. 12. 2014.
 *      Author: Alfis
 */

#include <api.hpp>

unsigned long API::sleepFrom = 300;
unsigned long API::sleepTo = 700;

API::API(){
    QTime time = QTime::currentTime();
    qsrand(time.msec());
}

void API::run(){
    delay();
}

void API::setSleepFrom(unsigned long msec){
    sleepFrom = msec;
}

void API::setSleepTo(unsigned long msec){
    sleepTo = msec;
}

