#include "TgSession.hpp"

TgSession::TgSession(QObject* parent) :
        settings(TG_SESSION_ORG, TG_SESSION_APP)
{
    Q_UNUSED(parent);
}

QString TgSession::session() const
{
    return settings.value(TG_SESSION_KEY).toString();
}

void TgSession::setSession(const QString &session)
{
    settings.setValue(TG_SESSION_KEY, session);
    emit sessionChanged();
    emit sessionStoredChanged();
}

bool TgSession::isSessionStored()
{
    return settings.contains(TG_SESSION_KEY) && session() != QString();
}
