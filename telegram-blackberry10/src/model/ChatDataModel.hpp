#ifndef CHATDATAMODEL_HPP_
#define CHATDATAMODEL_HPP_

#include <bb/cascades/DataModel>
#include <api/tgApi.hpp>

class ChatDataModel: public bb::cascades::DataModel
{
    Q_OBJECT
    Q_PROPERTY(QString peerPhoneNumber READ peerPhoneNumber WRITE setPeerPhoneNumber)
    Q_PROPERTY(QString typingStatus READ typingStatus NOTIFY typingStatusChanged)

public:
    ChatDataModel(QObject* parent = 0);

    static const QString TYPE_INBOUND;
    static const QString TYPE_OUTBOUND;

    QString typingStatus();
    QString peerPhoneNumber();
    void setPeerPhoneNumber(const QString& peerPhoneNumber);

    virtual int childCount(const QVariantList& indexPath);
    virtual bool hasChildren(const QVariantList& indexPath);
    virtual QVariant data(const QVariantList& indexPath);
    virtual QString itemType(const QVariantList& indexPath);

public slots:
    void sendMessage(const QString& mesage);

    signals:
    void typingStatusChanged();

private slots:
    void onContactTypingStatusChanged(const QString& phone, bool typingStatus);
    void onContactChatTypingStatusChanged(quint32 chatId, const QString& phone, bool typingStatus);
    void onChatHistoryReceived(QVector<ChatItem*> items);

private:
    void setTypingStatus(const QString& typingStatus);
    void getHistory();

    QString m_typingStatus;
    QString m_peerPhoneNumber;
    QVector<ChatItem*> m_items;
    tgApi api;
};

#endif
