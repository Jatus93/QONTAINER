#ifndef IOTBUILDER_H
#define IOTBUILDER_H

#include "../IoT/iot.h"
#include <QMap>

class IoTBuilder
{
protected:
    static QMap<std::string,IoTBuilder*>* IoTmap;
    virtual IoT* fbuild(const QJsonDocument& device) const = 0;
    virtual IoT* fbuild(const std::string& fSerial, const std::string& fRoom="",const std::string& fName="") const = 0;

public:
    IoTBuilder();
    virtual ~IoTBuilder() = default;
    static IoT* getDevice(const QJsonDocument& device);
    static void addDevice(std::string dClass, IoTBuilder* builder);
    static const QList<std::string>& getKeys();
    static IoT* build(const std::string& fSerial, const std::string& fClass, const std::string& fRoom="",const std::string& fName="")noexcept(false);
    static IoT* build(const QJsonDocument& device) noexcept(false);
};

//#include "IoTBuilder.moc"
#endif // IOTBUILDER_H
