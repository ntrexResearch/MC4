#ifndef DIOTAB_H
#define DIOTAB_H

#include "tab.h"
#include <QGroupBox>
#include <QLabel>
#include <QCheckBox>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QButtonGroup>

class DIOTab : public Tab
{
    Q_OBJECT
public:
    DIOTab(QObject *parent = nullptr);

    void refreshStatus(uint32_t);
    void refreshSigRev(uint32_t);

public slots:
    void inputSigRevCheckBox_clicked(int, bool);
    void outputOnOffPushButton_clicked(int);
    void outputSigRevCheckBox_clicked(int, bool);

private:
    static const int Max_IO = 16;
    QString high_style = "font: bold;""border-radius: 5px;""background-color: rgb(40, 200, 40);""color: rgb(240, 240, 240);";
    QString low_style = "font: bold;""border-radius: 5px;""background-color: lightgrey;""color: grey;";
    QString on_style = "font: bold;""border-radius: 5px;""background-color: lightblue;""color: white;";
    QString off_style = "font: bold;""border-radius: 5px;""background-color: lightgrey;""color: grey;";

    QGroupBox inputGroupBox;
    QGridLayout inputGridLayout;
    QLabel inputLabels[Max_IO];
    QComboBox inputComboBoxes[Max_IO];
    QLineEdit inputLineEdits[Max_IO];
    QButtonGroup inputSigRevCheckBoxGroup;

    QGroupBox outputGroupBox;
    QGridLayout outputGridLayout;
    QLabel outputLabels[Max_IO];
    QButtonGroup outputOnOffPushButtonGroup;
    QButtonGroup outputSigRevCheckBoxGroup;

    void initInputGroupBox();
    void initOutputGroupBox();
};

#endif // DIOTAB_H
