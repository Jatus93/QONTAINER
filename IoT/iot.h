#ifndef IOT_H
#define IOT_H
#include <iostream>
#include <QJsonObject>
class IoT{
protected:
    std::string serial;
    std::string dClass;
    std::string room;

public:
    IoT(std::string& fSerial,std::string& fClass,std::string& fRoom);
    const std::string& getSerial() const;
    const std::string& getClass() const;
    const std::string& getRoom() const;
    virtual const QJsonObject* getDeviceInstruction() const = 0;
    virtual const QJsonObject* getStatus() const = 0;
    virtual void setDevice(QJsonObject* instruction) = 0;
    virtual ~IoT() = default;

};

#endif // IOT_H
