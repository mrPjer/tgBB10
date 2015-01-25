#include <ChatDataModel.hpp>

ChatDataModel::ChatDataModel(QObject* parent) :
        bb::cascades::DataModel(parent)
{
    connect(&api, SIGNAL(contactTypingStatusChanged(QString, bool)),
            SLOT(onContactTypingStatusChanged(QString, bool)));
    connect(&api, SIGNAL(contactChatTypingStatusChanged(quint32, QString, bool)),
            SLOT(onContactChatTypingStatusChanged(quint32, QString, bool)));
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
}

int ChatDataModel::childCount(const QVariantList& indexPath)
{
    return 10;
}

bool ChatDataModel::hasChildren(const QVariantList& indexPath)
{
    return indexPath.size() == 0;
}

QVariant ChatDataModel::data(const QVariantList& indexPath)
{
    QMap<QString, QVariant> item;

    item.insert("messageText", "This is a sample text");
    item.insert("timestamp", "ts:ts");
    item.insert("readVisible", false);
    item.insert("sentVisible", false);
    item.insert("unsentVisible", false);
    item.insert("sendingVisible", false);

    return item;
}

QString ChatDataModel::itemType(const QVariantList& indexPath)
{
    // TODO differentiate between inbound and outbound
    return ChatDataModel::TYPE_OUTBOUND;
}

void ChatDataModel::sendMessage(const QString& message)
{
    // TODO handle sending message in a chat
    api.sendMessage(m_peerPhoneNumber, message);
}

void ChatDataModel::setTypingStatus(const QString& typingStatus)
{
    m_typingStatus = typingStatus;
    emit typingStatusChanged();
}

void ChatDataModel::onContactTypingStatusChanged(const QString& phone, bool typingStatus)
{
    if(phone != m_peerPhoneNumber) {
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
