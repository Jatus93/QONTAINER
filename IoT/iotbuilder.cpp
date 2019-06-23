#include "iotbuilder.h"

std::map<std::string,IoTBuilder*>* IoTBuilder::IoTmap = nullptr;

IoTBuilder::IoTBuilder(){
    if(IoTmap == nullptr)
        IoTmap = new std::map<std::string,IoTBuilder*>;
}

IoT* IoTBuilder::getDevice(const QJsonDocument& device){
    std::string deviceClass = device.object()["class"].toString().toStdString();
    std::map<std::string,IoTBuilder*>::iterator it= IoTmap->find(deviceClass);
    if(it != (*IoTmap).end())
        return it->second->fbuild(device);
    return nullptr;
}

void IoTBuilder::addDevice(std::string dClass, IoTBuilder* builder){
    (*IoTmap)[dClass] = builder;
}

const std::list<std::string>& IoTBuilder::getKeys(){
    std::list<std::string>* list  = new std::list<std::string>();
    std::map<std::string,IoTBuilder*>::iterator it = IoTmap->begin();
    while (it != IoTmap->end()) {
       list->push_back(it->first);
       it++;
    }
    return *list;
}

void IoTBuilder::builderCleaner(){
    std::list<std::string> keys = getKeys();
    foreach (std::string key , keys) {
         delete (*IoTmap)[key];
    }
    IoTmap->clear();
    delete IoTmap;
}

IoTBuilder::~IoTBuilder(){}
