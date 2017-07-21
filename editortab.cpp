#include "editortab.h"
#include <QString>
#include <QStringList>

EditorTab::EditorTab(QObject *parent) : Tab(parent)
{
    //Initialize parameter group box
    initParameterGroupBox();
    initActionGroupBox();
    initSingleGroupBox();
    initMotionGroupBox();
    //Initialize motion group box
//    initOptionComboBox();
//    initOffset2GroupBox();
//    initRadiusGroupBox();
//    initBlendGroupBox();

    gridLayout.addWidget(&parameterGroupBox, 0, 0, Qt::AlignLeft);
    gridLayout.addWidget(&singleGroupBox, 0, 1, 1, 2, Qt::AlignLeft);

    gridLayout.addWidget(&actionGroupBox, 1, 0, 1, 1);
    gridLayout.addWidget(&motionGroupBox, 1, 1, 2, 2, Qt::AlignLeft);


    //gridLayout.addWidget(&motionOffset1GroupBox, 0, 2, 2, 4, Qt::AlignTop);
    //gridLayout.addWidget(&motionOffset2GroupBox, 0, 6, 2, 4, Qt::AlignTop);
    widget.setLayout(&gridLayout);
    //connect(&actionTypeComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(handleSelectionChanged(int)));
}

//Parameter Group
void EditorTab::initParameterGroupBox()
{
    parameterLabels[0].setText("S.V");
    parameterLabels[1].setText("Vel.");
    parameterLabels[2].setText("Acc.");
    parameterLabels[3].setText("Dec.");

    parameterUnitLabels[0].setText("what");
    parameterUnitLabels[1].setText("mm/s");
    parameterUnitLabels[2].setText("mm/s<sup>2</sup>");
    parameterUnitLabels[3].setText("mm/s<sup>2</sup>");



    QStringList profileStringList = QStringList() << "Trape." << "Scurve";
    profileComboBox.addItems(profileStringList);

    parameterGridLayout.addWidget(&profileComboBox, 0, 1);
    profileComboBox.setFixedWidth(70);
    for(int i =0; i < 4; i++){
        parameterGridLayout.addWidget(&parameterLabels[i], i, 0);
        parameterLineEdits[i].setFixedWidth(70);
        parameterLineEdits[i].setAlignment(Qt::AlignRight);
        parameterGridLayout.addWidget(&parameterLineEdits[i-1], i, 1, 1, 2);
        parameterGridLayout.addWidget(&parameterUnitLabels[i], i, 3);
    }

    parameterGridLayout.setMargin(margin);
    parameterGridLayout.setSpacing(space);
    parameterGroupBox.setTitle("Parameter");
    parameterGroupBox.setLayout(&parameterGridLayout);
}
//Action Group
void EditorTab::initActionGroupBox()
{
    actionUnitLabels[0].setText("ms");
    actionUnitLabels[1].setText("step");
    actionUnitLabels[2].setText("port");
    actionUnitLabels[3].setText("count");
    actionUnitLabels[4].setText("unknown");
    actionTypeComboBox.setFixedWidth(60);
    //actionUnitLabels[1].setAlignment(Qt::AlignRight);

    for(int i = 0; i<5; i++){
        actionLineEdits[i].setFixedWidth(40);
        actionLineEdits[i].setAlignment(Qt::AlignRight);
        //actionUnitLabels[i].setFixedWidth(30);
    }
    //actionUnitLabels[4].setFixedWidth(33);

    QStringList actionTypeStringList = QStringList() << "Delay" << "Jump" << "Input" <<"Output"
                                                     << "Loop" << "End";

    actionTypeComboBox.addItems(actionTypeStringList);

    actionGridLayout.addWidget(&actionTypeComboBox, 0, 0, 1, 2 );
    for (int i =0; i < 5; i++){
        actionGridLayout.addWidget(&actionLineEdits[i], i, 2);
        actionGridLayout.addWidget(&actionUnitLabels[i], i, 3);
    }

    actionGridLayout.setMargin(margin);
    actionGridLayout.setSpacing(space);
    actionGroupBox.setTitle("Action");
    actionGroupBox.setLayout(&actionGridLayout);




}

//Single Group
void EditorTab::initSingleGroupBox()
{
    singleAxisLabels[0].setText("X");
    singleAxisLabels[1].setText("Y");
    singleAxisLabels[2].setText("Z");
    singleAxisLabels[3].setText("H");
    QStringList singleStringList = QStringList() << "N/A" << "GP" << "GPR" << "GV" << "GVI" << "GH";

    for (int i = 0; i<2; i++){
            singleUnitLabels[i].setText("mm");
            singleLineEdits[i].setFixedWidth(80);
            singleComboBox[i].addItems(singleStringList);
            singleComboBox[i].setFixedWidth(50);
            singleGridLayout.addWidget(&singleAxisLabels[i], i, 0, 1, 1);
            singleGridLayout.addWidget(&singleComboBox[i], i, 1, 1, 1);
            singleGridLayout.addWidget(&singleLineEdits[i], i, 2, 1, 2);
            singleGridLayout.addWidget(&singleUnitLabels[i], i, 4);
             }
    for (int i = 2; i<4; i++){
            singleUnitLabels[i].setText("mm");
            singleLineEdits[i].setFixedWidth(80);
            singleComboBox[i].addItems(singleStringList);
            singleComboBox[i].setFixedWidth(50);
            singleGridLayout.addWidget(&singleAxisLabels[i], i-2, 5, 1, 1);
            singleGridLayout.addWidget(&singleComboBox[i], i-2, 6, 1, 1);
            singleGridLayout.addWidget(&singleLineEdits[i], i-2, 7, 1, 2);
            singleGridLayout.addWidget(&singleUnitLabels[i], i-2, 9);
             }
   // singleGroupBox.setFixedSize(260, 150);
    singleGridLayout.setMargin(margin);
    singleGridLayout.setSpacing(space);
    singleGroupBox.setTitle("Single");
    singleGroupBox.setLayout(&singleGridLayout);

}

//Motion Group
void EditorTab::initMotionGroupBox()
{
    initOffset1GroupBox();
    initOffset2GroupBox();

    QStringList optionStringList = QStringList() << "Linear" << "Blend" << "Set X-Y"  <<
                                                    "Set Y-Z" << "Set Z-X"<< "Arc CW" << "Arc CCW";
    motionOptionComboBox.addItems(optionStringList);
    motionOptionComboBox.setFixedWidth(80);


    motionRadiusLabel.setFixedWidth(20);
    motionRadiusLineEdit.setFixedWidth(60);
    motionRadiusLineEdit.setAlignment(Qt::AlignRight);
    motionUnit3Label.setFixedWidth(23);
    motionUnit3Label.setText("mm");
    motionRadiusLabel.setText("R");

    motionBlendLabel.setText("B");
    motionBlendLabel.setFixedWidth(20);
    motionUnit4Label.setText("mm");
    motionBlendSpinBox.setFixedWidth(60);

    motionGridLayout.addWidget(&motionOptionComboBox, 0, 0, 1, 3);

    motionGridLayout.addWidget(&motionOffset1GroupBox, 1, 0, 5, 5);
    motionGridLayout.addWidget(&motionOffset2GroupBox, 1, 5, 5, 5);

    motionGridLayout.addWidget(&motionRadiusLabel, 6, 0);
    motionGridLayout.addWidget(&motionRadiusLineEdit, 6, 1, 1, 2);
    motionGridLayout.addWidget(&motionUnit3Label, 6, 3);

    motionGridLayout.addWidget(&motionBlendLabel, 6, 5);
    motionGridLayout.addWidget(&motionBlendSpinBox, 6, 6, 1, 2);
    motionGridLayout.addWidget(&motionUnit4Label, 6, 8);






//    motionGroupBox.setFixedSize(290,220);
    motionGridLayout.setMargin(margin);
    motionGridLayout.setSpacing(space);
    motionGroupBox.setTitle("Motion");
    motionGroupBox.setLayout(&motionGridLayout);
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
        motionOffset1LineEdits[i].setFixedWidth(70);
        motionUnit1Labels[i].setFixedWidth(23);
        motionOffset1GridLayout.addWidget(&motionAxis1Labels[i], i, 0);
        motionOffset1GridLayout.addWidget(&motionOffset1LineEdits[i], i, 1);
        motionOffset1GridLayout.addWidget(&motionUnit1Labels[i], i, 2);

    }

    motionOffset1GridLayout.setMargin(margin);
    motionOffset1GridLayout.setSpacing(space);
//    motionOffset1GroupBox.setFixedSize(130, 130);//Height(160);

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
        motionOffset2LineEdits[i].setFixedWidth(70);
        motionUnit2Labels[i].setFixedWidth(23);
        motionOffset2GridLayout.addWidget(&motionAxis2Labels[i], i, 0);
        motionOffset2GridLayout.addWidget(&motionOffset2LineEdits[i], i, 1);
        motionOffset2GridLayout.addWidget(&motionUnit2Labels[i], i, 2);
    }

    motionOffset2GridLayout.setMargin(margin);
    motionOffset2GridLayout.setSpacing(space);
//    motionOffset2GroupBox.setFixedSize(130, 130);//Height(160);

    motionOffset2GroupBox.setLayout(&motionOffset2GridLayout);

}



void EditorTab::handleSelectionChanged(int index)
{
    //Whe the combobox's index is changed
}
