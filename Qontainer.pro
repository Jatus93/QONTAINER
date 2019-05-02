TEMPLATE = subdirs

SUBDIRS += \
    IoT \
    testSwitch \
    testShutter \
    testLight \
    IoTBuilder \
    testIoTBuilder \
    Container \
    testContainer \
    Model \
    testModel

DISTFILES += \
    .travis.yml

unix:!macx: LIBS += -L$$OUT_PWD/IoT/ -lIoT

INCLUDEPATH += $$PWD/IoT
DEPENDPATH += $$PWD/IoT

unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/IoT/libIoT.a
