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
#include <vector>

class APIMessages: public QObject{
    APIDelay delay;
    Q_OBJECT

    SentMessage sem;
    StatedMessage stm;
    StatedMessages stms;
    Messages msgs;
    Dialogs dlgs;
    AffectedHistory ah;
    vector<int> vec;
    Chat ct;
    Chats cts;
    FullChat fct;
    EncryptedChat ec;
    DhConfig dc;
    SentEncryptedMessage em;
    SentEncryptedService ses;

public:
    APIMessages();

signals:
    void messageSent(SentMessage* stm);
    void mediaSent(StatedMessage* stm);
    void typingSet(bool);
    void messages(Messages* msgs);
    void dialogs(Dialogs* dlgs);
    void history(Messages* msgs);
    void searched(Messages* msgs);
    void historyRead(AffectedHistory* ah);
    void messageContentsRead(vector<int>* vec);
    void historyDeleted(AffectedHistory* ah);
    void messagesDeleted(vector<int>* vec);
    void messagesRestored(vector<int>* vec);
    void messagesReceived(vector<int>* vec);
    void mesageForwarded(StatedMessage* stm);
    void messagesForwarded(StatedMessages* stms);
    void broadcastSent(StatedMessages* stms);
    void chats(Chats* cts);
    void fullChat(FullChat* fct);
    void chatTitleEdited(StatedMessage* stm);
    void chatPhotoEdited(StatedMessage* stm);
    void chatUserAdded(StatedMessage* stm);
    void chatUserDeleted(StatedMessage* stm);
    void chatCreated(StatedMessage* stm);
    void dhConfig(DhConfig* dc);
    void encryptionRequested(EncryptedChat* ec);
    void encryptionAccepted(EncryptedChat* ec);
    void encryptionDiscarded(bool);
    void encryptedTypingSet(bool);
    void encryptedHistoryRead(bool);
    void encryptedSent(SentEncryptedMessage* em);
    void encryptedFileSent(SentEncryptedMessage* em);
    void encryptedServiceSent(SentEncryptedService* ses);
//    void queueReceived();

public slots:
    void sendMessage(InputPeer* peer, QString message, long random_id);
    void sendMedia(InputPeer* peer, InputMedia* media, long random_id);
    void setTyping(InputPeer* peer, bool typing, SendMessageAction* action);
    void getMessages(vector<int>* id);
    void getDialogs(int offset, int max_id, int limit);
    void getHistory(InputPeer* peer, int offset, int max_id, int limit);
    void search(InputPeer* peer, QString q, MessagesFilter* filter, int min_date, int max_date, int offset, int max_id, int limit);
    void readHistory(InputPeer* peer, int max_id, int offset, bool read_contents);
    void readMessageContents(vector<int>* id);
    void deleteHistory(InputPeer* peer, int offset);
    void deleteMessages(vector<int>* id);
    void restoreMessages(vector<int>* id);
    void receivedMessages(int max_id);
    void forwardMessage(InputPeer* peer, int id, long random_id);
    void forwardMessages(InputPeer* peer, vector<int>* id);
    void sendBroadcast(vector<InputUser*>* contacts, QString message, InputMedia* media);
    void getChats(vector<int>* id);
    void getFullChat(int chat_id);
    void editChatTitle(int chat_id, QString title);
    void editChatPhoto(int chat_id, InputChatPhoto* photo);
    void addChatUser(int chat_id, InputUser* user_id, int fwd_limit);
    void deleteChatUser(int chat_id, InputUser* user_id);
    void createChat(vector<InputUser*>* users, QString title);
    void getDhConfig(int version, int random_length);
    void requestEncryption(InputUser* user_id, int random_id, QString g_a);
    void acceptEncryption(InputEncryptedChat* peer, QString g_b, long key_fingerprint);
    void discardEncryption(int chat_id);
    void setEncryptedTyping(InputEncryptedChat* peer, bool typing);
    void readEncryptedHistory(InputEncryptedChat* peer, int max_date);
    void sendEncrypted(InputEncryptedChat* peer, long random_id, QString data);
    void sendEncryptedFile(InputEncryptedChat* peer, long random_id, QString data, InputEncryptedFile* file);
    void sendEncryptedService(InputEncryptedChat* peer, long random_id, QString data);
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
