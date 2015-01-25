#ifndef AVATARUTIL_HPP_
#define AVATARUTIL_HPP_

class AvatarUtil
{
public:
    static const QString AVATAR_DIR;
    static QStringList PLACEHOLDER_AVATARS;

    static QString getAvatarPath(const QString& contactNumber);
    static QString getPlaceholderAvatarPath(const QString& contactNumber);

};

#endif
