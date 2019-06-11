#-------------------------------------------------
#
# Project created by QtCreator 2019-05-12T17:49:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UI
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        interactiveiot.cpp \
        main.cpp \
        maincontent.cpp \
        mainwindow.cpp

HEADERS += \
        interactiveiot.h \
        maincontent.h \
        mainwindow.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


unix:!macx: LIBS += -L$$OUT_PWD/../Container/ -lContainer

INCLUDEPATH += $$PWD/../Container
DEPENDPATH += $$PWD/../Container

unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../Container/libContainer.a

unix:!macx: LIBS += -L$$OUT_PWD/../IoT/ -lIoT

INCLUDEPATH += $$PWD/../IoT
DEPENDPATH += $$PWD/../IoT

unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../IoT/libIoT.a

unix:!macx: LIBS += -L$$OUT_PWD/../IoTBuilder/ -lIoTBuilder

INCLUDEPATH += $$PWD/../IoTBuilder
DEPENDPATH += $$PWD/../IoTBuilder

unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../IoTBuilder/libIoTBuilder.a

unix:!macx: LIBS += -L$$OUT_PWD/../Model/ -lModel

INCLUDEPATH += $$PWD/../Model
DEPENDPATH += $$PWD/../Model

unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../Model/libModel.a

unix:!macx: LIBS += -L$$OUT_PWD/../QModel/ -lQModel

INCLUDEPATH += $$PWD/../QModel
DEPENDPATH += $$PWD/../QModel
