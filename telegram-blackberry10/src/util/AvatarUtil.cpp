#include <AvatarUtil.hpp>
#include <qdir.h>

const QString AvatarUtil::AVATAR_DIR = "data/avatars";

QStringList AvatarUtil::PLACEHOLDER_AVATARS = QStringList()
        << "images/testUsers/user_placeholder_blue.png"
        << "images/testUsers/user_placeholder_cyan.png"
        << "images/testUsers/user_placeholder_green.png"
        << "images/testUsers/user_placeholder_orange.png"
        << "images/testUsers/user_placeholder_pink.png"
        << "images/testUsers/user_placeholder_purple.png"
        << "images/testUsers/user_placeholder_red.png"
        << "images/testUsers/user_placeholder_yellow.png";

QStringList AvatarUtil::GROUP_PLACEHOLDER_AVATARS = QStringList()
        << "images/chatsList/chatAvatars/groupChatAvatars/group_placeholder_blue.png"
        << "images/chatsList/chatAvatars/groupChatAvatars/group_placeholder_cyan.png"
        << "images/chatsList/chatAvatars/groupChatAvatars/group_placeholder_green.png"
        << "images/chatsList/chatAvatars/groupChatAvatars/group_placeholder_orange.png"
        << "images/chatsList/chatAvatars/groupChatAvatars/group_placeholder_pink.png"
        << "images/chatsList/chatAvatars/groupChatAvatars/group_placeholder_purple.png"
        << "images/chatsList/chatAvatars/groupChatAvatars/group_placeholder_red.png"
        << "images/chatsList/chatAvatars/groupChatAvatars/group_placeholder_yellow.png";

AvatarUtil::AvatarUtil(QObject* parent) : QObject(parent)
{
}

QString AvatarUtil::getAvatarPath(const QString& contactNumber)
{
    return "file:///" + QDir::currentPath() + "/" + AvatarUtil::AVATAR_DIR + "/" + contactNumber + ".png";
}

QString AvatarUtil::getPlaceholderAvatarPath(const QString& contactNumber)
{
    const int position = qHash(contactNumber) % AvatarUtil::PLACEHOLDER_AVATARS.size();
    return "asset:///" + AvatarUtil::PLACEHOLDER_AVATARS[position];
}

QString AvatarUtil::getGroupPlaceholderAvatarPath(const int groupId)
{
    const int position = groupId % AvatarUtil::GROUP_PLACEHOLDER_AVATARS.size();
    return "asset:///" + AvatarUtil::GROUP_PLACEHOLDER_AVATARS[position];
}
