#include "tabletab.h"
#include <QDebug>
#include "tablebuttongrid.h"
#include <QHeaderView>

TableTab::TableTab(QObject *parent) : Tab(parent)
{

    gcodeTableWidget.setRowCount(0);
    gcodeTableWidget.setColumnCount(5);
    const QStringList header = QStringList()<<"cmd" << "Type" << "" << "" << "etc";
    //const QString header = " ";
    gcodeTableWidget.setHorizontalHeaderLabels(header);
    //To hide the first column
    //gcodeTableWidget.setColumnHidden(0,true);
    gcodeTableWidget.setEditTriggers(QAbstractItemView::NoEditTriggers);
    gcodeTableWidget.horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    // gcodeTableWidget.setItem(0,0, new QTableWidgetItem("Hello"));

    gcodeTableWidget.setColumnWidth(0,150);//For now
    gcodeTableWidget.setColumnWidth(0,40);//For now

    gcodeTableWidget.setSelectionBehavior(QAbstractItemView::SelectRows);
    tableLabel.setFixedSize(60,60);
    tableLabel.setAlignment(Qt::AlignCenter);

    gridLayout.addWidget(&gcodeTableWidget,0,0);

    widget.setLayout(&gridLayout);
}


void TableTab::insertRowTable(){
    gcodeTableWidget.insertRow(gcodeTableWidget.rowCount());

    gcodeTableWidget.setItem(0,0, new QTableWidgetItem("Hello"));
}

QTableWidget* TableTab::getTableWidget()
{
    return &gcodeTableWidget;
}

int TableTab::getMaxTableSize()
{
    return table_Size;
}
