/*
 * apiRegAuth.cpp
 *
 *  Created on: 6. 12. 2014.
 *      Author: Alfis
 */

#include <ctime>
#include "apiRegAuth.hpp"
#include <bb/cascades/CustomControl>

APIRegAuth::APIRegAuth(){
    auth.user = new User();
    auth.user->photo = new UserProfilePhoto();
    auth.user->status = new UserStatus();
    auth.user->photo->photo_small = new FileLocation();
    auth.user->photo->photo_big = new FileLocation();
    auth.user->status = new UserStatus();
}

void APIRegAuth::requestPhoneStatus(QString* phone_number){
    connect(&delay, SIGNAL(finished()), this, SLOT(phoneStatusReceivedEmitter()));
    delay.start();
}
void APIRegAuth::requestPhoneCode(QString* phone_number){
    //connect(&delay, SIGNAL(finished()), this, SLOT(codeSentEmitter()));
    delay.start();
}
void APIRegAuth::sendSms(QString* phone_number, QString* phone_code_hash){
    connect(&delay, SIGNAL(finished()), this, SLOT(smsSentEmitter()));
    delay.start();
}
void APIRegAuth::sendCall(QString* phone_number, QString* phone_code_hash){
    connect(&delay, SIGNAL(finished()), this, SLOT(callSentEmitter()));
    delay.start();
}
void APIRegAuth::signUp(QString* phone_number, QString* phone_code, QString* first_name, QString* last_name){
    //connect(&delay, SIGNAL(finished()), this, SLOT(signedUpEmitter()));
    delay.start();
}
void APIRegAuth::signIn(QString* phone_number, QString* phone_code){
    //connect(&delay, SIGNAL(finished()), this, SLOT(signedInEmitter()));
    delay.start();
}
void APIRegAuth::logOut(){
    connect(&delay, SIGNAL(finished()), this, SLOT(loggedOutEmitter()));
    delay.start();
}
void APIRegAuth::sendInvites(vector<QString*>* numbers, QString* message){
    connect(&delay, SIGNAL(finished()), this, SLOT(invitesSentEmitter()));
    delay.start();
}
void APIRegAuth::resetAuthorizations(){
    connect(&delay, SIGNAL(finished()), this, SLOT(authorizationsResetEmitter()));
    delay.start();
}
void APIRegAuth::exportAuthorization(int dc_id){
    connect(&delay, SIGNAL(finished()), this, SLOT(authorizationExportedEmitter()));
    delay.start();
}
void APIRegAuth::importAuthorization(int id, QString* bytes){
    connect(&delay, SIGNAL(finished()), this, SLOT(authorizationImportedEmitter()));
    delay.start();
}
// void APIRegAuth::bindTempAuthKey(){ connect(&delay, SIGNAL(finished()), this, SLOT(tempAuthKeyBoundEmitter())); }



void APIRegAuth::phoneStatusReceivedEmitter(){
    disconnect(&delay, SIGNAL(finished()), this, SLOT(phoneStatusReceivedEmitter()));
    QString str = "Whatever?";
    emit phoneStatusReceived(str, true, true);
}
/*
void APIRegAuth::codeSentEmitter(){
    disconnect(&delay, SIGNAL(finished()), this, SLOT(codeSentEmitter()));
    cs.phone_registered = true;
    cs.phone_code_hash = "2dc02d2cda9e615c84";
    emit codeSent(&cs);
}
*/
void APIRegAuth::smsSentEmitter(){
    disconnect(&delay, SIGNAL(finished()), this, SLOT(smsSentEmitter()));
    emit smsSent(true);
}
void APIRegAuth::callSentEmitter(){
    disconnect(&delay, SIGNAL(finished()), this, SLOT(callSentEmitter()));
    emit callSent(true);
}
/*
void APIRegAuth::signedUpEmitter(){
    disconnect(&delay, SIGNAL(finished()), this, SLOT(signedUpEmitter()));
    auth.expires = time(NULL) + 600;
    auth.user->id = 1337;
    auth.user->first_name = "Radomir";
    auth.user->last_name = "Cetnik";
    auth.user->username = "Ubica";
    auth.user->access_hash = 31337;
    auth.user->phone = "12345678";
    auth.user->inactive = false;
    emit signedUp(&auth);
}
void APIRegAuth::signedInEmitter(){
    disconnect(&delay, SIGNAL(finished()), this, SLOT(signedInEmitter()));
    auth.expires = time(NULL) + 600;
    auth.user->id = 1337;
    auth.user->first_name = "Radomir";
    auth.user->last_name = "Serbedzija";
    auth.user->phone = "12345678";
    auth.user->inactive = false;
    emit signedIn(&auth);
}
*/
void APIRegAuth::loggedOutEmitter(){
    disconnect(&delay, SIGNAL(finished()), this, SLOT(loggedOutEmitter()));
    emit loggedOut(true);
}
void APIRegAuth::invitesSentEmitter(){
    disconnect(&delay, SIGNAL(finished()), this, SLOT(invitesSentEmitter()));
    emit invitesSent(true);
}
void APIRegAuth::authorizationsResetEmitter(){
    disconnect(&delay, SIGNAL(finished()), this, SLOT(authorizationsResetEmitter()));
    emit authorizationsReset(true);
}
void APIRegAuth::authorizationExportedEmitter(){
    disconnect(&delay, SIGNAL(finished()), this, SLOT(authorizationExportedEmitter()));
    ea.id = 1337;
    ea.bytes = "some bytes here";
    emit authorizationExported(&ea);
}
void APIRegAuth::authorizationImportedEmitter(){
    disconnect(&delay, SIGNAL(finished()), this, SLOT(authorizationImportedEmitter()));
    auth.expires = time(NULL) + 600;
    auth.user->id = 1337;
    auth.user->first_name = "Radomir";
    auth.user->last_name = "Serbedzija";
    auth.user->phone = "12345678";
    auth.user->inactive = false;
    emit authorizationImported(&auth);
}
// void APIRegAuth::tempAuthKeyBoundEmitter(){ disconnect(&delay, SIGNAL(finished()), this, SLOT(tempAuthKeyBoundEmitter())); emit tempAuthKeyBound();}
