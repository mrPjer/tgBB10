#include <ChatDataModel.hpp>

ChatDataModel::ChatDataModel(QObject* parent) :
        bb::cascades::DataModel(parent)
{
    connect(&api, SIGNAL(contactTypingStatusChanged(QString, bool)),
            SLOT(onContactTypingStatusChanged(QString, bool)));
    connect(&api, SIGNAL(contactChatTypingStatusChanged(quint32, QString, bool)),
            SLOT(onContactChatTypingStatusChanged(quint32, QString, bool)));
    connect(&api, SIGNAL(chatHistoryReceived(QVector<ChatItem*>)),
            SLOT(onChatHistoryReceived(QVector<ChatItem*>)));
    connect(&api, SIGNAL(messageReceived(QString, QString, quint32)),
            SLOT(onMessageReceived(QString, QString, quint32)));
}

const QString ChatDataModel::TYPE_INBOUND = "inbound";
const QString ChatDataModel::TYPE_OUTBOUND = "outbound";

QString ChatDataModel::typingStatus()
{
    return m_typingStatus;
}

QString ChatDataModel::peerPhoneNumber()
{
    return m_peerPhoneNumber;
}

void ChatDataModel::setPeerPhoneNumber(const QString& peerPhoneNumber)
{
    this->m_peerPhoneNumber = peerPhoneNumber;
    this->getHistory();
}

int ChatDataModel::childCount(const QVariantList& indexPath)
{
    return m_items.size();
}

bool ChatDataModel::hasChildren(const QVariantList& indexPath)
{
    return indexPath.size() == 0;
}

QVariant ChatDataModel::data(const QVariantList& indexPath)
{
    ChatItem* item = m_items[indexPath[0].toInt()];
    QMap<QString, QVariant> result;

    // TODO there should be a way to return a chat item directly

    result.insert("messageText", item->messageText());
    result.insert("timestamp", item->timestamp());
    result.insert("readVisible", item->readVisible());
    result.insert("sentVisible", item->sentVisible());
    result.insert("unsentVisible", item->unsentVisible());
    result.insert("sendingVisible", item->sendingVisible());

    return result;
}

QString ChatDataModel::itemType(const QVariantList& indexPath)
{
    ChatItem* item = m_items[indexPath[0].toInt()];
    if (item->sentVisible()) {
        return ChatDataModel::TYPE_OUTBOUND;
    } else {
        return ChatDataModel::TYPE_INBOUND;
    }
}

void ChatDataModel::sendMessage(const QString& message)
{
    // TODO handle sending message in a chat
    api.sendMessage(m_peerPhoneNumber, message);
}

bool ChatDataModel::messageComparator(const ChatItem* lhs, const ChatItem* rhs)
{
    return lhs->rawTimestamp() < rhs->rawTimestamp();
}

void ChatDataModel::setTypingStatus(const QString& typingStatus)
{
    m_typingStatus = typingStatus;
    emit typingStatusChanged();
}

void ChatDataModel::getHistory()
{
    api.getHistory(m_peerPhoneNumber, 0, 0, 100);
}

void ChatDataModel::onContactTypingStatusChanged(const QString& phone, bool typingStatus)
{
    if (phone != m_peerPhoneNumber) {
        return;
    }
    if (typingStatus) {
        this->setTypingStatus("typing...");
    } else {
        this->setTypingStatus("");
    }
}

void ChatDataModel::onContactChatTypingStatusChanged(quint32 chatId, const QString& phone,
        bool typingStatus)
{
    // TODO check if phone number is a participant
    // TODO handle typing status of multiple participants
    if (typingStatus) {
        this->setTypingStatus("someone is typing...");
    } else {
        this->setTypingStatus("");
    }
}

void ChatDataModel::onChatHistoryReceived(QVector<ChatItem*> items)
{
    m_items = items;
    qSort(m_items.begin(), m_items.end(), ChatDataModel::messageComparator);
    emit itemsChanged(bb::cascades::DataModelChangeType::Init);
}

void ChatDataModel::onMessageReceived(const QString& phone, const QString& message,
        quint32 messageId)
{
    qDebug() << "Received message from " << phone;
    qDebug() << "Current peer is " << m_peerPhoneNumber;
    if (phone == m_peerPhoneNumber) {
        ChatItem *item = new ChatItem(0, message, QDateTime::currentMSecsSinceEpoch(), false, false,
                false, false);
        qDebug() << "Received message";
        m_items.push_back(item);
        QVariantList indexPath;
        indexPath.push_back(m_items.size());
        emit itemAdded(indexPath);
    }
}
