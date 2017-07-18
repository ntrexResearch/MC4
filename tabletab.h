#ifndef TABLETAB_H
#define TABLETAB_H

#include <QPushButton>
#include <QTableWidget>
#include <QGridLayout>
#include <QLabel>
#include "tab.h"


class TableTab : public Tab
{
    Q_OBJECT
public:
    TableTab(QObject *parent = nullptr);

protected:
    QLabel tableLabel;

private:
    QTableWidget gcodeTableWidget;


    const int Table_Size = 2000;
};

#endif // TABLETAB_H
