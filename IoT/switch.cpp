#include "switch.h"
std::string Switch::lClass = "switch";
QString Switch::rawStates = "{\"power\" : [" + QString::number(min) + ',' + QString::number(max) + "]}";

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

void Switch::setDevice(const QJsonDocument& instruction){
    int value = instruction.object().value("power").toInt();
    if(status.find("power")==status.end()){
        status.insert("power",value);
    } else {
        *status.find("power")=value;
    }

}

const QJsonDocument& Switch::getDeviceInstruction(){
    return states;
}
