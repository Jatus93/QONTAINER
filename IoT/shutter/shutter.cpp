#include "shutter.h"
#include <QTextStream>
#include <QDir>

std::string Shutter::lClass = "shutter";
QJsonDocument Shutter::states = QJsonDocument::fromJson("{\"height\":{\"min\":"+QString::number(min).toUtf8()+",\"max\":"+QString::number(max).toUtf8()+"}}");
Shutter::Shutter(const std::string& fSerial, const std::string& fRoom, const std::string& fName):IoT(fSerial,lClass,fRoom,fName)
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

const QJsonDocument& Shutter::getDeviceInstruction() const{
    return states;
}

void Shutter::setDevice(const QJsonDocument& instruction) noexcept(false){
    int value = instruction.object().value("height").toInt();

    if(value<min || value>max)
        throw std::invalid_argument("value is not valid");

    if(status.find("height")==status.end()){
        status.insert("height",value);
    } else {
        *status.find("height")=value;
    }
}

IoT* Shutter::clone() const{
    return new Shutter(JsonSerialize());
}

const std::string Shutter::getClass(){
    return lClass;
}
