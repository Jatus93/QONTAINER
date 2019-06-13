#include "maincontent.h"
MainContent::MainContent(QModel* eData,QWidget *parent) : QTabWidget(parent)
{
    if(eData == nullptr)
        data = new QModel(this);
    else
        data = eData;
    fillTabs();
    addOrEdit = nullptr;
}

void MainContent::fillTabs(){
    QJsonObject jrooms((QJsonDocument::fromJson(data->getAllRooms().c_str())).object());
    QJsonArray rooms =jrooms["rooms"].toArray();
    QTableView *tableViewAll = new QTableView;
    tabIndex.append(tableViewAll);
    tableViewAll->setModel(data);
    tableViewAll->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableViewAll->horizontalHeader()->setStretchLastSection(true);
    tableViewAll->verticalHeader()->hide();
    tableViewAll->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableViewAll->setSelectionMode(QAbstractItemView::SingleSelection);
    addTab(tableViewAll,tr("&All device"));
    connect(tableViewAll,SIGNAL(doubleClicked(const QModelIndex&)),this,SLOT(doubleClickedRow(const QModelIndex&)));
    foreach (auto room, rooms) {
        QString strRoom = room.toString();
        proxyModel = new QSortFilterProxyModel(this);
        proxyModel->setSourceModel(data);
        proxyModel->setFilterRegExp(QRegExp(strRoom, Qt::CaseInsensitive));
        proxyModel->setFilterKeyColumn(1);

        QTableView* tableView = new QTableView;
        tableView->setModel(proxyModel);

        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->horizontalHeader()->setStretchLastSection(true);
        tableView->verticalHeader()->hide();
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);

        tabIndex.append(tableView);
        addTab(tableView,strRoom);
        connect(tableView,SIGNAL(doubleClicked(const QModelIndex&)),this,SLOT(doubleClickedRow(const QModelIndex&)));
    }
}

void MainContent::redrawAll(){
    for(int i=0;tabIndex.size()>i;i++){
        delete tabIndex[i];
    }
    tabIndex.clear();
    fillTabs();
}
void MainContent::load(QString filepath){
    data->load(filepath.toStdString());
    redrawAll();
}

void MainContent::save(QString filepath){
    data->save(filepath.toStdString());
}

void MainContent::showEditOrAddEntryDialog(int index){
    if(addOrEdit == nullptr){
        if(index>=0){
            addOrEdit = new InteractiveIot (QString::fromStdString(data->getAllRooms()),data->getElementAt(index));
            addOrEdit->setWindowTitle(tr("Add a new Device"));
            connect(addOrEdit,SIGNAL(newDevice(QString)),this,SLOT(editEntry(QString)));
        }else{
            addOrEdit = new InteractiveIot (QString::fromStdString(data->getAllRooms()));
            addOrEdit->setWindowTitle(tr("Add a new Device"));
            connect(addOrEdit,SIGNAL(newDevice(QString)),this,SLOT(addEntry(QString)));
        }
        this->stackUnder(addOrEdit);
        connect(addOrEdit,SIGNAL(closing()),this,SLOT(resetAeEW()));
        addOrEdit->show();
    }else {
        QMessageBox messageBox;
        messageBox.critical(nullptr,"Error","All the operation must be completed before proceeding.");
        messageBox.setFixedSize(500,200);
    }
}
void MainContent::showAddEntryDialog(){
    showEditOrAddEntryDialog();
}
void MainContent::addEntry(QString device){
    QJsonDocument jDevice = QJsonDocument::fromJson(device.toUtf8());
    QString string_data = QString::fromStdString(data->getDeviceFiltered("{\"serial\":\""+jDevice.object()["serial"].toString().toStdString()+"\"}"));
    if(QJsonDocument::fromJson(string_data.toUtf8()).object()["serial"].toString()!=jDevice.object()["serial"].toString()){
        data->insertRows(0,1,QModelIndex());
        editEntry(device);
    } else {
        QMessageBox::information(this,tr("Device alredy registred"),tr("This serial has been used already"));
    }
}
void MainContent::editEntry(QString device){
    QModelIndex index = data->index(0,0,QModelIndex());
    data->setData(index,device,Qt::EditRole);
    addOrEdit->close();
    addOrEdit = nullptr;
    redrawAll();
}
void MainContent::doubleClickedRow(const QModelIndex& index){
    showEditOrAddEntryDialog(index.row());
}
void MainContent::resetAeEW(){
    addOrEdit = nullptr;
}
void MainContent::removeEntry(){

}
MainContent::~MainContent(){
    delete proxyModel;
    if(addOrEdit != nullptr)
        addOrEdit->close();
    delete data;
    for(int i=0;tabIndex.size()>i;i++){
        delete tabIndex[i];
    }
    tabIndex.clear();
}
