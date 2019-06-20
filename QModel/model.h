#ifndef MODEL_H
#define MODEL_H
#include "../IoT/iot.h"
#include <../Container/container.h>
#include <iostream>
#include <fstream>
#include <QResource>
#include "../IoT/iotbuilder.h"
#include "../IoT/iotdevices.h"

class Model
{
protected:
    class IoTContainer : public Container<IoT*>{
    public:
        IoTContainer();
        void loadFromJson(const std::string& dev);
        std::string serialize() const;
        Iterator searchName(std::string name) const;
        Iterator searchSerial(std::string serial) const;
        std::string getDevicesForAttribute(std::string attribute) const;
    };
    IoTContainer iotdev;
    static Container<std::string> rooms;
    static Container<std::string> devices;
    static std::string current_file_path;
    void fillDeviceContainer();
public:
    Model(const std::string& file_path=current_file_path);
    bool load(const std::string& file_path=current_file_path) ;
    bool save(const std::string& file_path=current_file_path) const;
    bool addDevice(const std::string& json_device);
    bool removeDevice(const std::string& json_device);
    bool setDeviceStatus(const std::string& status);
    bool setDeviceStatus(const std::string& status, int index);
    const std::string getSerializzation() const;
    const std::string getDeviceStatus(const int index) const;
    const std::string getDeviceFiltered(const std::string values = "") const;
    const std::string getAllDevicesClass() const;
    const std::string getAllRooms() const;
    static void addRoom(const std::string& room);
    void delRoom(const std::string& room);
    int size() const;
    IoT* getElementAt(int index) const;
    ~Model();
};

#endif // MODEL_H
