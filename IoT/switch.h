#ifndef SWITCH_H
#define SWITCH_H
#include "iot.h"
#include <QJsonObject>
#include <QJsonArray>

class Switch : public IoT
{
    static QJsonDocument states;
    static std::string lClass;
    static std::string rawStates;
    static int size;
    QJsonObject status; // power,on or power,off
public:
    Switch(std::string& fSerial, std::string& fRoom);
    Switch(const QJsonDocument& initializer);
    const QJsonDocument& getDeviceInstruction() const;
    const QJsonDocument& getStatus() const;
    void setDevice(const QJsonDocument& instruction);
};

#endif // SWITCH_H
