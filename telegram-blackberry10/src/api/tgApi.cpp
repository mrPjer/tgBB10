/*
 * thApi.cpp
 *
 *  Created on: 12. 12. 2014.
 *      Author: Alfis
 */

#include "config.hpp"
#ifdef TG_API_TG

#include "tgApi.hpp"
#include "app_secrets.hpp"
#include "TLValues.h"
#include <util/AvatarUtil.hpp>

#include <qdebug.h>
#include <QDate>
#include <QDateTime>

CTelegramCore* tgApi::core = NULL;

tgApi::tgApi(){

    bool shouldInit = false;

    if(core == NULL){
        core = new CTelegramCore();
        shouldInit = true;
    }

    connect(core, SIGNAL(connected()), SIGNAL(connected()));
    connect(core, SIGNAL(connected()), SLOT(connectionEstablished()));
    connect(core, SIGNAL(phoneCodeRequired()), SIGNAL(phoneCodeRequired()));
    connect(core, SIGNAL(phoneCodeIsInvalid()), SIGNAL(phoneCodeIsInvalid()));
    connect(core, SIGNAL(authenticated()), SIGNAL(authenticated()));
    connect(core, SIGNAL(contactListChanged()), SIGNAL(contactListChanged()));
    connect(core, SIGNAL(phoneStatusReceived(QString, bool, bool)),
            SIGNAL(phoneStatusReceived(QString, bool, bool)));
    connect(core, SIGNAL(phoneNumberInvalid()), SIGNAL(phoneNumberInvalid()));
    connect(core, SIGNAL(avatarReceived(QString, QByteArray, QString, QString)),
            SIGNAL(avatarReceived(QString, QByteArray, QString, QString)));
    connect(core, SIGNAL(messageReceived(QString, QString, quint32)),
            SIGNAL(messageReceived(QString, QString, quint32)));
    connect(core, SIGNAL(chatMessageReceived(quint32, QString, QString)),
            SIGNAL(chatMessageReceived(quint32, QString, QString)));
    connect(core, SIGNAL(contactStatusChanged(QString, TelegramNamespace::ContactStatus)),
            SIGNAL(contactStatusChanged(QString, TelegramNamespace::ContactStatus)));
    connect(core, SIGNAL(contactTypingStatusChanged(QString, bool)),
            SIGNAL(contactTypingStatusChanged(QString, bool)));
    connect(core, SIGNAL(contactChatTypingStatusChanged(quint32, QString, bool)),
            SIGNAL(contactChatTypingStatusChanged(quint32, QString, bool)));
    connect(core,
            SIGNAL(
                    sentMessageStatusChanged(QString, quint64, TelegramNamespace::MessageDeliveryStatus)),
            SIGNAL(
                    sentMessageStatusChanged(QString, quint64, TelegramNamespace::MessageDeliveryStatus)));
    connect(core, SIGNAL(chatAdded(quint32)), SIGNAL(chatAdded(quint32)));
    connect(core, SIGNAL(chatChanged(quint32)), SIGNAL(chatChanged(quint32)));
    connect(core, SIGNAL(initializated()), SIGNAL(initializated()));
    connect(core, SIGNAL(dialogsChanged()), SIGNAL(dialogsChanged()));
    connect(core, SIGNAL(authorizationErrorReceived()), SIGNAL(authorizationErrorReceived()));

    if(shouldInit){
        CAppInformation info;
        info.setAppId(TG_APP_ID);
        info.setAppHash(QLatin1String(TG_API_HASH));
        info.setAppVersion(QLatin1String("0.0.1"));
        info.setDeviceInfo(QLatin1String("BlackBerry 10"));
        info.setLanguageCode(QLatin1String("en"));
        info.setOsInfo(QLatin1String("BlackBerry 10"));
        core->setAppInformation(&info);
        core->initConnection(QLatin1String(TG_API_IP), TG_API_PORT);
    }

}

void tgApi::connectionEstablished() {
    qDebug() << "Connection established";
}

void tgApi::onConnectRetryTimeout() {
    qDebug() << "Retrying connection";
    const QByteArray secret = core->connectionSecretInfo();
    if(!secret.isEmpty()) {
        core->restoreConnection(secret);
    }
}

void tgApi::setAppInformation(const CAppInformation *newAppInfo){
    core->setAppInformation(newAppInfo);
}

QByteArray tgApi::connectionSecretInfo() const{
    return core->connectionSecretInfo();
}

bool tgApi::isAuthenticated(){
    return core->isAuthenticated();
}

QString tgApi::selfPhone() const{
    return core->selfPhone();
}

QStringList tgApi::contactList() const{
    return core->contactList();
}

QList<ChatListItem*> tgApi::dialogs() const{
    TLMessagesDialogs dialogs = core->dialogs();

    QList<ChatListItem*> result;
    QDate today = QDate::currentDate();
    QMap<int, TLUser> userMap;
    QMap<int, TLChat> chatMap;
    QMap<int, TLMessage> messageMap;

    foreach(const TLUser& user, dialogs.users) {
        userMap.insert(user.id, user);
    }

    foreach(const TLChat& chat, dialogs.chats) {
        chatMap.insert(chat.id, chat);
    }

    foreach(const TLMessage& message, dialogs.messages) {
        messageMap.insert(message.id, message);
    }

    foreach(const TLDialog dialog, dialogs.dialogs) {
        int unreadCount = dialog.unreadCount;

        QString title;
        QString imagePath;
        ChatListItem::Type type;

        if(dialog.peer.tlType == PeerUser) {
            int userId = dialog.peer.userId;
            type = ChatListItem::GROUP;
            if(userMap.contains(userId)) {
                TLUser user = userMap[userId];
                if(user.photo.photoId == 0) {
                    imagePath = AvatarUtil::getPlaceholderAvatarPath(user.phone);
                } else {
                    imagePath = AvatarUtil::getAvatarPath(user.phone);
                }
                title = QString("%1 %2").arg(user.firstName, user.lastName);
            } else {
                title = QString("Unknown user %1").arg(userId);
            }
        } else if(dialog.peer.tlType == PeerChat) {
            int chatId = dialog.peer.chatId;
            imagePath = AvatarUtil::getGroupPlaceholderAvatarPath(chatId);
            type = ChatListItem::NORMAL;
            if(chatMap.contains(chatId)) {
                TLChat chat = chatMap[chatId];
                title = chat.title;
            } else {
                title = QString("Unknown chat %1").arg(chatId);
            }
        }

        QString content;
        QString timestamp;
        QString seen;
        QString author;
        if(messageMap.contains(dialog.topMessage)) {
            TLMessage topMessage = messageMap[dialog.topMessage];
            content = topMessage.message;

            int time = topMessage.date;

            QDateTime qdt;
            qdt.setTime_t(time);
            QDate date = qdt.date();
            if(date == today) {
                timestamp = qdt.toString("hh:mm");
            } else if(date.daysTo(today) < 7) {
                timestamp = qdt.toString("ddd");
            } else {
                timestamp = qdt.toString("dd.MM.yy");
            }

            bool unread = topMessage.flags & 0x1;
            bool out = topMessage.flags & 0x2;
            if(!unread) {
                seen = "seen";
            } else if(out) {
                seen = "delivered";
            } else {
                seen = "none";
            }

            if(out) {
                author = "You";
            } else {
                TLUser messageAuthor = userMap[topMessage.fromId];
                author = QString("%1").arg(messageAuthor.firstName);
            }
        } else {
            content = "Unknown content";
        }

        result.append(new ChatListItem(
                // TODO asign proper parent
                0,
                title,
                content,
                timestamp,
                author,
                imagePath,
                seen,
                // TODO support for secret chats
                type,
                unreadCount
        ));

    }

    return result;
}

QVariant tgApi::contactStatus(const QString &phone) const{
    TelegramNamespace::ContactStatus result = core->contactStatus(phone);
    return result;
}

QString tgApi::contactFirstName(const QString &phone) const{
    return core->contactFirstName(phone);
}

QString tgApi::contactLastName(const QString &phone) const{
    return core->contactLastName(phone);
}

QString tgApi::contactAvatarToken(const QString &phone) const {
    return core->contactAvatarToken(phone);
}

QString tgApi::chatTitle(quint32 chatId) const {
    return core->chatTitle(chatId);
}

bool tgApi::getChatInfo(TelegramNamespace::GroupChat *chatInfo, quint32 chatId) const {
    return core->getChatInfo(chatInfo, chatId);
}

bool tgApi::getChatParticipants(QStringList *participants, quint32 chatId) {
    return core->getChatParticipants(participants, chatId);
}

QStringList tgApi::chatParticipants(quint32 publicChatId) const{
    return core->chatParticipants(publicChatId);
}

bool tgApi::initConnection(const QString &address, quint32 port){
    return core->initConnection(address, port);
}

bool tgApi::restoreConnection(const QByteArray &secret){
    return core->restoreConnection(secret);
}

void tgApi::closeConnection() {
    core->closeConnection();
}

void tgApi::requestPhoneStatus(const QString &phoneNumber){
    core->requestPhoneStatus(phoneNumber);
}


void tgApi::requestPhoneCode(const QString &phoneNumber){
	core->requestPhoneCode(phoneNumber);
}

void tgApi::signIn(const QString &phoneNumber, const QString &authCode){
	core->signIn(phoneNumber, authCode);
}

void tgApi::signUp(const QString &phoneNumber, const QString &authCode, const QString &firstName, const QString &lastName){
	core->signUp(phoneNumber, authCode, firstName, lastName);
}

void tgApi::addContact(const QString &phoneNumber){
	core->addContact(phoneNumber);
}

void tgApi::addContacts(const QStringList &phoneNumbers){
	core->addContacts(phoneNumbers);
}

void tgApi::deleteContact(const QString &phoneNumber){
	core->deleteContact(phoneNumber);
}

void tgApi::deleteContacts(const QStringList &phoneNumbers){
	core->deleteContacts(phoneNumbers);
}

void tgApi::getDialogs(quint32 offset, quint32 maxId, quint32 limit) {
    core->getDialogs(offset, maxId, limit);
}

void tgApi::requestContactAvatar(const QString &contact){
	core->requestContactAvatar(contact);
}

quint64 tgApi::sendMessage(const QString &phone, const QString &message){
	return core->sendMessage(phone,message);
} // Message id is random number

quint64 tgApi::sendChatMessage(quint32 chatId, const QString &message){
	return core->sendChatMessage(chatId, message);
} // Message id is random number

void tgApi::setTyping(const QString &phone, bool typingStatus){
	core->setTyping(phone, typingStatus);
}

void tgApi::setChatTyping(quint32 chatId, bool typingStatus){
	core->setChatTyping(chatId, typingStatus);
}

void tgApi::setMessageRead(const QString &phone, quint32 messageId){
	core->setMessageRead(phone, messageId);
}

    // Set visible (not actual) online status.

void tgApi::setOnlineStatus(bool onlineStatus){
	core->setOnlineStatus(onlineStatus);
}

quint32 tgApi::createChat(const QStringList &phones, const QString chatName){
	return core->createChat(phones, chatName);
}

#endif
