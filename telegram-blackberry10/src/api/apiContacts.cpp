/*
 * apiContacts.cpp
 *
 *  Created on: 11. 12. 2014.
 *      Author: Alfis
 */

#include "apiContacts.hpp"

void APIContacts::addContact(const QString& phone){
    connect(&delay, SIGNAL(finished()), this, SLOT(contactListChangedEmitter()));
    delay.start();
}
void APIContacts::addContacts(const QStringList& phone_numbers){
    connect(&delay, SIGNAL(finished()), this, SLOT(contactListChangedEmitter()));
    delay.start();
}
void APIContacts::deleteContact(const QString& phone){
    connect(&delay, SIGNAL(finished()), this, SLOT(contactListChangedEmitter()));
    delay.start();
}
void APIContacts::deleteContacts(const QStringList& phone_numbers){
    connect(&delay, SIGNAL(finished()), this, SLOT(contactListChangedEmitter()));
    delay.start();
}

void APIContacts::contactListChangedEmitter(){
    disconnect(&delay, SIGNAL(finished()), this, SLOT(contactListChangedEmitter()));
    emit contactListChanged();
}
