#include <QTimer>
#include "timer.hpp"

Timer::Timer(QObject* parent) :
        bb::cascades::CustomControl(), _timer(new QTimer(this))
{
    Q_UNUSED(parent);

    bool connectResult;

    Q_UNUSED(connectResult);

    connectResult = connect(_timer, SIGNAL(timeout()), this, SIGNAL(timeout()));

    Q_ASSERT(connectResult);

    setVisible(false);
}

bool Timer::isActive()
{
    return _timer->isActive();
}

int Timer::interval()
{
    return _timer->interval();
}

void Timer::setInterval(int miliseconds)
{
    if (_timer->interval() == miliseconds) {
        return;
    }

    _timer->setInterval(miliseconds);
    emit intervalChanged();
}

void Timer::start()
{
    if (_timer->isActive()) {
        return;
    }

    _timer->start();
    emit activeChanged();
}

void Timer::stop()
{
    if (!_timer->isActive()) {
        return;
    }

    _timer->stop();
    emit activeChanged();
}
