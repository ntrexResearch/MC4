#include "editormotiontab.h"
#include <QString>
#include <QStringList>
#include <QDebug>

EditorMotionTab::EditorMotionTab(QObject *parent) : Tab(parent)
{
    //Initialize the button group
    editorButtonGroup.addButton(&parameterAddPushButton, 0);
    editorButtonGroup.addButton(&parameterInsertPushButton, 1);
    editorButtonGroup.addButton(&singleAddPushButton, 2);
    editorButtonGroup.addButton(&singleInsertPushButton, 3);
    editorButtonGroup.addButton(&actionAddPushButton, 4);
    editorButtonGroup.addButton(&actionInsertPushButton, 5);
    editorButtonGroup.addButton(&motionAddPushButton, 6);
    editorButtonGroup.addButton(&motionInsertPushButton, 7);

    for (int i = 0; i < 8; i++)
    {
        editorButtonGroup.button(i)->setFocusPolicy(Qt::NoFocus);
    }

    //Initialize parameter group box
    initParameterGroupBox();
    initActionGroupBox();
    initSingleGroupBox();
    initMotionGroupBox();
    //Add each group box to the grid layout
    gridLayout.addWidget(&parameterGroupBox, 0, 0);
    gridLayout.addWidget(&singleGroupBox, 0, 1);
    gridLayout.addWidget(&actionGroupBox, 0, 2);
    gridLayout.addWidget(&motionGroupBox, 1, 0, 1, 3);

    gridLayout.setMargin(margin);
    gridLayout.setSpacing(0);

    widget.setLayout(&gridLayout);
    connect(&actionTypeComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(handleSelectionChanged(int)));
    connect(&editorButtonGroup, SIGNAL(buttonReleased(int)), this, SLOT(editorButtonsReleased(int)));
}

//Parameter Group
void EditorMotionTab::initParameterGroupBox()
{
    parameterLabels[0].setText("S.V");
    parameterLabels[1].setText("Vel.");
    parameterLabels[2].setText("Acc.");
    parameterLabels[3].setText("Dec.");

    parameterUnitLabels[0].setText("mm/s");
    parameterUnitLabels[1].setText("mm/s");
    parameterUnitLabels[2].setText("mm/s<sup>2</sup>");
    parameterUnitLabels[3].setText("mm/s<sup>2</sup>");

    parameterAddPushButton.setText("Add");
    parameterInsertPushButton.setText("Insert");


    QStringList profileStringList = QStringList() << "Trape." << "Scurve";
    profileComboBox.addItems(profileStringList);

    parameterGridLayout.addWidget(&profileComboBox, 0, 1, 1, 2);
    //profileComboBox.setFixedWidth(70);
    for(int i =0; i < 4; i++){
        parameterGridLayout.addWidget(&parameterLabels[i], i+1, 0);
        parameterLineEdits[i].setFixedWidth(70);
        parameterLineEdits[i].setAlignment(Qt::AlignRight);
        parameterGridLayout.addWidget(&parameterLineEdits[i], i+1, 1, 1, 2);
        parameterGridLayout.addWidget(&parameterUnitLabels[i], i+1, 3);
    }
    parameterAddPushButton.setFixedWidth(50);
    parameterInsertPushButton.setFixedWidth(50);

    parameterGridLayout.addWidget(&parameterAddPushButton, 5, 2);
    parameterGridLayout.addWidget(&parameterInsertPushButton, 5, 3);

    parameterGridLayout.setMargin(margin);
    parameterGridLayout.setSpacing(space);
    parameterGroupBox.setTitle("Parameter");
    parameterGroupBox.setLayout(&parameterGridLayout);
}

//Single Group
void EditorMotionTab::initSingleGroupBox()
{
    singleAxisLabels[0].setText("X");
    singleAxisLabels[1].setText("Y");
    singleAxisLabels[2].setText("Z");
    singleAxisLabels[3].setText("H");
    QStringList singleStringList = QStringList() << "N/A" << "GP" << "GPR" << "GV" << "GVI" << "GH";

    singleAddPushButton.setText("Add");
    singleInsertPushButton.setText("Insert");

    for (int i = 0; i<4; i++){
            singleUnitLabels[i].setText("mm");
            singleLineEdits[i].setFixedWidth(70);
            singleLineEdits[i].setAlignment(Qt::AlignRight);
            singleComboBox[i].addItems(singleStringList);
            singleComboBox[i].setFixedWidth(50);
            singleGridLayout.addWidget(&singleAxisLabels[i], i, 0, 1, 1);
            singleGridLayout.addWidget(&singleComboBox[i], i, 1, 1, 1);
            singleGridLayout.addWidget(&singleLineEdits[i], i, 2, 1, 2);
            singleGridLayout.addWidget(&singleUnitLabels[i], i, 4);
             }
    singleAddPushButton.setFixedWidth(50);
    singleInsertPushButton.setFixedWidth(50);

    singleGridLayout.addWidget(&singleAddPushButton, 4, 3);
    singleGridLayout.addWidget(&singleInsertPushButton, 4, 4);

    singleGridLayout.setMargin(margin);
    singleGridLayout.setSpacing(space);
    singleGroupBox.setTitle("Single");
    singleGroupBox.setLayout(&singleGridLayout);

}

//Action Group
void EditorMotionTab::initActionGroupBox()
{
    actionUnitLabels[0].setText("ms");
    actionUnitLabels[1].setText("step");
    actionUnitLabels[2].setText("port");
    actionUnitLabels[3].setText("count");
//    actionUnitLabels[4].setText("unknown");
    actionTypeComboBox.setFixedWidth(60);
    //actionUnitLabels[1].setAlignment(Qt::AlignRight);

    actionAddPushButton.setText("Add");
    actionInsertPushButton.setText("Insert");

    for(int i = 0; i<4; i++){
        actionLineEdits[i].setFixedWidth(40);
        actionLineEdits[i].setAlignment(Qt::AlignRight);
        //actionUnitLabels[i].setFixedWidth(30);
    }
    //actionUnitLabels[4].setFixedWidth(33);

    QStringList actionTypeStringList = QStringList() << "Delay" << "Jump" << "Input" <<"Output"
                                                     << "Loop" << "End";

    actionTypeComboBox.addItems(actionTypeStringList);

    actionGridLayout.addWidget(&actionTypeComboBox, 0, 0, 1, 2 );
    for (int i =0; i < 4; i++){
        actionGridLayout.addWidget(&actionLineEdits[i], i, 2, Qt::AlignRight);
        actionGridLayout.addWidget(&actionUnitLabels[i], i, 3);
    }
    actionGridLayout.addWidget(&actionRadioButton, 4, 2);
    actionAddPushButton.setFixedWidth(50);
    actionInsertPushButton.setFixedWidth(50);

    actionAddPushButton.setFixedWidth(50);
    actionInsertPushButton.setFixedWidth(50);

    actionGridLayout.addWidget(&actionAddPushButton, 5, 2);
    actionGridLayout.addWidget(&actionInsertPushButton, 5, 3);

    actionGridLayout.setMargin(margin);
    actionGridLayout.setSpacing(space);
    actionGroupBox.setTitle("Action");
    actionGroupBox.setLayout(&actionGridLayout);
}


//Motion Group
void EditorMotionTab::initMotionGroupBox()
{
    initOffset1GroupBox();
    initOffset2GroupBox();

    QStringList optionStringList = QStringList() << "Linear" << "Blend" << "Set X-Y"  <<
                                                    "Set Y-Z" << "Set Z-X"<< "Arc CW" << "Arc CCW";
    motionOptionComboBox.addItems(optionStringList);
    motionOptionComboBox.setFixedWidth(70);
    motionRadiusLineEdit.setFixedWidth(70);
    motionRadiusLineEdit.setAlignment(Qt::AlignRight);
    motionUnit3Label.setText("mm");
    motionRadiusLabel.setText("R");

    motionBlendLabel.setText("B");
//    motionUnit4Label.setText("mm");
    motionBlendSpinBox.setAlignment(Qt::AlignRight);
    motionBlendSpinBox.setMinimum(0.00);
    motionBlendSpinBox.setMaximum(1.00);
    motionBlendSpinBox.setDecimals(2);
    motionBlendSpinBox.setSingleStep(0.01);
    motionBlendSpinBox.setFixedWidth(70);

    motionAddPushButton.setText("Add");
    motionInsertPushButton.setText("Insert");

    motionGridLayout.addWidget(&motionOptionComboBox, 0, 1, 1, 1);

    motionGridLayout.addWidget(&motionOffset1GroupBox, 0, 4, 5, 5);
    motionGridLayout.addWidget(&motionOffset2GroupBox, 0, 9, 5, 5);

    motionGridLayout.addWidget(&motionRadiusLabel, 1, 0);
    motionGridLayout.addWidget(&motionRadiusLineEdit, 1, 1, 1, 1);
    motionGridLayout.addWidget(&motionUnit3Label, 1, 3);

    motionGridLayout.addWidget(&motionBlendLabel, 2, 0);
    motionGridLayout.addWidget(&motionBlendSpinBox, 2, 1, 1, 1);
    motionGridLayout.addWidget(&motionUnit4Label, 2, 3);

    motionAddPushButton.setFixedWidth(50);
    motionInsertPushButton.setFixedWidth(50);

    motionGridLayout.addWidget(&motionAddPushButton, 3, 0);
    motionGridLayout.addWidget(&motionInsertPushButton, 3, 1);

    motionGridLayout.setMargin(margin);
    motionGridLayout.setSpacing(space);
    motionGroupBox.setTitle("Motion");
    motionGroupBox.setLayout(&motionGridLayout);
}


void EditorMotionTab::initOffset1GroupBox()
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
  //      motionAxis2Labels[i].setFixedWidth(20);
        motionOffset1LineEdits[i].setFixedWidth(70);
        motionOffset1LineEdits[i].setAlignment(Qt::AlignRight);
        motionOffset1GridLayout.addWidget(&motionAxis1Labels[i], i, 0);
        motionOffset1GridLayout.addWidget(&motionOffset1LineEdits[i], i, 1);
        motionOffset1GridLayout.addWidget(&motionUnit1Labels[i], i, 2);
    }
    motionOffset1GridLayout.setMargin(margin);
    motionOffset1GridLayout.setSpacing(space);
    motionOffset1GroupBox.setLayout(&motionOffset1GridLayout);
}

void EditorMotionTab::initOffset2GroupBox()
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
   //     motionAxis2Labels[i].setFixedWidth(20);
        motionOffset2LineEdits[i].setAlignment(Qt::AlignRight);
        motionOffset2LineEdits[i].setFixedWidth(70);
        motionOffset2GridLayout.addWidget(&motionAxis2Labels[i], i, 0);
        motionOffset2GridLayout.addWidget(&motionOffset2LineEdits[i], i, 1);
        motionOffset2GridLayout.addWidget(&motionUnit2Labels[i], i, 2);
    }

    motionOffset2GridLayout.setMargin(margin);
    motionOffset2GridLayout.setSpacing(space);
    motionOffset2GroupBox.setLayout(&motionOffset2GridLayout);

}

void EditorMotionTab::editorButtonsReleased(int button_id)
{
    //QString message = motionOptionComboBox.itemText(0) ;
    RowData rowData;
    QString instruction;
    int currentIndex;
    //Do I need to make a getter?
    //rowData.instruction = message;

    switch(button_id)
    {

    case 0://
        //get parameter row data for add mode
        rowData.setMode(0);

    case 1:
        //get parameter row data for insert mode
        rowData.setInstruction(profileComboBox.itemText(0));
        rowData.setType(profileComboBox.itemText(0));
        rowData.setOffset1("Not implemented yet");
        break;
    case 2:
//get single row data for add mode
        rowData.setMode(0);
    case 3:
        rowData.setInstruction("Single mode");
        //rowData.setType(singleComboBox.itemText(0));
        rowData.setOffset1("Not implemented yet");
        break;
    case 4:
        rowData.setMode(0);
    case 5:
        rowData.setInstruction("Action Type");
        rowData.setType(actionTypeComboBox.itemText(0));
        rowData.setOffset1("Not implemented yet");
        break;
    case 6:
        rowData.setMode(0);
    case 7:
        currentIndex = motionOptionComboBox.currentIndex();
        if (currentIndex == 0){
            instruction = makeInstruction("lin(");
        }
        else if(currentIndex ==1)
            instruction = makeInstruction("ble(");
        else
            instruction += "ok(";
        //Concatenate all the offset data

        rowData.setInstruction(instruction);
        qDebug() << rowData.getInstruction();
        rowData.setType(profileComboBox.itemText(0));
        rowData.setOffset1("Not implemented yet");
        break;

    default:
        break;
    }
    emit editorButtonClicked(rowData);

}

void EditorMotionTab::handleSelectionChanged(int index)
{
    switch(index)
    {
    case 0:
       qDebug()<<"index 0 selected";
       break;
    case 1:
       qDebug()<<"index 1 selected";
       break;
    }
}

QString EditorMotionTab::makeInstruction(QString motionOption)
{
    QString instruction = "adti(" + motionOption;
    for (int i =0; i < 4; i++){
        if (motionOffset1LineEdits[i].text() != "")
            instruction += motionOffset1LineEdits[i].text();
        else
            instruction += "0";
        if(i != 3)
            instruction += ",";
     }
     instruction += "))";

     return instruction;
}
