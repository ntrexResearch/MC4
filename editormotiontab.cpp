#include "editormotiontab.h"
#include <QString>
#include <QStringList>

EditorMotionTab::EditorMotionTab(QObject *parent) : Tab(parent)
{



    offset2GroupBox.setTitle("Offset 2");
    radiusLabel.setText("R");
    blendLabel.setText("B");

    initOptionComboBox();
    initOffset1GroupBox();
    initOffset2GroupBox();
    initRadiusGroupBox();
    initBlendGroupBox();

    gridLayout.addWidget(&offset1GroupBox, 0, 2, 2, 4, Qt::AlignTop);
    gridLayout.addWidget(&offset2GroupBox, 0, 6, 2, 4, Qt::AlignTop);
    widget.setLayout(&gridLayout);

}

void EditorMotionTab::initOptionComboBox()
{
    QStringList optionStringList = QStringList() << "Linear" << "Blend" << "Set X-Y" <<                                             "Arc CW" << "Arc CCW" <<
                                                    "Set Y-Z" << "Set Z-X";
    optionComboBox.addItems(optionStringList);
    optionComboBox.setFixedWidth(80);
    optionLabel.setText("Options");

    gridLayout.addWidget(&optionLabel, 0, 0, 1, 1);
    gridLayout.addWidget(&optionComboBox, 0, 1, 1, 1);

}

void EditorMotionTab::initOffset1GroupBox()
{
    offset1GroupBox.setTitle("Offset 1");
    axis1Labels[0].setText("X");
    axis1Labels[1].setText("Y");
    axis1Labels[2].setText("Z");
    axis1Labels[3].setText("H");
    unit1Labels[0].setText("mm");
    unit1Labels[1].setText("mm");
    unit1Labels[2].setText("mm");
    unit1Labels[3].setText("mm");

    axis1Labels[0].setFixedWidth(20);
    axis1Labels[1].setFixedWidth(20);
    axis1Labels[2].setFixedWidth(20);
    axis1Labels[3].setFixedWidth(20);

    offset1LineEdits[0].setFixedWidth(80);
    offset1LineEdits[1].setFixedWidth(80);
    offset1LineEdits[2].setFixedWidth(80);
    offset1LineEdits[3].setFixedWidth(80);

    unit1Labels[0].setFixedWidth(23);
    unit1Labels[1].setFixedWidth(23);
    unit1Labels[2].setFixedWidth(23);
    unit1Labels[3].setFixedWidth(23);

    offset1GridLayout.addWidget(&axis1Labels[0], 0, 0);
    offset1GridLayout.addWidget(&axis1Labels[1], 1, 0);
    offset1GridLayout.addWidget(&axis1Labels[2], 2, 0);
    offset1GridLayout.addWidget(&axis1Labels[3], 3, 0);

    offset1GridLayout.addWidget(&offset1LineEdits[0], 0, 1);
    offset1GridLayout.addWidget(&offset1LineEdits[1], 1, 1);
    offset1GridLayout.addWidget(&offset1LineEdits[2], 2, 1);
    offset1GridLayout.addWidget(&offset1LineEdits[3], 3, 1);

    offset1GridLayout.addWidget(&unit1Labels[0], 0, 2);
    offset1GridLayout.addWidget(&unit1Labels[1], 1, 2);
    offset1GridLayout.addWidget(&unit1Labels[2], 2, 2);
    offset1GridLayout.addWidget(&unit1Labels[3], 3, 2);

    offset1GridLayout.setMargin(margin);
    offset1GridLayout.setSpacing(space);
    offset1GroupBox.setFixedHeight(160);
    offset1GroupBox.setLayout(&offset1GridLayout);

}

void EditorMotionTab::initOffset2GroupBox()
{
    offset2GroupBox.setTitle("Offset 1");
    axis2Labels[0].setText("X");
    axis2Labels[1].setText("Y");
    axis2Labels[2].setText("Z");
    axis2Labels[3].setText("H");
    unit2Labels[0].setText("mm");
    unit2Labels[1].setText("mm");
    unit2Labels[2].setText("mm");
    unit2Labels[3].setText("mm");

    axis2Labels[0].setFixedWidth(20);
    axis2Labels[1].setFixedWidth(20);
    axis2Labels[2].setFixedWidth(20);
    axis2Labels[3].setFixedWidth(20);

    offset2LineEdits[0].setFixedWidth(80);
    offset2LineEdits[1].setFixedWidth(80);
    offset2LineEdits[2].setFixedWidth(80);
    offset2LineEdits[3].setFixedWidth(80);

    unit2Labels[0].setFixedWidth(23);
    unit2Labels[1].setFixedWidth(23);
    unit2Labels[2].setFixedWidth(23);
    unit2Labels[3].setFixedWidth(23);

    offset2GridLayout.addWidget(&axis2Labels[0], 0, 0);
    offset2GridLayout.addWidget(&axis2Labels[1], 1, 0);
    offset2GridLayout.addWidget(&axis2Labels[2], 2, 0);
    offset2GridLayout.addWidget(&axis2Labels[3], 3, 0);

    offset2GridLayout.addWidget(&offset2LineEdits[0], 0, 1);
    offset2GridLayout.addWidget(&offset2LineEdits[1], 1, 1);
    offset2GridLayout.addWidget(&offset2LineEdits[2], 2, 1);
    offset2GridLayout.addWidget(&offset2LineEdits[3], 3, 1);

    offset2GridLayout.addWidget(&unit2Labels[0], 0, 2);
    offset2GridLayout.addWidget(&unit2Labels[1], 1, 2);
    offset2GridLayout.addWidget(&unit2Labels[2], 2, 2);
    offset2GridLayout.addWidget(&unit2Labels[3], 3, 2);

    offset2GridLayout.setMargin(margin);
    offset2GridLayout.setSpacing(space);
    offset2GroupBox.setFixedHeight(160);
    offset2GroupBox.setLayout(&offset2GridLayout);

}

void EditorMotionTab::initRadiusGroupBox()
{
    radiusLabel.setFixedWidth(20);
    radiusLineEdit.setFixedWidth(95);
    radiusLineEdit.setAlignment(Qt::AlignRight);
    unit3Label.setFixedWidth(23);
    unit3Label.setText("mm");

    gridLayout.addWidget(&radiusLabel, 2, 2, 1, 1, Qt::AlignRight );
    gridLayout.addWidget(&radiusLineEdit, 2, 3, 1, 2);
    gridLayout.addWidget(&unit3Label, 2, 5, 1, 1, Qt::AlignLeft);
}

void EditorMotionTab::initBlendGroupBox()
{
    blendLabel.setFixedWidth(20);
    gridLayout.addWidget(&blendLabel, 2, 6, 1, 1, Qt::AlignRight);
    gridLayout.addWidget(&blendSpinBox, 2, 7, 1, 2);

}
