#include "iot.h"

IoT::IoT(const std::string& fSerial, const std::string& fClass, const std::string& fRoom):
    serial(fSerial),
    dClass(fClass),
    room(fRoom){}

IoT::IoT(const QJsonDocument& initializer,const std::string& fClass):
    serial(initializer.object().value("serial").toString().toStdString()),
    dClass(fClass),
    room(initializer.object().value("room").toString().toStdString()){
}

const std::string& IoT::getSerial() const{
    return serial;
}

const std::string& IoT::getClass() const{
    return dClass;
}

const std::string& IoT::getRoom() const{
    return room;
}
