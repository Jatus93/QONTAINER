/**
  * @file IoT.h
  * @class IoT
  * @brief Base class for IoT hierarchy contains all the instance variables
  * @package IoT
  * @author Gianmarco Pettinato
  */
#ifndef IOT_H
#define IOT_H

#include <string>
#include <QJsonDocument>
#include <QJsonObject>

class IoT{

private:
    const std::string serial;
    const std::string dClass;
    std::string room;
    std::string name;

protected:
    QJsonObject status; /**< Where the IoT device status is stored */

public:
    /**
     * Base constructor only serial and fClass are needed
     * @brief IoT
     * @param fSerial
     * @param fClass
     * @param fRoom
     * @param fName
     */
    IoT(const std::string& fSerial, const std::string& fClass, const std::string& fRoom="",const std::string& fName="");
    /**
     * Works like the other constructor saving all the data inside a QJsonDocument
     * @brief IoT
     * @param initializer
     * @param fClass
     */
    IoT(const QJsonDocument& initializer, const std::string& fClass);
    /**
     *
     * Changes the device's room
     *
     * @brief setRoom
     * @param room
     */
    void setRoom(const std::string& room);
    /**
     *
     * Changes the device's name
     *
     * @brief setName
     * @param name
     */
    void setName(const std::string& name);
    /**
     *
     * returns the device's stored serial
     *
     * @brief getSerial
     * @return std::string returns the device's stored serial
     */
    const std::string& getSerial() const;
    /**
     *
     * returns the device's stored class
     *
     * @brief getClass
     * @return returns the device's stored class
     */
    const std::string& getClass() const;
    /**
     *
     * returns the device's stored room
     *
     * @brief getRoom
     * @return
     */
    const std::string& getRoom() const;
    /**
     *
     * returns the device's stored name
     *
     * @brief getName
     * @return
     */
    const std::string& getName() const;
    /**
     *
     * returns the device's stored status
     *
     * @brief getStatus
     * @return
     */
    const QJsonDocument& getStatus() const;
    /**
     *
     * virtual method used to compare two IoT devices
     * depends on the type of the IoT device
     *
     * @brief operator ==
     * @param dev
     * @return
     */
    virtual bool operator==(const IoT& dev) const;
    /**
     *
     * virtual method used to set QJsonObject Status
     * depends on the type of the IoT device
     *
     * @brief setDevice
     * @param instruction
     */
    virtual void setDevice(const QJsonDocument& instruction)  = 0;
    /**
     *
     * virtual method that returns the device's instruction
     * depends on the type of the IoT device
     *
     * @brief getDeviceInstruction
     * @return const QJsonDocument& that contains the device instruction
     */
    virtual const QJsonDocument& getDeviceInstruction() const = 0;
    /**
     *
     * virtual method used to get a cloned IoT device
     * depends on the type of the IoT device
     *
     * @brief clone
     * @return IoT pointer with the cloned object
     */
    virtual IoT* clone() const = 0;
    /**
     *
     * return the IoT device serialization;
     *
     * @brief JsonSerialize
     * @return
     */
    const QJsonDocument& JsonSerialize() const;
    /**
      * default destructor
      */
    virtual ~IoT();

};
#endif // IOT_H
