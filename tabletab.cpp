#include "tabletab.h"
#include <QGraphicsDropShadowEffect>
#include <QDebug>
#include "tablebuttongrid.h"


TableTab::TableTab(QObject *parent) : Tab(parent)
{
    QGraphicsDropShadowEffect* gdse = new QGraphicsDropShadowEffect();

    gcodeTableWidget.setRowCount(5);
    gcodeTableWidget.setColumnCount(1);
    const QStringList header = QStringList()<<"  ";
    //const QString header = " ";
    gcodeTableWidget.setHorizontalHeaderLabels(header);
    // gcodeTableWidget.setItem(0,0, new QTableWidgetItem("Hello"));
    gcodeTableWidget.setColumnWidth(0,500);//For now
    gcodeTableWidget.setSelectionBehavior(QAbstractItemView::SelectRows);
    tableLabel.setFixedSize(60,60);
    tableLabel.setAlignment(Qt::AlignCenter);
    tableLabel.setGraphicsEffect(gdse);

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
