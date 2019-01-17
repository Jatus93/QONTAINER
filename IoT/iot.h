#ifndef IOT_H
#define IOT_H
#include <iostream>
class IoT{
protected:
    std::string serial;
    std::string dClass;
    std::string room;

public:
    IoT(std::string& fSerial,std::string& fClass,std::string& fRoom);
    const std::string& getSerial() const;
    const std::string& getClass() const;
    const std::string& getRoom() const;
    virtual const void* getDeviceInstruction() const = 0;
    virtual const void* getStatus() const = 0;
    virtual void setDevice(void* instruction) = 0;
    virtual ~IoT() = default;

};

#endif // IOT_H
