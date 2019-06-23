#include "iot.h"

IoT::IoT(const std::string& fSerial, const std::string& fClass, const std::string& fRoom, const std::string& fName):
    serial(fSerial),
    dClass(fClass),
    room(fRoom),name(fName){
    if(fSerial.empty() || fClass.empty())
        throw std::invalid_argument("Invalid serial or class");
}

IoT::IoT(const QJsonDocument& initializer,const std::string& fClass):
    serial(initializer.object().value("serial").toString().toStdString()),
    dClass(fClass),
    room(initializer.object().value("room").toString().toStdString()),
    name(initializer.object().value("name").toString().toStdString()){
}

void IoT::setRoom(const std::string& room){
    this->room = room;
}
void IoT::setName(const std::string& name){
    this->name = name;
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

const std::string& IoT::getName() const{
    if(name.empty())
        return serial;
    return name;
}

const QJsonDocument& IoT::getStatus() const{
    return (*new QJsonDocument(this->status));
}
bool IoT::operator==(const IoT& dev) const{
    if(dClass != dev.dClass)
        return false;
    if(serial != dev.serial)
        return false;
    if(name != dev.name)
        return false;
    if(room != dev.room)
        return false;
    return true;
}

const QJsonDocument& IoT::JsonSerialize() const{
    QJsonObject toReturn;
    toReturn["serial"] = QString::fromStdString(serial);
    toReturn["serial"] = QString::fromStdString(serial);
    toReturn["class"] = QString::fromStdString(dClass);
    toReturn["room"] = QString::fromStdString(room);
    toReturn["name"] = QString::fromStdString(getName());
    toReturn["status"] = status;
    return *(new QJsonDocument(toReturn));
}

IoT::~IoT(){}
