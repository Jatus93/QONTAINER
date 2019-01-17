#include "iot.h"

IoT::IoT(std::string& fSerial,std::string& fClass,std::string& fRoom):serial(fSerial),dClass(fClass),room(fRoom){}

const std::string& IoT::getSerial() const{
    return serial;
}

const std::string& IoT::getClass() const{
    return dClass;
}

const std::string& IoT::getRoom() const{
    return room;
}
