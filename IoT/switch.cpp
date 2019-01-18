#include "switch.h"
std::string Switch::lClass = "switch";
std::string Switch::rawStates = "{\"power\" : [\"on\",\"off\"]}";
int Switch::size = static_cast<int>(strlen(rawStates.c_str()));
QJsonDocument Switch::states= QJsonDocument::fromRawData(rawStates.c_str(),size,QJsonDocument::Validate);

Switch::Switch(std::string& fSerial, std::string& fRoom):IoT(fSerial,lClass,fRoom){
    status.insert("power","off");
    std::cout<<states.rawData(&size)<<'\n';
}

Switch::Switch(const QJsonDocument& initializer):IoT(initializer,lClass){

}

const QJsonDocument& Switch::getDeviceInstruction() const{
    return states;
}

const QJsonDocument& Switch::getStatus() const{
    return (*new QJsonDocument(this->status));
}

void Switch::setDevice(const QJsonDocument& instruction){
    QJsonValue value = instruction.object().value("power");
    if(status.value("power").isNull())
        status.insert("power",value);
    else {
        *status.find("power")=value;
    }

}
