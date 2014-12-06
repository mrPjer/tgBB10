/*
 * apiRegAuth.cpp
 *
 *  Created on: 6. 12. 2014.
 *      Author: Alfis
 */

#include <ctime>
#include "apiRegAuth.hpp"

void APIRegAuth::checkPhone(string phone_number){
    QObject::connect(this, SIGNAL(finished()), this, SLOT(phoneCheckedEmitter()));
    start();
}
void APIRegAuth::sendCode(string phone_number, int sms_type, int api_id, string api_hash, string lang_code){
    QObject::connect(this, SIGNAL(finished()), this, SLOT(codeSentEmitter()));
    start();
}
void APIRegAuth::sendSms(string phone_number, string phone_code_hash){
    QObject::connect(this, SIGNAL(finished()), this, SLOT(smsSentEmitter()));
    start();
}
void APIRegAuth::sendCall(string phone_number, string phone_code_hash){
    QObject::connect(this, SIGNAL(finished()), this, SLOT(callSentEmitter()));
    start();
}
void APIRegAuth::signUp(string phone_number, string phone_code_hash, string phone_code, string first_name, string last_name){
    QObject::connect(this, SIGNAL(finished()), this, SLOT(signedUpEmitter()));
    start();
}
void APIRegAuth::signIn(string phone_number, string phone_code_hash, string phone_code){
    QObject::connect(this, SIGNAL(finished()), this, SLOT(signedInEmitter()));
    start();
}
void APIRegAuth::logOut(){
    QObject::connect(this, SIGNAL(finished()), this, SLOT(loggedOutEmitter()));
    start();
}
void APIRegAuth::sendInvites(vector<string>& numbers, string message){
    QObject::connect(this, SIGNAL(finished()), this, SLOT(invitesSentEmitter()));
    start();
}
void APIRegAuth::resetAuthorizations(){
    QObject::connect(this, SIGNAL(finished()), this, SLOT(authorizationsResetEmitter()));
    start();
}
void APIRegAuth::exportAuthorization(int dc_id){
    QObject::connect(this, SIGNAL(finished()), this, SLOT(authorizationExportedEmitter()));
    start();
}
void APIRegAuth::importAuthorization(int id, string bytes){
    QObject::connect(this, SIGNAL(finished()), this, SLOT(authorizationImportedEmitter()));
    start();
}
// void APIRegAuth::bindTempAuthKey(){ QObject::connect(this, SIGNAL(finished()), this, SLOT(tempAuthKeyBoundEmitter())); }



void APIRegAuth::phoneCheckedEmitter(){
    QObject::disconnect(this, SIGNAL(finished()), this, SLOT(phoneCheckedEmitter()));
    PhoneChecked pc;
    pc.phone_invited = true;
    pc.phone_registered = true;
    emit phoneChecked(pc);
}
void APIRegAuth::codeSentEmitter(){
    QObject::disconnect(this, SIGNAL(finished()), this, SLOT(codeSentEmitter()));
    CodeSent cs;
    cs.phone_registered = true;
    cs.phone_code_hash = "2dc02d2cda9e615c84";
    emit codeSent(cs);
}
void APIRegAuth::smsSentEmitter(){
    QObject::disconnect(this, SIGNAL(finished()), this, SLOT(smsSentEmitter()));
    emit smsSent(true);
}
void APIRegAuth::callSentEmitter(){
    QObject::disconnect(this, SIGNAL(finished()), this, SLOT(callSentEmitter()));
    emit callSent(true);
}
void APIRegAuth::signedUpEmitter(){
    QObject::disconnect(this, SIGNAL(finished()), this, SLOT(signedUpEmitter()));
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
    QObject::disconnect(this, SIGNAL(finished()), this, SLOT(signedInEmitter()));
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
    QObject::disconnect(this, SIGNAL(finished()), this, SLOT(loggedOutEmitter()));
    emit loggedOut(true);
}
void APIRegAuth::invitesSentEmitter(){
    QObject::disconnect(this, SIGNAL(finished()), this, SLOT(invitesSentEmitter()));
    emit invitesSent(true);
}
void APIRegAuth::authorizationsResetEmitter(){
    QObject::disconnect(this, SIGNAL(finished()), this, SLOT(authorizationsResetEmitter()));
    emit authorizationsReset(true);
}
void APIRegAuth::authorizationExportedEmitter(){
    QObject::disconnect(this, SIGNAL(finished()), this, SLOT(authorizationExportedEmitter()));
    ExportedAuthorization ea;
    ea.id = 1337;
    ea.bytes = "some bytes here";
    emit authorizationExported(ea);
}
void APIRegAuth::authorizationImportedEmitter(){
    QObject::disconnect(this, SIGNAL(finished()), this, SLOT(authorizationImportedEmitter()));
    Authorization auth;
    auth.expires = time(NULL) + 600;
    auth.user.id = 1337;
    auth.user.first_name = "Radomir";
    auth.user.last_name = "Cetnik";
    auth.user.phone = "12345678";
    auth.user.inactive = false;
    emit authorizationImported(auth);
}
// void APIRegAuth::tempAuthKeyBoundEmitter(){ QObject::disconnect(this, SIGNAL(finished()), this, SLOT(tempAuthKeyBoundEmitter())); emit tempAuthKeyBound();}
