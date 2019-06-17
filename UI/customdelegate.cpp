#include "customdelegate.h"

void CustomDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
                           const QModelIndex &index) const
{
    QJsonDocument status(QJsonDocument::fromJson(index.data().toString().toUtf8()).object());
    if( status.object().keys().size() !=0 && status.object()["serial"].isNull()){
        int newrectWidth = option.rect.width()/status.object().keys().size()+1;
        QList<QRect> division;
        foreach(const QString field,status.object().keys()){
            if(division.isEmpty()){
                division.push_front(QRect(option.rect));
                division.first().setWidth(newrectWidth);
                division.first().setHeight(option.rect.height());
            }else {
                division.push_front(QRect(division.first().x()+division.first().width(),division.first().y(),newrectWidth,option.rect.height()));
            }
            QTextOption optText(Qt::AlignCenter);
            optText.setFlags({QTextOption::WrapAtWordBoundaryOrAnywhere});
            painter->drawText(division.first(),field+": "+QString::number(status.object()[field].toInt()),optText);
        }

    }else {
        auto centeredOpt = option;
        centeredOpt.displayAlignment = Qt::AlignCenter;
        return QStyledItemDelegate::paint(painter,centeredOpt,index);
    }

}
