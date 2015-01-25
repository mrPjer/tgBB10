#include <model/ChatsDataModel.hpp>
#include <bb/cascades/DataModelChangeType>

ChatsDataModel::ChatsDataModel(QObject* parent) :
        bb::cascades::DataModel(parent)
{
    connect(&api, SIGNAL(dialogsChanged()), SLOT(onDialogsChanged()));
    items = api.dialogs();
}

const QString ChatsDataModel::TYPE_NORMAL = "normalChat";
const QString ChatsDataModel::TYPE_GROUP = "groupChat";
const QString ChatsDataModel::TYPE_SECRET = "secretChat";

int ChatsDataModel::unreadCount()
{
    int result = 0;

    foreach(ChatListItem* item, items){
        result += item->unreadCount();
    }

    return result;
}

int ChatsDataModel::childCount(const QVariantList& indexPath)
{
    Q_UNUSED(indexPath);
    return items.size();
}

bool ChatsDataModel::hasChildren(const QVariantList& indexPath)
{
    return indexPath.size() == 0;
}

QVariant ChatsDataModel::data(const QVariantList& indexPath)
{
    QMap<QString, QVariant> map;
    ChatListItem *item = items.at(indexPath[0].toInt());
    map.insert("chatName", item->title());
    map.insert("chatDescription", item->content());
    map.insert("unreadCount", item->unreadCount());
    map.insert("timeStamp", item->timestamp());
    map.insert("outgoingStatus", item->outgoingStatus());
    map.insert("author", item->author());
    map.insert("peerId", item->peerId());
    map.insert("chatAvatar", item->chatAvatar());

    return map;
}

QString ChatsDataModel::itemType(const QVariantList& indexPath)
{
    ChatListItem *item = items.at(indexPath[0].toInt());

    switch (item->type()) {
        case ChatListItem::NORMAL:
            return ChatsDataModel::TYPE_NORMAL;
        case ChatListItem::GROUP:
            return ChatsDataModel::TYPE_GROUP;
        case ChatListItem::SECRET:
            return ChatsDataModel::TYPE_SECRET;
        default:
            return ChatsDataModel::TYPE_NORMAL;
    }
}

void ChatsDataModel::onDialogsChanged()
{
    qDebug() << "Dialogs have changed!";
    items = api.dialogs();
    emit unreadCountChanged();
    emit itemsChanged(bb::cascades::DataModelChangeType::Init);
}
