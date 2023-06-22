QT       += core gui
QT       += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    block.cpp \
    blockI.cpp \
    blockJ.cpp \
    blockL.cpp \
    blockO.cpp \
    blockS.cpp \
    blockT.cpp \
    blockZ.cpp \
    checkerboard.cpp \
    coloroptionblock.cpp \
    database.cpp \
    gamemanager.cpp \
    gamescene.cpp \
    keyoptionblock.cpp \
    loadgamescene.cpp \
    main.cpp \
    mainscene.cpp \
    optionblock.cpp \
    profilemanager.cpp \
    rankingsscene.cpp \
    settingscene.cpp \
    userprofile.cpp

HEADERS += \
    block.h \
    blockI.h \
    blockJ.h \
    blockL.h \
    blockO.h \
    blockS.h \
    blockT.h \
    blockZ.h \
    checkerboard.h \
    coloroptionblock.h \
    database.h \
    gamemanager.h \
    gamescene.h \
    keyoptionblock.h \
    loadgamescene.h \
    mainscene.h \
    optionblock.h \
    profilemanager.h \
    rankingsscene.h \
    settingscene.h \
    userprofile.h

FORMS += \
    coloroptionblock.ui \
    gamescene.ui \
    keyoptionblock.ui \
    loadgamescene.ui \
    mainscene.ui \
    optionblock.ui \
    rankingsscene.ui \
    settingscene.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
