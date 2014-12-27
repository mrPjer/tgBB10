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

    Q_INVOKABLE QByteArray connectionSecretInfo() const;

signals:
    void phoneStatusReceived(const QString& phone, bool registered, bool invited);
    void phoneNumberInvalid();
    void authenticated();
//    void codeSent(CodeSent* cs);
//    void smsSent(bool result);
    void callSent(bool);
//    void signedUp(Authorization* auth);
    void signedIn(const Authorization &auth);
    void loggedOut(bool);
    void invitesSent(bool);
    void authorizationsReset(bool);
    void authorizationExported(ExportedAuthorization* ea);
    void authorizationImported(Authorization* auth);

public slots:
// Implemented in CTelegramCore
    void requestPhoneStatus(const QString &phone_number);
    void requestPhoneCode(const QString  &phone_number);
    void signIn(const QString &phone_number, const QString &auth_code);
    void signUp(QString* phone_number, QString* auth_code, QString* first_name, QString* last_name);
// Got this far.
    void sendSms(const QString &phone_number, const QString &phone_code_hash);
    void sendCall(const QString &phone_number, const QString &phone_code_hash);
    void logOut();
    void sendInvites(vector<QString*>* numbers, QString* message);
    void resetAuthorizations();
    void exportAuthorization(int dc_id);
    void importAuthorization(int id, QString* bytes);

    void phoneStatusReceivedEmitter();
//    void codeSentEmitter();
//    void smsSentEmitter();
    void callSentEmitter();
//    void signedUpEmitter();
    void signedInEmitter();
    void loggedOutEmitter();
    void invitesSentEmitter();
    void authorizationsResetEmitter();
    void authorizationExportedEmitter();
    void authorizationImportedEmitter();
};

#endif
