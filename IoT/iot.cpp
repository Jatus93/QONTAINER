#include "iot.h"

IoT::IoT(const std::string& fSerial, const std::string& fClass, const std::string& fRoom, const std::string& fName):
    serial(fSerial),
    dClass(fClass),
    room(fRoom),name(fName){}

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
    else {
        return name;
    }
}

const QJsonDocument& IoT::getStatus() const{
    return (*new QJsonDocument(this->status));
}

const QJsonDocument& IoT::JsonSerialize() const{
    QJsonObject toReturn;
    toReturn.insert("serial",QString::fromStdString(serial));
    toReturn.insert("class",QString::fromStdString(dClass));
    toReturn.insert("room",QString::fromStdString(room));
    toReturn.insert("name",QString::fromStdString(getName()));
    toReturn.insert("status",status);
    return *(new QJsonDocument(toReturn));
}
