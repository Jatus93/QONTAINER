#include <QtWidgets>

#include "mainwindow.h"

MainWindow::MainWindow()
{
    QWidget *widget = new QWidget;
    setCentralWidget(widget);
    QModel* data= new QModel(this);
    mainContent = new MainContent(data,this);
    if(data->getCurrenFile() == "" || data->getCurrenFile().isEmpty() || data->getCurrenFile().isNull()){
        QMessageBox::information(nullptr,tr("Welcome"),tr("Seems to be the first time this program has been launch, please choose where to save your devices"));
        while(data->getCurrenFile() == "" || data->getCurrenFile().isEmpty() || data->getCurrenFile().isNull()){
            saveAs();
            if(data->getCurrenFile() == "" || data->getCurrenFile().isEmpty() || data->getCurrenFile().isNull())
                QMessageBox::warning(nullptr,tr("Alert"),tr("The choosen file seems not valid, please try again"));
        }
    }
    QGridLayout *layout = new QGridLayout;
    infoLabel = new QLabel(this);
    infoLabel->setText(tr("Ci sono ")+QString::number(mainContent->size())+tr(" IoT device online"));
    QPushButton* addIot = new QPushButton(tr("add device"),this);
    addIot->setMaximumWidth(150);
    layout->addWidget(infoLabel,0,0,1,1);
    layout->addWidget(addIot,0,1,1,1);
    layout->addWidget(mainContent,1,0,1,0);
    widget->setLayout(layout);

    createActions();
    createMenus();
    connect(addIot,SIGNAL(clicked(bool)),mainContent,SLOT(showAddEntryDialog()));
    connect(mainContent,&MainContent::update,this,[this](){infoLabel->setText(tr("Ci sono ")+QString::number(mainContent->size())+tr(" IoT device online"));});

    setWindowTitle(tr("QContainer"));
    setMinimumSize(640, 480);
    resize(640, 480);
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
    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing file"));
    connect(openAct, &QAction::triggered, this, &MainWindow::open);

    saveAct = new QAction(tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save the document to disk"));
    connect(saveAct, &QAction::triggered, this, &MainWindow::save);

    saveAsAct = new QAction(tr("&Save as..."), this);
    saveAsAct->setShortcuts(QKeySequence::SaveAs);
    saveAsAct->setStatusTip(tr("Save the document to disk"));
    connect(saveAsAct, &QAction::triggered, this, &MainWindow::saveAs);

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, &QAction::triggered, this, &QWidget::close);

    removeAct = new QAction(tr("&Delete"));
    removeAct->setShortcut(QKeySequence::Delete);
    removeAct->setStatusTip(tr("Remove selected contents"));
    connect(removeAct, SIGNAL(triggered()),mainContent,SLOT(removeEntry()));

    editAct = new QAction(tr("&Edit"));
    editAct->setShortcut(QKeySequence::Replace);
    editAct->setStatusTip(tr("Edit selected contents"));
    connect(editAct, SIGNAL(triggered()),mainContent,SLOT(editSelectedRow()));

    aboutQtAct = new QAction(tr("About &Qt"), this);
    aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
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
