#ifndef CUSTOMBUTTONDELEGATE_H
#define CUSTOMBUTTONDELEGATE_H
#include <QPushButton>
#include <QPainter>
#include <QWidget>
#include <QJsonDocument>
#include <QJsonObject>
#include <QStyledItemDelegate>

class CustomDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    CustomDelegate(QWidget * parent=nullptr):QStyledItemDelegate(parent){}
    void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override;
};

#endif // CUSTOMBUTTONDELEGATE_H
