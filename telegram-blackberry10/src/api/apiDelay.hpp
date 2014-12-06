/*
 * apiDelay.hpp
 *
 *  Created on: 5. 12. 2014.
 *      Author: Alfis
 */

#ifndef APIDELAY_HPP_
#define APIDELAY_HPP_

#include <QThread>
#include <QTime>
using namespace std;

class APIDelay: public QThread{
    Q_OBJECT
private:
    static unsigned long sleepFrom;
    static unsigned long sleepTo;
    void run();

protected:
    void delay();

public:
    APIDelay();

public slots:
    void setSleepFrom(unsigned long msec);
    void setSleepTo(unsigned long msec);

};


#endif /* APIDELAY_HPP_ */
