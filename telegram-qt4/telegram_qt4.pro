APP_NAME = telegram_qt4

CONFIG += qt warn_on

DEFINES += TELEGRAM_QT4_STATIC_LINK

include(src/telegram-qt.pro)

# uncomment for building static library
CONFIG += staticlib

# uncomment for generating separate debug info
# CONFIG += separate_debug_info

# include(cascades10_library.pri)

include(config.pri)

# specify a list of .ts files for supported languages
# TRANSLATIONS += $${TARGET}_en_US.ts

# uncomment following line to include translations to binary
# RESOURCES += translations/qm/telegram_qt4_translations.qrc
