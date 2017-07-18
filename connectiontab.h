#ifndef CONNECTIONTAB_H
#define CONNECTIONTAB_H

#include "qserialport.h"
#include <QLineEdit>
#include <QSerialPort>
#include <QTimer>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QComboBox>
#include <QLabel>
#include "tab.h"

class ConnectionTab : public Tab
{
    Q_OBJECT

public:
    ConnectionTab(QObject *parent = nullptr);

    static void sendMessage(QString);

signals:
    void updateAxisTab(QList<char>);
    void updateDigitalIOTab(QList<uint32_t>);
    void updatePollingData(QList<uint32_t>);

public slots:
    void run();
    void connectPushButton_clicked();
    void sendPrompt();

private:
    static const int Buffer_Size = 1024;
    QPlainTextEdit consolPlainTextEdit;
    QLineEdit promptLineEdit;
    QPushButton connectPushButton;
    QComboBox comPortComboBox;
    QComboBox baudRateComboBox;

    QSerialPort serialPort;
    QLabel comPortLabel;
    QLabel baudRateLabel;


    int rx_flag;
    int rx_index;
    int rx_count;
    int proc_flag;
    bool consol_flag;
    char rx_buffer[Buffer_Size];
    static QList<QString> txBuffer;

    QTimer timer;

    int max_time_out;
    int time_out;

    void refreshCOMPortList();
    void writeBuffer();
    void readBuffer();
    void processRxBuffer();
    void setProcessFlag(QString);
};

#endif // CONNECTIONTAB_H
