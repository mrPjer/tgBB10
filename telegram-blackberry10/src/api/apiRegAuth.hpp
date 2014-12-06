/*
 * apiRegAuth.hpp
 *
 *  Created on: 6. 12. 2014.
 *      Author: Alfis
 */

#ifndef APIREGAUTH_HPP_
#define APIREGAUTH_HPP_

#include "apiDelay.hpp"
#include "apiTypes.hpp"
#include <string>
#include <vector>
using namespace std;

class APIRegAuth: public APIDelay{
    Q_OBJECT

signals:
    void phoneChecked(PhoneChecked pc);
    void codeSent(CodeSent cs);
    void smsSent(bool);
    void callSent(bool);
    void signedUp(Authorization auth);
    void signedIn(Authorization auth);
    void loggedOut(bool);
    void invitesSent(bool);
    void authorizationsReset(bool);
    void authorizationExported(ExportedAuthorization ea);
    void authorizationImported(Authorization auth);
//    void tempAuthKeyBound();


public slots:
    void checkPhone(string phone_number);
    void sendCode(string num, int sms_type, int api_id, string api_hash, string lang_code);
    void sendSms(string phone_number, string phone_code_hash);
    void sendCall(string phone_number, string phone_code_hash);
    void signUp(string phone_number, string phone_code_hash, string phone_code, string first_name, string last_name);
    void signIn(string phone_number, string phone_code_hash, string phone_code);
    void logOut();
    void sendInvites(vector<string>& numbers, string message);
    void resetAuthorizations();
    void exportAuthorization(int dc_id);
    void importAuthorization(int id, string bytes);
//    void bindTempAuthKey();

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
//    void tempAuthKeyBoundEmitter();
};



#endif /* APIREGAUTH_HPP_ */
