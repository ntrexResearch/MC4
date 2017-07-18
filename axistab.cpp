#include "axistab.h"
#include <QGraphicsDropShadowEffect>
#include <QWidget>
#include "connectiontab.h"

AxisTab::AxisTab(QObject *parent) : Tab(parent)
{
    QString style = "font-size: 60px;""border-radius: 20px;""background-color: rgb(255, 255, 255);""color: rgb(100, 100, 100);";

    QGraphicsDropShadowEffect* gdse = new QGraphicsDropShadowEffect();
    gdse->setBlurRadius(20);
    gdse->setOffset(0);
    gdse->setColor(QColor(40, 40, 240));

    axisLabel.setStyleSheet(style);
    axisLabel.setFixedSize(60, 60);
    axisLabel.setAlignment(Qt::AlignCenter);
    axisLabel.setGraphicsEffect(gdse);

    axisButtonGroup.addButton(&risingEdgeCheckBox, 0);
    axisButtonGroup.addButton(&dirCCWCheckBox, 1);
    axisButtonGroup.addButton(&softLimitEnableCheckBox, 2);
    axisButtonGroup.addButton(&hardLimitEnableCheckBox, 3);
    axisButtonGroup.addButton(&swapLowHighCheckBox, 4);
    axisButtonGroup.addButton(&homingDirCheckBox, 5);
    axisButtonGroup.addButton(&zeroAtHomeCheckBox, 6);
    axisButtonGroup.addButton(&zeroAfterHomeCheckBox, 7);
    axisButtonGroup.addButton(&servoOnCheckBox, 8);
    axisButtonGroup.addButton(&servoInPosCheckBox, 9);
    axisButtonGroup.addButton(&servoFaultCheckBox, 10);
    axisButtonGroup.addButton(&servoClearCheckBox, 11);
    axisButtonGroup.addButton(&homeSensorCheckBox, 12);
    axisButtonGroup.addButton(&lowLimitCheckBox, 13);
    axisButtonGroup.addButton(&highLimitCheckBox, 14);
    axisButtonGroup.addButton(&homeSensorRadioButton, 15);
    axisButtonGroup.addButton(&lowLimitRadioButton, 16);
    axisButtonGroup.addButton(&highLimitRadioButton, 17);
    axisButtonGroup.setExclusive(false);

    initPulseGroupBox();
    initSoftLimitGroupBox();
    initHardLimitGroupBox();
    initParameterGroupBox();
    initHomingGroupBox();
    initSigRevGroupBox();

    gridLayout.addWidget(&axisLabel, 0, 0, 1, 1, Qt::AlignCenter);
    gridLayout.addWidget(&pulseGroupBox, 0, 1);
    gridLayout.addWidget(&softLimitGroupBox, 0, 2, 1, 2);
    gridLayout.addWidget(&hardLimitGroupBox, 0, 4);
    gridLayout.addWidget(&parameterGroupBox, 1, 1, 1, 2);
    gridLayout.addWidget(&homingGroupBox, 1, 3, 1, 2);
    gridLayout.addWidget(&sigRevGroupBox, 2, 1, 1, 2);

    widget.setLayout(&gridLayout);

    connect(&lowSoftLimitLineEdit, SIGNAL(editingFinished()), this, SLOT(editingLowSoftLimit_finished()));
    connect(&highSoftLimitLineEdit, SIGNAL(editingFinished()), this, SLOT(editingHighSoftLimit_finished()));
    connect(&moveLengthLineEdit, SIGNAL(editingFinished()), this, SLOT(editingMoveLength_finished()));
    connect(&velocityLineEdit, SIGNAL(editingFinished()), this, SLOT(editingVelocity_finished()));
    connect(&accelerationLineEdit, SIGNAL(editingFinished()), this, SLOT(editingAcceleration_finished()));
    connect(&decelerationLineEdit, SIGNAL(editingFinished()), this, SLOT(editingDeceleration_finished()));
    connect(&homeOffsetLineEdit, SIGNAL(editingFinished()), this, SLOT(editingHomeOffset_finished()));
    connect(&homingVelocityLineEdit, SIGNAL(editingFinished()), this, SLOT(editingHomingVelocity_finished()));
    connect(&axisButtonGroup, SIGNAL(buttonClicked(int)), this, SLOT(axisButton_clicked(int)));
}

void AxisTab::editingLowSoftLimit_finished()
{
    ConnectionTab::sendMessage("lsl" + QString::number(id) + "=" + lowSoftLimitLineEdit.text());
}

void AxisTab::editingHighSoftLimit_finished()
{
    ConnectionTab::sendMessage("hsl" + QString::number(id) + "=" + highSoftLimitLineEdit.text());
}

void AxisTab::editingMoveLength_finished()
{
     ConnectionTab::sendMessage("mvl" + QString::number(id) + "=" + moveLengthLineEdit.text());
}

void AxisTab::editingVelocity_finished()
{
    ConnectionTab::sendMessage("vel" + QString::number(id) + "=" + velocityLineEdit.text());
}

void AxisTab::editingAcceleration_finished()
{
    ConnectionTab::sendMessage("acc" + QString::number(id) + "=" + accelerationLineEdit.text());
}

void AxisTab::editingDeceleration_finished()
{

    ConnectionTab::sendMessage("dec" + QString::number(id) + "=" + decelerationLineEdit.text());
}

void AxisTab::editingHomeOffset_finished()
{
    ConnectionTab::sendMessage("hof" + QString::number(id) + "=" + homeOffsetLineEdit.text());
}

void AxisTab::editingHomingVelocity_finished()
{
    ConnectionTab::sendMessage("hvl" + QString::number(id) + "=" + homingVelocityLineEdit.text());
}

void AxisTab::axisButton_clicked(int button_id)
{
    int value = !axisButtonGroup.button(button_id)->isChecked() ? 0 : 1;

    QString message;

    switch (button_id)
    {
    case 0:
        message.append("ce");
        break;
    case 1:
        message.append("dp");
        break;
    case 2:
        message.append("sl");
        break;
    case 3:
        message.append("hl");
        break;
    case 4:
        message.append("lsp");
        break;
    case 5:
        message.append("hdc");
        break;
    case 6:
        message.append("zah");
        break;
    case 7:
        message.append("zfh");
        break;
    case 8:
        message.append("soa");
        break;
    case 9:
        message.append("ipa");
        break;
    case 10:
        message.append("ala");
        break;
    case 11:
        message.append("ara");
        break;
    case 12:
        message.append("hsa");
        break;
    case 13:
        message.append("lla");
        break;
    case 14:
        message.append("hla");
        break;
    case 15:
    case 16:
    case 17:
        value = button_id - 15;
        message.append("hs");
        break;
    }

    message.append(QString::number(id) + "=" + QString::number(value));

    ConnectionTab::sendMessage(message);
}

void AxisTab::initPulseGroupBox()
{
    risingEdgeCheckBox.setText("Rising Edge");
    dirCCWCheckBox.setText("Dir.(CCW)");

    pulseGridLayout.addWidget(&risingEdgeCheckBox,0,0);
    pulseGridLayout.addWidget(&dirCCWCheckBox,1,0);

    pulseGroupBox.setTitle("Pulse");
    pulseGridLayout.setMargin(margin);
    pulseGridLayout.setSpacing(space);    

    pulseGroupBox.setLayout(&pulseGridLayout);
}

void AxisTab::initSoftLimitGroupBox()
{
    softLimitEnableCheckBox.setText("Enabled");
    lowSoftLimitLabel.setText("Lo.");
    lowSoftLimitLineEdit.setFixedWidth(80);
    lowSoftLimitLineEdit.setAlignment(Qt::AlignRight);
    lowSoftLimitUnitLabel.setText("mm");
    highSoftLimitLabel.setText("Hi.");
    highSoftLimitLineEdit.setFixedWidth(80);
    highSoftLimitLineEdit.setAlignment(Qt::AlignRight);
    highSoftLimitUnitLabel.setText("mm");

    softLimitGridLayout.addWidget(&softLimitEnableCheckBox, 0, 0);
    softLimitGridLayout.addWidget(&lowSoftLimitLabel, 0, 1);
    softLimitGridLayout.addWidget(&lowSoftLimitLineEdit, 0, 2);
    softLimitGridLayout.addWidget(&lowSoftLimitUnitLabel, 0, 3);
    softLimitGridLayout.addWidget(&highSoftLimitLabel, 1, 1);
    softLimitGridLayout.addWidget(&highSoftLimitLineEdit, 1, 2);
    softLimitGridLayout.addWidget(&highSoftLimitUnitLabel, 1, 3);

    softLimitGroupBox.setTitle("Soft Limit");
    softLimitGridLayout.setMargin(margin);
    softLimitGridLayout.setSpacing(space);
    softLimitGroupBox.setLayout(&softLimitGridLayout);
}

void AxisTab::initHardLimitGroupBox()
{
    hardLimitEnableCheckBox.setText("Enabled");
    swapLowHighCheckBox.setText("Lo. ↔ Hi.");

    hardLimitGridLayout.addWidget(&hardLimitEnableCheckBox, 0, 0);
    hardLimitGridLayout.addWidget(&swapLowHighCheckBox, 1, 0);

    hardLimitGroupBox.setTitle("Hard Limit");
    hardLimitGridLayout.setMargin(margin);
    hardLimitGridLayout.setSpacing(space);
    hardLimitGroupBox.setLayout(&hardLimitGridLayout);
}

void AxisTab::initParameterGroupBox()
{
    moveLengthLabel.setText("M.L.");
    moveLengthLineEdit.setFixedWidth(80);
    moveLengthLineEdit.setAlignment(Qt::AlignRight);
    moveLengthUnitLabel.setText("mm/pul");
    velocityLabel.setText("Veloc.");
    velocityLineEdit.setFixedWidth(80);
    velocityLineEdit.setAlignment(Qt::AlignRight);
    velocityUnitLabel.setText("mm/s");
    accelerationLabel.setText("Accel.");
    accelerationLineEdit.setFixedWidth(80);
    accelerationLineEdit.setAlignment(Qt::AlignRight);
    accelerationUnitLabel.setText("mm/s<sup>2</sup>");
    decelerationLabel.setText("Decel.");
    decelerationLineEdit.setFixedWidth(80);
    decelerationLineEdit.setAlignment(Qt::AlignRight);
    decelerationUnitLabel.setText("mm/s<sup>2</sup>");

    parameterGridLayout.addWidget(&moveLengthLabel, 0, 0);
    parameterGridLayout.addWidget(&moveLengthLineEdit, 0, 1);
    parameterGridLayout.addWidget(&moveLengthUnitLabel, 0, 2);
    parameterGridLayout.addWidget(&velocityLabel, 2, 0);
    parameterGridLayout.addWidget(&velocityLineEdit, 2, 1);
    parameterGridLayout.addWidget(&velocityUnitLabel, 2, 2);
    parameterGridLayout.addWidget(&accelerationLabel, 3, 0);
    parameterGridLayout.addWidget(&accelerationLineEdit, 3, 1);
    parameterGridLayout.addWidget(&accelerationUnitLabel, 3, 2);
    parameterGridLayout.addWidget(&decelerationLabel, 4, 0);
    parameterGridLayout.addWidget(&decelerationLineEdit, 4, 1);
    parameterGridLayout.addWidget(&decelerationUnitLabel, 4, 2);

    parameterGroupBox.setTitle("Parameter");
    parameterGridLayout.setMargin(margin);
    parameterGridLayout.setSpacing(space);
    parameterGroupBox.setLayout(&parameterGridLayout);
}

void AxisTab::initHomingGroupBox()
{
    homingDirCheckBox.setText("Dir. (CW)");
    homeSensorRadioButton.setText("Home");
    lowLimitRadioButton.setText("Lo. Limit");
    highLimitRadioButton.setText("Hi. Limit");
    zeroAtHomeCheckBox.setText("Zero At Home");
    zeroAfterHomeCheckBox.setText("Zero After Home");
    homeOffsetLabel.setText("Offset");
    homeOffsetLineEdit.setFixedWidth(80);
    homeOffsetLineEdit.setAlignment(Qt::AlignRight);
    homeOffsetUnitLabel.setText("mm");
    homingVelocityLabel.setText("Velocity");
    homingVelocityLineEdit.setFixedWidth(80);
    homingVelocityLineEdit.setAlignment(Qt::AlignRight);
    homingVelocityUnitLabel.setText("mm/s");

    homingGridLayout.addWidget(&homingDirCheckBox, 0, 0, 1, 2);
    homingGridLayout.addWidget(&zeroAtHomeCheckBox, 1, 0, 1, 2);
    homingGridLayout.addWidget(&zeroAfterHomeCheckBox, 2, 0, 1, 2);
    homingGridLayout.addWidget(&homeSensorRadioButton, 0, 2);
    homingGridLayout.addWidget(&lowLimitRadioButton, 1, 2);
    homingGridLayout.addWidget(&highLimitRadioButton, 2, 2);
    homingGridLayout.addWidget(&homeOffsetLabel, 3, 0);
    homingGridLayout.addWidget(&homeOffsetLineEdit, 3, 1);
    homingGridLayout.addWidget(&homeOffsetUnitLabel, 3, 2);
    homingGridLayout.addWidget(&homingVelocityLabel, 4, 0);
    homingGridLayout.addWidget(&homingVelocityLineEdit, 4, 1);
    homingGridLayout.addWidget(&homingVelocityUnitLabel, 4, 2);

    homingGroupBox.setTitle("Homing");
    homingGridLayout.setMargin(margin);
    homingGridLayout.setSpacing(space);
    homingGroupBox.setLayout(&homingGridLayout);
}

void AxisTab::initSigRevGroupBox()
{
    servoOnCheckBox.setText("Sv. On");
    servoInPosCheckBox.setText("Sv. In-pos");
    servoFaultCheckBox.setText("Sv. Fault");
    servoClearCheckBox.setText("Sv. Clear");
    homeSensorCheckBox.setText("Home");
    lowLimitCheckBox.setText("Lo. Limit");
    highLimitCheckBox.setText("Hi. Limit");

    sigRevGridLayout.addWidget(&servoOnCheckBox, 0, 0);
    sigRevGridLayout.addWidget(&servoInPosCheckBox, 1, 0);
    sigRevGridLayout.addWidget(&servoFaultCheckBox, 2, 0);
    sigRevGridLayout.addWidget(&servoClearCheckBox, 3, 0);
    sigRevGridLayout.addWidget(&homeSensorCheckBox, 0, 1);
    sigRevGridLayout.addWidget(&lowLimitCheckBox, 1, 1);
    sigRevGridLayout.addWidget(&highLimitCheckBox, 2, 1);

    sigRevGroupBox.setTitle("Signal Reversion");
    sigRevGridLayout.setMargin(margin);
    sigRevGridLayout.setSpacing(space);
    sigRevGroupBox.setLayout(&sigRevGridLayout);
}

void AxisTab::refresh(uint32_t data[])
{
    risingEdgeCheckBox.setChecked(data[0] & 0x0004);
    dirCCWCheckBox.setChecked(data[0] & 0x0008);
    softLimitEnableCheckBox.setChecked(data[0] & 0x0010);
    hardLimitEnableCheckBox.setChecked(data[0] & 0x0020);
    swapLowHighCheckBox.setChecked(data[0] & 0x0040);
    homingDirCheckBox.setChecked(data[0] & 0x0080);
    zeroAtHomeCheckBox.setChecked(data[0] & 0x0100);
    zeroAfterHomeCheckBox.setChecked(data[0] & 0x0200);
    lowLimitRadioButton.setChecked(data[0] & 0x0400);
    highLimitRadioButton.setChecked(data[0] & 0x0800);
    homeSensorRadioButton.setChecked(!(data[0] & 0x0C00));
    servoOnCheckBox.setChecked(data[0] & 0x1000);
    servoInPosCheckBox.setChecked(data[0] & 0x2000);
    servoFaultCheckBox.setChecked(data[0] & 0x4000);
    servoClearCheckBox.setChecked(data[0] & 0x8000);
    homeSensorCheckBox.setChecked(data[0] & 0x10000);
    lowLimitCheckBox.setChecked(data[0] & 0x20000);
    highLimitCheckBox.setChecked(data[0] & 0x40000);

    lowSoftLimitLineEdit.setText(QString::number((int) data[1]));
    highSoftLimitLineEdit.setText(QString::number((int) data[2]));
    moveLengthLineEdit.setText(QString::number(data[3] / 1000000000.0));
    velocityLineEdit.setText(QString::number(data[4]));
    accelerationLineEdit.setText(QString::number(data[5]));
    decelerationLineEdit.setText(QString::number(data[6]));
    homeOffsetLineEdit.setText(QString::number((int) data[7]));
    homingVelocityLineEdit.setText(QString::number((int) data[8]));
}
