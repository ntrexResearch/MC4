#include "tablebuttongrid.h"
#include <QGraphicsDropShadowEffect>
#include <QDebug>
#include "tabletab.h"
#include "table1tab.h"
#include "table2tab.h"
#include "table3tab.h"
#include "table4tab.h"
#include "table5tab.h"
#include "table6tab.h"
#include "table7tab.h"
#include "table8tab.h"
#include "table9tab.h"
#include "table10tab.h"
#include "tablebuttongrid.h"

TableButtonGrid::TableButtonGrid(QObject *parent) : QObject(parent)
{
//    QGraphicsDropShadowEffect* gdse = new QGraphicsDropShadowEffect();
//    QPushButton* upPushButton = new QPushButton();
//    QPushButton* downPushButton = new QPushButton();
//    QPushButton* addPushButton = new QPushButton();
//    QPushButton* loadPushButton = new QPushButton();
//    QPushButton* savePushButton = new QPushButton();

//    gdse->setBlurRadius(5);
//    gdse->setOffset(0);
//    gdse->setColor(QColor(0,0,0));

    tableButtonGroup.addButton(&savePushButton, 0);
    tableButtonGroup.addButton(&loadPushButton, 1);
    tableButtonGroup.addButton(&upPushButton, 2);
    tableButtonGroup.addButton(&downPushButton, 3);
//  tableButtonGroup.addButton(&addPushButton, 4);

    savePushButton.setFixedSize(50,25);
    loadPushButton.setFixedSize(50,25);
    upPushButton.setFixedSize(40,25);
    downPushButton.setFixedSize(40,25);

    savePushButton.setFocusPolicy(Qt::NoFocus);
    loadPushButton.setFocusPolicy(Qt::NoFocus);
    upPushButton.setFocusPolicy(Qt::NoFocus);
    downPushButton.setFocusPolicy(Qt::NoFocus);

    upPushButton.setText("Up");
    downPushButton.setText("Down");
    loadPushButton.setText("Load");
    savePushButton.setText("Save");


    gridLayout.addWidget(&savePushButton,0,0);
    gridLayout.addWidget(&loadPushButton, 0, 1);
    gridLayout.addWidget(&saveProgressBar, 0, 2, 1, 2);
    gridLayout.addWidget(&upPushButton, 0, 4);
    gridLayout.addWidget(&downPushButton, 0, 5);

    connect(&tableButtonGroup, SIGNAL(buttonReleased(int)),  this, SLOT(tableButton_released(int)));


}



void TableButtonGrid::tableButton_released(int button_id)\
{
    //Just tell which button is clicked
    emit updateTable(button_id);
  }

QGridLayout* TableButtonGrid::getGridLayout()
{
    return &gridLayout;
}
