QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_test_container.cpp

unix:!macx: LIBS += -L$$OUT_PWD/../Container/ -lContainer

INCLUDEPATH += $$PWD/../Container
DEPENDPATH += $$PWD/../Container

unix:!macx: PRE_TARGETDEPS += $$OUT_PWD/../Container/libContainer.a
