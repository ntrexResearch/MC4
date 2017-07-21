#ifndef EditorTab_H
#define EditorTab_H

#include "tab.h"
#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QSpinBox>
#include <QGroupBox>
#include <QLabel>
#include <QComboBox>
#include <QRadioButton>

class EditorTab : public Tab
{
    Q_OBJECT
public:
    EditorTab(QObject *parent = nullptr);

private:
    static const int margin = 4;
    static const int space = 5;

    //Parameter Group Box
    QGroupBox parameterGroupBox;
    QGridLayout parameterGridLayout;
    QLineEdit parameterLineEdits[4];
    QComboBox profileComboBox;
    QLabel parameterLabels[4];
    QLabel parameterUnitLabels[4];

    //Action Group Box
    QGroupBox actionGroupBox;
    QGridLayout actionGridLayout;
    QComboBox actionTypeComboBox;
    QLineEdit actionLineEdits[5];
    QLabel actionUnitLabels[5];
    QRadioButton actionRadioButton;

    //Single Group Box
    QGroupBox singleGroupBox;
    QGridLayout singleGridLayout;
    QLineEdit singleLineEdits[4];
    QComboBox singleComboBox[4];
    QLabel singleAxisLabels[4];
    QLabel singleUnitLabels[4];

    //Motion Group Box
    QGroupBox motionGroupBox;
    QGridLayout motionGridLayout;
    QComboBox motionOptionComboBox;

    QGroupBox motionOffset1GroupBox;
    QGridLayout motionOffset1GridLayout;
    QLineEdit motionOffset1LineEdits[4];
    QLabel motionAxis1Labels[4];
    QLabel motionUnit1Labels[4];

    QGroupBox motionOffset2GroupBox;
    QGridLayout motionOffset2GridLayout;
    QLineEdit motionOffset2LineEdits[4];
    QLabel motionAxis2Labels[4];
    QLabel motionUnit2Labels[4];

    QLabel motionRadiusLabel;
    QLineEdit motionRadiusLineEdit;
    QLabel motionUnit3Label;

    QLabel motionBlendLabel;
    QSpinBox motionBlendSpinBox;
    QLabel motionUnit4Label;



    //Initialize parameter group box
    void initParameterGroupBox();

    //Initialize action group box
    void initActionGroupBox();

    //Initialize single group box
    void initSingleGroupBox();

    //Initialize motion group box
    void initMotionGroupBox();
    void initOffset1GroupBox();
    void initOffset2GroupBox();

    void handleSelectionChanged(int);

};

#endif // EDITORMOTION_H
