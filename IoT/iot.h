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
    std::string name;
    QJsonObject status;

public:
    IoT(const std::string& fSerial, const std::string& fClass, const std::string& fRoom,const std::string& fName="");
    IoT(const QJsonDocument& initializer, const std::string& fClass);
    const std::string& getSerial() const;
    const std::string& getClass() const;
    const std::string& getRoom() const;
    const std::string& getName() const;
    const QJsonDocument& getStatus() const;
    virtual void setDevice(const QJsonDocument& instruction) = 0;
    virtual ~IoT() = default;

};

#endif // IOT_H
