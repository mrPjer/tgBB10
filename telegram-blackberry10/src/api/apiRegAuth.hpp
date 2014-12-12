#ifndef APIREGAUTH_HPP_
#define APIREGAUTH_HPP_

#include "apiDelay.hpp"
#include "apiTypes.hpp"
#include <QString>
#include <vector>
#include <bb/cascades/CustomControl>
using namespace std;

class APIRegAuth: public bb::cascades::CustomControl{
    APIDelay delay;
    Q_OBJECT

    CodeSent cs;
    Authorization auth;
    ExportedAuthorization ea;

public:
    APIRegAuth();

signals:
    void phoneStatusReceived(const QString&, bool, bool);
//    void codeSent(CodeSent* cs);
    void smsSent(bool);
    void callSent(bool);
//    void signedUp(Authorization* auth);
//    void signedIn(Authorization* auth);
    void loggedOut(bool);
    void invitesSent(bool);
    void authorizationsReset(bool);
    void authorizationExported(ExportedAuthorization* ea);
    void authorizationImported(Authorization* auth);

public slots:
// Implemented in CTelegramCore
    void requestPhoneStatus(QString* phone_number);
    void requestPhoneCode(QString* phone_number);
    void signIn(QString* phone_number, QString* auth_code);
    void signUp(QString* phone_number, QString* auth_code, QString* first_name, QString* last_name);
// Got this far.
    void sendSms(QString* phone_number, QString* phone_code_hash);
    void sendCall(QString* phone_number, QString* phone_code_hash);
    void logOut();
    void sendInvites(vector<QString*>* numbers, QString* message);
    void resetAuthorizations();
    void exportAuthorization(int dc_id);
    void importAuthorization(int id, QString* bytes);

    void phoneStatusReceivedEmitter();
//    void codeSentEmitter();
    void smsSentEmitter();
    void callSentEmitter();
//    void signedUpEmitter();
//    void signedInEmitter();
    void loggedOutEmitter();
    void invitesSentEmitter();
    void authorizationsResetEmitter();
    void authorizationExportedEmitter();
    void authorizationImportedEmitter();
};

#endif
