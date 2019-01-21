QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_test_shutter.cpp

unix:!macx: LIBS += -L$$OUT_PWD/../IoT/ -lIoT

INCLUDEPATH += $$PWD/../IoT/shutter
DEPENDPATH += $$PWD/../IoT/shutter

unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../IoT/libIoT.a
