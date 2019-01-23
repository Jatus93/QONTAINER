#ifndef IOTFACTORYDEVICE_H
#define IOTFACTORYDEVICE_H
#include <iotbuilder.h>
#include <typeinfo>

template<class T> class IoTFactoryDevice : public IoTBuilder{
protected:
    IoT* fbuild(const QJsonDocument& device) const{
        return new T(device);
    }
    IoT* fbuild(const std::string& fSerial, const std::string& fRoom="",const std::string& fName="") const{
        return new T(fSerial,fRoom,fName);
    }
public:
    IoTFactoryDevice(const std::string& name):IoTBuilder(){
        IoTBuilder::addDevice(name,this);
    }
};
#endif // IOTFACTORYDEVICE_H
