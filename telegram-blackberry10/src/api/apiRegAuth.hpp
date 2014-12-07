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
#include <QString>
#include <vector>
using namespace std;

class APIRegAuth: public QObject{
    APIDelay delay;
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
    void checkPhone(QString phone_number);
    void sendCode(QString phone_number, int sms_type, int api_id, QString api_hash, QString lang_code);
    void sendSms(QString phone_number, QString phone_code_hash);
    void sendCall(QString phone_number, QString phone_code_hash);
    void signUp(QString phone_number, QString phone_code_hash, QString phone_code, QString first_name, QString last_name);
    void signIn(QString phone_number, QString phone_code_hash, QString phone_code);
    void logOut();
    void sendInvites(vector<QString>& numbers, QString message);
    void resetAuthorizations();
    void exportAuthorization(int dc_id);
    void importAuthorization(int id, QString bytes);
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
