QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_test_iot_builder.cpp

unix:!macx: LIBS += -L$$OUT_PWD/../IoTBuilder/ -lIoTBuilder

INCLUDEPATH += $$PWD/../IoTBuilder
DEPENDPATH += $$PWD/../IoTBuilder

unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../IoTBuilder/libIoTBuilder.a

unix:!macx: LIBS += -L$$OUT_PWD/../IoT/ -lIoT

INCLUDEPATH += $$PWD/../IoT
DEPENDPATH += $$PWD/../IoT

unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../IoT/libIoT.a
