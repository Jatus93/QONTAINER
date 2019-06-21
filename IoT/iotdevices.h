#ifndef IOTDEVICES_H
#define IOTDEVICES_H
#include "./shutter/shutter.h"
#include "./switch/switch.h"
#include "./light/dimmerablelight.h"
#include "iotfactorydevice.h"

static const IoTFactoryDevice<Switch>* Switchfactory = new IoTFactoryDevice<Switch>("switch") ; /**< Contains IoTFactoryDevice<Switch> instance */
static const IoTFactoryDevice<Shutter>* Shutterfactory = new IoTFactoryDevice<Shutter>("shutter"); /**< Contains IoTFactoryDevice<Shutter> instance */
static const IoTFactoryDevice<DimmerableLight>* DimmerableLightfactory = new IoTFactoryDevice<DimmerableLight>("dimmerableLight"); /**< Contains IoTFactoryDevice<DimmerableLight> instance */

#endif // IOTDEVICES_H
