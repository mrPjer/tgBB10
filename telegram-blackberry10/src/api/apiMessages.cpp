/*
 * apiMessages.cpp
 *
 *  Created on: 8. 12. 2014.
 *      Author: Alfis
 */

#include "apiMessages.hpp"

APIMessages::APIMessages(){
    sem.id = 1337;
    sem.date = 31337;
    sem.pts = 1;
    sem.seq = 2222;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
}

void APIMessages::sendMessage(InputPeer* peer, QString message, long random_id){
	connect(&delay, SIGNAL(finished()), this, SLOT(messageSent()));
	delay.start();
}
void APIMessages::sendMedia(InputPeer* peer, InputMedia* media, long random_id){
	connect(&delay, SIGNAL(finished()), this, SLOT(mediaSent()));
	delay.start();
}
void APIMessages::setTyping(InputPeer* peer, bool typing, SendMessageAction* action){
	connect(&delay, SIGNAL(finished()), this, SLOT(typingSet()));
	delay.start();
}
void APIMessages::getMessages(vector<int>* id){
	connect(&delay, SIGNAL(finished()), this, SLOT(messages()));
	delay.start();
}
void APIMessages::getDialogs(int offset, int max_id, int limit){
	connect(&delay, SIGNAL(finished()), this, SLOT(dialogs()));
	delay.start();
}
void APIMessages::getHistory(InputPeer* peer, int offset, int max_id, int limit){
	connect(&delay, SIGNAL(finished()), this, SLOT(history()));
	delay.start();
}
void APIMessages::search(InputPeer* peer, QString q, MessagesFilter* filter, int min_date, int max_date, int offset, int max_id, int limit){
	connect(&delay, SIGNAL(finished()), this, SLOT(searched()));
	delay.start();
}
void APIMessages::readHistory(InputPeer* peer, int max_id, int offset, bool read_contents){
	connect(&delay, SIGNAL(finished()), this, SLOT(historyRead()));
	delay.start();
}
void APIMessages::readMessageContents(vector<int>* id){
	connect(&delay, SIGNAL(finished()), this, SLOT(messageContentsRead()));
	delay.start();
}
void APIMessages::deleteHistory(InputPeer* peer, int offset){
	connect(&delay, SIGNAL(finished()), this, SLOT(historyDeleted()));
	delay.start();
}
void APIMessages::deleteMessages(vector<int>* id){
	connect(&delay, SIGNAL(finished()), this, SLOT(messagesDeleted()));
	delay.start();
}
void APIMessages::restoreMessages(vector<int>* id){
	connect(&delay, SIGNAL(finished()), this, SLOT(messagesRestored()));
	delay.start();
}
void APIMessages::receivedMessages(int max_id){
	connect(&delay, SIGNAL(finished()), this, SLOT(messagesReceived()));
	delay.start();
}
void APIMessages::forwardMessage(InputPeer* peer, int id, long random_id){
	connect(&delay, SIGNAL(finished()), this, SLOT(mesageForwarded()));
	delay.start();
}
void APIMessages::forwardMessages(InputPeer* peer, vector<int>* id){
	connect(&delay, SIGNAL(finished()), this, SLOT(messagesForwarded()));
	delay.start();
}
void APIMessages::sendBroadcast(vector<InputUser*>* contacts, QString message, InputMedia* media){
	connect(&delay, SIGNAL(finished()), this, SLOT(broadcastSent()));
	delay.start();
}
void APIMessages::getChats(vector<int>* id){
	connect(&delay, SIGNAL(finished()), this, SLOT(chats()));
	delay.start();
}
void APIMessages::getFullChat(int chat_id){
	connect(&delay, SIGNAL(finished()), this, SLOT(fullChat()));
	delay.start();
}
void APIMessages::editChatTitle(int chat_id, QString title){
	connect(&delay, SIGNAL(finished()), this, SLOT(chatTitleEdited()));
	delay.start();
}
void APIMessages::editChatPhoto(int chat_id, InputChatPhoto* photo){
	connect(&delay, SIGNAL(finished()), this, SLOT(chatPhotoEdited()));
	delay.start();
}
void APIMessages::addChatUser(int chat_id, InputUser* user_id, int fwd_limit){
	connect(&delay, SIGNAL(finished()), this, SLOT(chatUserAdded()));
	delay.start();
}
void APIMessages::deleteChatUser(int chat_id, InputUser* user_id){
	connect(&delay, SIGNAL(finished()), this, SLOT(chatUserDeleted()));
	delay.start();
}
void APIMessages::createChat(vector<InputUser*>* users, QString title){
	connect(&delay, SIGNAL(finished()), this, SLOT(chatCreated()));
	delay.start();
}
void APIMessages::getDhConfig(int version, int random_length){
	connect(&delay, SIGNAL(finished()), this, SLOT(dhConfig()));
	delay.start();
}
void APIMessages::requestEncryption(InputUser* user_id, int random_id, QString g_a){
	connect(&delay, SIGNAL(finished()), this, SLOT(encryptionRequested()));
	delay.start();
}
void APIMessages::acceptEncryption(InputEncryptedChat* peer, QString g_b, long key_fingerprint){
	connect(&delay, SIGNAL(finished()), this, SLOT(encryptionAccepted()));
	delay.start();
}
void APIMessages::discardEncryption(int chat_id){
	connect(&delay, SIGNAL(finished()), this, SLOT(encryptionDiscarded()));
	delay.start();
}
void APIMessages::setEncryptedTyping(InputEncryptedChat* peer, bool typing){
	connect(&delay, SIGNAL(finished()), this, SLOT(encryptedTypingSet()));
	delay.start();
}
void APIMessages::readEncryptedHistory(InputEncryptedChat* peer, int max_date){
	connect(&delay, SIGNAL(finished()), this, SLOT(encryptedHistoryRead()));
	delay.start();
}
void APIMessages::sendEncrypted(InputEncryptedChat* peer, long random_id, QString data){
	connect(&delay, SIGNAL(finished()), this, SLOT(encryptedSent()));
	delay.start();
}
void APIMessages::sendEncryptedFile(InputEncryptedChat* peer, long random_id, QString data, InputEncryptedFile* file){
	connect(&delay, SIGNAL(finished()), this, SLOT(encryptedFileSent()));
	delay.start();
}
void APIMessages::sendEncryptedService(InputEncryptedChat* peer, long random_id, QString data){
	connect(&delay, SIGNAL(finished()), this, SLOT(encryptedServiceSent()));
	delay.start();
}



void APIMessages::messageSentEmitter(){;
	disconnect(&delay, SIGNAL(finished()), this, SLOT(messageSent()));
	emit messageSent(&sem);
}
void APIMessages::mediaSentEmitter(){;
	disconnect(&delay, SIGNAL(finished()), this, SLOT(mediaSent()));
	emit mediaSent(&stm);
}
void APIMessages::typingSetEmitter(){;
	disconnect(&delay, SIGNAL(finished()), this, SLOT(typingSet()));
	emit typingSet(true);
}
void APIMessages::messagesEmitter(){;
	disconnect(&delay, SIGNAL(finished()), this, SLOT(messages()));
	emit messages(&msgs);
}
void APIMessages::dialogsEmitter(){;
	disconnect(&delay, SIGNAL(finished()), this, SLOT(dialogs()));
	emit dialogs(&dlgs);
}
void APIMessages::historyEmitter(){;
	disconnect(&delay, SIGNAL(finished()), this, SLOT(history()));
	emit history(&msgs);
}
void APIMessages::searchedEmitter(){;
	disconnect(&delay, SIGNAL(finished()), this, SLOT(searched()));
	emit searched(&msgs);
}
void APIMessages::historyReadEmitter(){;
	disconnect(&delay, SIGNAL(finished()), this, SLOT(historyRead()));
	emit historyRead(&ah);
}
void APIMessages::messageContentsReadEmitter(){;
	disconnect(&delay, SIGNAL(finished()), this, SLOT(messageContentsRead()));
	emit messageContentsRead(&vec);
}
void APIMessages::historyDeletedEmitter(){;
	disconnect(&delay, SIGNAL(finished()), this, SLOT(historyDeleted()));
	emit historyDeleted(&ah);
}
void APIMessages::messagesDeletedEmitter(){;
	disconnect(&delay, SIGNAL(finished()), this, SLOT(messagesDeleted()));
	emit messagesDeleted(&vec);
}
void APIMessages::messagesRestoredEmitter(){;
	disconnect(&delay, SIGNAL(finished()), this, SLOT(messagesRestored()));
	emit messagesRestored(&vec);
}
void APIMessages::messagesReceivedEmitter(){;
	disconnect(&delay, SIGNAL(finished()), this, SLOT(messagesReceived()));
	emit messagesReceived(&vec);
}
void APIMessages::mesageForwardedEmitter(){;
	disconnect(&delay, SIGNAL(finished()), this, SLOT(mesageForwarded()));
	emit mesageForwarded(&stm);
}
void APIMessages::messagesForwardedEmitter(){;
	disconnect(&delay, SIGNAL(finished()), this, SLOT(messagesForwarded()));
	emit messagesForwarded(&stms);
}
void APIMessages::broadcastSentEmitter(){;
	disconnect(&delay, SIGNAL(finished()), this, SLOT(broadcastSent()));
	emit broadcastSent(&stms);
}
void APIMessages::chatsEmitter(){;
	disconnect(&delay, SIGNAL(finished()), this, SLOT(chats()));
	emit chats(&cts);
}
void APIMessages::fullChatEmitter(){;
	disconnect(&delay, SIGNAL(finished()), this, SLOT(fullChat()));
	emit fullChat(&fct);
}
void APIMessages::chatTitleEditedEmitter(){;
	disconnect(&delay, SIGNAL(finished()), this, SLOT(chatTitleEdited()));
	emit chatTitleEdited(&stm);
}
void APIMessages::chatPhotoEditedEmitter(){;
	disconnect(&delay, SIGNAL(finished()), this, SLOT(chatPhotoEdited()));
	emit chatPhotoEdited(&stm);
}
void APIMessages::chatUserAddedEmitter(){;
	disconnect(&delay, SIGNAL(finished()), this, SLOT(chatUserAdded()));
	emit chatUserAdded(&stm);
}
void APIMessages::chatUserDeletedEmitter(){;
	disconnect(&delay, SIGNAL(finished()), this, SLOT(chatUserDeleted()));
	emit chatUserDeleted(&stm);
}
void APIMessages::chatCreatedEmitter(){;
	disconnect(&delay, SIGNAL(finished()), this, SLOT(chatCreated()));
	emit chatCreated(&stm);
}
void APIMessages::dhConfigEmitter(){;
	disconnect(&delay, SIGNAL(finished()), this, SLOT(dhConfig()));
	emit dhConfig(&dc);
}
void APIMessages::encryptionRequestedEmitter(){;
	disconnect(&delay, SIGNAL(finished()), this, SLOT(encryptionRequested()));
	emit encryptionRequested(&ec);
}
void APIMessages::encryptionAcceptedEmitter(){;
	disconnect(&delay, SIGNAL(finished()), this, SLOT(encryptionAccepted()));
	emit encryptionAccepted(&ec);
}
void APIMessages::encryptionDiscardedEmitter(){;
	disconnect(&delay, SIGNAL(finished()), this, SLOT(encryptionDiscarded()));
	emit encryptionDiscarded(true);
}
void APIMessages::encryptedTypingSetEmitter(){;
	disconnect(&delay, SIGNAL(finished()), this, SLOT(encryptedTypingSet()));
	emit encryptedTypingSet(true);
}
void APIMessages::encryptedHistoryReadEmitter(){;
	disconnect(&delay, SIGNAL(finished()), this, SLOT(encryptedHistoryRead()));
	emit encryptedHistoryRead(true);
}
void APIMessages::encryptedSentEmitter(){;
	disconnect(&delay, SIGNAL(finished()), this, SLOT(encryptedSent()));
	emit encryptedSent(&em);
}
void APIMessages::encryptedFileSentEmitter(){;
	disconnect(&delay, SIGNAL(finished()), this, SLOT(encryptedFileSent()));
	emit encryptedFileSent(&em);
}
void APIMessages::encryptedServiceSentEmitter(){;
	disconnect(&delay, SIGNAL(finished()), this, SLOT(encryptedServiceSent()));
	emit encryptedServiceSent(&ses);
}
