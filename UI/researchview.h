#ifndef RESARCHVIEW_H
#define RESARCHVIEW_H

#include <QDialog>
#include <QTableView>
#include <QSortFilterProxyModel>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QLayout>
#include <QHeaderView>
#include <customdelegate.h>
#include <../QModel/qmodel.h>
class ResearchView : public QDialog
{
    Q_OBJECT
private:
    QSortFilterProxyModel* model;
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

public slots:
};

#endif // RESARCHVIEW_H
