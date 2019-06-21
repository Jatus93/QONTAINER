/**
  * @file switch.h
  * @class Switch
  * @extends IoT
  * @brief specific IoT implementation for Switch devices
  * @package IoT
  * @author Gianmarco Pettinato
  */
#ifndef SWITCH_H
#define SWITCH_H

#include "../iot.h"


class Switch : public IoT
{
private:
    static const std::string lClass; /**< Contains the IoT class definition */
    static const QJsonDocument states; /**< Contains the IoT instruction definition */
    static constexpr int min = 0; /**< min value of the device */
    static constexpr int max = 1; /**< max value of the device */

public:
    /**
     *
     * Base constructor only serial is needed recalls IoT base constructor with fClass = lClass
     *
     * @brief Switch
     * @param fSerial
     * @param fRoom
     * @param fName
     */
    Switch(const std::string& fSerial, const std::string& fRoom="", const std::string& fName="");
    /**
     *
     * Works like the other constructor saving all the data inside a QJsonDocument
     * recalls IoT base constructor with fClass = lClass
     *
     * @brief Switch
     * @param initializer
     */
    Switch(const QJsonDocument& initializer);
    /**
     *
     * specific switch implementation of the virtual method IoT::instruction
     * depends on the type of the IoT device
     *
     * @brief getDeviceInstruction
     * @return const QJsonDocument& that contains the device instruction
     */
    const QJsonDocument& getDeviceInstruction() const override;
    /**
     *
     * specific switch implementation of the virtual method IoT::clone()
     * depends on the type of the IoT device
     *
     * @brief clone
     * @return IoT pointer with the cloned object
     */
    IoT* clone() const override;
    /**
     *
     * specific switch implementation of the virtual method IoT::setDevice()
     * depends on the type of the IoT device
     *
     * @brief setDevice
     * @param instruction
     */
    void setDevice(const QJsonDocument& instruction) override;
};

#endif // SWITCH_H
