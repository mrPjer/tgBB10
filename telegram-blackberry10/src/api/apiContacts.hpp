/*
 * apiContacts.hpp
 *
 *  Created on: 11. 12. 2014.
 *      Author: Alfis
 */

#ifndef APICONTACTS_HPP_
#define APICONTACTS_HPP_


#include "apiDelay.hpp"
#include "apiTypes.hpp"
#include <QStringList>
#include <bb/cascades/CustomControl>

class APIContacts: public bb::cascades::CustomControl{
    APIDelay delay;
    Q_OBJECT

signals:
    void contactListChanged();

public slots:
// CTelegramCore
    void addContact(const QString& phone);
    void addContacts(const QStringList& phone_numbers);
    void deleteContact(const QString& phone);
    void deleteContacts(const QStringList& phone_numbers);

    void contactListChangedEmitter();
// Got this far.
};



#endif /* APICONTACTS_HPP_ */
