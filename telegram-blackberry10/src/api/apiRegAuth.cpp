/*
 * apiRegAuth.cpp
 *
 *  Created on: 6. 12. 2014.
 *      Author: Alfis
 */

#include "apiRegAuth.hpp"

void APIRegAuth::checkPhone(){ QObject::connect(this, SIGNAL(finished()), SLOT(phoneCheckedEmitter())); }
void APIRegAuth::sendCode(){}
void APIRegAuth::sendSms(){}
void APIRegAuth::sendCall(){}
void APIRegAuth::signUp(){}
void APIRegAuth::signIn(){}
void APIRegAuth::logOut(){}
void APIRegAuth::sendInvites(){}
void APIRegAuth::resetAuthorizations(){}
void APIRegAuth::exportAuthorization(){}
void APIRegAuth::importAuthorization(){}
void APIRegAuth::bindTempAuthKey(){}

void APIRegAuth::phoneCheckedEmitter(){
    QObject::disconnect(this, SIGNAL(finished()), this, SLOT(phoneCheckedEmitter()));
    emit phoneChecked();
}
void APIRegAuth::codeSentEmitter(){}
void APIRegAuth::smsSentEmitter(){}
void APIRegAuth::callSentEmitter(){}
void APIRegAuth::signedUpEmitter(){}
void APIRegAuth::signedInEmitter(){}
void APIRegAuth::loggedOutEmitter(){}
void APIRegAuth::invitesSentEmitter(){}
void APIRegAuth::authorizationsResetEmitter(){}
void APIRegAuth::authorizationExportedEmitter(){}
void APIRegAuth::authorizationImportedEmitter(){}
void APIRegAuth::tempAuthKeyBoundEmitter(){}
