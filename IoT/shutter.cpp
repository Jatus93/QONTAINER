#include "shutter.h"

std::string Shutter::lClass = "shutter";
QString Shutter::rawStates = "{\"height\" : [" + QString::number(min) + ',' + QString::number(max) + "]}";
QJsonDocument Shutter::states= QJsonDocument::fromJson(rawStates.toUtf8());

Shutter::Shutter(const std::string& fSerial, const std::string& fRoom, const std::string& fName):IoT(fSerial,fRoom,lClass,fName)
{
    status.insert("height",min);
}

Shutter::Shutter(const QJsonDocument& initializer):IoT(initializer,lClass){
    if(initializer.object().value("status").isNull()){
        status.insert("height",min);
    }else{
        setDevice(QJsonDocument(initializer.object().value("status").toObject()));
    }
}

const QJsonDocument& Shutter::getDeviceInstruction(){
    return states;
}

void Shutter::setDevice(const QJsonDocument& instruction){
    int value = instruction.object().value("power").toInt();

    if(status.find("height")==status.end()){
        status.insert("power",value);
    } else {
        *status.find("power")=value;
    }
}
