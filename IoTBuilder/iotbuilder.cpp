#include "iotbuilder.h"

std::map<std::string,IoTBuilder*>* IoTBuilder::IoTmap = nullptr;
/**
 * @brief IoTBuilder::IoTBuilder
 */
IoTBuilder::IoTBuilder(){
    if(IoTmap == nullptr)
        IoTmap = new std::map<std::string,IoTBuilder*>;
}
/**
 * @brief IoTBuilder::build
 * @param fSerial
 * @param fClass
 * @param fRoom
 * @param fName
 * @return
 */
IoT* IoTBuilder::build(const std::string& fSerial, const std::string& fClass, const std::string& fRoom,const std::string& fName){
    std::map<std::string,IoTBuilder*>::iterator it= IoTmap->find(fClass);
    if(it != (*IoTmap).end()){
        return it->second->fbuild(fSerial,fRoom,fName);
    }
    throw std::invalid_argument(fClass + " couldn't be found");
}
/**
 * @brief IoTBuilder::build
 * @param device
 * @return
 */
IoT* IoTBuilder::build(const QJsonDocument& device){
    std::string check = device.toJson().toStdString();
    std::string tClass = device.object()["class"].toString("empty").toStdString();
    if( tClass != "empty"){//!device.object().value("class").isNull()){
        std::map<std::string,IoTBuilder*>::iterator it= IoTmap->find(tClass);
        if(it != (*IoTmap).end())
            return it->second->fbuild(device);
        throw std::invalid_argument(tClass + " couldn't be found");
    }
    throw std::invalid_argument("Invalid Json document \"class\" field is missing");

}
/**
 * @brief IoTBuilder::getDevice
 * @param device
 * @return
 */
IoT* IoTBuilder::getDevice(const QJsonDocument& device){
    std::string deviceClass = device.object()["class"].toString().toStdString();
    std::map<std::string,IoTBuilder*>::iterator it= IoTmap->find(deviceClass);
    if(it != (*IoTmap).end())
        return it->second->build(device);
    return nullptr;
}
/**
 * @brief IoTBuilder::addDevice
 * @param dClass
 * @param builder
 */
void IoTBuilder::addDevice(std::string dClass, IoTBuilder* builder){
    (*IoTmap)[dClass] = builder;
}
/**
 * @brief IoTBuilder::getKeys
 * @return
 */
const std::list<std::string>& IoTBuilder::getKeys(){
    std::list<std::string>* list  = new std::list<std::string>();
    std::map<std::string,IoTBuilder*>::iterator it = IoTmap->begin();
    while (it != IoTmap->end()) {
       list->push_back(it->first);
       it++;
    }
    return *list;
}
/**
 * @brief IoTBuilder::builderCleaner
 */
void IoTBuilder::builderCleaner(){
    std::list<std::string> keys = getKeys();
    foreach (std::string key , keys) {
         delete (*IoTmap)[key];
    }
    IoTmap->clear();
    delete IoTmap;
}
