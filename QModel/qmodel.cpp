#include "qmodel.h"

QModel::QModel(QObject* parent):QAbstractTableModel(parent),Model(){}

QModel::QModel(std::string file_path,QObject* parent):QAbstractTableModel(parent),Model(file_path){}

int QModel::rowCount(const QModelIndex &parent) const{
    Q_UNUSED(parent)
    return size();
}

int QModel::columnCount(const QModelIndex &parent) const{
    Q_UNUSED(parent)
    return 4;
}

QVariant QModel::data(const QModelIndex &index, int role) const{
    if(!index.isValid())
        return QVariant();
    if(index.row()>size() || index.row()<0 )
        return QVariant();
    if(role == Qt::DisplayRole){
        const auto dev = getElementAt(index.row());
        if(index.column() == 0)
            return QString::fromStdString(dev->getName());
        if(index.column() == 1)
            return QString::fromStdString(dev->getRoom());
        if(index.column() == 2)
            return QString(dev->getStatus().toJson(QJsonDocument::Compact));
    }
    return QVariant();
}

QVariant QModel::headerData(int section, Qt::Orientation orientation, int role) const{
    if (role != Qt::DisplayRole)
        return QVariant();
    if(orientation == Qt::Horizontal){
        if(section == 0)
            return tr("Name");
        if(section == 1)
            return tr("Room");
        if(section == 2)
            return tr("Status");
    }
    if(orientation == Qt::Vertical){
        return QString::number(section);
    }
    return QVariant();
}

bool QModel::insertRows(int position, int rows, const QModelIndex &index){
    Q_UNUSED(index);
    beginInsertRows(QModelIndex(), position, position + rows - 1);
    endInsertRows();
    return true;
}

bool QModel::setData(const QModelIndex &index, const QVariant &value, int role){
    if(index.isValid() && role == Qt::EditRole){
        int row = index.row();
        IoT* device = nullptr;
        try {
            device = iotdev[row];
        } catch (std::out_of_range& e) {
            if(strcmp(e.what(), "Index is out of range")){
                bool result = addDevice(value.toString().toStdString());
                emit dataChanged(index,index,{role});
                return result;
            }
        }
        QJsonDocument instructions = QJsonDocument::fromVariant(QJsonDocument::fromVariant(value).object()["status"].toVariant());
        device->setDevice(instructions);
        emit dataChanged(index,index,{role});
        return true;
    }
    return false;
}
