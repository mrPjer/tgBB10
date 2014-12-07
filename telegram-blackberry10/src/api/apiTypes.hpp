/*
 * apiTypes.hpp
 *
 *  Created on: 6. 12. 2014.
 *      Author: Alfis
 */

#ifndef APITYPES_HPP_
#define APITYPES_HPP_

#include <QString>

struct PhoneChecked: public QObject{
    Q_OBJECT
    Q_PROPERTY(bool phone_registered READ isPhoneRegistered)
    Q_PROPERTY(bool phone_invited READ isPhoneInvited)
public:
    bool isPhoneRegistered(){return phone_registered;}
    bool isPhoneInvited(){return phone_invited;}

    bool phone_registered;
    bool phone_invited;
};

struct CodeSent: public QObject{
    Q_OBJECT
public:
    bool phone_registered;
    QString phone_code_hash;
};

struct FileLocation: public QObject{
    Q_OBJECT
public:
    int dc_id;
    long volume_id;
    int local_id;
    long secret;
};

struct UserProfilePhoto: public QObject{
    Q_OBJECT
public:
    long photo_id;
    FileLocation photo_small;
    FileLocation photo_big;
};

struct UserStatus: public QObject{
    Q_OBJECT
public:
    int expires;
    int was_online;
};

struct User: public QObject{
    Q_OBJECT
public:
    int id;
    QString first_name;
    QString last_name;
    QString phone;
    UserProfilePhoto photo;
    UserStatus status;
    bool inactive;
};

struct Authorization: public QObject{
    Q_OBJECT
public:
    int expires;
    User user;
};

struct ExportedAuthorization: public QObject{
    Q_OBJECT
public:
    int id;
    QString bytes;
};


#endif /* APITYPES_HPP_ */
