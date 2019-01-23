#ifndef DIMMERABLELIGHT_H
#define DIMMERABLELIGHT_H

#include "../iot.h"

class DimmerableLight: public IoT
{
private:
    static const std::string lClass;
    static const QJsonDocument states;
    static constexpr int minBrightness = 0;
    static constexpr int maxBrightness = 100;
    static constexpr int on = 1;
    static constexpr int off = 0;
public:
    DimmerableLight(const std::string& fSerial, const std::string& fRoom="", const std::string& fName="");
    DimmerableLight(const QJsonDocument& initializer);
    const QJsonDocument& getDeviceInstruction() const;
    void setDevice(const QJsonDocument& instruction) noexcept(false);
    IoT* clone() const;
    static const std::string getClass();
};
#endif // DIMMERABLELIGHT_H
