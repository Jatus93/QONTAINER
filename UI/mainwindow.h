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
    void open();
    void save();
    void saveAs();
private:
    QModel* data;
    void createActions();
    void createMenus();
    MainContent * mainContent;
    QMenu *fileMenu;
    QMenu *helpMenu;
    QAction *openAct;
    QAction *saveAct;
    QAction *saveAsAct;
    QAction *exitAct;
    QAction *aboutQtAct;
    QAction *removeAct;
    QAction *editAct;
    QLabel *infoLabel;
};
#endif // MAINWINDOW_H
