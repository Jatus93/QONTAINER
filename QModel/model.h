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
#include <../IoT/iot.h>
#include <../Container/container.h>
#include <../Container/smartptr.h>
#include <../IoT/iotbuilder.h>
#include <../IoT/iotdevices.h>

class Model
{
private:
    void fillContainer(const std::string& dev);
    std::string filterDevicesForAttribute(std::string attribute) const;
    const Container<SmartPtr<IoT>>::Iterator& searchSerial(const std::string serial) const;
    Container<std::string> rooms;
    Container<std::string> devices;
    void fillDeviceContainer();
protected:
    std::string currentFilePath;
    Container<SmartPtr<IoT>> iotdev;
public:
    /**
     * @brief Model
     * @param filePath
     */
    Model(const std::string& filePath="");
    /**
     * @brief load
     * @param filePath
     * @return
     */
    bool load(const std::string& filePath="") ;
    /**
     * @brief save
     * @param filePath
     * @return
     */
    bool save(const std::string& filePath="") const;
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
    void addRoom(const std::string& room);
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
