#ifndef MAINCONTENT_H
#define MAINCONTENT_H

#include <QTabWidget>
#include <QTabBar>
#include <QSortFilterProxyModel>
#include <QTableWidget>
#include <QWindow>
#include "../QModel/qmodel.h"

class MainContent : public QTabWidget
{
    Q_OBJECT
private:
    QModel* data;
    void fillTabs();
    QSortFilterProxyModel *proxyModel;
    QList<int> tabIndex;
public:
    explicit MainContent(/**std::string rooms = "",std::string devices="",*/ QWidget *parent = nullptr);
    void load(QString filepath);

};

#endif // MAINCONTENT_H
