#ifndef IOT_H
#define IOT_H

#include <iostream>
#include <fstream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>

class IoT{

private:
    const std::string serial;
    const std::string dClass;
    std::string room;
    std::string name;

protected:
    QJsonObject status;

public:
    IoT(const std::string& fSerial, const std::string& fClass, const std::string& fRoom="",const std::string& fName="");
    IoT(const QJsonDocument& initializer, const std::string& fClass);
    void setRoom(const std::string& room);
    void setName(const std::string& name);
    const std::string& getSerial() const;
    const std::string& getClass() const;
    const std::string& getRoom() const;
    const std::string& getName() const;
    const QJsonDocument& getStatus() const;
    virtual void setDevice(const QJsonDocument& instruction) noexcept(false) = 0;
    virtual const QJsonDocument& getDeviceInstruction() const = 0;
    virtual IoT* clone() const = 0;
    const QJsonDocument& JsonSerialize() const;
    virtual ~IoT() = default;

};
#endif // IOT_H
