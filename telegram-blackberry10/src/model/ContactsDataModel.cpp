#include <ContactsDataModel.hpp>
#include <util/AvatarUtil.hpp>

ContactsDataModel::ContactsDataModel(QObject* parent) :
        bb::cascades::DataModel(parent)
{
    connect(&api, SIGNAL(contactListChanged()), SLOT(onContactsChanged()));
    connect(&api, SIGNAL(contactStatusChanged(QString, TelegramNamespace::ContactStatus)),
            SLOT(onContactsChanged()));
    connect(&api, SIGNAL(avatarReceived(QString, QByteArray, QString, QString)), SLOT(onAvatarReceived(const QString&, const QByteArray&, const QString&, const QString&)));
    this->loadContacts();
}

const QString ContactsDataModel::STATUS_UNKNOWN = "unknown";
const QString ContactsDataModel::STATUS_OFFLINE = "offline";
const QString ContactsDataModel::STATUS_ONLINE = "online";

int ContactsDataModel::childCount(const QVariantList& indexPath)
{
    // TODO add support for headers
    Q_UNUSED(indexPath)
    return contacts.size();
}

bool ContactsDataModel::hasChildren(const QVariantList& indexPath)
{
    // TODO add support for headers
    return indexPath.size() == 0;
}

QVariant ContactsDataModel::data(const QVariantList& indexPath)
{
    return contacts.at(indexPath[0].toInt());
}

QString ContactsDataModel::itemType(const QVariantList& indexPath)
{
    // TODO return header or contact
    return "contact";
}

void ContactsDataModel::onContactsChanged()
{
    qDebug() << "Contacts have changed!";
    this->loadContacts();
}

void ContactsDataModel::onAvatarReceived(const QString& contact, const QByteArray& data, const QString& mimeType, const QString& avatarToken)
{
    qDebug() << "Received avatar for " << contact;
    localContactAvatarTokens[contact] = avatarToken;

    QDir localDir;
    localDir.mkpath(AvatarUtil::AVATAR_DIR);
    QFile avatarFile(AvatarUtil::AVATAR_DIR + "/" + contact + ".png");
    QImage image;
    image.loadFromData(data);
    image.save(&avatarFile, "PNG");
    avatarFile.close();

    emit itemsChanged(bb::cascades::DataModelChangeType::Init);
}

bool ContactsDataModel::contactComparator(const QMap<QString, QVariant>& lhs, const QMap<QString, QVariant> rhs)
{
    return lhs["name"].toString() < rhs["name"].toString();
}

void ContactsDataModel::loadContacts()
{
    qDebug() << "Loading contacts";
    contacts.clear();
    QStringList numbers = api.contactList();
    qDebug() << "Got " << numbers;

    foreach(QString number, numbers){
        QDir localDir;
        localDir.mkpath(AvatarUtil::AVATAR_DIR);
        const QString firstName = api.contactFirstName(number);
        const QString lastName = api.contactLastName(number);
        const QVariant status = api.contactStatus(number);
        const QString avatarToken = api.contactAvatarToken(number);

        QMap<QString, QVariant> item;
        item.insert("name", QString("%1 %2").arg(firstName, lastName));
        item.insert("phone", number);
        item.insert("status", status);

        if(!avatarToken.isEmpty()) {
            if(!localContactAvatarTokens.contains(number) && localContactAvatarTokens[number] != avatarToken) {
                api.requestContactAvatar(number);
            }
            qDebug() << "Image will be shown from " << "file:///" + AvatarUtil::getAvatarPath(number);
            item.insert("imagePath", AvatarUtil::getAvatarPath(number));
        } else {
            item.insert("imagePath", AvatarUtil::getPlaceholderAvatarPath(number));
        }

        contacts.push_back(item);
    }

    qSort(contacts.begin(), contacts.end(), ContactsDataModel::contactComparator);

    emit itemsChanged(bb::cascades::DataModelChangeType::Init);
}
