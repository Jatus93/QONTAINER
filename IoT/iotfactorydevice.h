/**
  * @file IoTFactoryDevice.h
  * @class IoTFactoryDevice
  * @extends IoTBuilder
  * @brief IoTBuilder implementation as template
  * @package IoT
  * @author Gianmarco Pettinato
  */
#ifndef IOTFACTORYDEVICE_H
#define IOTFACTORYDEVICE_H
#include "iotbuilder.h"

template<class T> class IoTFactoryDevice : public IoTBuilder{
protected:
    /**
     * @brief fbuild
     * @param device
     * @return
     */
    IoT* fbuild(const QJsonDocument& device) const{
        return new T(device);
    }
    /**
     * @brief fbuild
     * @param fSerial
     * @param fRoom
     * @param fName
     * @return
     */
    IoT* fbuild(const std::string& fSerial, const std::string& fRoom="",const std::string& fName="") const{
        return new T(fSerial,fRoom,fName);
    }
public:
    /**
     * @brief IoTFactoryDevice
     * @param name
     */
    IoTFactoryDevice(const std::string& name):IoTBuilder(){
        IoTBuilder::addDevice(name,this);
    }
    ~IoTFactoryDevice() = default;
};
#endif // IOTFACTORYDEVICE_H
