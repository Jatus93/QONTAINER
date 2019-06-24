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
    researchView = nullptr;
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
            tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
            connect(tableView->selectionModel(),&QItemSelectionModel::selectionChanged,this, &MainContent::selectionChanged);
            connect(this, &QTabWidget::currentChanged, this, [this](int tabIndex) {
                auto *tableView = qobject_cast<QTableView *>(widget(tabIndex));
                if (tableView)
                    emit selectionChanged(tableView->selectionModel()->selection());
            });
            tabIndex.insert(strRoom,tableView);
            addTab(tableView,strRoom);
            connect(tableView,SIGNAL(doubleClicked(const QModelIndex&)),this,SLOT(editSelectedRow()));
            tableView->setItemDelegate(new CustomDelegate(this));
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
        QMessageBox::information(this,tr("Successo"),tr("il file è stato caricato correttamente"));
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
        QMessageBox::information(this,tr("Successo"),tr("il file è stato salvato correttamente"));
    }
}

void MainContent::showEditOrAddEntryDialog(QString device){
    QWidget * parent = this;
    if(researchView)
        parent = researchView;
    if(addOrEdit){
        addOrEdit->close();
        delete addOrEdit;
    }
    addOrEdit = new InteractiveIot (QString::fromStdString(data->getAllRooms()),device,parent);
    if(!device.isEmpty()){
        addOrEdit->setWindowTitle(tr("Modifica il dispositivo"));
        connect(addOrEdit,SIGNAL(newDevice(QString)),this,SLOT(editEntry(QString)));
    }else {
        addOrEdit->setWindowTitle(tr("Aggiungi dispotivo"));
        connect(addOrEdit,SIGNAL(newDevice(QString)),this,SLOT(addEntry(QString)));
    }
    addOrEdit->show();

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
        data->setData(index,device,Qt::DisplayRole);
        addOrEdit->close();
        addOrEdit = nullptr;
        fillTabs();
        emit update();
    } else {
        QMessageBox::information(this,tr("Il dispositivo è già stato registrato"),tr("Questo seriale è già in uso"));
    }
}
void MainContent::editEntry(QString device){
    QTableView *temp = static_cast<QTableView*>(currentWidget());
    QSortFilterProxyModel *proxy = static_cast<QSortFilterProxyModel*>(temp->model());
    QItemSelectionModel *selectionModel = temp->selectionModel();

    if(selectionModel->selectedRows().empty()){
        temp = researchView->findChild<QTableView *>();
        proxy = static_cast<QSortFilterProxyModel*>(temp->model());
        selectionModel = temp->selectionModel();
    }
    QModelIndex index = selectionModel->selectedRows().first();
    proxy->setData(index,device,Qt::EditRole);
    addOrEdit->close();
    addOrEdit = nullptr;
    fillTabs();
    emit update();
}
void MainContent::editSelectedRow(QTableView* table){
    QTableView *temp;
    if(table == nullptr)
        temp = static_cast<QTableView*>(currentWidget());
    else
        temp = table;
    QSortFilterProxyModel *proxy = static_cast<QSortFilterProxyModel*>(temp->model());
    QItemSelectionModel *selectionModel = temp->selectionModel();
    int size = selectionModel->selectedRows().size();
    if(size>0){
        if(size > 1){
            QMessageBox::information(this,tr("Errore di selezione"),tr("Si può modificare solo un elemento per volta"));
        }else {
            QModelIndex index = selectionModel->selectedRows().first();
            auto ldata = proxy->data(index,Qt::EditRole);
            showEditOrAddEntryDialog(ldata.value<QString>());
            emit update();
        }
    }
}
void MainContent::removeEntry(QTableView* table){
    QTableView *temp = static_cast<QTableView*>(currentWidget());
    if(table != nullptr)
        temp = table;
    QSortFilterProxyModel *proxy = static_cast<QSortFilterProxyModel*>(temp->model());
    QItemSelectionModel *selectionModel = temp->selectionModel();

    QModelIndexList indexes = selectionModel->selectedRows();
    for(int i = 0; i<indexes.size();i++){
        QModelIndex index = indexes[i];
        proxy->removeRows(index.row(), 1, QModelIndex());
    }
    emit update();

}

void MainContent::showResearchDialog(){
    if(researchView == nullptr)
        researchView = new ResearchView(data);
    researchView->show();
    connect(researchView,SIGNAL(doubleClicked(QTableView*)),this,SLOT(editSelectedRow(QTableView*)));
    connect(researchView,SIGNAL(remove(QTableView*)),this,SLOT(removeEntry(QTableView*)));
    connect(researchView,SIGNAL(edit(QTableView*)),this,SLOT(editSelectedRow(QTableView*)));
    connect(researchView,&ResearchView::closing,this,[this](){researchView->close();delete researchView; researchView = nullptr;});
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
