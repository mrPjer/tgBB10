#ifndef APICONTACTS_HPP_
#define APICONTACTS_HPP_

#include "apiDelay.hpp"
#include "apiTypes.hpp"
#include <QStringList>
#include <bb/cascades/CustomControl>
#include "TelegramNamespace.hpp"

class APIContacts: public bb::cascades::CustomControl
{
    Q_OBJECT

    APIDelay delay;

public:
    Q_INVOKABLE QStringList contactList() const;
    Q_INVOKABLE QVariant contactStatus(const QString &phone) const;
    Q_INVOKABLE QString contactFirstName(const QString &phone) const;
    Q_INVOKABLE QString contactLastName(const QString &phone) const;

public slots:
    void addContact(const QString& phone);
    void addContacts(const QStringList& phone_numbers);
    void deleteContact(const QString& phone);
    void deleteContacts(const QStringList& phone_numbers);

    void contactListChangedEmitter();

signals:
    void contactStatusChanged(const QString &phone, TelegramNamespace::ContactStatus status);
    void contactListChanged();
    void avatarReceived(const QString &contact, const QByteArray &data, const QString &mimeType);
};

#endif
