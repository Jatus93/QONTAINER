QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_test_light.cpp

unix:!macx: LIBS += -L$$OUT_PWD/../IoT/ -lIoT

INCLUDEPATH += $$PWD/../IoT/light
DEPENDPATH += $$PWD/../IoT/light

unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../IoT/libIoT.a
