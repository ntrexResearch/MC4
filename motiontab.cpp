#include "motiontab.h"
#include <QPushButton>
#include "connectiontab.h"
#include <QRadioButton>

MotionTab::MotionTab(QObject *parent) : Tab(parent)
{
    initParamGroupBox();
    initMotionGroupBox();

    gridLayout.setMargin(5);

    widget.setLayout(&gridLayout);

    connect(&motionButtonGroup, SIGNAL(buttonClicked(int)), this, SLOT(motionButton_clicked(int)));
}

void MotionTab::motionButton_clicked(int button_id)
{
    switch (button_id){
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    default:
        break;
    }
}

void MotionTab::initParamGroupBox()
{
    for(int i = 0 ; i < 4; i++)
    {
        QRadioButton* radioButton = new QRadioButton();

        planButtonGroup.addButton(radioButton, i);

        paramLineEdits[i].setFixedWidth(80);

        paramGridLayout.addWidget(&paramLabels[i], i, 0);
        paramGridLayout.addWidget(&paramLineEdits[i], i, 1);
        paramGridLayout.addWidget(&paramUnitLabels[i], i, 2);

        paramGridLayout.addWidget(radioButton, i, 3);
    }

    paramLabels[0].setText("Start Vel.");
    paramLabels[1].setText("Velocity");
    paramLabels[2].setText("Acceleration");
    paramLabels[3].setText("Deceleration");

    planButtonGroup.button(0)->setText("X-Y");
    planButtonGroup.button(1)->setText("Y-Z");
    planButtonGroup.button(2)->setText("Z-X");

    paramGridLayout.removeWidget(planButtonGroup.button(3));

    paramGroupBox.setLayout(&paramGridLayout);
    gridLayout.addWidget(&paramGroupBox, 0, 0);
}

void MotionTab::initMotionGroupBox()
{
    for (int i = 0; i < 4; i++)
    {
        QPushButton* pushButton = new QPushButton();
        pushButton->setFixedSize(50, 50);
        pushButton->setIconSize(QSize(40, 40));

        motionButtonGroup.addButton(pushButton, i);

        variableLabels[i].setAlignment(Qt::AlignCenter);
        variableLineEdits[i].setFixedWidth(80);
        variableLineEdits[i].setAlignment(Qt::AlignRight);
        variableUnitLabels[i].setAlignment(Qt::AlignCenter);
        variableUnitLabels[i].setText("mm");

        variableLabels[i + 4].setAlignment(Qt::AlignCenter);
        variableLineEdits[i + 4].setFixedWidth(80);
        variableLineEdits[i + 4].setAlignment(Qt::AlignRight);
        variableUnitLabels[i + 4].setAlignment(Qt::AlignCenter);
        variableUnitLabels[i + 4].setText("mm");

        motionGridLayout.addWidget(pushButton, 0, 2 * i + i / 2, 1, 2);
        motionGridLayout.setAlignment(pushButton, Qt::AlignCenter);

        motionGridLayout.addWidget(&variableLabels[i], i + 1, 0);
        motionGridLayout.addWidget(&variableLineEdits[i], i + 1, 1, 1, 2);
        motionGridLayout.addWidget(&variableUnitLabels[i], i + 1, 3);

        motionGridLayout.addWidget(&variableLabels[i + 4], i + 1, 5);
        motionGridLayout.addWidget(&variableLineEdits[i + 4], i + 1, 6, 1, 2);
        motionGridLayout.addWidget(&variableUnitLabels[i + 4], i + 1, 8);
    }

    motionButtonGroup.button(0)->setIcon(QIcon(":/images/linear.png"));
    //motionButtonGroup.button(1)->setIcon(QIcon(":/images/linear.png"));
    motionButtonGroup.button(2)->setIcon(QIcon(":/images/arc_ccw.png"));
    motionButtonGroup.button(3)->setIcon(QIcon(":/images/arc_cw.png"));

    variableLabels[0].setText("X1");
    variableLabels[1].setText("Y1");
    variableLabels[2].setText("Z1");
    variableLabels[3].setText("H1");
    variableLabels[4].setText("X2");
    variableLabels[5].setText("Y2");
    variableLabels[6].setText("Z2");
    variableLabels[7].setText("H2");

    radiusLabel.setAlignment(Qt::AlignCenter);
    radiusLabel.setText("R");
    radiusLineEdit.setFixedWidth(80);
    radiusUnitLabel.setAlignment(Qt::AlignCenter);
    radiusUnitLabel.setText("mm");

    blendLabel.setAlignment(Qt::AlignCenter);
    blendLabel.setText("B");
    blendRateSpinBox.setFixedWidth(80);
    blendRateSpinBox.setDecimals(2);
    blendRateSpinBox.setMinimum(0.00);
    blendRateSpinBox.setMaximum(1.00);

    motionGridLayout.addWidget(&radiusLabel, 5, 0);
    motionGridLayout.addWidget(&radiusLineEdit, 5, 1, 1, 2);
    motionGridLayout.addWidget(&radiusUnitLabel, 5, 3);

    motionGridLayout.addWidget(&blendLabel, 5, 5);
    motionGridLayout.addWidget(&blendRateSpinBox, 5, 6, 1, 2);

    motionGridLayout.setColumnMinimumWidth(4, 5);
    motionGridLayout.setMargin(2);
    motionGridLayout.setHorizontalSpacing(2);
    motionGridLayout.setVerticalSpacing(5);

    motionGroupBox.setLayout(&motionGridLayout);
    gridLayout.addWidget(&motionGroupBox, 1, 0);
}
