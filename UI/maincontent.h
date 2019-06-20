#ifndef MAINCONTENT_H
#define MAINCONTENT_H

#include <QTabWidget>
#include <QTabBar>
#include <QSortFilterProxyModel>
#include <QTableWidget>
#include <QHeaderView>
#include <QWindow>
#include <QDebug>
#include "../QModel/qmodel.h"
#include "interactiveiot.h"
#include "customdelegate.h"

class MainContent : public QTabWidget
{
    Q_OBJECT
private:
    InteractiveIot * addOrEdit;
    QModel* data;
    void fillTabs();
    QSortFilterProxyModel *proxyModel;
    QMap<QString,QTableView*> tabIndex;
    void redrawAll();
private slots:
    void resetAeEW();
public:
    explicit MainContent(QModel* eData=nullptr, QWidget *parent = nullptr);
    ~MainContent();
    void load(QString filepath);
    void save(QString filepath="");
    int size();
public slots:
    void showEditOrAddEntryDialog(QString device="");
    void showAddEntryDialog();
    void addEntry(QString device);
    void editEntry(QString device);
    void removeEntry();
    void editSelectedRow();

signals:
    void selectionChanged (const QItemSelection &selected);
    void update();
};

#endif // MAINCONTENT_H
