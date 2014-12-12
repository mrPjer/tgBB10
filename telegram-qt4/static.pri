LIBTARGET = telegram_qt4

profile {
    LIBTARGETDIR_PROFILE = -p
}
CONFIG(debug, debug|release) {
    LIBTARGETDIR_DEBUG = -g
}
device {
    LIBTARGETDIR = arm$${LIBTARGETDIR_PROFILE}
}
simulator {
    LIBTARGETDIR = x86$${LIBTARGETDIR_PROFILE}
}

BASEDIR      = $${PWD}
INCLUDEPATH *= $$quote($${BASEDIR}/include)
DEPENDPATH  *= $$quote($${BASEDIR}/include)
LIBS        += -L$${BASEDIR}/$${LIBTARGETDIR} -l$${LIBTARGET}
