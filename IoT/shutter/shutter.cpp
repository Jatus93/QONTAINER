#include "shutter.h"
#include <QTextStream>
#include <QDir>

std::string Shutter::lClass = "shutter";
QJsonDocument Shutter::states = QJsonDocument::fromBinaryData(QFile("config.json").readAll());
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
    std::cout<< QDir::currentPath().toStdString()<<'\n';
    return states;
}

void Shutter::setDevice(const QJsonDocument& instruction) noexcept(false){
    int value = instruction.object().value("height").toInt(-1);

    if(value == -1)
        throw std::invalid_argument("field power is missing");

    if(value<min || value>max)
        throw std::invalid_argument("value is not valid");

    if(status.find("height")==status.end()){
        status.insert("height",value);
    } else {
        *status.find("height")=value;
    }
}
