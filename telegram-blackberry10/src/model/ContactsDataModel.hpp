#ifndef CONTACTSDATAMODEL_HPP_
#define CONTACTSDATAMODEL_HPP_

#include "../config.hpp"
#include <bb/cascades/DataModel>

#ifdef TG_API_MOCK
#include <api/apiContacts.hpp>
#else
#include <api/tgApi.hpp>
#endif

class ContactsDataModel : public bb::cascades::DataModel
{
    Q_OBJECT

public:
    ContactsDataModel(QObject* parent = 0);

    static const QString STATUS_UNKNOWN;
    static const QString STATUS_OFFLINE;
    static const QString STATUS_ONLINE;

    virtual int childCount(const QVariantList& indexPath);
    virtual bool hasChildren(const QVariantList& indexPath);
    virtual QVariant data(const QVariantList& indexPath);
    virtual QString itemType(const QVariantList& indexPath);

private slots:
    void onContactsChanged();
    void onAvatarReceived(const QString &contact, const QByteArray &data, const QString &mimeType, const QString& avatarToken);

private:
    void loadContacts();
    static bool contactComparator(const QMap<QString, QVariant>& lhs, const QMap<QString, QVariant> rhs);

#ifdef TG_API_MOCK
    APIContacts api;
#else
    tgApi api;
#endif
    QMap<QString, QString> localContactAvatarTokens;
    QList<QMap<QString, QVariant> > contacts;
};

#endif
