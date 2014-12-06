/*
 * apiTypes.hpp
 *
 *  Created on: 6. 12. 2014.
 *      Author: Alfis
 */

#ifndef APITYPES_HPP_
#define APITYPES_HPP_

struct PhoneChecked{
    bool phone_registered;
    bool phone_invited;
};

struct CodeSent{
    bool phone_registered;
    string phone_code_hash;
};

struct FileLocation{
    int dc_id;
    long volume_id;
    int local_id;
    long secret;
};

struct UserProfilePhoto{
    long photo_id;
    FileLocation photo_small;
    FileLocation photo_big;
};

struct UserStatus{
    int expires;
    int was_online;
};

struct User{
    int id;
    string first_name;
    string last_name;
    string phone;
    UserProfilePhoto photo;
    UserStatus status;
    bool inactive;
};

struct Authorization{
    int expires;
    User user;
};

struct ExportedAuthorization{
    int id;
    string bytes;
};


#endif /* APITYPES_HPP_ */
