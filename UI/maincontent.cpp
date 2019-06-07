#include "maincontent.h"
MainContent::MainContent(QWidget *parent) : QTabWidget(parent)
{
    data = new QModel(this);
    fillTabs();
}

void MainContent::fillTabs(){
    //QJsonArray rooms =QJsonDocument::fromJson(data->getAllRooms().c_str()).object().value("room").toArray();
    QTableView *tableView = new QTableView;
    tableView->setModel(data);
    tabIndex.append(addTab(tableView,tr("&All device")));
    /**foreach (auto room, rooms) {
        tableView = new QTableView;
        tableView->setModel(data);
        addTab(tableView,room.toString());
    }*/
}

void MainContent::load(QString filepath){
    data->load(filepath.toStdString());
    for(int i=0;tabIndex.size()>i;i++){
        removeTab(tabIndex[i]);
    }
    tabIndex.clear();
    fillTabs();
}
