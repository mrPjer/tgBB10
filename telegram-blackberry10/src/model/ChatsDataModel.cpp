#include <model/ChatsDataModel.hpp>
#include <bb/cascades/DataModelChangeType>

ChatsDataModel::ChatsDataModel(QObject* parent) :
        bb::cascades::DataModel(parent)
{
    connect(&api, SIGNAL(dialogsChanged()), SLOT(onDialogsChanged()));
}

const QString ChatsDataModel::TYPE_NORMAL = "normalChat";
const QString ChatsDataModel::TYPE_GROUP = "groupChat";
const QString ChatsDataModel::TYPE_SECRET = "secretChat";

int ChatsDataModel::childCount(const QVariantList& indexPath)
{
    qDebug() << "Total children: " << api.dialogs().size();
    return api.dialogs().size();
}

bool ChatsDataModel::hasChildren(const QVariantList& indexPath)
{
    return indexPath.size() == 0;
}

QVariant ChatsDataModel::data(const QVariantList& indexPath)
{
    QMap<QString, QVariant> map;
    ChatListItem *item = api.dialogs().at(indexPath[0].toInt());
    map.insert("chatName", item->title());
    map.insert("chatDescription", item->content());
    map.insert("unreadCount", item->unreadCount());
    map.insert("timeStamp", item->timestamp());
    map.insert("outgoingStatus", item->outgoingStatus());
    map.insert("author", item->author());
    map.insert("chatAvatar", item->chatAvatar());

    return map;
}

QString ChatsDataModel::itemType(const QVariantList& indexPath)
{
    ChatListItem *item = api.dialogs().at(indexPath[0].toInt());

    switch (item->type()) {
        case ChatListItem::NORMAL:
            return "normalChat";
        case ChatListItem::GROUP:
            return "groupChat";
        case ChatListItem::SECRET:
            return "secretChat";
        default:
            return "normalChat";
    }
}

void ChatsDataModel::onDialogsChanged()
{
    qDebug() << "Dialogs have changed!";
    api.dialogs();
    emit itemsChanged(bb::cascades::DataModelChangeType::Init);
}
