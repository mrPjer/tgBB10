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

#include <qdebug.h>

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
    connect(core, SIGNAL(avatarReceived(QString, QByteArray, QString)),
            SIGNAL(avatarReceived(QString, QByteArray, QString)));
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

QStringList tgApi::chatParticipants(quint32 publicChatId) const{
    return core->chatParticipants(publicChatId);
}

bool tgApi::initConnection(const QString &address, quint32 port){
    return core->initConnection(address, port);
}

bool tgApi::restoreConnection(const QByteArray &secret){
    return core->restoreConnection(secret);
}

void tgApi::requestPhoneStatus(const QString &phoneNumber){
    return core->requestPhoneStatus(phoneNumber);
}


void tgApi::requestPhoneCode(const QString &phoneNumber){
	return core->requestPhoneCode(phoneNumber);
}

void tgApi::signIn(const QString &phoneNumber, const QString &authCode){
	return core->signIn(phoneNumber, authCode);
}

void tgApi::signUp(const QString &phoneNumber, const QString &authCode, const QString &firstName, const QString &lastName){
	return core->signUp(phoneNumber, authCode, firstName, lastName);
}

void tgApi::addContact(const QString &phoneNumber){
	return core->addContact(phoneNumber);
}

void tgApi::addContacts(const QStringList &phoneNumbers){
	return core->addContacts(phoneNumbers);
}

void tgApi::deleteContact(const QString &phoneNumber){
	return core->deleteContact(phoneNumber);
}

void tgApi::deleteContacts(const QStringList &phoneNumbers){
	return core->deleteContacts(phoneNumbers);
}

void tgApi::requestContactAvatar(const QString &contact){
	return core->requestContactAvatar(contact);
}

quint64 tgApi::sendMessage(const QString &phone, const QString &message){
	return core->sendMessage(phone,message);
} // Message id is random number

quint64 tgApi::sendChatMessage(quint32 chatId, const QString &message){
	return core->sendChatMessage(chatId, message);
} // Message id is random number

void tgApi::setTyping(const QString &phone, bool typingStatus){
	return core->setTyping(phone, typingStatus);
}

void tgApi::setChatTyping(quint32 chatId, bool typingStatus){
	return core->setChatTyping(chatId, typingStatus);
}

void tgApi::setMessageRead(const QString &phone, quint32 messageId){
	return core->setMessageRead(phone, messageId);
}

    // Set visible (not actual) online status.

void tgApi::setOnlineStatus(bool onlineStatus){
	return core->setOnlineStatus(onlineStatus);
}

quint32 tgApi::createChat(const QStringList &phones, const QString chatName){
	return core->createChat(phones, chatName);
}

#endif
