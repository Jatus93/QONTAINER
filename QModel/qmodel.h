/**
  * @file qmodel.h
  * @class QModel
  * @extends QAbstractTableModel, Model
  * @brief specific QAbstractTableModel implementation for QModel
  * @package QModel
  * @author Gianmarco Pettinato
  */
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
    /**
     * @brief QModel
     * @param parent
     */
    QModel(QObject* parent=nullptr);
    /**
     * @brief QModel
     * @param file_path
     * @param parent
     */
    QModel(std::string file_path,QObject* parent=nullptr);
    /**
     * @brief rowCount
     * @param parent
     * @return
     */
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    /**
     * @brief columnCount
     * @param parent
     * @return
     */
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    /**
     * @brief data
     * @param index
     * @param role
     * @return
     */
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    /**
     * @brief headerData
     * @param section
     * @param orientation
     * @param role
     * @return
     */
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    /**
     * @brief insertRows
     * @param position
     * @param rows
     * @param index
     * @return
     */
    bool insertRows(int position, int rows, const QModelIndex &index) override;
    /**
     * @brief removeRows
     * @param position
     * @param rows
     * @param index
     * @return
     */
    bool removeRows(int position, int rows, const QModelIndex &index) override;
    /**
     * @brief setData
     * @param index
     * @param value
     * @param role
     * @return
     */
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    /**
     * @brief save
     * @param path
     * @return
     */
    bool save(QString path="");
    /**
     * @brief load
     * @param path
     * @return
     */
    bool load(QString path="");
    /**
     * @brief getCurrenFile
     * @return
     */
    QString getCurrenFile() const;
    ~QModel() override;
};

#endif // QMODEL_H
