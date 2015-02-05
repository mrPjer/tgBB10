#ifndef CHATITEM_HPP_
#define CHATITEM_HPP_

class ChatItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString messageText READ messageText)
    Q_PROPERTY(QString timestamp READ timestamp)
    Q_PROPERTY(bool readVisible READ readVisible)
    Q_PROPERTY(bool sentVisible READ sentVisible)
    Q_PROPERTY(bool unsentVisible READ unsentVisible)
    Q_PROPERTY(bool sendingVisible READ sendingVisible)

public:
    explicit ChatItem(
            QObject* parent = 0,
            const QString& text = 0,
            const quint32 timestamp = 0,
            const bool readVisible = false,
            const bool sentVisible = false,
            const bool unsentVisible = false,
            const bool sendingVisible = false
            );

    QString messageText() const;
    QString timestamp() const;
    quint32 rawTimestamp() const;
    bool readVisible() const;
    bool unsentVisible() const;
    bool sentVisible() const;
    bool sendingVisible() const;

private:
    QString m_text;
    quint32 m_timestamp;
    bool m_read_visible;
    bool m_unsent_visible;
    bool m_sent_visible;
    bool m_sending_visible;
};

#endif
