#include "dimmerablelight.h"
const std::string DimmerableLight::lClass = "dimmerableLight";
const QJsonDocument DimmerableLight::states= QJsonDocument::fromJson("{\"power\":{\"min\":"+QString::number(off).toUtf8()+",\"max\":"+ QString::number(on).toUtf8()+"},\"brightness\":{\"min\":"+ QString::number(minBrightness).toUtf8()+",\"max\":"+QString::number(maxBrightness).toUtf8()+"}}");

DimmerableLight::DimmerableLight(const std::string& fSerial, const std::string& fRoom, const std::string& fName):IoT(fSerial,lClass,fRoom,fName)
{
    status.insert("power",off);
    status.insert("brightness",minBrightness);
}
DimmerableLight::DimmerableLight(const QJsonDocument& initializer):IoT(initializer,lClass){
    if(initializer.object().value("status").isNull()){
        status.insert("power",off);
        status.insert("brightness",minBrightness);
    }else{
        setDevice(QJsonDocument(initializer.object().value("status").toObject()));
    }
}

const QJsonDocument& DimmerableLight::getDeviceInstruction() const{
    return states;
}

void DimmerableLight::setDevice(const QJsonDocument& instruction) {
    QJsonObject data(instruction.object());
    if(!data.isEmpty()){
        //power control
        if(data["power"].toInt() == off || data["power"].toInt() == on)
            status["power"] = data["power"];
        else
            throw std::invalid_argument("power value is invalid");
        //brightness control
        if(data["brightness"].toInt()>=minBrightness && data["brightness"].toInt()<=maxBrightness )
            status["brightness"] = data["brightness"];
        else
            throw std::invalid_argument("brightness value is invalid");
    }
    if(status["brightness"].toInt()==0)
        status["power"] = 0;
}

bool DimmerableLight::operator==(const IoT& dev) const{
    if(IoT::operator==(dev)){
        QJsonObject dStatus(dev.getStatus().object());
        return (status["power"].toInt() == dStatus["power"].toInt(-1)) && (status["brightness"].toInt() == dStatus["brightness"].toInt(-1));
    }
    return false;
}

IoT* DimmerableLight::clone() const{
    return new DimmerableLight(JsonSerialize());
}
