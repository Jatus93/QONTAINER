#ifndef IOT_H
#define IOT_H
#include <iostream>
#include <QJsonDocument>
#include <QJsonObject>
class IoT{
protected:
    std::string serial;
    std::string dClass;
    std::string room;

public:
    IoT(const std::string& fSerial, const std::string& fClass, const std::string& fRoom);
    IoT(const QJsonDocument& initializer, const std::string& fClass);
    const std::string& getSerial() const;
    const std::string& getClass() const;
    const std::string& getRoom() const;
    virtual const QJsonDocument& getDeviceInstruction() const = 0;
    virtual const QJsonDocument& getStatus() const = 0;
    virtual void setDevice(const QJsonDocument& instruction) = 0;
    virtual ~IoT() = default;

};

#endif // IOT_H
