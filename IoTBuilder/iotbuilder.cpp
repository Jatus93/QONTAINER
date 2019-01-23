#include "iotbuilder.h"

QMap<std::string,IoTBuilder*>* IoTBuilder::IoTmap = nullptr;

IoTBuilder::IoTBuilder(){
    if(IoTmap == nullptr)
        IoTmap = new QMap<std::string,IoTBuilder*>;
}

IoT* IoTBuilder::build(const std::string& fSerial, const std::string& fClass, const std::string& fRoom,const std::string& fName){
    if(IoTmap->contains(fClass)){
        return IoTmap->value(fClass)->fbuild(fSerial,fRoom,fName);
    }
    throw std::invalid_argument(fClass + " couldn't be found");
}

IoT* IoTBuilder::build(const QJsonDocument& device){
    if(!device.object().value("class").isNull()){
        std::string tClass = device.object().value("class").toString().toStdString();
        if(IoTmap->contains(tClass)){
            return IoTmap->value(tClass)->fbuild(device);
        }else{
            throw std::invalid_argument(tClass + " couldn't be found");
        }
    }
    throw std::invalid_argument("Invalid Json document \"class\" field is missing");

}
IoT* IoTBuilder::getDevice(const QJsonDocument& device){
    std::string deviceClass = device.object().value("class").toString().toStdString();
    if(IoTmap->contains(deviceClass))
        return IoTmap->value(deviceClass)->build(device);
    return nullptr;
}

void IoTBuilder::addDevice(std::string dClass, IoTBuilder* builder){
    IoTmap->insert(dClass,builder);
}

const QList<std::string>& IoTBuilder::getKeys(){
    return *(new QList<std::string>(IoTmap->keys()));
}
