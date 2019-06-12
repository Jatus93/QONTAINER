#ifndef MAINCONTENT_H
#define MAINCONTENT_H

#include <QTabWidget>
#include <QTabBar>
#include <QSortFilterProxyModel>
#include <QTableWidget>
#include <QWindow>
#include "../QModel/qmodel.h"
#include "interactiveiot.h"

class MainContent : public QTabWidget
{
    Q_OBJECT
private:
    QModel* data;
    void fillTabs();
    QSortFilterProxyModel *proxyModel;
    QList<int> tabIndex;
public:
    explicit MainContent(QModel* eData=nullptr, QWidget *parent = nullptr);
    void load(QString filepath);
    void save(QString filepath);
public slots:
    void showAddEntryDialog();
    void addEntry(QString device);
    void editEntry();
    void removeEntry();

signals:
    void selectionChanged (const QItemSelection &selected);
};

#endif // MAINCONTENT_H
