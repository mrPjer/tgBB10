/*
 * thApi.cpp
 *
 *  Created on: 12. 12. 2014.
 *      Author: Alfis
 */

#include "tgApi.hpp"

CTelegramCore tgApi::core;

tgApi::tgApi(){

    connect( &core,  SIGNAL( connected() ), SIGNAL( connected() )  );
    connect( &core,  SIGNAL( phoneCodeRequired() ), SIGNAL( phoneCodeRequired() )  );
    connect( &core,  SIGNAL( phoneCodeIsInvalid() ), SIGNAL( phoneCodeIsInvalid() )  );
    connect( &core,  SIGNAL( authenticated() ), SIGNAL( authenticated() )  );
    connect( &core,  SIGNAL( contactListChanged() ), SIGNAL( contactListChanged() )  );
    connect( &core,  SIGNAL( phoneStatusReceived(const QString &phone, bool registered, bool invited) ), SIGNAL( phoneStatusReceived(const QString &phone, bool registered, bool invited) )  );
    connect( &core,  SIGNAL( avatarReceived(const QString &contact, const QByteArray &data, const QString &mimeType) ), SIGNAL( avatarReceived(const QString &contact, const QByteArray &data, const QString &mimeType) )  );

    connect( &core,  SIGNAL( messageReceived(const QString &phone, const QString &message, quint32 messageId) ), SIGNAL( messageReceived(const QString &phone, const QString &message, quint32 messageId) )  ); // Message id is incremental number
    connect( &core,  SIGNAL( chatMessageReceived(quint32 chatId, const QString &phone, const QString &message) ), SIGNAL( chatMessageReceived(quint32 chatId, const QString &phone, const QString &message) )  );
    connect( &core,  SIGNAL( contactStatusChanged(const QString &phone, TelegramNamespace::ContactStatus status) ), SIGNAL( contactStatusChanged(const QString &phone, TelegramNamespace::ContactStatus status) )  );
    connect( &core,  SIGNAL( contactTypingStatusChanged(const QString &phone, bool typingStatus) ), SIGNAL( contactTypingStatusChanged(const QString &phone, bool typingStatus) )  );
    connect( &core,  SIGNAL( contactChatTypingStatusChanged(quint32 chatId, const QString &phone, bool typingStatus) ), SIGNAL( contactChatTypingStatusChanged(quint32 chatId, const QString &phone, bool typingStatus) )  );

    connect( &core,  SIGNAL( sentMessageStatusChanged(const QString &phone, quint64 messageId, TelegramNamespace::MessageDeliveryStatus status) ), SIGNAL( sentMessageStatusChanged(const QString &phone, quint64 messageId, TelegramNamespace::MessageDeliveryStatus status) )  ); // Message id is random number

    connect( &core,  SIGNAL( chatAdded(quint32 publichChatId) ), SIGNAL( chatAdded(quint32 publichChatId) )  );
    connect( &core,  SIGNAL( chatChanged(quint32 publichChatId) ), SIGNAL( chatChanged(quint32 publichChatId) )  );

    connect( &core,  SIGNAL( initializated() ), SIGNAL( initializated() )  );
}

void tgApi::setAppInformation(const CAppInformation *newAppInfo){
    core.setAppInformation(newAppInfo);
}

QByteArray tgApi::connectionSecretInfo() const{
    return core.connectionSecretInfo();
}

bool tgApi::isAuthenticated(){
    return core.isAuthenticated();
}

QString tgApi::selfPhone() const{
    return core.selfPhone();
}

QStringList tgApi::contactList() const{
    return core.contactList();
}

TelegramNamespace::ContactStatus tgApi::contactStatus(const QString &phone) const{
    return core.contactStatus(phone);
}

QString tgApi::contactFirstName(const QString &phone) const{
    return core.contactFirstName(phone);
}

QString tgApi::contactLastName(const QString &phone) const{
    return core.contactLastName(phone);
}

QStringList tgApi::chatParticipants(quint32 publicChatId) const{
    return core.chatParticipants(publicChatId);
}

bool tgApi::initConnection(const QString &address, quint32 port){
    return core.initConnection(address, port);
}

bool tgApi::restoreConnection(const QByteArray &secret){
    return core.restoreConnection(secret);
}

void tgApi::requestPhoneStatus(const QString &phoneNumber){
    return core.requestPhoneStatus(phoneNumber);
}


void tgApi::requestPhoneCode(const QString &phoneNumber){
	return core.requestPhoneCode(phoneNumber);
}

void tgApi::signIn(const QString &phoneNumber, const QString &authCode){
	return core.signIn(phoneNumber, authCode);
}

void tgApi::signUp(const QString &phoneNumber, const QString &authCode, const QString &firstName, const QString &lastName){
	return core.signUp(phoneNumber, authCode, firstName, lastName);
}

void tgApi::addContact(const QString &phoneNumber){
	return core.addContact(phoneNumber);
}

void tgApi::addContacts(const QStringList &phoneNumbers){
	return core.addContacts(phoneNumbers);
}

void tgApi::deleteContact(const QString &phoneNumber){
	return core.deleteContact(phoneNumber);
}

void tgApi::deleteContacts(const QStringList &phoneNumbers){
	return core.deleteContacts(phoneNumbers);
}

void tgApi::requestContactList(){
	return core.requestContactList();
}

void tgApi::requestContactAvatar(const QString &contact){
	return core.requestContactAvatar(contact);
}

quint64 tgApi::sendMessage(const QString &phone, const QString &message){
	return core.sendMessage(phone,message);
} // Message id is random number

quint64 tgApi::sendChatMessage(quint32 chatId, const QString &message){
	return core.sendChatMessage(chatId, message);
} // Message id is random number

void tgApi::setTyping(const QString &phone, bool typingStatus){
	return core.setTyping(phone, typingStatus);
}

void tgApi::setChatTyping(quint32 chatId, bool typingStatus){
	return core.setChatTyping(chatId, typingStatus);
}

void tgApi::setMessageRead(const QString &phone, quint32 messageId){
	return core.setMessageRead(phone, messageId);
}

    // Set visible (not actual) online status.

void tgApi::setOnlineStatus(bool onlineStatus){
	return core.setOnlineStatus(onlineStatus);
}

quint32 tgApi::createChat(const QStringList &phones, const QString chatName){
	return core.createChat(phones, chatName);
}

