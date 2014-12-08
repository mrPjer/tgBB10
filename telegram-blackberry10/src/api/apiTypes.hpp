#ifndef APITYPES_HPP_
#define APITYPES_HPP_

#include <QString>
#include <vector>
using namespace std;

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
    Q_PROPERTY(bool phone_registered READ isPhoneRegistered)
    Q_PROPERTY(QString phone_code_hash READ getPhoneCodeHash)
public:
    bool isPhoneRegistered(){return phone_registered;}
    QString getPhoneCodeHash(){return phone_code_hash;}

    bool phone_registered;
    QString phone_code_hash;
};

struct FileLocation: public QObject{
    Q_OBJECT
    Q_PROPERTY(int dc_id READ getDCID)
    Q_PROPERTY(int volume_id READ getVolumeID)
    Q_PROPERTY(int local_id READ getLocalID)
    Q_PROPERTY(int secret READ getSecret)
public:
    int getDCID(){return dc_id;}
    int getVolumeID(){return volume_id;}
    int getLocalID(){return local_id;}
    int getSecret(){return secret;}

    int dc_id;
    long volume_id;
    int local_id;
    long secret;
};

struct UserProfilePhoto: public QObject{
    Q_OBJECT
    Q_PROPERTY(long photo_id READ getPhotoID)
    Q_PROPERTY(FileLocation* photo_small READ getPhotoSmall)
    Q_PROPERTY(FileLocation* photo_big READ getPhotoBig)
public:
    long getPhotoID(){return photo_id;}
    FileLocation* getPhotoSmall(){return photo_small;}
    FileLocation* getPhotoBig(){return photo_big;}

    long photo_id;
    FileLocation* photo_small;
    FileLocation* photo_big;
};

struct UserStatus: public QObject{
    Q_OBJECT
    Q_PROPERTY(int expires READ getExpires)
    Q_PROPERTY(int was_online READ getWasOnline)
public:
    int getExpires(){return expires;}
    int getWasOnline(){return was_online;}

    int expires;
    int was_online;
};

struct User: public QObject{
    Q_OBJECT
    Q_PROPERTY(int id READ getID)
    Q_PROPERTY(QString first_name READ getFirstName)
    Q_PROPERTY(QString last_name READ getLastName)
    Q_PROPERTY(QString phone READ getPhone)
    Q_PROPERTY(UserProfilePhoto* photo READ getPhoto)
    Q_PROPERTY(UserStatus* status READ getStatus)
    Q_PROPERTY(bool inactive READ isInactive)
public:
    int getID(){return id;}
    QString getFirstName(){return first_name;}
    QString getLastName(){return last_name;}
    QString getPhone(){return phone;}
    UserProfilePhoto* getPhoto(){return photo;}
    UserStatus* getStatus(){return status;}
    bool isInactive(){return inactive;}

    int id;
    QString first_name;
    QString last_name;
    QString username;
    long access_hash;
    QString phone;
    UserProfilePhoto* photo;
    UserStatus* status;
    bool inactive;
};

struct Authorization: public QObject{
    Q_OBJECT
    Q_PROPERTY(int expires READ getExpires)
    Q_PROPERTY(User* user READ getUser)
public:
    int getExpires(){return expires;}
    User* getUser(){return user;}

    int expires;
    User* user;
};

struct ExportedAuthorization: public QObject{
    Q_OBJECT
    Q_PROPERTY(int id READ getID)
    Q_PROPERTY(QString bytes READ getBytes)
public:
    int getID(){return id;}
    QString getBytes(){return bytes;}

    int id;
    QString bytes;
};

struct InputPeer: public QObject{
    Q_OBJECT
    Q_PROPERTY(int user_id READ getUserID)
    Q_PROPERTY(long access_hash READ getAccessHash)
    Q_PROPERTY(int chat_id READ getChatID)
public:
    int getUserID(){return user_id;}
    long getAccessHash(){return access_hash;}
    int getChatID(){return chat_id;}

    int user_id;
    long access_hash;
    int chat_id;
};

struct InputGeoChat: public QObject{
    Q_OBJECT
    Q_PROPERTY(int chat_id READ getChatID)
    Q_PROPERTY(long access_hash READ getAccessHash)
public:
    int getChatID(){return chat_id;}
    long getAccessHash(){return access_hash;}

    int chat_id;
    long access_hash;
};

struct InputNotifyPeer: public QObject{
    Q_OBJECT
    Q_PROPERTY(InputPeer* peer READ getPeer)
    Q_PROPERTY(InputGeoChat* peer_geo_chat READ getPeerGeoChat)
public:
    InputPeer* getPeer(){return peer;}
    InputGeoChat* getPeerGeoChat(){return peer_geo_chat;}

    InputPeer* peer;
    InputGeoChat* peer_geo_chat;
};

struct InputPeerNotifyEvents: public QObject{
    Q_OBJECT
    Q_PROPERTY(bool all READ isAll)
public:
    bool isAll(){return all;}

    bool all;
};

struct PeerNotifySettings: public QObject{
    Q_OBJECT
    Q_PROPERTY(int mute_until READ getMuteUntil)
    Q_PROPERTY(QString sound READ getSound)
    Q_PROPERTY(bool show_previews READ isShowingPreviews)
    Q_PROPERTY(int events_mask READ getEventsMask)
public:
    int getMuteUntil(){return mute_until;}
    QString getSound(){return sound;}
    bool isShowingPreviews(){return show_previews;}
    int getEventsMask(){return events_mask;}

    int mute_until;
    QString sound;
    bool show_previews;
    int events_mask;

};

struct InputPeerNotifySettings: public PeerNotifySettings{
    Q_OBJECT
    Q_PROPERTY(InputPeerNotifyEvents* events READ getEvents)
public:
    InputPeerNotifyEvents* getEvents(){return events;}

    InputPeerNotifyEvents* events;
};

struct PhotoSize: public QObject{
    Q_OBJECT
    Q_PROPERTY(QString type READ getType)
    Q_PROPERTY(FileLocation* location READ getLocation)
    Q_PROPERTY(int w READ getW)
    Q_PROPERTY(int h READ getH)
    Q_PROPERTY(int size READ getSize)
    Q_PROPERTY(QString bytes READ getBytes)
public:
    QString getType(){return type;}
    FileLocation* getLocation(){return location;}
    int getW(){return w;}
    int getH(){return h;}
    int getSize(){return size;}
    QString getBytes(){return bytes;}

    QString type;
    FileLocation* location;
    int w;
    int h;
    int size;
    QString bytes;
};

struct WallPaper: public QObject{
    Q_OBJECT
    Q_PROPERTY(int id READ getID)
    Q_PROPERTY(QString title READ getTitle)
    Q_PROPERTY(vector<PhotoSize>* sizes READ getSizes)
    Q_PROPERTY(int color READ getColor)
    Q_PROPERTY(int bg_color READ getBgColor)
public:
    int getID(){return id;}
    QString getTitle(){return title;}
    vector<PhotoSize>* getSizes(){return sizes;}
    int getColor(){return color;}
    int getBgColor(){return bg_color;}

    int id;
    QString title;
    vector<PhotoSize>* sizes;
    int color;
    int bg_color;
};

#endif
