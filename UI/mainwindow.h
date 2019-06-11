#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "../QModel/qmodel.h"
#include "maincontent.h"
class QLabel;
class QAction;
class QActionEvent;
class QMenu;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

protected:
#ifndef QT_NO_CONTEXTMENU
    void contextMenuEvent(QContextMenuEvent *event) override;
#endif // QT_NO_CONTEXTMENU
private slots:
    void newFile();
    void open();
    void save();
    void cut();
    void copy();
    void paste();
    void about();
    void aboutQt();
private:
    QModel* data;
    void createActions();
    void createMenus();
    MainContent * mainContent;
    QMenu *fileMenu;
    QMenu *helpMenu;
    QAction *newAct;
    QAction *openAct;
    QAction *saveAct;
    QAction *exitAct;
    QAction *cutAct;
    QAction *copyAct;
    QAction *pasteAct;
    QAction *aboutAct;
    QAction *aboutQtAct;
    QLabel *infoLabel;
};
#endif // MAINWINDOW_H
