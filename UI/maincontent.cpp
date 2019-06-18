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
    QTableView *tableViewAll = new QTableView(this);
    tabIndex.append(tableViewAll);
    tableViewAll->setModel(data);
    tableViewAll->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableViewAll->horizontalHeader()->setStretchLastSection(true);
    tableViewAll->verticalHeader()->hide();
    tableViewAll->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableViewAll->setSelectionMode(QAbstractItemView::SingleSelection);
    tableViewAll->setItemDelegate(new CustomDelegate());
    QHeaderView *vHeader = tableViewAll->verticalHeader();
    vHeader->setSectionResizeMode(QHeaderView::ResizeMode::Interactive);
    addTab(tableViewAll,tr("&All device"));
    connect(tableViewAll,SIGNAL(doubleClicked(const QModelIndex&)),this,SLOT(doubleClickedRow(const QModelIndex&)));
    foreach (auto room, rooms) {
        QString strRoom = room.toString();
        proxyModel = new QSortFilterProxyModel(this);
        proxyModel->setSourceModel(data);
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
        tabIndex.append(tableView);
        addTab(tableView,strRoom);
        connect(tableView,SIGNAL(doubleClicked(const QModelIndex&)),this,SLOT(doubleClickedRow(const QModelIndex&)));
        tableView->setItemDelegate(new CustomDelegate());
        vHeader = tableView->verticalHeader();
        vHeader->setSectionResizeMode(QHeaderView::ResizeMode::Interactive);
    }
    connect(tableViewAll->selectionModel(),&QItemSelectionModel::selectionChanged,this, &MainContent::selectionChanged);
    connect(this, &QTabWidget::currentChanged, this, [this](int tabIndex) {
        auto *tableView = qobject_cast<QTableView *>(widget(tabIndex));
        if (tableView)
            emit selectionChanged(tableView->selectionModel()->selection());
    });
}

void MainContent::redrawAll(){
    for(int i=0;tabIndex.size()>i;i++){
        delete tabIndex[i];
    }
    tabIndex.clear();
    fillTabs();
    emit update();
}

void MainContent::load(QString filepath){
    data->load(filepath.toStdString());
    redrawAll();
}

void MainContent::save(QString filepath){
    if(filepath=="")
        data->save();
    else{
        data->save(filepath.toStdString());
        data->load(filepath.toStdString());
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
        //editEntry(device);
        QModelIndex index = data->index(0,0,QModelIndex());
        data->setData(index,device,Qt::UserRole);
        addOrEdit->close();
        addOrEdit = nullptr;
        redrawAll();
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
    redrawAll();
}
void MainContent::doubleClickedRow(const QModelIndex& index){
    QTableView *w = dynamic_cast<QTableView*>(sender());
    auto ldata =  w->model()->data(index,Qt::EditRole);
    showEditOrAddEntryDialog(ldata.value<QString>());
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
    redrawAll();
}

int MainContent::size(){
    return data->size();
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
