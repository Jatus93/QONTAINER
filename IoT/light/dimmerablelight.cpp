#include "dimmerablelight.h"
const std::string DimmerableLight::lClass = "dimmerableLight";
const QJsonDocument DimmerableLight::states= QJsonDocument::fromJson("{\"power\": {	\"min\":"+ QString::number(off).toUtf8() +" ,\"max\": "+ QString::number(on).toUtf8() +"},\"brightness\": {	\"min\":"+ QString::number(minBrightness).toUtf8() +" ,\"max\": "+ QString::number(maxBrightness).toUtf8() +"}}");

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
    QJsonObject local(states.object());
    if(!data.isEmpty()){
        QStringList eKeys = data.keys();
        QStringList iKeys = local.keys();
        QString key;
        foreach (key, eKeys) {
            if(iKeys.contains(key)){
                //status[key] = instruction.object()[key];
                if(data[key].toInt()>=local[key].toObject()["min"].toInt() && data[key].toInt()<=local[key].toObject()["max"].toInt())
                    status[key] = instruction.object()[key];
                else {
                    throw std::invalid_argument(key.toStdString()+" field value is not valid");
                }
            }

        }
    }
    if(status["brightness"].toInt()<=0)
        status["power"] = 0;
}

IoT* DimmerableLight::clone() const{
    return new DimmerableLight(JsonSerialize());
}


const std::string DimmerableLight::getClass(){
    return lClass;
}
