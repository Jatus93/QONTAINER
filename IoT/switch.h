#ifndef SWITCH_H
#define SWITCH_H
#include "iot.h"

class Switch : public IoT
{
    static QJsonObject states;
    static std::string lClass;
    int status; // can be on or off
public:
    Switch(std::string& fSerial, std::string& fRoom);
    const QJsonObject* getDeviceInstruction() const;
    const QJsonObject* getStatus() const;
    void setDevice(QJsonObject* instruction);
};

#endif // SWITCH_H
