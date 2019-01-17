#include "switch.h"
std::string Switch::lClass = "switch";
int Switch::states[] = {0,1};
Switch::Switch(std::string& fSerial, std::string& fRoom):IoT(fSerial,lClass,fRoom){}

const void* Switch::getDeviceInstruction() const{
    return states;
}
const void *Switch::getStatus() const{
    return &status;
}

void Switch::setDevice(void* instruction){

}
