#include "model.h"


Model::Model()
{
}

Container<IoT>* Model::buildFrom(const QJsonDocument& devices){
    Container<IoT>* toReturn = new Container<IoT>;
    const QJsonObject json = devices.object();
    foreach (const QString& key, json.keys()) {
        QJsonDocument* device = new QJsonDocument(json.value(key).toObject());
        toReturn->pushBack(*(IoTBuilder::build(*device)));
    }
    return toReturn;
}

QJsonDocument& Model::serialize(const Container<IoT>& container){
    QJsonObject devices;
    const Iterator<IoT> it = container.getConstIterator();
    int i = 0;
    while(it!=nullptr){
        devices.insert(QString::number(i++),(*it).JsonSerialize().object());
        it++;
    }
    return *(new QJsonDocument(devices));
}
