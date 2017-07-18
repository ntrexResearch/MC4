#include "controlstatusgrid.h"

#include <QPushButton>
#include <QGraphicsDropShadowEffect>

ControlStatusGrid::ControlStatusGrid(QObject *parent) : QObject(parent)
{
    for (int i = 0 ; i < 4; i++)
    {
        QPushButton* axisPushButton = new QPushButton();
        QPushButton* vpPushButton = new QPushButton();
        QGraphicsDropShadowEffect* gdse = new QGraphicsDropShadowEffect();

        gdse->setBlurRadius(5);
        gdse->setOffset(0);
        gdse->setColor(QColor(0, 0, 0));

        axisButtonGroup.addButton(axisPushButton, i);
        vpButtonGroup.addButton(vpPushButton, i);

        axisPushButton->setGraphicsEffect(gdse);
        axisPushButton->setStyleSheet(normal_style);

        inPosLabels[i].setFixedWidth(30);
        inPosLabels[i].setStyleSheet(deactive_style);
        inPosLabels[i].setAlignment(Qt::AlignCenter);
        inPosLabels[i].setText("In.P");

        sensorLabels[i].setFixedWidth(30);
        sensorLabels[i].setStyleSheet(deactive_style);
        sensorLabels[i].setAlignment(Qt::AlignCenter);

        posLabels[i].setFixedWidth(30);
        posLabels[i].setAlignment(Qt::AlignCenter);
        posLabels[i].setText("Pos");
        posLineEdits[i].setFixedWidth(80);
        posLineEdits[i].setAlignment(Qt::AlignRight);
        posUnitLabels[i].setFixedWidth(40);
        posUnitLabels[i].setAlignment(Qt::AlignLeft);
        posUnitLabels[i].setText("mm");

        velLabels[i].setFixedWidth(30);
        velLabels[i].setAlignment(Qt::AlignCenter);
        velLabels[i].setText("Vel");
        velLineEdits[i].setFixedWidth(80);
        velLineEdits[i].setAlignment(Qt::AlignRight);
        velUnitLabels[i].setFixedWidth(40);
        velUnitLabels[i].setAlignment(Qt::AlignLeft);
        velUnitLabels[i].setText("mm/s");

        vpPushButton->setFixedWidth(30);
        vpPushButton->setText("P");
        vpSpinBox[i].setFixedWidth(80);
        vpSpinBox[i].setDecimals(3);
        vpSpinBox[i].setMinimum(-999999.999);
        vpSpinBox[i].setMaximum(999999.999);
        vpUnitLabels[i].setFixedWidth(40);
        vpUnitLabels[i].setAlignment(Qt::AlignLeft);
        vpUnitLabels[i].setText("mm");

        gridLayout.addWidget(axisPushButton, 4 * i + 1, 0, 2, 2);
        gridLayout.addWidget(&inPosLabels[i], 4 * i + 3, 0);
        gridLayout.addWidget(&sensorLabels[i], 4 * i + 3, 1);

        gridLayout.addWidget(&posLabels[i], 4 * i + 1, 2);
        gridLayout.addWidget(&posLineEdits[i], 4 * i + 1, 3);
        gridLayout.addWidget(&posUnitLabels[i], 4 * i + 1, 4);
        gridLayout.addWidget(&velLabels[i], 4 * i + 2, 2);
        gridLayout.addWidget(&velLineEdits[i], 4 * i + 2, 3);
        gridLayout.addWidget(&velUnitLabels[i], 4 * i + 2, 4);
        gridLayout.addWidget(vpPushButton, 4 * i + 3, 2);
        gridLayout.addWidget(&vpSpinBox[i], 4 * i + 3, 3);
        gridLayout.addWidget(&vpUnitLabels[i], 4 * i + 3, 4);

        gridLayout.setRowMinimumHeight(4 * i, 10);
    }    

    axisButtonGroup.button(0)->setText("X");
    axisButtonGroup.button(1)->setText("Y");
    axisButtonGroup.button(2)->setText("Z");
    axisButtonGroup.button(3)->setText("H");    

    gridLayout.setRowMinimumHeight(0, 20);
    gridLayout.setMargin(5);
    gridLayout.setHorizontalSpacing(0);
    gridLayout.setVerticalSpacing(0);
}

QGridLayout* ControlStatusGrid::getGridLayout()
{
    return &gridLayout;
}
