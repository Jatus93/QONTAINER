#ifndef CONTAINERFILLER_H
#define CONTAINERFILLER_H
#include "container.h"
#include "iotbuilder.h"

class ContainerFiller
{

public:
    static Container<IoT>* buildFrom(const QJsonDocument& devices);
    static QJsonDocument& serialize(const Container<IoT>& container);
};

#endif // CONTAINERFILLER_H
