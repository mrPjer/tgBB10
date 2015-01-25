#include <ChatItem.hpp>
#include <qdatetime.h>

ChatItem::ChatItem(
        QObject* parent,
        const QString& text,
        const quint32 timestamp,
        const bool readVisible,
        const bool sentVisible,
        const bool unsentVisible,
        const bool sendingVisible) : QObject(parent)
{
    m_text = text;
    m_timestamp = timestamp;
    m_read_visible = readVisible;
    m_sent_visible = sentVisible;
    m_sending_visible = sendingVisible;
    m_unsent_visible = unsentVisible;
}

QString ChatItem::messageText() const
{
    return m_text;
}

QString ChatItem::timestamp() const
{
    QDateTime dt;
    dt.setTime_t(m_timestamp);
    return dt.toString("dd.MM.yy hh:mm");
}

bool ChatItem::readVisible() const
{
    return m_read_visible;
}

bool ChatItem::unsentVisible() const
{
    return m_unsent_visible;
}

bool ChatItem::sentVisible() const
{
    return m_sent_visible;
}

bool ChatItem::sendingVisible() const
{
    return m_sending_visible;
}
