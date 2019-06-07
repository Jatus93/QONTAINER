#include "qmodel.h"

QModel::QModel(QObject* parent):QAbstractTableModel(parent),Model(){}

QModel::QModel(std::string file_path,QObject* parent):QAbstractTableModel(parent),Model(file_path){}

int QModel::rowCount(const QModelIndex &parent) const{
    Q_UNUSED(parent)
    return size();
}

int QModel::columnCount(const QModelIndex &parent) const{
    Q_UNUSED(parent)
    return 3;
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
            return (tr(getDeviceStatus(index.row()).c_str()));
    }
    return QVariant();
}

QVariant QModel::headerData(int section, Qt::Orientation orientation, int role) const{
    if (role != Qt::DisplayRole)
            return QVariant();
    if(orientation == Qt::Horizontal){
        if(section == 0)
            return tr("Nome dispositivo");
        if(section == 1)
            return tr("Status");
    }
    if(orientation == Qt::Vertical){
        return QString::number(section);
    }
    return QVariant();
}
