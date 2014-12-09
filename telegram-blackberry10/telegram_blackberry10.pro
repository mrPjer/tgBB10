APP_NAME = telegram_blackberry10

CONFIG += qt warn_on cascades10

LIBS += -lcrypto

include(config.pri)

INCLUDEPATH += $$_PRO_FILE_PWD_/../telegram-qt4/src
include($$quote($$_PRO_FILE_PWD_)/../telegram-qt4/static.pri)
