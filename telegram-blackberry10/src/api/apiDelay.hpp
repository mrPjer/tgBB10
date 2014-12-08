#ifndef APIDELAY_HPP_
#define APIDELAY_HPP_

#include <QThread>
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


#endif
