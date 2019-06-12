#include "maincontent.h"
MainContent::MainContent(QModel* eData,QWidget *parent) : QTabWidget(parent)
{
    if(eData == nullptr)
        data = new QModel(this);
    else
        data = eData;
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

void MainContent::save(QString filepath){
    data->save(filepath.toStdString());
}
void MainContent::showAddEntryDialog(){
}
void MainContent::addEntry(QString device){

}
void MainContent::editEntry(){

}
void MainContent::removeEntry(){

}
