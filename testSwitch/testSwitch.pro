QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_test_switch.cpp

unix:!macx: LIBS += -L$$OUT_PWD/../IoT/ -lIoT

INCLUDEPATH += $$PWD/../IoT \
                $$PWD/../IoT/switch
DEPENDPATH += $$PWD/../IoT \
            $$PWD/../IoT/switch

unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../IoT/libIoT.a