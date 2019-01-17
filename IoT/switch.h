#ifndef SWITCH_H
#define SWITCH_H
#include "iot.h"

class Switch : public IoT
{
    static int states[];
    static std::string lClass;
    int status; // can be on or off
public:
    Switch(std::string& fSerial, std::string& fRoom);
    const void* getDeviceInstruction() const;
    const void* getStatus() const;
    void setDevice(void* instruction);
};

#endif // SWITCH_H
