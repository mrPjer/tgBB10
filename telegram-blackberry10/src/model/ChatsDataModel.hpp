#ifndef CHATSDATAMODEL_HPP_
#define CHATSDATAMODEL_HPP_

#include <bb/cascades/DataModel>
#include "api/tgApi.hpp"

class ChatsDataModel: public bb::cascades::DataModel
{
    Q_OBJECT

public:
    static const QString TYPE_NORMAL;
    static const QString TYPE_GROUP;
    static const QString TYPE_SECRET;

    ChatsDataModel(QObject* parent = 0);

    virtual int childCount(const QVariantList& indexPath);
    virtual bool hasChildren(const QVariantList& indexPath);
    virtual QVariant data(const QVariantList& indexPath);
    virtual QString itemType(const QVariantList& indexPath);

private slots:
    void onDialogsChanged();

private:
    tgApi api;
    //QList<ChatListItem*> chats;

};

#endif
