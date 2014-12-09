/*
 * apiMessages.cpp
 *
 *  Created on: 8. 12. 2014.
 *      Author: Alfis
 */

#include "apiMessages.hpp"


void APIMessages::sendMessage(){
	connect(&delay, SIGNAL(finished()), this, SLOT(()));
	delay.start();
}
void APIMessages::sendMedia(){
	connect(&delay, SIGNAL(finished()), this, SLOT(()));
	delay.start();
}
void APIMessages::setTyping(){
	connect(&delay, SIGNAL(finished()), this, SLOT(()));
	delay.start();
}
void APIMessages::getMessages(){
	connect(&delay, SIGNAL(finished()), this, SLOT(()));
	delay.start();
}
void APIMessages::getDialogs(){
	connect(&delay, SIGNAL(finished()), this, SLOT(()));
	delay.start();
}
void APIMessages::getHistory(){
	connect(&delay, SIGNAL(finished()), this, SLOT(()));
	delay.start();
}
void APIMessages::search(){
	connect(&delay, SIGNAL(finished()), this, SLOT(()));
	delay.start();
}
void APIMessages::readHistory(){
	connect(&delay, SIGNAL(finished()), this, SLOT(()));
	delay.start();
}
void APIMessages::readMessageContents(){
	connect(&delay, SIGNAL(finished()), this, SLOT(()));
	delay.start();
}
void APIMessages::deleteHistory(){
	connect(&delay, SIGNAL(finished()), this, SLOT(()));
	delay.start();
}
void APIMessages::deleteMessages(){
	connect(&delay, SIGNAL(finished()), this, SLOT(()));
	delay.start();
}
void APIMessages::restoreMessages(){
	connect(&delay, SIGNAL(finished()), this, SLOT(()));
	delay.start();
}
void APIMessages::receivedMessages(){
	connect(&delay, SIGNAL(finished()), this, SLOT(()));
	delay.start();
}
void APIMessages::forwardMessage(){
	connect(&delay, SIGNAL(finished()), this, SLOT(()));
	delay.start();
}
void APIMessages::forwardMessages(){
	connect(&delay, SIGNAL(finished()), this, SLOT(()));
	delay.start();
}
void APIMessages::sendBroadcast(){
	connect(&delay, SIGNAL(finished()), this, SLOT(()));
	delay.start();
}
void APIMessages::getChats(){
	connect(&delay, SIGNAL(finished()), this, SLOT(()));
	delay.start();
}
void APIMessages::getFullChat(){
	connect(&delay, SIGNAL(finished()), this, SLOT(()));
	delay.start();
}
void APIMessages::editChatTitle(){
	connect(&delay, SIGNAL(finished()), this, SLOT(()));
	delay.start();
}
void APIMessages::editChatPhoto(){
	connect(&delay, SIGNAL(finished()), this, SLOT(()));
	delay.start();
}
void APIMessages::addChatUser(){
	connect(&delay, SIGNAL(finished()), this, SLOT(()));
	delay.start();
}
void APIMessages::deleteChatUser(){
	connect(&delay, SIGNAL(finished()), this, SLOT(()));
	delay.start();
}
void APIMessages::createChat(){
	connect(&delay, SIGNAL(finished()), this, SLOT(()));
	delay.start();
}
void APIMessages::getDhConfig(){
	connect(&delay, SIGNAL(finished()), this, SLOT(()));
	delay.start();
}
void APIMessages::requestEncryption(){
	connect(&delay, SIGNAL(finished()), this, SLOT(()));
	delay.start();
}
void APIMessages::acceptEncryption(){
	connect(&delay, SIGNAL(finished()), this, SLOT(()));
	delay.start();
}
void APIMessages::discardEncryption(){
	connect(&delay, SIGNAL(finished()), this, SLOT(()));
	delay.start();
}
void APIMessages::setEncryptedTyping(){
	connect(&delay, SIGNAL(finished()), this, SLOT(()));
	delay.start();
}
void APIMessages::readEncryptedHistory(){
	connect(&delay, SIGNAL(finished()), this, SLOT(()));
	delay.start();
}
void APIMessages::sendEncrypted(){
	connect(&delay, SIGNAL(finished()), this, SLOT(()));
	delay.start();
}
void APIMessages::sendEncryptedFile(){
	connect(&delay, SIGNAL(finished()), this, SLOT(()));
	delay.start();
}
void APIMessages::sendEncryptedService(){
	connect(&delay, SIGNAL(finished()), this, SLOT(()));
	delay.start();
}

void APIMessages::messageSentEmitter();
void APIMessages::mediaSentEmitter();
void APIMessages::typingSetEmitter();
void APIMessages::messagesEmitter();
void APIMessages::dialogsEmitter();
void APIMessages::historyEmitter();
void APIMessages::searchedEmitter();
void APIMessages::historyReadEmitter();
void APIMessages::messageContentsReadEmitter();
void APIMessages::historyDeletedEmitter();
void APIMessages::messagesDeletedEmitter();
void APIMessages::messagesRestoredEmitter();
void APIMessages::messagesReceivedEmitter();
void APIMessages::mesageForwardedEmitter();
void APIMessages::messagesForwardedEmitter();
void APIMessages::broadcastSentEmitter();
void APIMessages::chatsEmitter();
void APIMessages::fullChatEmitter();
void APIMessages::chatTitleEditedEmitter();
void APIMessages::chatPhotoEditedEmitter();
void APIMessages::chatUserAddedEmitter();
void APIMessages::chatUserDeletedEmitter();
void APIMessages::chatCreatedEmitter();
void APIMessages::dhConfigEmitter();
void APIMessages::encryptionRequestedEmitter();
void APIMessages::encryptionAcceptedEmitter();
void APIMessages::encryptionDiscardedEmitter();
void APIMessages::encryptedTypingSetEmitter();
void APIMessages::encryptedHistoryReadEmitter();
void APIMessages::encryptedSentEmitter();
void APIMessages::encryptedFileSentEmitter();
void APIMessages::encryptedServiceSentEmitter();
