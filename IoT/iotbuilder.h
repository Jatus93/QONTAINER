#ifndef IOTBUILDER_H
#define IOTBUILDER_H

#include "./iot.h"
#include <QMap>

class IoTBuilder
{
protected:
    static std::map<std::string,IoTBuilder*>* IoTmap;
    static void addDevice(std::string dClass, IoTBuilder* builder);
    virtual IoT* fbuild(const QJsonDocument& device) const = 0;
    virtual IoT* fbuild(const std::string& fSerial, const std::string& fRoom="",const std::string& fName="") const = 0;

public:
    IoTBuilder();
    virtual ~IoTBuilder() = default;
    static void builderCleaner();
    static IoT* getDevice(const QJsonDocument& device);
    static const std::list<std::string>& getKeys();
    static IoT* build(const std::string& fSerial, const std::string& fClass, const std::string& fRoom="",const std::string& fName="");
    static IoT* build(const QJsonDocument& device) ;
};

//#include "IoTBuilder.moc"
#endif // IOTBUILDER_H
