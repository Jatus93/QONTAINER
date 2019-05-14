#include "containerfiller.h"


Container<IoT>* ContainerFiller::buildFrom(const QJsonDocument& devices){
    Container<IoT>* toReturn = new Container<IoT>;
    const QJsonObject json = devices.object();
    foreach (const QString& key, json.keys()) {
        QJsonDocument* device = new QJsonDocument(json.value(key).toObject());
        toReturn->pushBack(*(IoTBuilder::build(*device)));
    }
    return toReturn;
}

QJsonDocument& ContainerFiller::serialize(const Container<IoT>& container){
    QJsonObject devices;
    const Iterator<IoT> it = container.getConstIterator();
    int i = 0;
    while(it!=nullptr){

        devices.insert(QString::number(i++),(*it).JsonSerialize());
        it++;
    }
    return *(new QJsonDocument(devices));
}
