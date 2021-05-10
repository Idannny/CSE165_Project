QT       += core gui\
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = First
TEMPLATE = app

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Button.cpp \
    Color.cpp \
    Game.cpp \
    Goal.cpp \
    Player.cpp \
    Score.cpp \
    Warrants.cpp \
    main.cpp \
    walls.cpp

HEADERS += \
    Button.h \
    Button.h \
    Color.h \
    Game.h \
    Goal.h \
    Player.h \
    Score.h \
    Warrants.h \
    walls.h

FORMS += \
   # TitleWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    media.qrc

DISTFILES +=
