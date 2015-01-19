#include <mock/MockMessagesApi.hpp>

#include <api/model/ChatListItem.hpp>

MockMessagesApi::MockMessagesApi(QObject* parent) :
        QObject(parent)
{
}

QList<ChatListItem*> MockMessagesApi::dialogs() const
{
    QList<ChatListItem*> result;

    result.append(
            new ChatListItem(0, "Damien's Shark", "So you've come for some shark hunting?",
                    "5:06 PM", "Tob",
                    "asset:///images/chatsList/chatAvatars/groupChatAvatars/group_placeholder_cyan.png",
                    "none", 3));

    result.append(
            new ChatListItem(0, "Adam Smith", "Very cool! I'm not so surprised.", "2:27 PM", "You",
                    "asset:///images/chatsList/chatAvatars/groupChatAvatars/group_placeholder_orange.png",
                    "seen", 0));

    result.append(
            new ChatListItem(0, "Anastasiya Shy", "It's raining women", "2:24 PM", "typing...",
                    "asset:///images/chatsList/chatAvatars/SingleChatAvatars/user_placeholder_pink.png",
                    "none", 0));

    result.append(
            new ChatListItem(0, "Samus Aran", "Well I know everything about that.", "2:24 PM",
                    "You",
                    "asset:///images/chatsList/chatAvatars/SingleChatAvatars/user_placeholder_yellow.png",
                    "none", 0));

    return result;
}
