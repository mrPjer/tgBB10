/*
 * apiContacts.cpp
 *
 *  Created on: 11. 12. 2014.
 *      Author: Alfis
 */

#include "apiContacts.hpp"

void APIContacts::addContact(const QString& phone)
{
    connect(&delay, SIGNAL(finished()), this, SLOT(contactListChangedEmitter()));
    delay.start();
}
void APIContacts::addContacts(const QStringList& phone_numbers)
{
    connect(&delay, SIGNAL(finished()), this, SLOT(contactListChangedEmitter()));
    delay.start();
}
void APIContacts::deleteContact(const QString& phone)
{
    connect(&delay, SIGNAL(finished()), this, SLOT(contactListChangedEmitter()));
    delay.start();
}
void APIContacts::deleteContacts(const QStringList& phone_numbers)
{
    connect(&delay, SIGNAL(finished()), this, SLOT(contactListChangedEmitter()));
    delay.start();
}

QStringList APIContacts::contactList() const
{
    QStringList result;
    result.append("385911234001");
    result.append("385911234002");
    result.append("385911234003");
    result.append("385911234004");
    result.append("385911234005");
    result.append("385911234006");
    result.append("385911234007");
    result.append("385911234008");
    result.append("385911234009");
    result.append("385911234010");
    result.append("385911234011");
    result.append("385911234012");
    result.append("385911234013");
    result.append("385911234014");
    result.append("385911234015");

    return result;
}

QString APIContacts::contactFirstName(const QString &phone) const
{
    if (phone.endsWith("001")) {
        return "Adam";
    } else if (phone.endsWith("002")) {
        return "Anastasya";
    } else if (phone.endsWith("003")) {
        return "Bart";
    } else if (phone.endsWith("004")) {
        return "Boris";
    } else if (phone.endsWith("005")) {
        return "Jane";
    } else if (phone.endsWith("006")) {
        return "John";
    } else if (phone.endsWith("007")) {
        return "Jz";
    } else if (phone.endsWith("008")) {
        return "Omar";
    } else if (phone.endsWith("009")) {
        return "Oprah";
    } else if (phone.endsWith("010")) {
        return "Papa";
    } else if (phone.endsWith("011")) {
        return "Pero";
    } else if (phone.endsWith("012")) {
        return "Petar";
    } else if (phone.endsWith("013")) {
        return "Plavac";
    } else if (phone.endsWith("014")) {
        return "Psy";
    } else if (phone.endsWith("015")) {
        return "Tod";
    }
    return "Unknown";
}

QString APIContacts::contactLastName(const QString &phone) const
{
    if (phone.endsWith("001")) {
        return "Smith";
    } else if (phone.endsWith("002")) {
        return "Shy";
    } else if (phone.endsWith("003")) {
        return "Smith";
    } else if (phone.endsWith("004")) {
        return "Simpsoniac";
    } else if (phone.endsWith("005")) {
        return "Janice";
    } else if (phone.endsWith("006")) {
        return "Doe";
    } else if (phone.endsWith("007")) {
        return "JayZee";
    } else if (phone.endsWith("008")) {
        return "Pink";
    } else if (phone.endsWith("009")) {
        return "Perwoll";
    } else if (phone.endsWith("010")) {
        return "Papich";
    } else if (phone.endsWith("011")) {
        return "Perich";
    } else if (phone.endsWith("012")) {
        return "Tone";
    } else if (phone.endsWith("013")) {
        return "Zone";
    } else if (phone.endsWith("014")) {
        return "Psycho";
    } else if (phone.endsWith("015")) {
        return "Fisher";
    }
    return "Unknown";
}

QVariant APIContacts::contactStatus(const QString &phone) const
{
    int type = phone.right(3).toInt();

    if (type < 5 && type % 2 == 0) {
        return TelegramNamespace::ContactStatusOffline;
    } else if (type > 5 && type % 3 == 0) {
        return TelegramNamespace::ContactStatusUnknown;
    } else {
        return TelegramNamespace::ContactStatusOnline;
    }
}

void APIContacts::contactListChangedEmitter()
{
    disconnect(&delay, SIGNAL(finished()), this, SLOT(contactListChangedEmitter()));
    emit contactListChanged();
}


QString APIContacts::contactAvatarToken(const QString &phone) const
{
    return "";
}

QString APIContacts::requestContactAvatar(const QString &phone) const
{
    // Do nothing for now
}
