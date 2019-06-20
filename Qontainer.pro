TARGET = Qontainer
TEMPLATE = subdirs
CONFIG += c++11

SUBDIRS += \
    IoT \
    QModel \
    UI \
    Container \

DISTFILES += \
    .travis.yml
