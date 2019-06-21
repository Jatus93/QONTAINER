#ifndef MAINCONTENT_H
#define MAINCONTENT_H

#include <QTabWidget>
#include <QTabBar>
#include <QSortFilterProxyModel>
#include <QTableWidget>
#include <QHeaderView>
#include <QWindow>
#include "../QModel/qmodel.h"
#include <interactiveiot.h>
#include <customdelegate.h>
#include <researchview.h>

class MainContent : public QTabWidget
{
    Q_OBJECT
private:
    InteractiveIot * addOrEdit;
    ResearchView * researchView;
    QModel* data;
    void fillTabs();
    QSortFilterProxyModel *proxyModel;
    QMap<QString,QTableView*> tabIndex;
    void redrawAll();
private slots:
    void resetAeEW();
public:
    /**
     * Constructor that require the QModel
     * @brief MainContent
     * @param eData
     * @param parent
     */
    explicit MainContent(QModel* eData, QWidget *parent = nullptr);
    ~MainContent();

    /**
     * load the file in the filepath
     * @brief load
     * @param filepath
     */
    void load(QString filepath);
    /**
     * save the file in the filepath
     * @brief save
     * @param filepath
     */
    void save(QString filepath="");
    /**
     * @brief size
     * @return
     */
    int size();
public slots:
    /**
     * shows the interactiveiot interface, the string is requred to edit the IoT device
     * @brief showEditOrAddEntryDialog
     * @param device
     */
    void showEditOrAddEntryDialog(QString device="");
    /**
     * show the interface to add an IoT device
     * @brief showAddEntryDialog
     */
    void showAddEntryDialog();
    /**
     * adds an entry to the model
     * @brief addEntry
     * @param device
     */
    void addEntry(QString device);
    /**
     * edit an entry in the model
     * @brief editEntry
     * @param device
     */
    void editEntry(QString device);
    /**
     * delete the entry from the model
     * @brief removeEntry
     */
    void removeEntry();
    /**
     * call the showEditOrAddEntryDialog with the selected row
     * @brief editSelectedRow
     */
    void editSelectedRow(QTableView* table = nullptr);
    /**
     * shows the ResearchDialog
     * @brief showResearchDialog
     */
    void showResearchDialog();

signals:
    void selectionChanged (const QItemSelection &selected);
    void update();
};

#endif // MAINCONTENT_H
