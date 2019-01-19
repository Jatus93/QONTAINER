#ifndef SWITCH_H
#define SWITCH_H
#include "iot.h"
#include <QJsonObject>
#include <QJsonArray>

class Switch : public IoT
{
private:
    static std::string lClass;
    static QString rawStates;
    static QJsonDocument states;
    static constexpr int min = 0;
    static constexpr int max = 1;

public:
    Switch(const std::string& fSerial, const std::string& fRoom, const std::string& fName="");
    Switch(const QJsonDocument& initializer);
    static const QJsonDocument& getDeviceInstruction();
    void setDevice(const QJsonDocument& instruction);
};

#endif // SWITCH_H
