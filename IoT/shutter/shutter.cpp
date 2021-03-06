#include "shutter.h"

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

void Shutter::setDevice(const QJsonDocument& instruction) {
    QString instr = instruction.toJson();
    int value = instruction.object()["height"].toInt(0);

    if(value<min || value>max)
        throw std::invalid_argument("value is not valid");

    if(status.find("height")==status.end()){
        status.insert("height",value);
    } else {
        *status.find("height")=value;
    }
}
bool Shutter::operator==(const IoT& dev) const{
    if(IoT::operator==(dev)){
        QJsonObject dStatus(dev.getStatus().object());
        return status["height"].toInt() == dStatus["height"].toInt(-1);
    }
    return false;
}

IoT* Shutter::clone() const{
    return new Shutter(JsonSerialize());
}
