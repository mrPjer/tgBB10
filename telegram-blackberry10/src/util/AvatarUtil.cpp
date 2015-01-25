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

QString AvatarUtil::getAvatarPath(const QString& contactNumber)
{
    return "file:///" + QDir::currentPath() + "/" + AvatarUtil::AVATAR_DIR + "/" + contactNumber + ".png";
}

QString AvatarUtil::getPlaceholderAvatarPath(const QString& contactNumber)
{
    const int position = qHash(contactNumber) % AvatarUtil::PLACEHOLDER_AVATARS.size();
    return "asset:///" + AvatarUtil::PLACEHOLDER_AVATARS[position];
}
