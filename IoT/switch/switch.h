#ifndef SWITCH_H
#define SWITCH_H
#include "../iot.h"

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
    const QJsonDocument& getDeviceInstruction() const;
    void setDevice(const QJsonDocument& instruction) noexcept(false);
};

#endif // SWITCH_H
