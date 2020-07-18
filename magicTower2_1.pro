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
    Information.cpp \
    beginning.cpp \
    book.cpp \
    dialog.cpp \
    dmsdoor.cpp \
    fight.cpp \
    floortrans.cpp \
    main.cpp \
    mainwindow.cpp \
    mypushbutton.cpp \
    store.cpp \
    variables.cpp

HEADERS += \
    Information.h \
    beginning.h \
    book.h \
    dialog.h \
    dmsdoor.h \
    fight.h \
    floortrans.h \
    mainwindow.h \
    mt.h \
    mypushbutton.h \
    store.h \
    variables.h

FORMS += \
    beginning.ui \
    book.ui \
    dialog.ui \
    dmsdoor.ui \
    fight.ui \
    floortrans.ui \
    mainwindow.ui \
    store.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    magicTower2_1.pro

RESOURCES += \
    Graphics/res.qrc \
    Sound_sour.qrc \
    Sprite_sour_01.qrc \
    Sprite_sour_02.qrc \
    Sprite_sour_03.qrc \
    Sprite_sour_04.qrc \
    Sprite_sour_05.qrc \
    img.qrc

DISTFILES += \
    magicTower2_0_zh_CN.ts \
