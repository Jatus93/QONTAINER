/**
  * @file Shutter.h
  * @class Shutter
  * @extends IoT
  * @brief specific IoT implementation for Shutter devices
  * @package IoT
  * @author Gianmarco Pettinato
  */
#ifndef Shutter_H
#define Shutter_H
#include "../iot.h"

class Shutter : public IoT
{
private:
    static std::string lClass; /**< Contains the IoT class definition */
    static QJsonDocument states; /**< Contains the IoT instruction definition */
    static constexpr int min = 0; /**< min value of the device */
    static constexpr int max = 100; /**< max value of the device */

public:
    /**
     *
     * Base constructor only serial is needed recalls IoT base constructor with fClass = lClass
     *
     * @brief Shutter
     * @param fSerial
     * @param fRoom
     * @param fName
     */
    Shutter(const std::string& fSerial, const std::string& fRoom="", const std::string& fName="");
    /**
     *
     * Works like the other constructor saving all the data inside a QJsonDocument
     * recalls IoT base constructor with fClass = lClass
     *
     * @brief Shutter
     * @param initializer
     */
    Shutter(const QJsonDocument& initializer);
    /**
     *
     * specific Shutter implementation of the virtual method IoT::instruction
     * depends on the type of the IoT device
     *
     * @brief getDeviceInstruction
     * @return const QJsonDocument& that contains the device instruction
     */
    const QJsonDocument& getDeviceInstruction() const override;
    /**
     *
     * virtual method used to compare two IoT devices
     * depends on the type of the IoT device
     *
     * @brief operator ==
     * @param dev
     * @return
     */
    bool operator==(const IoT& dev) const override;
    /**
     *
     * specific Shutter implementation of the virtual method IoT::setDevice()
     * depends on the type of the IoT device
     *
     * @brief setDevice
     * @param instruction
     */
    void setDevice(const QJsonDocument& instruction) override;
    /**
     *
     * specific Shutter implementation of the virtual method IoT::clone()
     * depends on the type of the IoT device
     *
     * @brief clone
     * @return IoT pointer with the cloned object
     */
    IoT* clone() const override;
};
#endif // Shutter_H
