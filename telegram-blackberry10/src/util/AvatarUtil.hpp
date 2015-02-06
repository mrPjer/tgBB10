#ifndef AVATARUTIL_HPP_
#define AVATARUTIL_HPP_

class AvatarUtil : public QObject
{
    Q_OBJECT
public:
    explicit AvatarUtil(QObject* parent = 0);

    static const QString AVATAR_DIR;
    static QStringList PLACEHOLDER_AVATARS;
    static QStringList GROUP_PLACEHOLDER_AVATARS;

    static Q_INVOKABLE QString getAvatarPath(const QString& contactNumber);
    static Q_INVOKABLE QString getPlaceholderAvatarPath(const QString& contactNumber);
    static Q_INVOKABLE QString getGroupPlaceholderAvatarPath(const int groupId);
};

#endif
