#include "editorbuttongrid.h"

EditorButtonGrid::EditorButtonGrid(QObject *parent) : QObject(parent)
{
    editorButtonGroup.addButton(&addPushButton, 0);
    editorButtonGroup.addButton(&insertPushButton, 1);

    addPushButton.setText("Add");
    insertPushButton.setText("Insert");

    addPushButton.setFixedWidth(50);
    insertPushButton.setFixedWidth(50);

    addPushButton.setFocusPolicy(Qt::NoFocus);
    insertPushButton.setFocusPolicy(Qt::NoFocus);

    gridLayout.addWidget(&addPushButton, 0, 0, 1, 1, Qt::AlignLeft);
    gridLayout.addWidget(&insertPushButton, 0, 1, 1, 10, Qt::AlignLeft);

    connect(&editorButtonGroup, SIGNAL(buttonReleased(int)), this, SLOT(editorButton_released(int)));
}


QGridLayout* EditorButtonGrid::getGridLayout()
{
    return &gridLayout;
}

void EditorButtonGrid::editorButton_released(int button_id)
{
    emit editorButtonClicked(button_id);
}
