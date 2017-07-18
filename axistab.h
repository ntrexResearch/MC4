#ifndef AXISTAB_H
#define AXISTAB_H

#include "tab.h"
#include <QLabel>
#include <QGroupBox>
#include <QWidget>
#include <QGridLayout>
#include <QCheckBox>
#include <QLineEdit>
#include <QRadioButton>
#include <QButtonGroup>

class AxisTab : public Tab
{
    Q_OBJECT
public:
    AxisTab(QObject *parent = nullptr);

    void refresh(uint32_t[]);

signals:

public slots:
    void editingLowSoftLimit_finished();
    void editingHighSoftLimit_finished();
    void editingMoveLength_finished();
    void editingVelocity_finished();
    void editingAcceleration_finished();
    void editingDeceleration_finished();
    void editingHomeOffset_finished();
    void editingHomingVelocity_finished();
    void axisButton_clicked(int);

protected:
    static const int margin = 4;
    static const int space = 5;

    int id;

    QLabel axisLabel;

    QButtonGroup axisButtonGroup;

    QGroupBox pulseGroupBox;
    QGridLayout pulseGridLayout;
    QCheckBox risingEdgeCheckBox;
    QCheckBox dirCCWCheckBox;

    QGroupBox softLimitGroupBox;
    QGridLayout softLimitGridLayout;
    QCheckBox softLimitEnableCheckBox;
    QLabel lowSoftLimitLabel;
    QLineEdit lowSoftLimitLineEdit;
    QLabel lowSoftLimitUnitLabel;
    QLabel highSoftLimitLabel;
    QLineEdit highSoftLimitLineEdit;
    QLabel highSoftLimitUnitLabel;

    QGroupBox hardLimitGroupBox;
    QGridLayout hardLimitGridLayout;
    QCheckBox hardLimitEnableCheckBox;
    QCheckBox swapLowHighCheckBox;

    QGroupBox parameterGroupBox;
    QGridLayout parameterGridLayout;
    QLabel moveLengthLabel;
    QLineEdit moveLengthLineEdit;
    QLabel moveLengthUnitLabel;
    QLabel velocityLabel;
    QLineEdit velocityLineEdit;
    QLabel velocityUnitLabel;
    QLabel accelerationLabel;
    QLineEdit accelerationLineEdit;
    QLabel accelerationUnitLabel;
    QLabel decelerationLabel;
    QLineEdit decelerationLineEdit;
    QLabel decelerationUnitLabel;

    QGroupBox homingGroupBox;
    QGridLayout homingGridLayout;
    QCheckBox homingDirCheckBox;
    QCheckBox zeroAtHomeCheckBox;
    QCheckBox zeroAfterHomeCheckBox;
    QRadioButton homeSensorRadioButton;
    QRadioButton lowLimitRadioButton;
    QRadioButton highLimitRadioButton;
    QLabel homeOffsetLabel;
    QLineEdit homeOffsetLineEdit;
    QLabel homeOffsetUnitLabel;
    QLabel homingVelocityLabel;
    QLineEdit homingVelocityLineEdit;
    QLabel homingVelocityUnitLabel;

    QGroupBox sigRevGroupBox;
    QCheckBox servoOnCheckBox;
    QCheckBox servoInPosCheckBox;
    QCheckBox servoFaultCheckBox;
    QCheckBox servoClearCheckBox;
    QCheckBox homeSensorCheckBox;
    QCheckBox lowLimitCheckBox;
    QCheckBox highLimitCheckBox;
    QGridLayout sigRevGridLayout;

private:
    void initPulseGroupBox();
    void initSoftLimitGroupBox();
    void initHardLimitGroupBox();
    void initParameterGroupBox();
    void initHomingGroupBox();
    void initSigRevGroupBox();
};


#endif // AXISTAB_H
