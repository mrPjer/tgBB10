#ifndef TGSESSION_HPP_
#define TGSESSION_HPP_

#include <QObject>
#include <QSettings>

#define TG_SESSION_ORG "FlokiTheKitten"
#define TG_SESSION_APP "tgBB10"
#define TG_SESSION_KEY "session/key"

class TgSession: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QByteArray session READ session WRITE setSession NOTIFY sessionChanged)
    Q_PROPERTY(bool sessionStored READ isSessionStored NOTIFY sessionStoredChanged)

public:

    explicit TgSession(QObject* parent = 0);

    QByteArray session() const;
    void setSession(const QByteArray &session);

    bool isSessionStored();

    signals:
    void sessionChanged();
    void sessionStoredChanged();

private:
    QSettings settings;

};

#endif
