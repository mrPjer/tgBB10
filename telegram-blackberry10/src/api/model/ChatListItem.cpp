#include <ChatListItem.hpp>

ChatListItem::ChatListItem(
        QObject* parent,
        const QString& title,
        const QString& content,
        const QString& timestamp,
        const QString& author,
        const QString& chatAvatar,
        const QString& outgoingStatus,
        const Type& type,
        const int unreadCount
        ) :
        QObject(parent),
        m_title(title),
        m_content(content),
        m_timestamp(timestamp),
        m_author(author),
        m_chat_avatar(chatAvatar),
        m_outgoing_status(outgoingStatus),
        m_type(type),
        m_unread_count(unreadCount)
{
}

QString ChatListItem::title() const
{
    return m_title;
}

QString ChatListItem::content() const
{
    return m_content;
}

QString ChatListItem::timestamp() const
{
    return m_timestamp;
}

QString ChatListItem::author() const
{
    return m_author;
}

QString ChatListItem::chatAvatar() const
{
    return m_chat_avatar;
}

QString ChatListItem::outgoingStatus() const
{
    return m_outgoing_status;
}

ChatListItem::Type ChatListItem::type() const {
    return m_type;
}

int ChatListItem::unreadCount() const
{
    return m_unread_count;
}
