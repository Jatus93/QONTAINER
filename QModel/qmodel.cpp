#include "qmodel.h"

QModel::QModel(QObject* parent):QAbstractTableModel(parent),Model(){
    settings = new QSettings(tr("Unipd"),tr("Qocontainer"));
    QString current = settings->value("last_file").value<QString>();
    if (settings->contains("last_file"))
        Model::load(current.toStdString());
    else {
        settings->setValue("last_file",tr(""));
    }
}

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
    const IoT& dev = *getElementAt(index.row());
    if(role == Qt::DisplayRole){
        if(index.column() == 0)
            return QString::fromStdString(dev.getName());
        if(index.column() == 1)
            return QString::fromStdString(dev.getRoom());
        if(index.column() == 2)
            return QString(dev.getStatus().toJson(QJsonDocument::Compact));
        if(index.column() == 3)
            return QString(dev.JsonSerialize().toJson(QJsonDocument::Compact));
    }else if(role == Qt::EditRole) {
        return QString(dev.JsonSerialize().toJson(QJsonDocument::Compact));
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

bool QModel::removeRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginRemoveRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; ++row){
        iotdev.deleteElementAt(position+row);
    }
    endRemoveRows();
    emit dataChanged(index,index,{Qt::EditRole});
    return true;
}

bool QModel::setData(const QModelIndex &index, const QVariant &value, int role){
    bool result = false;
    if(index.isValid() && role == Qt::EditRole){
        int row = index.row();
        result = setDeviceStatus(value.toString().toStdString(),row);
    }
    if(role == Qt::DisplayRole){
        result = addDevice(value.toString().toStdString());
    }
    emit dataChanged(index,index,{Qt::EditRole});
    return result;
}

bool QModel::save(QString path){
    bool result = false;
    if(path=="")
        result = Model::save();
    else {
        result = Model::save(path.toStdString());
        settings->setValue("last_file",path);
        settings->sync();
    }
    return result;
}

bool QModel::load(QString path){
    bool result = false;
    beginRemoveRows(QModelIndex(), 0, size() - 1);
    endRemoveRows();
    if(path=="")
        result = Model::load();
    else {
        result = Model::load(path.toStdString());
        settings->setValue("last_file",path);
        settings->sync();
    }
    beginInsertRows(QModelIndex(),0,size()-1);
    endInsertRows();
    emit dataChanged(QModelIndex(),QModelIndex(),{Qt::EditRole});
    return result;
}

QString QModel::getCurrenFile() const{
    return settings->value("last_file").value<QString>();
}

QModel::~QModel(){
    settings->sync();
    delete settings;
}
