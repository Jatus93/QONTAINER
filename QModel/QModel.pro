QT       -= gui
TARGET = QModel
TEMPLATE = lib
HEADERS += \
    qmodel.h

SOURCES += \
    qmodel.cpp

unix:!macx: LIBS += -L$$OUT_PWD/../Model/ -lModel

INCLUDEPATH += $$PWD/../Model
DEPENDPATH += $$PWD/../Model

unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../Model/libModel.a

unix:!macx: LIBS += -L$$OUT_PWD/../IoTBuilder/ -lIoTBuilder

INCLUDEPATH += $$PWD/../IoTBuilder
DEPENDPATH += $$PWD/../IoTBuilder

unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../IoTBuilder/libIoTBuilder.a

unix:!macx: LIBS += -L$$OUT_PWD/../IoT/ -lIoT

INCLUDEPATH += $$PWD/../IoT
DEPENDPATH += $$PWD/../IoT

unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../IoT/libIoT.a
