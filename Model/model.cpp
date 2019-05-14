#include "model.h"
std::string Model::default_path = "IoTManager.json";
QJsonObject Model::room;
QJsonObject Model::devices;

/**
 * @brief Model::IoTContainer::IoTContainer
 * @param dev
 */
void Model::IoTContainer::loadFromJson(const std::string& dev){
    QJsonDocument devices = QJsonDocument::fromJson(dev.c_str());
    if(devices.isNull())
        std::cout<<"file vuoto o non valido"<<'\n';
    else {
        const QJsonObject json = devices.object();
        foreach (const QString& key, json.keys()) {
            if(key == "rooms")
                room = devices.object()[key].toObject();
            else if(key == "dClasses")
                Model::devices = devices.object()[key].toObject();
            else {
                QJsonDocument* device = new QJsonDocument(json.value(key).toObject());
                this->pushBack(*IoTBuilder::build(*device));
            }
        }
    }
}
/**
 * @brief Model::IoTContainer::IoTContainer
 */
Model::IoTContainer::IoTContainer():Container<IoT>(){}
/**
 * @brief Model::IoTContainer::serialize
 * @return
 */
std::string Model::IoTContainer::serialize() const{
    std::string devices("{");
    const Iterator<IoT> it = getConstIterator();
    int i = 0;
    while(it!=nullptr){
        devices = devices + '"' + std::to_string(i++)+ '"' + ":" + (*it).JsonSerialize().toJson().toStdString();
        it++;
        if(it!=nullptr)
            devices = devices + ",";
    }
    devices = devices + "}";
    return devices;
}
/**
 * @brief Model::IoTContainer::searchName
 * @param name
 * @return
 */

Iterator<IoT> Model::IoTContainer::searchName(std::string name) const{
    Iterator<IoT> it = this->getConstIterator();
    bool exit = false;
    while(!(it==nullptr || exit)){
        exit = ((*it).getName() == name);
        if(!exit)
            it++;
    }
    return it;
}
/**
 * @brief Model::IoTContainer::searchSerial
 * @param serial
 * @return
 */
Iterator<IoT> Model::IoTContainer::searchSerial(std::string serial) const{
    Iterator<IoT> it = this->getConstIterator();
    bool exit = false;
    while(!(it==nullptr || exit)){
        exit = (*it).getSerial() == serial;
        if(!exit)
            it++;
    }
    return it;
}

/**
 * @brief Model::IoTContainer::getDevicesForAttribute
 * @param attribute
 * @return
 */
std::string Model::IoTContainer::getDevicesForAttribute(std::string attribute) const{
    QJsonDocument json = QJsonDocument::fromJson(attribute.c_str());
    QStringList keys = json.object().keys();
    std::string toReturn = "{    ";
    int i=0;
    const Iterator<IoT> it(this->getConstIterator());
    while(it!=nullptr){
        const IoT& dev = it.getData();
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

/**
 * @brief Model::Model
 * @param file_path
 */
Model::Model(const std::string& file_path){
    load(file_path);
}
/**
 * @brief Model::load
 * @param file_path
 * @return
 */
bool Model::load(const std::string &file_path){
    bool status = false;
    std::ifstream IoTfile(file_path);
    if(IoTfile.is_open()){
        std::string devices;
        std::string line;
        while (getline(IoTfile,line)) {
            devices = devices+line;
        }
        iotdev.loadFromJson(devices);
        status = true;
    }else {
        std::ofstream IoTFileTmp(file_path);
        IoTFileTmp << "{}";
        IoTFileTmp.close();
        load(file_path);
    }
    IoTfile.close();
    return status;
}
/**
 * @brief Model::save
 * @param file_path
 * @return
 */
bool Model::save(const std::string &file_path) const{
    bool status = false;
    std::ofstream IoTfile(file_path);
    if(IoTfile.is_open()){
        IoTfile<<iotdev.serialize();
        status = true;
    }else {
        throw std::runtime_error("could not open file path");
    }
    IoTfile.close();
    return status;
}
/**
 * @brief Model::addDevice
 * @param json_device
 * @return
 */

bool Model::addDevice(const std::string &json_device){
    QJsonDocument device = QJsonDocument::fromJson(json_device.c_str());
    Iterator<IoT> dev = iotdev.searchSerial(device.object()["serial"].toString().toStdString());
    if(dev != nullptr)
        iotdev.deleteElementAt(dev);
    try {
        iotdev.pushBack(*IoTBuilder::getDevice(device));
    } catch (std::runtime_error* e) {
        std::cout<<e->what()<<'\n';
        return false;
    }
    return true;
}
/**
 * @brief Model::setDeviceStatus
 * @param status
 * @return
 */

bool Model::setDeviceStatus(const std::string &status){
    bool ok = false;
    QJsonDocument j_status = QJsonDocument::fromJson(status.c_str());
    std::string serial = j_status.object()["serial"].toString().toStdString();
    QJsonDocument command(j_status.object()["status"].toObject());
    const Iterator<IoT> it = iotdev.searchSerial(serial);
    const IoT* const_ptr = &(*it);
    IoT* ptr = const_cast<IoT*>(const_ptr);
    try {
        ptr->setDevice(command);
        std::string after = ptr->getStatus().toJson().toStdString();
        ok = command.toJson().toStdString() == after;
    } catch (std::runtime_error* e) {
        std::cout<<e->what()<<'\n';
        ok = false;
    }
    return ok;
}
/**
 * @brief Model::removeDevice
 * @param json_device
 * @return
 */
bool Model::removeDevice(const std::string &json_device){
    QJsonDocument device = QJsonDocument::fromJson(json_device.c_str());
    const Iterator<IoT> it = iotdev.searchSerial(device.object()["serial"].toString().toStdString());
    try{
        iotdev.deleteElementAt(it);
    }catch(std::runtime_error* e){
        std::cout<<e->what()<<'\n';
        return false;
    }
    return true;
}

/**
 * @brief Model::getDeviceStatus
 * @param index
 * @return
 */
const std::string Model::getDeviceStatus(const int index) const{
    const IoT& device = (iotdev[index]);
    return device.getStatus().toJson().toStdString();
}

const std::string Model::getDeviceFiltered(const std::string values) const{
    return (iotdev.getDevicesForAttribute(values));
}

const std::string Model::getAllDevicesClass() const{
    return QJsonDocument(devices).toJson().toStdString();
}

const std::string Model::getAllRooms() const{
    return QJsonDocument(room).toJson().toStdString();
}

bool Model::addRoom(std::string & room){
    //room_serialized
    return false;
}

Model::~Model(){
    IoTBuilder::builderCleaner();
}
