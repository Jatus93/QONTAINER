#ifndef MODEL_H
#define MODEL_H
#include "../IoT/iot.h"
#include <container.h>
#include <iostream>
#include <fstream>
#include <iotdevices.h>

class Model
{
private:
    class IoTContainer : public Container<IoT>{
    public:
        //IoTContainer(const std::string& dev);
        void loadFromJson(const std::string& dev);
        IoTContainer();
        std::string serialize() const;
        Iterator<IoT> searchName(std::string name) const;
        Iterator<IoT> searchSerial(std::string serial) const;
    };
    IoTContainer iotdev;
    static std::string default_path;
public:
    Model(const std::string& file_path=default_path);
    bool load(const std::string& file_path=default_path) ;
    bool save(const std::string& file_path=default_path) const;
    bool addDevice(const std::string& json_device);
    bool removeDevice(const std::string& json_device);
    bool setDeviceStatus(const std::string& status);
    const std::string getDeviceStatus(const int index) const;
};

#endif // MODEL_H
