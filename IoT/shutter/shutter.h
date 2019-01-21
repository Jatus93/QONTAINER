#ifndef SHUTTER_H
#define SHUTTER_H
#include "../iot.h"

class Shutter : public IoT
{
private:
    static std::string lClass;
    static QString rawStates;
    static QJsonDocument states;
    static constexpr int min = 0;
    static constexpr int max = 100;

public:
    Shutter(const std::string& fSerial, const std::string& fRoom, const std::string& fName="");
    Shutter(const QJsonDocument& initializer);
    const QJsonDocument& getDeviceInstruction() const;
    void setDevice(const QJsonDocument& instruction) noexcept(false);
};

#endif // SHUTTER_H
