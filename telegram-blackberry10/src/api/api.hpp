/*
 * api.hpp
 *
 *  Created on: 5. 12. 2014.
 *      Author: Alfis
 */

#ifndef API_HPP_
#define API_HPP_

#include <QThread>
#include <QTime>
#include <QGlobal.h>
#include <unistd.h>
using namespace std;

class API: public QThread{
    Q_OBJECT
private:
    static unsigned long sleepFrom;
    static unsigned long sleepTo;
    virtual void run() = 0;

protected:
    void delay(){
        ::delay(qrand() % (sleepTo - sleepFrom + 1) + sleepFrom);
    }

public:
    API();

public slots:
    void setSleepFrom(unsigned long msec);
    void setSleepTo(unsigned long msec);

};


#endif /* API_HPP_ */
