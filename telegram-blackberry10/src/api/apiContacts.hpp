#ifndef APICONTACTS_HPP_
#define APICONTACTS_HPP_

#include "apiDelay.hpp"
#include "apiTypes.hpp"
#include <QStringList>
#include <bb/cascades/CustomControl>

class APIContacts: public bb::cascades::CustomControl
{
    APIDelay delay;Q_OBJECT

signals:
    void contactListChanged();

public slots:
    void addContact(const QString& phone);
    void addContacts(const QStringList& phone_numbers);
    void deleteContact(const QString& phone);
    void deleteContacts(const QStringList& phone_numbers);

    void contactListChangedEmitter();
};

#endif
