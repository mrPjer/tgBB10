#include "TgSession.hpp"

TgSession::TgSession(QObject* parent) :
        settings(TG_SESSION_ORG, TG_SESSION_APP)
{
    Q_UNUSED(parent);
}

QByteArray TgSession::session() const
{
    return settings.value(TG_SESSION_KEY).toByteArray();
}

void TgSession::setSession(const QByteArray &session)
{
    settings.setValue(TG_SESSION_KEY, session);
    emit sessionChanged();
    emit sessionStoredChanged();
}

void TgSession::clearSession()
{
    settings.remove(TG_SESSION_KEY);
    emit sessionChanged();
    emit sessionStoredChanged();
}

bool TgSession::isSessionStored()
{
    return settings.contains(TG_SESSION_KEY) && session() != QByteArray();
}
