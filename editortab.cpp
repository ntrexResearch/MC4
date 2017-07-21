#include "editortab.h"
#include <QString>
#include <QStringList>

EditorTab::EditorTab(QObject *parent) : Tab(parent)
{
    //Initialize parameter group box
    initParameterGroupBox();
    initActionGroupBox();
        //Initialize motion group box
//    initOptionComboBox();
//    initOffset1GroupBox();
//    initOffset2GroupBox();
//    initRadiusGroupBox();
//    initBlendGroupBox();

    gridLayout.addWidget(&parameterGroupBox, 0, 0, Qt::AlignLeft);
    gridLayout.addWidget(&actionGroupBox, 0, 1);
    //gridLayout.addWidget(&motionOffset1GroupBox, 0, 2, 2, 4, Qt::AlignTop);
    //gridLayout.addWidget(&motionOffset2GroupBox, 0, 6, 2, 4, Qt::AlignTop);
    widget.setLayout(&gridLayout);

}

//Parameter Group
void EditorTab::initParameterGroupBox()
{
    parameterLabels[0].setText("Profile");
    parameterLabels[1].setText("S.V");
    parameterLabels[2].setText("Vel.");
    parameterLabels[3].setText("Acc.");
    parameterLabels[4].setText("Dec.");
    QStringList profileStringList = QStringList() << "Trapezoid" << "Scu";
    profileComboBox.addItems(profileStringList);

    parameterGridLayout.addWidget(&parameterLabels[0], 0, 0);
    parameterGridLayout.addWidget(&profileComboBox, 0, 1);
    profileComboBox.setFixedWidth(80);
    for(int i =1; i < 4; i++){
        parameterGridLayout.addWidget(&parameterLabels[i], i, 0);
        parameterGridLayout.addWidget(&parameterLineEdits[i-1], i, 1);
        parameterLineEdits[i-1].setFixedWidth(80);
    }
    parameterGroupBox.setFixedSize(140, 130);
    parameterGroupBox.setTitle("Parameter");
    parameterGroupBox.setLayout(&parameterGridLayout);
}
//Action Group
void EditorTab::initActionGroupBox()
{
    actionUnitLabels[0].setText("ms");
    actionUnitLabels[1].setText("dd");
    actionUnitLabels[2].setText("step");
    actionUnitLabels[3].setText("port");
    actionUnitLabels[4].setText("count");

    actionUnitLabels[1].setAlignment(Qt::AlignRight);
    for(int i = 0; i<5; i++){
        actionLineEdits[i].setFixedWidth(60);
        actionLineEdits[i].setAlignment(Qt::AlignRight);
        actionUnitLabels[i].setFixedWidth(30);
    }

    QStringList actionTypeStringList = QStringList() << "Delay" << "Jump" << "Input" <<"Output"
                                                     << "Loop" << "End";

    actionTypeComboBox.addItems(actionTypeStringList);

    actionGridLayout.addWidget(&actionTypeComboBox, 0, 0, 1, 4);

    actionGridLayout.addWidget(&actionLineEdits[0], 0, 4, 1, 3);
    actionGridLayout.addWidget(&actionUnitLabels[0], 0, 8);
    //# unit
    actionGridLayout.addWidget(&actionUnitLabels[1], 0, 9);
    actionGridLayout.addWidget(&actionLineEdits[1], 0, 10, 1, 3);
    actionGridLayout.addWidget(&actionUnitLabels[2], 0, 13);

    actionGridLayout.addWidget(&actionLineEdits[2], 1, 4, 1, 3);
    //Port
    actionGridLayout.addWidget(&actionUnitLabels[3], 1, 8);

    actionGridLayout.addWidget(&actionLineEdits[3], 1, 10, 1, 3);

    actionGridLayout.addWidget(&actionLineEdits[4], 2, 4, 1, 3);

    actionGridLayout.addWidget(&actionUnitLabels[4], 2, 8);


    actionGroupBox.setFixedSize(270, 130);
    actionGroupBox.setTitle("Action");
    actionGroupBox.setLayout(&actionGridLayout);




}

//Motion Group
void EditorTab::initOptionComboBox()
{
    QStringList optionStringList = QStringList() << "Linear" << "Blend" << "Set X-Y" << "Arc CW" << "Arc CCW" <<
                                                    "Set Y-Z" << "Set Z-X";
    motionOptionComboBox.addItems(optionStringList);
    motionOptionComboBox.setFixedWidth(80);
    motionOptionLabel.setText("Options");

    gridLayout.addWidget(&motionOptionLabel, 0, 0, 1, 1);
    gridLayout.addWidget(&motionOptionComboBox, 0, 1, 1, 1);

}

void EditorTab::initOffset1GroupBox()
{
    motionOffset1GroupBox.setTitle("Offset 1");
    motionAxis1Labels[0].setText("X");
    motionAxis1Labels[1].setText("Y");
    motionAxis1Labels[2].setText("Z");
    motionAxis1Labels[3].setText("H");
    motionUnit1Labels[0].setText("mm");
    motionUnit1Labels[1].setText("mm");
    motionUnit1Labels[2].setText("mm");
    motionUnit1Labels[3].setText("mm");
    for(int i =0; i<4; i++){
        motionAxis1Labels[i].setFixedWidth(20);
        motionOffset1LineEdits[i].setFixedWidth(80);
        motionUnit1Labels[i].setFixedWidth(23);
        motionOffset1GridLayout.addWidget(&motionAxis1Labels[i], i, 0);
        motionOffset1GridLayout.addWidget(&motionOffset1LineEdits[i], i, 1);
        motionOffset1GridLayout.addWidget(&motionUnit1Labels[i], i, 2);

    }

    motionOffset1GridLayout.setMargin(margin);
    motionOffset1GridLayout.setSpacing(space);
    motionOffset1GroupBox.setFixedHeight(160);

    motionOffset1GroupBox.setLayout(&motionOffset1GridLayout);


}

void EditorTab::initOffset2GroupBox()
{
    motionOffset2GroupBox.setTitle("Offset 2");
    motionAxis2Labels[0].setText("X");
    motionAxis2Labels[1].setText("Y");
    motionAxis2Labels[2].setText("Z");
    motionAxis2Labels[3].setText("H");
    motionUnit2Labels[0].setText("mm");
    motionUnit2Labels[1].setText("mm");
    motionUnit2Labels[2].setText("mm");
    motionUnit2Labels[3].setText("mm");
    for(int i =0; i<4; i++){
        motionAxis2Labels[i].setFixedWidth(20);
        motionOffset2LineEdits[i].setFixedWidth(80);
        motionUnit2Labels[i].setFixedWidth(23);
        motionOffset2GridLayout.addWidget(&motionAxis2Labels[i], i, 0);
        motionOffset2GridLayout.addWidget(&motionOffset2LineEdits[i], i, 1);
        motionOffset2GridLayout.addWidget(&motionUnit2Labels[i], i, 2);
    }

    motionOffset2GridLayout.setMargin(margin);
    motionOffset2GridLayout.setSpacing(space);
    motionOffset2GroupBox.setFixedHeight(160);

    motionOffset2GroupBox.setLayout(&motionOffset2GridLayout);

}

void EditorTab::initRadiusGroupBox()
{
    motionRadiusLabel.setFixedWidth(20);
    motionRadiusLineEdit.setFixedWidth(95);
    motionRadiusLineEdit.setAlignment(Qt::AlignRight);
    motionUnit3Label.setFixedWidth(23);
    motionUnit3Label.setText("mm");
    motionRadiusLabel.setText("R");

    gridLayout.addWidget(&motionRadiusLabel, 2, 2, 1, 1, Qt::AlignRight );
    gridLayout.addWidget(&motionRadiusLineEdit, 2, 3, 1, 2);
    gridLayout.addWidget(&motionUnit3Label, 2, 5, 1, 1, Qt::AlignLeft);
}

void EditorTab::initBlendGroupBox()
{
    motionBlendLabel.setText("B");
    motionBlendLabel.setFixedWidth(20);
    gridLayout.addWidget(&motionBlendLabel, 2, 6, 1, 1, Qt::AlignRight);
    gridLayout.addWidget(&motionBlendSpinBox, 2, 7, 1, 2);

}
