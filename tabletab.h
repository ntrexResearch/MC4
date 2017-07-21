#ifndef TABLETAB_H
#define TABLETAB_H

#include <QPushButton>
#include <QTableWidget>
#include <QGridLayout>
#include <QLabel>
#include <QTableWidgetItem>
#include "tab.h"


class TableTab : public Tab
{
    Q_OBJECT
public:
    TableTab(QObject *parent = nullptr);
    void insertRowTable();
    QTableWidget* getTableWidget();
    static int getMaxTableSize();

protected:
    QLabel tableLabel;

private:
    QTableWidget gcodeTableWidget;

    static const int table_Size = 2000;
};

#endif // TABLETAB_H
