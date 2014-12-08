/*
 * apiMessages.hpp
 *
 *  Created on: 8. 12. 2014.
 *      Author: Alfis
 */
#ifndef APIMESSAGES_HPP_
#define APIMESSAGES_HPP_


#include "apiDelay.hpp"
#include "apiTypes.hpp"

class APIMessages: public QObject{
    APIDelay delay;
    Q_OBJECT

public:
    APIMessages();

signals:
    void messageSent();
    void mediaSent();
    void typingSet();
    void messages();
    void dialogs();
    void history();
    void searched();
    void historyRead();
    void messageContentsRead();
    void historyDeleted();
    void messagesDeleted();
    void messagesRestored();
    void messagesReceived();
    void mesageForwarded();
    void messagesForwarded();
    void broadcastSent();
    void chats();
    void fullChat();
    void chatTitleEdited();
    void chatPhotoEdited();
    void chatUserAdded();
    void chatUserDeleted();
    void chatCreated();
    void dhConfig();
    void encryptionRequested();
    void encryptionAccepted();
    void encryptionDiscarded();
    void encryptedTypingSet();
    void encryptedHistoryRead();
    void encryptedSent();
    void encryptedFileSent();
    void encryptedServiceSent();
//    void queueReceived();

public slots:
    void sendMessage();
    void sendMedia();
    void setTyping();
    void getMessages();
    void getDialogs();
    void getHistory();
    void search();
    void readHistory();
    void readMessageContents();
    void deleteHistory();
    void deleteMessages();
    void restoreMessages();
    void receivedMessages();
    void forwardMessage();
    void forwardMessages();
    void sendBroadcast();
    void getChats();
    void getFullChat();
    void editChatTitle();
    void editChatPhoto();
    void addChatUser();
    void deleteChatUser();
    void createChat();
    void getDhConfig();
    void requestEncryption();
    void acceptEncryption();
    void discardEncryption();
    void setEncryptedTyping();
    void readEncryptedHistory();
    void sendEncrypted();
    void sendEncryptedFile();
    void sendEncryptedService();
//    void receivedQueue();

    void messageSentEmitter();
    void mediaSentEmitter();
    void typingSetEmitter();
    void messagesEmitter();
    void dialogsEmitter();
    void historyEmitter();
    void searchedEmitter();
    void historyReadEmitter();
    void messageContentsReadEmitter();
    void historyDeletedEmitter();
    void messagesDeletedEmitter();
    void messagesRestoredEmitter();
    void messagesReceivedEmitter();
    void mesageForwardedEmitter();
    void messagesForwardedEmitter();
    void broadcastSentEmitter();
    void chatsEmitter();
    void fullChatEmitter();
    void chatTitleEditedEmitter();
    void chatPhotoEditedEmitter();
    void chatUserAddedEmitter();
    void chatUserDeletedEmitter();
    void chatCreatedEmitter();
    void dhConfigEmitter();
    void encryptionRequestedEmitter();
    void encryptionAcceptedEmitter();
    void encryptionDiscardedEmitter();
    void encryptedTypingSetEmitter();
    void encryptedHistoryReadEmitter();
    void encryptedSentEmitter();
    void encryptedFileSentEmitter();
    void encryptedServiceSentEmitter();
//    void queueReceivedEmitter();
};


#endif /* APIMESSAGES_HPP_ */
