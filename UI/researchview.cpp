#include "researchview.h"

ResearchView::ResearchView(QModel* eModel,QWidget *parent) : QWidget(parent)
{
    model = new QSortFilterProxyModel(this);
    model->setSourceModel(eModel);
    QGridLayout* layout = new QGridLayout(this);
    QLabel* researchLabel = new QLabel(tr("Inserire i termini di ricerca"),this);
    QLineEdit * inputfield = new QLineEdit(this);
    QLabel* filterLabel = new QLabel(tr("Inserire i termini per filtrare la ricerca"),this);
    QComboBox * filter = new QComboBox(this);
    for (int i=0;i<eModel->columnCount();i++) {
        filter->addItem(eModel->headerData(i,Qt::Horizontal,0).toString());
    }
    model->setFilterRegExp(QRegExp(".*",Qt::CaseInsensitive));
    model->setFilterKeyColumn(0);
    deviceTable = new QTableView(this);
    deviceTable->setModel(model);
    deviceTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    deviceTable->horizontalHeader()->setStretchLastSection(true);
    deviceTable->verticalHeader()->hide();
    deviceTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    deviceTable->setSelectionMode(QAbstractItemView::ExtendedSelection);
    deviceTable->setItemDelegate(new CustomDelegate(this));
    layout->addWidget(researchLabel,0,0);
    layout->addWidget(inputfield,0,1);
    layout->addWidget(filterLabel,0,2);
    layout->addWidget(filter,0,3);
    layout->addWidget(deviceTable,1,0,1,0);
    this->setLayout(layout);
    connect(inputfield,SIGNAL(textChanged(const QString)),this,SLOT(stringChanged(const QString&)));
    connect(filter,SIGNAL(currentIndexChanged(int)),this,SLOT(selectionChanged(const int&)));
    connect(deviceTable, &QTableView::doubleClicked,this,[this](){emit doubleClicked(deviceTable);});
    setWindowTitle(tr("Ricerca"));
    setFixedSize(640,480);
    this->setWindowModality(Qt::WindowModal);
    setupAct();
}

void ResearchView::stringChanged(const QString & rTerm){
    model->setFilterRegExp(QRegExp(rTerm,Qt::CaseInsensitive));
    this->update();
}

void ResearchView::selectionChanged(const int& selectionIndex){
    model->setFilterKeyColumn(selectionIndex);
}

void ResearchView::closeEvent(QCloseEvent *event){
    emit closing();
    QWidget::closeEvent(event);
}
#ifndef QT_NO_CONTEXTMENU
void ResearchView::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.addAction(editAct);
    menu.addAction(removeAct);
    menu.exec(event->globalPos());
}
#endif // QT_NO_CONTEXTMENU

void ResearchView::setupAct(){
    removeAct = new QAction(tr("&Rimuovi"),this);
    removeAct->setStatusTip(tr("Rimuov l'elmento selezionato"));
    connect(removeAct, &QAction::triggered,this,[this](){emit remove(deviceTable);});

    editAct = new QAction(tr("&Modifica"),this);
    editAct->setStatusTip(tr("Modifica l'elemento selezionato"));
    connect(editAct, &QAction::triggered,this,[this](){emit edit(deviceTable);});
}
