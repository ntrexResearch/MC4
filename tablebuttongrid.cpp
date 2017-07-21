#include "tablebuttongrid.h"

TableButtonGrid::TableButtonGrid(QObject *parent) : QObject(parent)
{
    tableButtonGroup.addButton(&savePushButton, 0);
    tableButtonGroup.addButton(&loadPushButton, 1);
    tableButtonGroup.addButton(&upPushButton, 2);
    tableButtonGroup.addButton(&downPushButton, 3);

    savePushButton.setFixedWidth(50);
    loadPushButton.setFixedWidth(50);
    upPushButton.setFixedWidth(40);
    downPushButton.setFixedWidth(40);

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
    emit tableButtonClicked(button_id);
  }

QGridLayout* TableButtonGrid::getGridLayout()
{
    return &gridLayout;
}
