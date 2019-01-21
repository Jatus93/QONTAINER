#include "switch.h"
std::string Switch::lClass = "switch";
QString Switch::rawStates = "{\"power\": {	\"min\":"+ QString::number(min) +" ,\"max\": "+ QString::number(max) +"}}}";

QJsonDocument Switch::states= QJsonDocument::fromJson(rawStates.toUtf8());

Switch::Switch(const std::string& fSerial, const std::string& fRoom, const std::string& fName):IoT(fSerial,lClass,fRoom,fName){
    status.insert("power",min);
}

Switch::Switch(const QJsonDocument& initializer):IoT(initializer,lClass){
    if(initializer.object().value("status").isNull()){
        status.insert("power",min);
    }else{
        setDevice(QJsonDocument(initializer.object().value("status").toObject()));
    }
}

void Switch::setDevice(const QJsonDocument& instruction) noexcept(false){
    int value = instruction.object().value("power").toInt(-1);

    if(value == -1)
        value = min; //reset status if field is missing

    if(value<min || value>max)
        throw std::invalid_argument("value is not valid");

    if(status.find("power")==status.end()){
        status.insert("power",value);
    } else {
        *status.find("power")=value;
    }

}

const QJsonDocument& Switch::getDeviceInstruction() const{
    return states;
}
