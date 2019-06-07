TEMPLATE = subdirs

SUBDIRS += \
    IoT \
    QModel \
    UI \
    IoTBuilder \
    Container \
    Model

DISTFILES += \
    .travis.yml

unix:!macx: LIBS += -L$$OUT_PWD/IoT/ -lIoT

INCLUDEPATH += $$PWD/IoT
DEPENDPATH += $$PWD/IoT

unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/IoT/libIoT.a
