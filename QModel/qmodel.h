#ifndef QMODEL_H
#define QMODEL_H

#include <QAbstractTableModel>
#include <QDebug>
#include <QSettings>
#include <QFileInfo>
#include "model.h"
class QModel : public QAbstractTableModel, public Model
{
    Q_OBJECT
private:
    QSettings *settings;
public:
    QModel(QObject* parent=nullptr);
    QModel(std::string file_path,QObject* parent=nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    bool insertRows(int position, int rows, const QModelIndex &index) override;
    bool removeRows(int position, int rows, const QModelIndex &index) override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    bool save(QString path="");
    bool load(QString path="");
    QString getCurrenFile() const;
    ~QModel() override;
};

#endif // QMODEL_H
