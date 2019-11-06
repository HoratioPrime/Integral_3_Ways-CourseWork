QT       += core gui
QT       += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

win32:RC_ICONS += img/ico-i3.ico

CONFIG += c++14

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
    functionpack.cpp \
    integral.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    functionpack.h \
    integral.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    img/Asset_D^x.png \
    img/Asset_D^x@2x.png \
    img/Asset_D^x@3x.png \
    img/Asset_D^x@4x.png \
    img/Asset_arccos.png \
    img/Asset_arccos@2x.png \
    img/Asset_arccos@3x.png \
    img/Asset_arcctg.png \
    img/Asset_arcctg@2x.png \
    img/Asset_arcctg@3x.png \
    img/Asset_arcctg@4x.png \
    img/Asset_arcsin.png \
    img/Asset_arcsin@2x.png \
    img/Asset_arcsin@3x.png \
    img/Asset_arcsin@4x.png \
    img/Asset_arctg.png \
    img/Asset_arctg@2x.png \
    img/Asset_arctg@4x.png \
    img/Asset_cos.png \
    img/Asset_cos@2x.png \
    img/Asset_cos@3x.png \
    img/Asset_cos@4x.png \
    img/Asset_ctg.png \
    img/Asset_ctg@2x.png \
    img/Asset_ctg@3x.png \
    img/Asset_ctg@4x.png \
    img/Asset_exp.png \
    img/Asset_exp@2x.png \
    img/Asset_exp@3x.png \
    img/Asset_exp@4x.png \
    img/Asset_ln.png \
    img/Asset_ln@2x.png \
    img/Asset_ln@3x.png \
    img/Asset_ln@4x.png \
    img/Asset_sin.png \
    img/Asset_sin@2x.png \
    img/Asset_sin@3x.png \
    img/Asset_sin@4x.png \
    img/Asset_tg.png \
    img/Asset_tg@2x.png \
    img/Asset_tg@3x.png \
    img/Asset_tg@4x.png \
    img/Asset_x^D.png \
    img/Asset_x^D@2x.png \
    img/Asset_x^D@3x.png \
    img/Asset_x^D@4x.png \
    img/PastIntegrals \
    img/checked.png \
    img/circle.png \
    img/ic_radio_button_unchecked_24px.svg \
    img/ico-i3.ico \
    img/ico-i3.png \
    img/integral-GUI.png \
    img/integral-GUI_back.png \
    img/intro.png \
    res/PastIntegrals \
    sound/oxp.wav

RESOURCES +=
