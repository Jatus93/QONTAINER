#include "switch.h"
std::string Switch::lClass = "switch";
QJsonObject Switch::states{{"on",1},{"off",0}};
Switch::Switch(std::string& fSerial, std::string& fRoom):IoT(fSerial,lClass,fRoom){}

const QJsonObject* Switch::getDeviceInstruction() const{
    return &states;
}
const QJsonObject *Switch::getStatus() const{
    return new QJsonObject{{"status",status}};
}

void Switch::setDevice(QJsonObject* instruction){
}
