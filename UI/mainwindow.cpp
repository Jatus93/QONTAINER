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
    QPushButton* RemoveIot = new QPushButton(tr("remove device"),this);
    layout->addWidget(infoLabel,0,0);
    layout->addWidget(addIot,0,1);
    layout->addWidget(RemoveIot,0,2);
    layout->addWidget(mainContent);
    layout->setRowStretch(0,1);
    widget->setLayout(layout);

    createActions();
    createMenus();
    connect(addIot,SIGNAL(clicked(bool)),mainContent,SLOT(showAddEntryDialog()));
    connect(RemoveIot,SIGNAL(clicked(bool)),mainContent,SLOT(removeEntry()));
    connect(mainContent,&MainContent::update,this,[this](){infoLabel->setText(tr("Ci sono ")+QString::number(mainContent->size())+tr(" IoT device online"));});

    setWindowTitle(tr("QContainer"));
    setMinimumSize(640, 480);
    resize(640, 480);
}


#ifndef QT_NO_CONTEXTMENU
void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.addAction(cutAct);
    menu.addAction(copyAct);
    menu.addAction(pasteAct);
    menu.addAction(removeAct);
    menu.exec(event->globalPos());
}
#endif // QT_NO_CONTEXTMENU

void MainWindow::newFile()
{
    infoLabel->setText(tr("Invoked <b>File|New</b>"));
}

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
    //infoLabel->setText(tr("Invoked <b>File|Save</b>"));
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

void MainWindow::cut()
{
    infoLabel->setText(tr("Invoked <b>Edit|Cut</b>"));
}

void MainWindow::copy()
{
    infoLabel->setText(tr("Invoked <b>Edit|Copy</b>"));
}

void MainWindow::paste()
{
    infoLabel->setText(tr("Invoked <b>Edit|Paste</b>"));
}

void MainWindow::about()
{
    infoLabel->setText(tr("Invoked <b>Help|About</b>"));
    QMessageBox::about(this, tr("About Menu"),
                       tr("The <b>Menu</b> example shows how to create "
                          "menu-bar menus and context menus."));
}

void MainWindow::aboutQt()
{
    infoLabel->setText(tr("Invoked <b>Help|About Qt</b>"));
}

void MainWindow::createActions()
{
    newAct = new QAction(tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new file"));
    connect(newAct, &QAction::triggered, this, &MainWindow::newFile);

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

    cutAct = new QAction(tr("Cu&t"), this);
    cutAct->setShortcuts(QKeySequence::Cut);
    cutAct->setStatusTip(tr("Cut the current selection's contents to the "
                            "clipboard"));
    connect(cutAct, &QAction::triggered, this, &MainWindow::cut);

    copyAct = new QAction(tr("&Copy"), this);
    copyAct->setShortcuts(QKeySequence::Copy);
    copyAct->setStatusTip(tr("Copy the current selection's contents to the "
                             "clipboard"));
    connect(copyAct, &QAction::triggered, this, &MainWindow::copy);

    pasteAct = new QAction(tr("&Paste"), this);
    pasteAct->setShortcuts(QKeySequence::Paste);
    pasteAct->setStatusTip(tr("Paste the clipboard's contents into the current "
                              "selection"));
    connect(pasteAct, &QAction::triggered, this, &MainWindow::paste);

    removeAct = new QAction(tr("&Delete"));
    removeAct->setShortcut(QKeySequence::Delete);
    removeAct->setStatusTip(tr("Remove selected contents"));
    connect(removeAct, SIGNAL(triggered()),mainContent,SLOT(removeEntry()));

    aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(aboutAct, &QAction::triggered, this, &MainWindow::about);

    aboutQtAct = new QAction(tr("About &Qt"), this);
    aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
    connect(aboutQtAct, &QAction::triggered, qApp, &QApplication::aboutQt);
    connect(aboutQtAct, &QAction::triggered, this, &MainWindow::aboutQt);
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(saveAsAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);
}
