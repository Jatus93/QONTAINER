/**
  * @file dimmerablelight.h
  * @class DimmerableLight
  * @extends IoT
  * @brief specific IoT implementation for DimmerableLight devices
  * @package IoT
  * @author Gianmarco Pettinato
  */
#ifndef DIMMERABLELIGHT_H
#define DIMMERABLELIGHT_H

#include "../iot.h"

class DimmerableLight: public IoT
{
private:
    static const std::string lClass; /**< Contains the IoT class definition */
    static const QJsonDocument states; /**< Contains the IoT instruction definition */
    static constexpr int minBrightness = 0; /**< min value of the device brightness*/
    static constexpr int maxBrightness = 100; /**< max value of the device brightness*/
    static constexpr int on = 1; /**< on value of the device */
    static constexpr int off = 0; /**< off value of the device */
public:
    /**
     *
     * Base constructor only serial is needed recalls IoT base constructor with fClass = lClass
     *
     * @brief DimmerableLight
     * @param fSerial
     * @param fRoom
     * @param fName
     */
    DimmerableLight(const std::string& fSerial, const std::string& fRoom="", const std::string& fName="");
    /**
     *
     * Works like the other constructor saving all the data inside a QJsonDocument
     * recalls IoT base constructor with fClass = lClass
     *
     * @brief DimmerableLight
     * @param initializer
     */
    DimmerableLight(const QJsonDocument& initializer);
    /**
     *
     * specific DimmerableLight implementation of the virtual method IoT::instruction
     * depends on the type of the IoT device
     *
     * @brief getDeviceInstruction
     * @return const QJsonDocument& that contains the device instruction
     */
    const QJsonDocument& getDeviceInstruction() const override;
    /**
     *
     * specific switch implementation of the virtual method IoT::operator==()
     * depends on the type of the IoT device
     *
     * @brief operator ==
     * @param dev
     * @return
     */
    bool operator==(const IoT& dev) const override;
    /**
     *
     * specific DimmerableLight implementation of the virtual method IoT::setDevice()
     * depends on the type of the IoT device
     *
     * @brief setDevice
     * @param instruction
     */
    void setDevice(const QJsonDocument& instruction) override;
    /**
     *
     * specific DimmerableLight implementation of the virtual method IoT::clone()
     * depends on the type of the IoT device
     *
     * @brief clone
     * @return IoT pointer with the cloned object
     */
    IoT* clone() const override;
};
#endif // DIMMERABLELIGHT_H
