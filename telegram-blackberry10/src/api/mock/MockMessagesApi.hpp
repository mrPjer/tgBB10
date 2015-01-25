#ifndef MOCKMESSAGESAPI_H_
#define MOCKMESSAGESAPI_H_

#include <model/ChatListItem.hpp>

class MockMessagesApi : public QObject
{
    Q_OBJECT
public:
    explicit MockMessagesApi(QObject* parent = 0);

    QList<ChatListItem*> dialogs() const;

    signals:
    void dialogsChanged();
};

#endif
