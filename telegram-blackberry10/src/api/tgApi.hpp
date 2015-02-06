/*
 * tgApi.hpp
 *
 *  Created on: 12. 12. 2014.
 *      Author: Alfis
 */

#ifndef TGAPI_HPP_
#define TGAPI_HPP_

#include "config.hpp"

#include "TLTypes.hpp"

#ifdef TG_API_TG

#include <bb/cascades/CustomControl>
#include "CAppInformation.hpp"
#include "TelegramNamespace.hpp"
#include "CTelegramCore.hpp"
#include "model/ChatItem.hpp"

#include "model/ChatListItem.hpp"

class tgApi: public bb::cascades::CustomControl{
    Q_OBJECT

public:

    tgApi();

    inline const CAppInformation *appInfo() { return core->appInfo(); }
    void setAppInformation(const CAppInformation *newAppInfo);

    Q_INVOKABLE QByteArray connectionSecretInfo() const;

    Q_INVOKABLE bool isAuthenticated();
    Q_INVOKABLE QStringList contactList() const;
    Q_INVOKABLE QString selfPhone() const;
    Q_INVOKABLE QString selfFirstName() const;
    Q_INVOKABLE QString selfLastName() const;
    Q_INVOKABLE QString selfUsername() const;
    Q_INVOKABLE QList<ChatListItem*> dialogs() const;
    Q_INVOKABLE QVariant contactStatus(const QString &phone) const;
    Q_INVOKABLE QString contactFirstName(const QString &phone) const;
    Q_INVOKABLE QString contactLastName(const QString &phone) const;
    Q_INVOKABLE QString contactAvatarToken(const QString &phone) const;
    Q_INVOKABLE QString chatTitle(quint32 chatId) const;
    Q_INVOKABLE QStringList chatParticipants(quint32 publicChatId) const;

    Q_INVOKABLE bool getChatInfo(TelegramNamespace::GroupChat *chatInfo, quint32 chatId) const;
    Q_INVOKABLE bool getChatParticipants(QStringList *participants, quint32 chatId);

public slots:
    void onConnectRetryTimeout();
    bool initConnection(const QString &address, quint32 port);
    bool restoreConnection(const QByteArray &secret);
    void closeConnection();

    void requestPhoneStatus(const QString &phoneNumber);
    void requestPhoneCode(const QString &phoneNumber);
    void signIn(const QString &phoneNumber, const QString &authCode);
    void signUp(const QString &phoneNumber, const QString &authCode, const QString &firstName, const QString &lastName);

    void addContact(const QString &phoneNumber);
    void addContacts(const QStringList &phoneNumbers);

    void deleteContact(const QString &phoneNumber);
    void deleteContacts(const QStringList &phoneNumbers);

    void getDialogs(quint32 offset, quint32 maxId, quint32 limit);
    void getHistory(const QString& phoneNumber, quint32 offset, quint32 maxId, quint32 limit);

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
    void authenticated();
    void initializated();
    void selfUserKnown();
    void phoneCodeRequired();
    void phoneCodeIsInvalid();
    void contactListChanged();
    void phoneStatusReceived(const QString &phone, bool registered, bool invited);
    void phoneNumberInvalid();
    void avatarReceived(const QString &contact, const QByteArray &data, const QString &mimeType, const QString& avatarToken);

    void messageReceived(const QString &phone, const QString &message, quint32 messageId); // Message id is incremental number
    void chatMessageReceived(quint32 chatId, const QString &phone, const QString &message);
    void contactStatusChanged(const QString &phone, TelegramNamespace::ContactStatus status);
    void contactTypingStatusChanged(const QString &phone, bool typingStatus);
    void contactChatTypingStatusChanged(quint32 chatId, const QString &phone, bool typingStatus);

    void dialogsChanged();
    void chatHistoryReceived(QVector<ChatItem*> messages);

    void sentMessageStatusChanged(const QString &phone, quint64 messageId, TelegramNamespace::MessageDeliveryStatus status); // Message id is random number

    void chatAdded(quint32 publichChatId);
    void chatChanged(quint32 publichChatId);

    void authorizationErrorReceived();

private slots:
    void connectionEstablished();
    void messagesHistoryReceived(const QVector<TLMessage> &messages, const QVector<TLChat> &chats, const QVector<TLUser> &users);
    void messagesHistorySliceReceived(quint32 count, const QVector<TLMessage> &messages, const QVector<TLChat> &chats, const QVector<TLUser> &users);


private:
    static CTelegramCore* core;
};

#endif

#endif /* TGAPI_HPP_ */
