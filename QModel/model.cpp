#include "model.h"
std::string Model::currentFilePath = "";
Container<std::string> Model::rooms;
Container<std::string> Model::devices;

void Model::IoTContainer::loadFromJson(const std::string& dev){
    QJsonDocument devices = QJsonDocument::fromJson(dev.c_str());
    if(devices.isNull())
        std::cout<<"file vuoto o non valido"<<'\n';
    else {
        const QJsonObject json = devices.object();
        foreach (const QString& key, json.keys()) {
            QJsonDocument* device = new QJsonDocument(json.value(key).toObject());
            std::string room = device->object().value("room").toString().toStdString();
            IoT * rDevice = IoTBuilder::getDevice(*device);
            if(rDevice != nullptr)
                this->pushBack(rDevice);
            addRoom(room);
        }
    }
}

Model::IoTContainer::IoTContainer():Container<IoT*>(){}

std::string Model::IoTContainer::serialize() const{
    std::string devices("{");
    const Iterator it = getConstIterator();
    int i = 0;
    while(it!=nullptr){
        devices = devices + '"' + std::to_string(i++)+ '"' + ":" + (*it)->JsonSerialize().toJson().toStdString();
        it++;
        if(it!=nullptr)
            devices = devices + ",";
    }
    devices = devices + "}";
    return devices;
}

Container<IoT*>::Iterator Model::IoTContainer::searchName(std::string name) const{
    Container<IoT*>::Iterator it = this->getConstIterator();
    bool exit = false;
    while(!(it==nullptr || exit)){
        exit = ((*it)->getName() == name);
        if(!exit)
            it++;
    }
    return it;
}

Container<IoT*>::Iterator Model::IoTContainer::searchSerial(std::string serial) const{
    Container<IoT*>::Iterator it = this->getConstIterator();
    bool exit = false;
    while(!(it==nullptr || exit)){
        exit = (*it)->getSerial() == serial;
        if(!exit)
            it++;
    }
    return it;
}

std::string Model::IoTContainer::getDevicesForAttribute(std::string attribute) const{
    if(attribute == "")
        return serialize();
    QJsonDocument json = QJsonDocument::fromJson(attribute.c_str());
    QStringList keys = json.object().keys();
    std::string toReturn = "{    ";
    int i=0;
    const Container<IoT*>::Iterator it(this->getConstIterator());
    while(it!=nullptr){
        const IoT& dev = *(it.getData());
        it++;
        QJsonObject IoTStatus = dev.JsonSerialize().object();
        foreach(const QString& key, IoTStatus.keys()){
            if(!keys.contains(key)){
                IoTStatus.remove(key);
            }
        }
        if(json == QJsonDocument(IoTStatus)){
            toReturn += std::to_string(i++) +":";
            toReturn= toReturn+ dev.JsonSerialize().toJson().toStdString();
            if(it != nullptr)
                toReturn = toReturn + ',';
        }
    }
    //toReturn = getAllRooms()
    toReturn = toReturn + '}';

    return toReturn;
}

void Model::fillDeviceContainer(){
    std::list<std::string> keys = IoTBuilder::getKeys();
    foreach(std::string key,keys){
        devices.pushBack(key);
    }
}

Model::Model(const std::string& filePath){
    if(filePath!=currentFilePath)
        currentFilePath = filePath;
    load();
    if(devices.size() == 0){
        fillDeviceContainer();
    }
}

bool Model::load(const std::string &filePath){
    bool status = false;
    if(filePath != ""){
        if(filePath!=currentFilePath)
            currentFilePath = filePath;
        if(iotdev.size()>0)
        {
            Container<IoT*>::Iterator it = iotdev.getIterator();
            while(it != nullptr){
                delete *it;
                iotdev.deleteElementAt(it);
            }

        }
        int i =0 ;
        while(rooms.size()>0){
            rooms.deleteElementAt(i);
        }
        std::ifstream IoTfile(filePath);
        if(IoTfile.is_open()){
            std::string devices;
            std::string line;
            while (getline(IoTfile,line)) {
                devices = devices+line;
            }
            iotdev.loadFromJson(devices);
            status = true;
        }else {
            std::ofstream IoTFileTmp(filePath);
            IoTFileTmp << "{}";
            IoTFileTmp.close();
            load(filePath);
        }
        IoTfile.close();
    }
    return status;
}

bool Model::save(const std::string &filePath) const{
    bool status = false;
    if(filePath!=""){
        if(filePath!=currentFilePath)
            currentFilePath = filePath;
        std::ofstream IoTfile(filePath);
        if(IoTfile.is_open()){
            IoTfile<<getSerializzation();
            status = true;
        }else {
            throw std::runtime_error("could not open file path");
        }
        IoTfile.close();
    }
    return status;
}

bool Model::addDevice(const std::string &json_device){
    QJsonDocument device = QJsonDocument::fromJson(json_device.c_str());
    Container<IoT*>::Iterator dev = iotdev.searchSerial(device.object()["serial"].toString().toStdString());
    if(dev != nullptr)
        return false;
    try {
        IoT* rDevice = IoTBuilder::getDevice(device);
        iotdev.pushFront(rDevice);
        std::string room = rDevice->getRoom();
        addRoom(room);
    } catch (std::runtime_error* e) {
        std::cout<<e->what()<<'\n';
        return false;
    }
    return true;
}

bool Model::setDeviceStatus(const std::string &status){
    bool ok = false;
    QJsonDocument jStatus = QJsonDocument::fromJson(status.c_str());
    std::string serial = jStatus.object()["serial"].toString().toStdString();
    QJsonDocument command(jStatus.object()["status"].toObject());
    const Container<IoT*>::Iterator it = iotdev.searchSerial(serial);
    const IoT* const_ptr = (*it);
    IoT* ptr = const_cast<IoT*>(const_ptr);
    try {
        ptr->setName(jStatus.object()["name"].toString().toStdString());
        ptr->setRoom(jStatus.object()["room"].toString().toStdString());
        addRoom(jStatus.object()["room"].toString().toStdString());
        ptr->setDevice(command);
        std::string after = ptr->getStatus().toJson().toStdString();
        ok = command.toJson().toStdString() == after;
    } catch (std::runtime_error* e) {
        std::cout<<e->what()<<'\n';
        ok = false;
    }
    return ok;
}

bool Model::setDeviceStatus(const std::string& status, int index){
    bool result = false;
    IoT* device = nullptr;
    try {
        device = iotdev[index];
    } catch (std::out_of_range& e) {
        if(strcmp(e.what(), "Index is out of range")){
            result = addDevice(status);
            return result;
        }
    }
    QJsonObject jDevice(QJsonDocument::fromJson(status.c_str()).object());
    try {
        device->setName(jDevice["name"].toString().toStdString());
        device->setRoom(jDevice["room"].toString().toStdString());
        device->setDevice(QJsonDocument(jDevice["status"].toObject()));
    } catch (const std::invalid_argument & e) {
        Q_UNUSED(e)
        result = false;
    }

    return  result;
}

bool Model::removeDevice(const std::string &json_device){
    QJsonDocument device = QJsonDocument::fromJson(json_device.c_str());
    const Container<IoT*>::Iterator it = iotdev.searchSerial(device.object()["serial"].toString().toStdString());
    try{
        delete *it;
        iotdev.deleteElementAt(it);
    }catch(std::runtime_error* e){
        std::cout<<e->what()<<'\n';
        return false;
    }
    return true;
}

const std::string Model::getSerializzation() const{
    return this->iotdev.serialize();
}

const std::string Model::getDeviceStatus(const int index) const{
    const IoT* device = (iotdev[index]);
    return device->getStatus().toJson().toStdString();
}

const std::string Model::getDeviceFiltered(const std::string values) const{
    return (iotdev.getDevicesForAttribute(values));
}

const std::string Model::getAllDevicesClass() const {
    Container<std::string>::Iterator it = devices.getConstIterator();
    std::string toReturn = "{\"devices\":[";
    while(it!=nullptr){
        toReturn += "\""+it.getData()+"\"";
        it++;
        if(it!=nullptr)
            toReturn += ",";
    }
    toReturn += "]}";
    return toReturn;
}

const std::string Model::getAllRooms() const {
    Container<std::string>::Iterator it = rooms.getConstIterator();
    std::string toReturn = "{\"rooms\":[";
    while(it!=nullptr){
        toReturn += "\""+it.getData()+"\"";
        it++;
        if(it!=nullptr)
            toReturn += ",";
    }
    toReturn += "]}";
    return toReturn;
}

void Model::addRoom(const std::string& room){
    const Container<std::string>::Iterator it(rooms.search(room));
    if(it == nullptr)
        rooms.pushBack(room);
}

void Model::delRoom(const std::string& room){
    const Container<std::string>::Iterator it(rooms.search(room));
    if(it != nullptr)
        rooms.deleteElementAt(it);
}

int Model::size() const{
    return iotdev.size();
}
IoT* Model::getElementAt(int i) const{
    return iotdev[i]->clone();
}
Model::~Model(){
    IoTBuilder::builderCleaner();
    Container<IoT*>::Iterator it = iotdev.getIterator();
    while(it!=nullptr){
        delete *it;
        it++;
    }
}
