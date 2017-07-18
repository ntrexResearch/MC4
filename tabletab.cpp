#include "tabletab.h"
#include <QGraphicsDropShadowEffect>

TableTab::TableTab(QObject *parent) : Tab(parent)
{
    QGraphicsDropShadowEffect* gdse = new QGraphicsDropShadowEffect();

    gcodeTableWidget.setRowCount(5);
    gcodeTableWidget.setColumnCount(1);
    gcodeTableWidget.setItem(0,0, new QTableWidgetItem("Hello"));
    gcodeTableWidget.setColumnWidth(0,500);//For now
    tableLabel.setFixedSize(60,60);
    tableLabel.setAlignment(Qt::AlignCenter);
    tableLabel.setGraphicsEffect(gdse);

    gridLayout.addWidget(&gcodeTableWidget,0,0);

    widget.setLayout(&gridLayout);
}


