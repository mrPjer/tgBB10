#ifndef CHATSDATAMODEL_HPP_
#define CHATSDATAMODEL_HPP_

#include "../config.hpp"
#include <bb/cascades/DataModel>

// TODO This needs to be solved better so that this component doesn't care about which API type is being used
#ifdef TG_API_MOCK
#include <api/mock/MockMessagesApi.hpp>
#else
#include <api/tgApi.hpp>
#endif

class ChatsDataModel: public bb::cascades::DataModel
{
    Q_OBJECT
    Q_PROPERTY(int unreadCount READ unreadCount NOTIFY unreadCountChanged)

public:
    static const QString TYPE_NORMAL;
    static const QString TYPE_GROUP;
    static const QString TYPE_SECRET;

    ChatsDataModel(QObject* parent = 0);

    int unreadCount();

    virtual int childCount(const QVariantList& indexPath);
    virtual bool hasChildren(const QVariantList& indexPath);
    virtual QVariant data(const QVariantList& indexPath);
    virtual QString itemType(const QVariantList& indexPath);

    signals:
    void unreadCountChanged();

private slots:
    void onDialogsChanged();

private:
#ifdef TG_API_MOCK
    MockMessagesApi api;
#else
    tgApi api;
#endif
    QList<ChatListItem*> items;

};

#endif
