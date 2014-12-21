/*
 * tgApi.hpp
 *
 *  Created on: 12. 12. 2014.
 *      Author: Alfis
 */

#ifndef TGAPI_HPP_
#define TGAPI_HPP_

#include "config.hpp"

#ifdef TG_API_TG

#include <bb/cascades/CustomControl>
#include "CAppInformation.hpp"
#include "TelegramNamespace.hpp"
#include "CTelegramCore.hpp"

class tgApi: public bb::cascades::CustomControl{
    Q_OBJECT

public:

    tgApi();

    inline const CAppInformation *appInfo() { return core->appInfo(); }
    void setAppInformation(const CAppInformation *newAppInfo);

    QByteArray connectionSecretInfo() const;

    Q_INVOKABLE bool isAuthenticated();
    Q_INVOKABLE QString selfPhone() const;
    Q_INVOKABLE QStringList contactList() const;
    Q_INVOKABLE TelegramNamespace::ContactStatus contactStatus(const QString &phone) const;
    Q_INVOKABLE QString contactFirstName(const QString &phone) const;
    Q_INVOKABLE QString contactLastName(const QString &phone) const;
    Q_INVOKABLE QStringList chatParticipants(quint32 publicChatId) const;

public slots:
    void onConnectRetryTimeout();
    bool initConnection(const QString &address, quint32 port);
    bool restoreConnection(const QByteArray &secret);

    void requestPhoneStatus(const QString &phoneNumber);
    void requestPhoneCode(const QString &phoneNumber);
    void signIn(const QString &phoneNumber, const QString &authCode);
    void signUp(const QString &phoneNumber, const QString &authCode, const QString &firstName, const QString &lastName);

    void addContact(const QString &phoneNumber);
    void addContacts(const QStringList &phoneNumbers);

    void deleteContact(const QString &phoneNumber);
    void deleteContacts(const QStringList &phoneNumbers);

    void requestContactAvatar(const QString &contact);

    quint64 sendMessage(const QString &phone, const QString &message); // Message id is random number
    quint64 sendChatMessage(quint32 chatId, const QString &message); // Message id is random number
    void setTyping(const QString &phone, bool typingStatus);
    void setChatTyping(quint32 chatId, bool typingStatus);

    void setMessageRead(const QString &phone, quint32 messageId);

    // Set visible (not actual) online status.
    void setOnlineStatus(bool onlineStatus);

    quint32 createChat(const QStringList &phones, const QString chatName);

signals:
    void connected();
    void phoneCodeRequired();
    void phoneCodeIsInvalid();
    void authenticated();
    void contactListChanged();
    void phoneStatusReceived(const QString &phone, bool registered, bool invited);
    void phoneNumberInvalid();
    void avatarReceived(const QString &contact, const QByteArray &data, const QString &mimeType);

    void messageReceived(const QString &phone, const QString &message, quint32 messageId); // Message id is incremental number
    void chatMessageReceived(quint32 chatId, const QString &phone, const QString &message);
    void contactStatusChanged(const QString &phone, TelegramNamespace::ContactStatus status);
    void contactTypingStatusChanged(const QString &phone, bool typingStatus);
    void contactChatTypingStatusChanged(quint32 chatId, const QString &phone, bool typingStatus);

    void sentMessageStatusChanged(const QString &phone, quint64 messageId, TelegramNamespace::MessageDeliveryStatus status); // Message id is random number

    void chatAdded(quint32 publichChatId);
    void chatChanged(quint32 publichChatId);

    void initializated();

private slots:
    void connectionEstablished();

private:
    static CTelegramCore* core;
};

#endif

#endif /* TGAPI_HPP_ */
