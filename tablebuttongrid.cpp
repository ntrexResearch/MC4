#include "tablebuttongrid.h"
#include <QGraphicsDropShadowEffect>
#include <QDebug>
#include "tabletab.h"

TableButtonGrid::TableButtonGrid(QObject *parent) : QObject(parent)
{
    QGraphicsDropShadowEffect* gdse = new QGraphicsDropShadowEffect();
//    QPushButton* upPushButton = new QPushButton();
//    QPushButton* downPushButton = new QPushButton();
//    QPushButton* addPushButton = new QPushButton();
//    QPushButton* loadPushButton = new QPushButton();
//    QPushButton* savePushButton = new QPushButton();

    gdse->setBlurRadius(5);
    gdse->setOffset(0);
    gdse->setColor(QColor(0,0,0));


    tableButtonGroup.addButton(&upPushButton, 0);
    tableButtonGroup.addButton(&downPushButton, 1);
    tableButtonGroup.addButton(&addPushButton, 2);
    tableButtonGroup.addButton(&loadPushButton, 3);
    tableButtonGroup.addButton(&savePushButton, 4);

    upPushButton.setText("Up");
    downPushButton.setText("Down");
    addPushButton.setText("Add");
    loadPushButton.setText("Load");
    savePushButton.setText("Save");

    for (int i = 0; i < 5; i++)
    {
        tableButtonGroup.button(i)->setGraphicsEffect(gdse);
    }

    gridLayout.addWidget(&upPushButton,0,0);
    gridLayout.addWidget(&downPushButton, 0, 1);
    gridLayout.addWidget(&addPushButton, 0, 2);
    gridLayout.addWidget(&loadPushButton, 0, 3);
    gridLayout.addWidget(&savePushButton, 0, 4);

    connect(&tableButtonGroup, SIGNAL(buttonReleased(int)),  this, SLOT(tableButton_released(int)));


}

void TableButtonGrid::tableButton_released(int button_id)\
{
    switch(button_id)
    {
    case 0:

    case 1:
        qDebug()<<"Success";
        break;

    case 2:
        qDebug()<<"Okaaaay";
        //TableTab::insertRowTable();
        //MainWindow::tableTab[0]
       // ui->getTableTab(0)->insertRowTable();
        break;

    default:
        break;
    }
}

QGridLayout* TableButtonGrid::getGridLayout()
{
    return &gridLayout;
}
