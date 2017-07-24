#ifndef ControlMotionTab_H
#define ControlMotionTab_H

#include "tab.h"
#include <QButtonGroup>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QDoubleSpinBox>

class ControlMotionTab : public Tab
{
    Q_OBJECT
public:
    ControlMotionTab(QObject *parent = nullptr);

signals:

public slots:
    void motionButton_clicked(int);

private:
    QButtonGroup motionButtonGroup;
    QButtonGroup planButtonGroup;

    QGroupBox paramGroupBox;
    QGridLayout paramGridLayout;
    QLabel  paramLabels[4];
    QLineEdit paramLineEdits[4];
    QLabel paramUnitLabels[4];

    QGroupBox motionGroupBox;
    QGridLayout motionGridLayout;
    QLabel  variableLabels[8];
    QLineEdit variableLineEdits[8];
    QLabel variableUnitLabels[8];
    QLabel radiusLabel;
    QLineEdit radiusLineEdit;
    QLabel radiusUnitLabel;
    QLabel blendLabel;
    QDoubleSpinBox blendRateSpinBox;

    void initParamGroupBox();
    void initMotionGroupBox();
};

#endif // ControlMotionTab_H
