#include "apiAccount.hpp"

APIAccount::APIAccount(){
    pns.mute_until = 1337;
    pns.sound = "zvuk of the jungle";
    pns.events_mask = 31337;

    user.photo = new UserProfilePhoto();
    user.status = new UserStatus();
    user.photo->photo_small = new FileLocation();
    user.photo->photo_big = new FileLocation();
    user.status = new UserStatus();
}


void APIAccount::registerDevice(int token_type, QString token, QString device_model, QString system_version, QString app_version, bool app_sandbox, QString lang_code){
	connect(&delay, SIGNAL(finished()), this, SLOT(deviceRegisteredEmitter()));
	delay.start();
}
void APIAccount::unregisterDevice(int token_type, QString token){
	connect(&delay, SIGNAL(finished()), this, SLOT(deviceUnregisteredEmitter()));
	delay.start();
}
void APIAccount::updateNotifySettings(InputNotifyPeer* peer, InputPeerNotifySettings* settings){
	connect(&delay, SIGNAL(finished()), this, SLOT(notifySettingsUpdatedEmitter()));
	delay.start();
}
void APIAccount::getNotifySettings(InputNotifyPeer* peer){
	connect(&delay, SIGNAL(finished()), this, SLOT(notifySettingsEmitter()));
	delay.start();
}
void APIAccount::resetNotifySettings(){
	connect(&delay, SIGNAL(finished()), this, SLOT(notifySettingsResetEmitter()));
	delay.start();
}
void APIAccount::updateProfile(QString first_name, QString last_name){
	connect(&delay, SIGNAL(finished()), this, SLOT(profileUpdatedEmitter()));
	delay.start();
}
void APIAccount::updateStatus(bool offline){
	connect(&delay, SIGNAL(finished()), this, SLOT(statusUpdatedEmitter()));
	delay.start();
}
void APIAccount::getWallPapers(){
	connect(&delay, SIGNAL(finished()), this, SLOT(wallPapersEmitter()));
	delay.start();
}
void APIAccount::checkUsername(QString username){
	connect(&delay, SIGNAL(finished()), this, SLOT(usernameCheckedEmitter()));
	delay.start();
}
void APIAccount::updateUsername(QString username){
	connect(&delay, SIGNAL(finished()), this, SLOT(usernameUpdatedEmitter()));
	delay.start();
}



void APIAccount::deviceRegisteredEmitter(){
	disconnect(&delay, SIGNAL(finished()), this, SLOT(deviceRegisteredEmitter()));
	emit deviceRegistered(true);
}
void APIAccount::deviceUnregisteredEmitter(){
	disconnect(&delay, SIGNAL(finished()), this, SLOT(deviceUnregisteredEmitter()));
	emit deviceUnregistered(true);
}
void APIAccount::notifySettingsUpdatedEmitter(){
	disconnect(&delay, SIGNAL(finished()), this, SLOT(notifySettingsUpdatedEmitter()));
	emit notifySettingsUpdated(true);
}
void APIAccount::notifySettingsEmitter(){
	disconnect(&delay, SIGNAL(finished()), this, SLOT(notifySettingsEmitter()));
    pns.mute_until = 1337;
    pns.sound = "zvuk of the jungle";
    pns.events_mask = 31337;
	emit notifySettings(&pns);
}
void APIAccount::notifySettingsResetEmitter(){
	disconnect(&delay, SIGNAL(finished()), this, SLOT(notifySettingsResetEmitter()));
	emit notifySettingsReset(true);
}
void APIAccount::profileUpdatedEmitter(){
	disconnect(&delay, SIGNAL(finished()), this, SLOT(profileUpdatedEmitter()));
    user.id = 1337;
    user.first_name = "Radomir";
    user.last_name = "Cetnik";
    user.username = "Ubica";
    user.access_hash = 31337;
    user.phone = "12345678";
    user.inactive = false;
	emit profileUpdated(&user);
}
void APIAccount::statusUpdatedEmitter(){
	disconnect(&delay, SIGNAL(finished()), this, SLOT(statusUpdatedEmitter()));
	emit statusUpdated(true);
}
void APIAccount::wallPapersEmitter(){
	disconnect(&delay, SIGNAL(finished()), this, SLOT(wallPapersEmitter()));
	emit wallPapers(&wallpapers);
}
void APIAccount::usernameCheckedEmitter(){
	disconnect(&delay, SIGNAL(finished()), this, SLOT(usernameCheckedEmitter()));
	emit usernameChecked(true);
}
void APIAccount::usernameUpdatedEmitter(){
	disconnect(&delay, SIGNAL(finished()), this, SLOT(usernameUpdatedEmitter()));
    user.id = 1337;
    user.first_name = "Radomir";
    user.last_name = "Cetnik";
    user.username = "Ubica";
    user.access_hash = 31337;
    user.phone = "12345678";
    user.inactive = false;
	emit usernameUpdated(&user);
}
