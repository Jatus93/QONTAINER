#-------------------------------------------------
#
# Project created by QtCreator 2019-01-19T17:53:55
#
#-------------------------------------------------
QT       -= gui

TARGET = IoT
TEMPLATE = lib
CONFIG += staticlib
CONFIG += c++11



# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        iot.cpp \
    switch/switch.cpp \
    shutter/shutter.cpp \
    light/dimmerablelight.cpp \
    iotbuilder.cpp
	

HEADERS += \
        iot.h \
    switch/switch.h \
    shutter/shutter.h \
    light/dimmerablelight.h\
    iotbuilder.h \
    iotfactorydevice.h \
    iotdevices.h
