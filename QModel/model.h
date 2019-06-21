/**
  * @file model.h
  * @class Model
  * @package QModel
  * @author Gianmarco Pettinato
  */
#ifndef MODEL_H
#define MODEL_H
#include <QString>
#include <QStringList>
#include <fstream>
#include "../IoT/iot.h"
#include <../Container/container.h>
#include "../IoT/iotbuilder.h"
#include "../IoT/iotdevices.h"

class Model
{
protected:
    /**
     * @brief The IoTContainer class
     */
    class IoTContainer : public Container<IoT*>{
    public:
        IoTContainer();
        void loadFromJson(const std::string& dev);
        std::string serialize() const;
        Iterator searchName(std::string name) const;
        Iterator searchSerial(std::string serial) const;
        std::string getDevicesForAttribute(std::string attribute) const;
    };
    IoTContainer iotdev;
    static Container<std::string> rooms;
    static Container<std::string> devices;
    static std::string currentFilePath;
    void fillDeviceContainer();
public:
    /**
     * @brief Model
     * @param filePath
     */
    Model(const std::string& filePath=currentFilePath);
    /**
     * @brief load
     * @param filePath
     * @return
     */
    bool load(const std::string& filePath=currentFilePath) ;
    /**
     * @brief save
     * @param filePath
     * @return
     */
    bool save(const std::string& filePath=currentFilePath) const;
    /**
     * @brief addDevice
     * @param json_device
     * @return
     */
    bool addDevice(const std::string& json_device);
    /**
     * does perfom a deep delete of the element
     * @brief removeDevice
     * @param json_device
     * @return
     */
    bool removeDevice(const std::string& json_device);
    /**
     * @brief setDeviceStatus
     * @param status
     * @return
     */
    bool setDeviceStatus(const std::string& status);
    /**
     * @brief setDeviceStatus
     * @param status
     * @param index
     * @return
     */
    bool setDeviceStatus(const std::string& status, int index);
    /**
     * @brief getSerializzation
     * @return
     */
    const std::string getSerializzation() const;
    /**
     * @brief getDeviceStatus
     * @param index
     * @return
     */
    const std::string getDeviceStatus(const int index) const;
    /**
     * @brief getDeviceFiltered
     * @param values
     * @return
     */
    const std::string getDeviceFiltered(const std::string values = "") const;
    /**
     * @brief getAllDevicesClass
     * @return
     */
    const std::string getAllDevicesClass() const;
    /**
     * @brief getAllRooms
     * @return
     */
    const std::string getAllRooms() const;
    /**
     * @brief addRoom
     * @param room
     */
    static void addRoom(const std::string& room);
    /**
     * @brief delRoom
     * @param room
     */
    void delRoom(const std::string& room);
    /**
     * @brief size
     * @return
     */
    int size() const;
    /**
     * @brief getElementAt
     * @param index
     * @return
     */
    IoT* getElementAt(int index) const;

    ~Model();
};

#endif // MODEL_H
