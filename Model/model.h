#ifndef MODEL_H
#define MODEL_H
#include <QJsonDocument>
#include <QFile>
#include <QVector>
#include <container.h>
#include <iotbuilder.h>

class Model
{
private:
    static Container<IoT*> iotdev;
    static Container<IoT>* buildFrom(const QJsonDocument& devices);
    static QJsonDocument& serialize(const Container<IoT>& container);
public:
    Model();
    bool load(const std::string& file_path) ;
    bool save(const std::string& file_path) const;
    bool addDevice(const std::string& json_device);
    bool removeDevice(const std::string& json_device);
    bool setDeviceStatus(const std::string& status);
    const std::string& getDeviceStatus(const int index) const;
};

#endif // MODEL_H
