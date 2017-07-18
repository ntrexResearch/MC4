#include "connectiontab.h"

#include <QSerialPortInfo>
#include "axistab.h"


QList<QString> ConnectionTab::txBuffer;

ConnectionTab::ConnectionTab(QObject *parent) : Tab(parent)
{
    comPortLabel.setText("COM Port");
    comPortLabel.setFixedSize(60,20);
    comPortComboBox.setFixedSize(100,20);

    baudRateLabel.setText("Baud Rate");
    comPortLabel.setFixedSize(60,20);
    baudRateComboBox.setFixedSize(100,20);

    connectPushButton.setText("Connect");
    connectPushButton.setFixedSize(80,50);

    consolPlainTextEdit.setReadOnly(true);

    gridLayout.addWidget(&comPortLabel,0,0,Qt::AlignRight);
    gridLayout.addWidget(&comPortComboBox,0,1);
    gridLayout.addWidget(&baudRateLabel,1,0,Qt::AlignRight);
    gridLayout.addWidget(&baudRateComboBox,1,1);
    gridLayout.addWidget(&connectPushButton,0,2,2,1);
    gridLayout.addWidget(&consolPlainTextEdit,2,0,1,3);
    gridLayout.addWidget(&promptLineEdit,3,0,1,3);

    widget.setLayout(&gridLayout);

    QStringList baudRateList = { "9600", "19200", "38400", "115200", "230400", "460800"};

    baudRateComboBox.addItems(baudRateList);

    baudRateComboBox.setCurrentIndex(0);

    connect(&connectPushButton, SIGNAL(clicked(bool)), this, SLOT(connectPushButton_clicked()));
    connect(&promptLineEdit, SIGNAL(returnPressed()), this, SLOT(sendPrompt()));
    connect(&timer, SIGNAL(timeout()), this, SLOT(run()));
    timer.start(1);
}

void ConnectionTab::sendMessage(QString message)
{
    txBuffer.append(message + "\n");
}

void ConnectionTab::sendPrompt()
{
    if(!serialPort.isOpen())
        return;

    sendMessage(promptLineEdit.text());

    consol_flag = true;

    promptLineEdit.clear();
}

void ConnectionTab::run()
{
    if (comPortComboBox.isEnabled())
        refreshCOMPortList();

    if (!serialPort.isOpen())
        return;

    if (time_out > max_time_out)
    {
        consolPlainTextEdit.appendHtml("t/o");
        serialPort.clear();
        txBuffer.clear();
        time_out = rx_flag = rx_count = rx_index = proc_flag = consol_flag = 0;
    }

    switch (rx_flag)
    {
    case 0:
        writeBuffer();
        break;
    case 1:
    case 2:
        readBuffer();
        break;
    default:
        break;
    }
}

void ConnectionTab::writeBuffer()
{
    rx_flag = 1;

    if (txBuffer.isEmpty())
        sendMessage("pol");
    else if (consol_flag)
    {
        rx_flag = 2;
        consol_flag = false;
    }

    QString txString = txBuffer.first().toLatin1();

    setProcessFlag(txString);

    serialPort.write(txString.toLatin1());

    txBuffer.removeFirst();
}

void ConnectionTab::readBuffer()
{
    rx_index += serialPort.readLine(&rx_buffer[rx_index], Buffer_Size - rx_index);

    if ((rx_count && rx_count != rx_index) || rx_buffer[rx_index - 1] != ('\n'))
    {
        time_out++;

        return;
    }

    if (rx_flag == 2)
        consolPlainTextEdit.appendHtml((QString) rx_buffer);

    processRxBuffer();

    time_out = rx_flag = rx_count = rx_index = proc_flag = 0;
}

void ConnectionTab::processRxBuffer()
{
    switch (proc_flag)
    {
    case 1:  
    {
        QList<char> axiData;

        for (int i = 0; i < rx_index; i++)
            axiData.append(rx_buffer[i]);

        emit updateAxisTab(axiData);

        break;
    }
    case 2:
    {
        QList<uint32_t> dioData;

        dioData.append(*((uint32_t*) &rx_buffer[0]));

        emit updateDigitalIOTab(dioData);

        break;
    }
    case 3:
    {
        QList<uint32_t> polData;

        for (int i = 0; i < rx_index / 4; i++)
            polData.append(*((uint32_t*) &rx_buffer[4 * i]));

        emit updatePollingData(polData);

        break;
    }    
    default:
        break;
    }

    max_time_out = 100;
}

void ConnectionTab::setProcessFlag(QString txStr)
{
    if (txStr.contains("axi"))
    {
        rx_count = 43;

        proc_flag = 1;

        max_time_out = 100;
    }
    else if (txStr.contains("dio"))
    {
        rx_count = 10;

        proc_flag = 2;

        max_time_out = 40;
    }
    else if (txStr.contains("pol"))
    {
        rx_count = 46;

        proc_flag = 3;

        max_time_out = 100;
    }
}

void ConnectionTab::refreshCOMPortList()
{
    QList<QSerialPortInfo> spInfo = QSerialPortInfo::availablePorts();
    QStringList comPortList;

    bool flag = comPortComboBox.count() != spInfo.size();

    for (int i = 0; !flag && i < spInfo.size(); i++)
        if (comPortComboBox.itemText(i).compare(spInfo[i].portName()))
            flag = true;

    if (flag)
    {
        for (int i = 0; i < spInfo.size(); i++)
            comPortList.append(spInfo[i].portName());

        comPortComboBox.clear();

        comPortComboBox.addItems(comPortList);
    }
}

void ConnectionTab::connectPushButton_clicked()
{
    if(!serialPort.isOpen())
    {
        serialPort.setPortName(comPortComboBox.currentText());
        serialPort.setBaudRate(baudRateComboBox.currentText().toInt());
        serialPort.setDataBits(QSerialPort::Data8);
        serialPort.setParity(QSerialPort::NoParity);
        serialPort.setStopBits((QSerialPort::OneStop));
        serialPort.setFlowControl(QSerialPort::NoFlowControl);
        serialPort.open(QIODevice::ReadWrite);

        serialPort.clear();
        txBuffer.clear();

        for (int i = 0; i < Buffer_Size; i++)
            rx_buffer[i] = 0;

        time_out = rx_flag = rx_count = rx_index = proc_flag = consol_flag = 0;

        max_time_out = 100;
    }
    else
    {
        serialPort.clear();
        txBuffer.clear();

        serialPort.close();
    }

    if(!serialPort.isOpen())
    {
        comPortComboBox.setEnabled(true);
        baudRateComboBox.setEnabled(true);
        connectPushButton.setText("Connect");
    }
    else
    {
        comPortComboBox.setEnabled(false);
        baudRateComboBox.setEnabled(false);
        connectPushButton.setText("Disconnect");

        sendMessage("axi1");
        sendMessage("axi2");
        sendMessage("axi3");
        sendMessage("axi4");
        sendMessage("dio");
    }
}
