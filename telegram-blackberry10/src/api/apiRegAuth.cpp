/*
 * apiRegAuth.cpp
 *
 *  Created on: 6. 12. 2014.
 *      Author: Alfis
 */

#include <ctime>
#include "apiRegAuth.hpp"

void APIRegAuth::checkPhone(string phone_number){
    connect(&delay, SIGNAL(finished()), this, SLOT(phoneCheckedEmitter()));
    delay.start();
}
void APIRegAuth::sendCode(string phone_number, int sms_type, int api_id, string api_hash, string lang_code){
    connect(&delay, SIGNAL(finished()), this, SLOT(codeSentEmitter()));
    delay.start();
}
void APIRegAuth::sendSms(string phone_number, string phone_code_hash){
    connect(&delay, SIGNAL(finished()), this, SLOT(smsSentEmitter()));
    delay.start();
}
void APIRegAuth::sendCall(string phone_number, string phone_code_hash){
    connect(&delay, SIGNAL(finished()), this, SLOT(callSentEmitter()));
    delay.start();
}
void APIRegAuth::signUp(string phone_number, string phone_code_hash, string phone_code, string first_name, string last_name){
    connect(&delay, SIGNAL(finished()), this, SLOT(signedUpEmitter()));
    delay.start();
}
void APIRegAuth::signIn(string phone_number, string phone_code_hash, string phone_code){
    connect(&delay, SIGNAL(finished()), this, SLOT(signedInEmitter()));
    delay.start();
}
void APIRegAuth::logOut(){
    connect(&delay, SIGNAL(finished()), this, SLOT(loggedOutEmitter()));
    delay.start();
}
void APIRegAuth::sendInvites(vector<string>& numbers, string message){
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
void APIRegAuth::importAuthorization(int id, string bytes){
    connect(&delay, SIGNAL(finished()), this, SLOT(authorizationImportedEmitter()));
    delay.start();
}
// void APIRegAuth::bindTempAuthKey(){ connect(&delay, SIGNAL(finished()), this, SLOT(tempAuthKeyBoundEmitter())); }



void APIRegAuth::phoneCheckedEmitter(){
    disconnect(&delay, SIGNAL(finished()), this, SLOT(phoneCheckedEmitter()));
    PhoneChecked pc;
    pc.phone_invited = true;
    pc.phone_registered = true;
    emit phoneChecked(pc);
}
void APIRegAuth::codeSentEmitter(){
    disconnect(&delay, SIGNAL(finished()), this, SLOT(codeSentEmitter()));
    CodeSent cs;
    cs.phone_registered = true;
    cs.phone_code_hash = "2dc02d2cda9e615c84";
    emit codeSent(cs);
}
void APIRegAuth::smsSentEmitter(){
    disconnect(&delay, SIGNAL(finished()), this, SLOT(smsSentEmitter()));
    emit smsSent(true);
}
void APIRegAuth::callSentEmitter(){
    disconnect(&delay, SIGNAL(finished()), this, SLOT(callSentEmitter()));
    emit callSent(true);
}
void APIRegAuth::signedUpEmitter(){
    disconnect(&delay, SIGNAL(finished()), this, SLOT(signedUpEmitter()));
    Authorization auth;
    auth.expires = time(NULL) + 600;
    auth.user.id = 1337;
    auth.user.first_name = "Radomir";
    auth.user.last_name = "Cetnik";
    auth.user.phone = "12345678";
    auth.user.inactive = false;
    emit signedUp(auth);
}
void APIRegAuth::signedInEmitter(){
    disconnect(&delay, SIGNAL(finished()), this, SLOT(signedInEmitter()));
    Authorization auth;
    auth.expires = time(NULL) + 600;
    auth.user.id = 1337;
    auth.user.first_name = "Radomir";
    auth.user.last_name = "Cetnik";
    auth.user.phone = "12345678";
    auth.user.inactive = false;
    emit signedIn(auth);
}
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
    ExportedAuthorization ea;
    ea.id = 1337;
    ea.bytes = "some bytes here";
    emit authorizationExported(ea);
}
void APIRegAuth::authorizationImportedEmitter(){
    disconnect(&delay, SIGNAL(finished()), this, SLOT(authorizationImportedEmitter()));
    Authorization auth;
    auth.expires = time(NULL) + 600;
    auth.user.id = 1337;
    auth.user.first_name = "Radomir";
    auth.user.last_name = "Cetnik";
    auth.user.phone = "12345678";
    auth.user.inactive = false;
    emit authorizationImported(auth);
}
// void APIRegAuth::tempAuthKeyBoundEmitter(){ disconnect(&delay, SIGNAL(finished()), this, SLOT(tempAuthKeyBoundEmitter())); emit tempAuthKeyBound();}
