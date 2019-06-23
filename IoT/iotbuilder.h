/**
  * @file IoTBuilder.h
  * @class IoTBuilder
  * @related IoT
  * @brief IoTBuilder this class is used to
  * @package IoT
  * @author Gianmarco Pettinato
  */
#ifndef IOTBUILDER_H
#define IOTBUILDER_H

#include "./iot.h"
#include <map>
#include <list>

class IoTBuilder
{
protected:
    static std::map<std::string,IoTBuilder*>* IoTmap; /**< Contains all the IoTFactoryDevice instances */
    /**
     *
     * Static method that add a IoTBuilder to the IoTmap
     *
     * @brief addDevice
     * @param dClass
     * @param builder
     */
    static void addDevice(std::string dClass, IoTBuilder* builder);
    /**
     *
     * virtual method that returns a new IoT object
     *
     * @brief fbuild
     * @param device
     * @return new IoTdevice
     */
    virtual IoT* fbuild(const QJsonDocument& device) const = 0;
    /**
     *
     * virtual method that returns a new IoT object
     *
     * @brief fbuild
     * @param fSerial
     * @param fRoom
     * @param fName
     * @return new IoTdevice
     */
    virtual IoT* fbuild(const std::string& fSerial, const std::string& fRoom="",const std::string& fName="") const = 0;

public:
    /**
     *
     * default constructor that  initialize the map if is not
     *
     * @brief IoTBuilder
     */
    IoTBuilder();
    /**
     * default destructor
     */
    virtual ~IoTBuilder();
    /**
     * static method that performs a deep clean to the map
     * @brief builderCleaner
     */
    static void builderCleaner();
    /**
     *
     * static methdo that returns a new IoT object
     *
     * @brief getDevice
     * @param device
     * @return
     */
    static IoT* getDevice(const QJsonDocument& device);
    /**
     *
     * static method that return a list that contains all the classes available
     *
     * @brief getKeys
     * @return
     */
    static const std::list<std::string>& getKeys();
};

//#include "IoTBuilder.moc"
#endif // IOTBUILDER_H
