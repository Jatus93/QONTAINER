QT       -= gui
TARGET = QModel
TEMPLATE = lib
CONFIG += staticlib
HEADERS += \
    qmodel.h \
    model.h

SOURCES += \
    qmodel.cpp \
    model.cpp



unix:!macx: LIBS += -L$$OUT_PWD/../Container/ -lContainer

INCLUDEPATH += $$PWD/../Container
DEPENDPATH += $$PWD/../Container

unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../Container/libContainer.a

unix:!macx: LIBS += -L$$OUT_PWD/../IoT/ -lIoT

INCLUDEPATH += $$PWD/../IoT
DEPENDPATH += $$PWD/../IoT

unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../IoT/libIoT.a
