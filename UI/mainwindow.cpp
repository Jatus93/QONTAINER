#include <QtWidgets>

#include "mainwindow.h"

MainWindow::MainWindow()
{
    QWidget *widget = new QWidget;
    setCentralWidget(widget);
    QModel* data= new QModel(this);
    mainContent = new MainContent(data,this);
    if(data->getCurrenFile() == "" || data->getCurrenFile().isEmpty() || data->getCurrenFile().isNull()){
        QMessageBox::information(nullptr,tr("Benvenuto"),tr("Sembra essere il primo avvio del programma, per favore selezione un file da usare per salvare il contenuto"));
        while(data->getCurrenFile() == "" || data->getCurrenFile().isEmpty() || data->getCurrenFile().isNull()){
            saveAs();
            if(data->getCurrenFile() == "" || data->getCurrenFile().isEmpty() || data->getCurrenFile().isNull())
                QMessageBox::warning(nullptr,tr("Attenzione"),tr("Il file scelto non sembra essere valido, per favore riprova"));
        }
    }
    QGridLayout *layout = new QGridLayout;
    infoLabel = new QLabel(this);
    infoLabel->setText(tr("Ci sono ")+QString::number(mainContent->size())+tr(" IoT dispositivi online"));
    QPushButton* addIot = new QPushButton(tr("aggiungi disposito"),this);
    addIot->setMaximumWidth(150);
    QPushButton* searchIot = new QPushButton(tr("cerca disposito"),this);
    searchIot->setMaximumWidth(150);
    layout->addWidget(infoLabel,0,0,1,1);
    layout->addWidget(addIot,0,1,1,1);
    layout->addWidget(searchIot,0,2,1,1);
    layout->addWidget(mainContent,1,0,2,0);
    widget->setLayout(layout);

    createActions();
    createMenus();
    connect(searchIot,SIGNAL(clicked(bool)),mainContent,SLOT(showResearchDialog()));
    connect(addIot,SIGNAL(clicked(bool)),mainContent,SLOT(showAddEntryDialog()));
    connect(mainContent,&MainContent::update,this,[this](){infoLabel->setText(tr("Ci sono ")+QString::number(mainContent->size())+tr(" IoT dispositivi online"));});

    setWindowTitle(tr("QContainer"));
    setMinimumSize(640, 480);
    resize(840, 780);
}


#ifndef QT_NO_CONTEXTMENU
void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.addAction(editAct);
    menu.addAction(removeAct);
    menu.exec(event->globalPos());
}
#endif // QT_NO_CONTEXTMENU

void MainWindow::open()
{
    //infoLabel->setText(tr("Invoked <b>File|Open</b>"));
    QString fileName = QFileDialog::getOpenFileName(this, ("Open File"),
                                                    "/home",
                                                    ("JSonFile (*.json)"));
    if(!fileName.isEmpty())
        mainContent->load(fileName);
}

void MainWindow::save()
{
    mainContent->save();
}

void MainWindow::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this,("Save as"),
                                                    "/home",
                                                    ("JSonFile (*.json)"));
    if(!fileName.isEmpty())
        mainContent->save(fileName);
}

void MainWindow::createActions()
{
    openAct = new QAction(tr("&Apri..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Apre un file esistente"));
    connect(openAct, &QAction::triggered, this, &MainWindow::open);

    saveAct = new QAction(tr("&Salva"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Salva nel file corrente"));
    connect(saveAct, &QAction::triggered, this, &MainWindow::save);

    saveAsAct = new QAction(tr("&Salva con nome"), this);
    saveAsAct->setShortcuts(QKeySequence::SaveAs);
    saveAsAct->setStatusTip(tr("Salva in un nuovo file"));
    connect(saveAsAct, &QAction::triggered, this, &MainWindow::saveAs);

    exitAct = new QAction(tr("Chiudi"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Chiude l'applicazione, senza salvare"));
    connect(exitAct, &QAction::triggered, this, &QWidget::close);

    removeAct = new QAction(tr("&Rimuovi"),this);
    removeAct->setShortcut(QKeySequence::Delete);
    removeAct->setStatusTip(tr("Rimuov l'elmento selezionato"));
    connect(removeAct, &QAction::triggered,this->mainContent,&MainContent::removeEntry);

    editAct = new QAction(tr("&Modifica"),this);
    editAct->setShortcut(QKeySequence::Replace);
    editAct->setStatusTip(tr("Modifica l'elemento selezionato"));
    connect(editAct, SIGNAL(triggered()),mainContent,SLOT(editSelectedRow()));

    aboutQtAct = new QAction(tr("About &Qt"), this);
    aboutQtAct->setStatusTip(tr("Mostra la versione di QT usata"));
    connect(aboutQtAct, &QAction::triggered, qApp, &QApplication::aboutQt);
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(saveAsAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutQtAct);
}
