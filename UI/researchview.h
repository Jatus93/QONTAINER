#ifndef RESARCHVIEW_H
#define RESARCHVIEW_H

#include <QWidget>
#include <QTableView>
#include <QSortFilterProxyModel>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QLayout>
#include <QHeaderView>
#include <customdelegate.h>
#include <QMenu>
#include <QContextMenuEvent>
#include <../QModel/qmodel.h>
class ResearchView : public QWidget
{
    Q_OBJECT
protected:
#ifndef QT_NO_CONTEXTMENU
    void contextMenuEvent(QContextMenuEvent *event) override;
#endif // QT_NO_CONTEXTMENU
private:
    QAction* editAct;
    QAction* removeAct;
    QSortFilterProxyModel* model;
    QTableView * deviceTable;
    void setupAct();
private slots:
    /**
     * Changes the text researched
     * @brief stringChanged
     * @param rTerm
     */
    void stringChanged(const QString& rTerm);
    /**
     * Changes the column of research
     * @brief selectionChanged
     * @param selectionIndex
     */
    void selectionChanged(const int& selectionIndex);
    /**
     * @brief closeEvent
     * @param event
     */
    void closeEvent(QCloseEvent* event) override;
public:
    /**
     * Constructor for the research view that builds a Modal Window
     * @brief ResearchView
     * @param eModel
     * @param parent
     */
    explicit ResearchView(QModel* eModel,QWidget *parent = nullptr);

signals:
    /**
     * Signal proxy for double click event on row
     * @brief doubleClicked
     * @param table
     */
    void doubleClicked(QTableView* table);
    /**
     * @brief edit
     */
    void edit(QTableView* table);
    /**
     * @brief remove
     */
    void remove(QTableView* table);
    /**
     * @brief closing
     */
    void closing();

public slots:
};

#endif // RESARCHVIEW_H
