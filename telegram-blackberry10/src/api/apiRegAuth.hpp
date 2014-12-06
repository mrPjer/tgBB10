/*
 * apiRegAuth.hpp
 *
 *  Created on: 6. 12. 2014.
 *      Author: Alfis
 */

#ifndef APIREGAUTH_HPP_
#define APIREGAUTH_HPP_

#include "apiDelay.hpp"

class APIRegAuth: public APIDelay{
    Q_OBJECT

signals:
    void phoneChecked();
    void codeSent();
    void smsSent();
    void callSent();
    void signedUp();
    void signedIn();
    void loggedOut();
    void invitesSent();
    void authorizationsReset();
    void authorizationExported();
    void authorizationImported();
    void tempAuthKeyBound();


public slots:
    void checkPhone();
    void sendCode();
    void sendSms();
    void sendCall();
    void signUp();
    void signIn();
    void logOut();
    void sendInvites();
    void resetAuthorizations();
    void exportAuthorization();
    void importAuthorization();
    void bindTempAuthKey();

    void phoneCheckedEmitter();
    void codeSentEmitter();
    void smsSentEmitter();
    void callSentEmitter();
    void signedUpEmitter();
    void signedInEmitter();
    void loggedOutEmitter();
    void invitesSentEmitter();
    void authorizationsResetEmitter();
    void authorizationExportedEmitter();
    void authorizationImportedEmitter();
    void tempAuthKeyBoundEmitter();
};



#endif /* APIREGAUTH_HPP_ */
