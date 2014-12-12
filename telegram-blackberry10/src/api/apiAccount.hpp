#ifndef APIACCOUNT_HPP_
#define APIACCOUNT_HPP_

#include "apiDelay.hpp"
#include "apiTypes.hpp"
#include <QString>
#include <bb/cascades/CustomControl>

class APIAccount: public bb::cascades::CustomControl{
    APIDelay delay;
    Q_OBJECT

    PeerNotifySettings pns;
    User user;
    vector<WallPaper> wallpapers;

public:
    APIAccount();

signals:
    void deviceRegistered(bool);
    void deviceUnregistered(bool);
    void notifySettingsUpdated(bool);
    void notifySettings(PeerNotifySettings* pns);
    void notifySettingsReset(bool);
    void profileUpdated(User* user);
    void statusUpdated(bool);
    void wallPapers(vector<WallPaper>* wallpapers);
    void usernameChecked(bool canBeUsed);
    void usernameUpdated(User* user);

public slots:
    void registerDevice(int token_type, QString token, QString device_model, QString system_version, QString app_version, bool app_sandbox, QString lang_code);
    void unregisterDevice(int token_type, QString token);
    void updateNotifySettings(InputNotifyPeer* peer, InputPeerNotifySettings* settings);
    void getNotifySettings(InputNotifyPeer* peer);
    void resetNotifySettings();
    void updateProfile(QString first_name, QString last_name);
    void updateStatus(bool offline);
    void getWallPapers();
    void checkUsername(QString username);
    void updateUsername(QString username);

    void deviceRegisteredEmitter();
    void deviceUnregisteredEmitter();
    void notifySettingsUpdatedEmitter();
    void notifySettingsEmitter();
    void notifySettingsResetEmitter();
    void profileUpdatedEmitter();
    void statusUpdatedEmitter();
    void wallPapersEmitter();
    void usernameCheckedEmitter();
    void usernameUpdatedEmitter();
};

#endif
