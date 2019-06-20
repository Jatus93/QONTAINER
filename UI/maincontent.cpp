#include "maincontent.h"
MainContent::MainContent(QModel* eData,QWidget *parent) : QTabWidget(parent)
{
    if(eData == nullptr)
        data = new QModel(this);
    else
        data = eData;

    connect(this, &QTabWidget::currentChanged, this, [this](int tabIndex) {
        auto *tableView = qobject_cast<QTableView *>(widget(tabIndex));
        if (tableView)
            emit selectionChanged(tableView->selectionModel()->selection());
    });
    fillTabs();
    addOrEdit = nullptr;
}

void MainContent::fillTabs(){
    QJsonObject jrooms((QJsonDocument::fromJson(data->getAllRooms().c_str())).object());
    QJsonArray rooms =jrooms["rooms"].toArray();
    rooms.push_front("All devices");
    foreach (auto room, rooms) {
        QString strRoom = room.toString();
        if(tabIndex.find(strRoom) == tabIndex.end()){
            proxyModel = dynamic_cast<QSortFilterProxyModel *>(data);
            proxyModel = new QSortFilterProxyModel(this);
            proxyModel->setSourceModel(data);
            if(room == "All devices")
                proxyModel->setFilterRegExp(QRegExp(".*", Qt::CaseInsensitive));
            else
                proxyModel->setFilterRegExp(QRegExp(strRoom, Qt::CaseInsensitive));
            proxyModel->setFilterKeyColumn(1);

            QTableView* tableView = new QTableView(this);
            tableView->setModel(proxyModel);

            tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
            tableView->horizontalHeader()->setStretchLastSection(true);
            tableView->verticalHeader()->hide();
            tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
            tableView->setSelectionMode(QAbstractItemView::SingleSelection);
            connect(tableView->selectionModel(),&QItemSelectionModel::selectionChanged,this, &MainContent::selectionChanged);
            connect(this, &QTabWidget::currentChanged, this, [this](int tabIndex) {
                auto *tableView = qobject_cast<QTableView *>(widget(tabIndex));
                if (tableView)
                    emit selectionChanged(tableView->selectionModel()->selection());
            });
            tabIndex.insert(strRoom,tableView);
            addTab(tableView,strRoom);
            connect(tableView,SIGNAL(doubleClicked(const QModelIndex&)),this,SLOT(editSelectedRow()));
            tableView->setItemDelegate(new CustomDelegate());
        }
    }
    foreach(auto room, tabIndex.keys()){
        if(!rooms.contains(room) && room!="All devices"){
            tabIndex[room]->hide();
            delete tabIndex[room];
            tabIndex.remove(room);
        }else {
            tabIndex[room]->update();
        }
    }
}

void MainContent::load(QString filepath){
    if(data->load(filepath)){
        QMessageBox::information(this,tr("Success"),tr("file was loaded correctly"));
        fillTabs();
        emit update();
    }
}

void MainContent::save(QString filepath){
    bool result=false;
    if(filepath=="")
        result = data->save();
    else{
        if(data->save(filepath))
            result = data->load(filepath);
    }
    if(result){
        QMessageBox::information(this,tr("Success"),tr("file was saved correctly"));
    }
}

void MainContent::showEditOrAddEntryDialog(QString device){
    if(addOrEdit == nullptr){
        addOrEdit = new InteractiveIot (QString::fromStdString(data->getAllRooms()),device,this);
        if(device != ""){
            addOrEdit->setWindowTitle(tr("Add a new Device"));
            connect(addOrEdit,SIGNAL(newDevice(QString)),this,SLOT(editEntry(QString)));
        }else {
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
        QModelIndex index = data->index(0,0,QModelIndex());
        data->setData(index,device,Qt::UserRole);
        addOrEdit->close();
        addOrEdit = nullptr;
        fillTabs();
        emit update();
    } else {
        QMessageBox::information(this,tr("Device alredy registred"),tr("This serial has been used already"));
    }
}
void MainContent::editEntry(QString device){
    QTableView *temp = static_cast<QTableView*>(currentWidget());
    QSortFilterProxyModel *proxy = static_cast<QSortFilterProxyModel*>(temp->model());
    QItemSelectionModel *selectionModel = temp->selectionModel();

    QModelIndex index = selectionModel->selectedRows().first();
    proxy->setData(index,device,Qt::EditRole);
    addOrEdit->close();
    addOrEdit = nullptr;
    fillTabs();
    emit update();
}
void MainContent::editSelectedRow(){
    QTableView *temp = static_cast<QTableView*>(currentWidget());
    QSortFilterProxyModel *proxy = static_cast<QSortFilterProxyModel*>(temp->model());
    QItemSelectionModel *selectionModel = temp->selectionModel();

    QModelIndexList indexes = selectionModel->selectedRows();
    foreach (QModelIndex index, indexes) {
        auto ldata = proxy->data(index,Qt::EditRole);
        showEditOrAddEntryDialog(ldata.value<QString>());
    }
    emit update();
}
void MainContent::resetAeEW(){
    addOrEdit = nullptr;
}
void MainContent::removeEntry(){

    QTableView *temp = static_cast<QTableView*>(currentWidget());
    QSortFilterProxyModel *proxy = static_cast<QSortFilterProxyModel*>(temp->model());
    QItemSelectionModel *selectionModel = temp->selectionModel();

    QModelIndexList indexes = selectionModel->selectedRows();
    foreach (QModelIndex index, indexes) {
        int row = index.row();
        proxy->removeRows(row, 1, QModelIndex());
    }
    emit update();

}

int MainContent::size(){
    return data->size();
}

MainContent::~MainContent(){
    delete proxyModel;
    if(addOrEdit != nullptr)
        addOrEdit->close();
    delete data;
    tabIndex.clear();
}
