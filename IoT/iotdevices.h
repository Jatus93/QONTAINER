#ifndef IOTDEVICES_H
#define IOTDEVICES_H
#include "./shutter/shutter.h"
#include "./switch/switch.h"
#include "./light/dimmerablelight.h"
#include "iotfactorydevice.h"

static const IoTFactoryDevice<Switch>* Switchfactory = new IoTFactoryDevice<Switch>("switch") ;
static const IoTFactoryDevice<Shutter>* Shutterfactory = new IoTFactoryDevice<Shutter>("shutter");
static const IoTFactoryDevice<DimmerableLight>* DimmerableLightfactory = new IoTFactoryDevice<DimmerableLight>("dimmerableLight");

#endif // IOTDEVICES_H
