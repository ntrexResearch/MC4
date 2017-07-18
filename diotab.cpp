#include "diotab.h"
#include "connectiontab.h"

DIOTab::DIOTab(QObject *parent) : Tab(parent)
{
    initInputGroupBox();
    initOutputGroupBox();

    widget.setLayout(&gridLayout);
}

void DIOTab::initInputGroupBox()
{
    QStringList cmdList = { "N/A", "GP", "GPR1", "GV", "GVI" };

    for (int i = 0; i < Max_IO; i++)
    {
        QCheckBox* sigRevCheckBox = new QCheckBox();

        inputLabels[i].setText(QString::number(i + 1));
        inputLabels[i].setStyleSheet(low_style);
        inputLabels[i].setFixedHeight(20);
        inputLabels[i].setFixedWidth(20);
        inputLabels[i].setAlignment(Qt::AlignCenter);
        inputComboBoxes[i].addItems(cmdList);
        inputComboBoxes[i].setFixedHeight(20);
        inputLineEdits[i].setFixedHeight(20);
        inputLineEdits[i].setFixedWidth(80);

        inputSigRevCheckBoxGroup.addButton(sigRevCheckBox, i);

        inputGridLayout.addWidget(&inputLabels[i], i % 8, 5 * (i / 8) + 0);
        inputGridLayout.addWidget(&inputComboBoxes[i], i % 8, 5 * (i / 8) + 1);
        inputGridLayout.addWidget(&inputLineEdits[i], i % 8, 5 * (i / 8) + 2, 1, 2);
        inputGridLayout.addWidget(sigRevCheckBox, i % 8, 5 * (i / 8) + 4);
    }

    inputSigRevCheckBoxGroup.setExclusive(false);

    inputGroupBox.setTitle("Input");

    inputGridLayout.setColumnMinimumWidth(4, 24);
    inputGridLayout.setVerticalSpacing(1);
    inputGridLayout.setHorizontalSpacing(5);

    inputGroupBox.setLayout(&inputGridLayout);
    gridLayout.addWidget(&inputGroupBox, 0, 0);
}

void DIOTab::initOutputGroupBox()
{
    for (int i = 0; i < Max_IO; i++)
    {
        QPushButton* onOffPushButton = new QPushButton();
        QCheckBox* sigRevCheckBox = new QCheckBox();

        outputOnOffPushButtonGroup.addButton(onOffPushButton, i);
        outputSigRevCheckBoxGroup.addButton(sigRevCheckBox, i);

        outputLabels[i].setText(QString::number(i + 1));
        outputLabels[i].setStyleSheet(low_style);
        outputLabels[i].setFixedHeight(20);
        outputLabels[i].setFixedWidth(20);
        outputLabels[i].setAlignment(Qt::AlignCenter);

        onOffPushButton->setText("Off");
        onOffPushButton->setStyleSheet(off_style);
        onOffPushButton->setFixedHeight(20);
        onOffPushButton->setFixedWidth(35);

        outputGridLayout.addWidget(&outputLabels[i], i % 4, 4 * (i / 4) + 0);
        outputGridLayout.addWidget(onOffPushButton, i % 4, 4 * (i / 4) + 1);
        outputGridLayout.addWidget(sigRevCheckBox, i % 4, 4 * (i / 4) + 2);
    }

    outputSigRevCheckBoxGroup.setExclusive(false);

    outputGridLayout.setColumnMinimumWidth(4, 10);
    outputGridLayout.setColumnMinimumWidth(9, 10);
    outputGridLayout.setVerticalSpacing(0);
    outputGridLayout.setHorizontalSpacing(10);

    outputGroupBox.setLayout(&outputGridLayout);
    gridLayout.addWidget(&outputGroupBox, 1, 0);

    connect(&inputSigRevCheckBoxGroup, SIGNAL(buttonToggled(int,bool)), this, SLOT(inputSigRevCheckBox_clicked(int,bool)));
    connect(&outputOnOffPushButtonGroup, SIGNAL(buttonClicked(int)), this, SLOT(outputOnOffPushButton_clicked(int)));
    connect(&outputSigRevCheckBoxGroup, SIGNAL(buttonToggled(int,bool)), this, SLOT(outputSigRevCheckBox_clicked(int,bool)));
}

void DIOTab::refreshStatus(uint32_t dio_data)
{    
    for (int i = 0; i < Max_IO; i++)
    {
        if (dio_data & 0x1)
            inputLabels[i].setStyleSheet(high_style);
        else
            inputLabels[i].setStyleSheet(low_style);

        dio_data >>= 1;

        if (dio_data & 0x1)
            outputLabels[i].setStyleSheet(high_style);
        else
            outputLabels[i].setStyleSheet(low_style);

        if ((dio_data & 0x1) != outputSigRevCheckBoxGroup.button(i)->isChecked())
        {
            outputOnOffPushButtonGroup.button(i)->setText("On");
            outputOnOffPushButtonGroup.button(i)->setStyleSheet(on_style);
        }
        else
        {
            outputOnOffPushButtonGroup.button(i)->setText("Off");
            outputOnOffPushButtonGroup.button(i)->setStyleSheet(off_style);
        }

        dio_data >>= 1;
    }
}

void DIOTab::refreshSigRev(uint32_t sig_rev_data)
{
    for (int i = 0; i < Max_IO; i++)
    {
        inputSigRevCheckBoxGroup.button(i)->setChecked(sig_rev_data & 0x1);

        sig_rev_data >>= 1;

        outputSigRevCheckBoxGroup.button(i)->setChecked(!(sig_rev_data & 0x1));

        sig_rev_data >>= 1;
    }
}

void DIOTab::inputSigRevCheckBox_clicked(int checkBox_id, bool checked)
{
    if (checked)
        ConnectionTab::sendMessage("dia" + QString::number(checkBox_id + 1) + "=1");
    else
        ConnectionTab::sendMessage("dia" + QString::number(checkBox_id + 1) + "=0");
}

void DIOTab::outputOnOffPushButton_clicked(int button_id)
{
    QAbstractButton* outputOnOffPushButton = outputOnOffPushButtonGroup.button(button_id);

    if (outputOnOffPushButton->text().contains("On"))
        ConnectionTab::sendMessage("dol" + QString::number(button_id + 1) + "=0");
    else if (outputOnOffPushButton->text().contains("Off"))
        ConnectionTab::sendMessage("dol" + QString::number(button_id + 1) + "=1");
}

void DIOTab::outputSigRevCheckBox_clicked(int checkBox_id, bool checked)
{
    if (checked)
        ConnectionTab::sendMessage("doa" + QString::number(checkBox_id + 1) + "=0");
    else
        ConnectionTab::sendMessage("doa" + QString::number(checkBox_id + 1) + "=1");
}
