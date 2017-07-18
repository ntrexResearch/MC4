#ifndef CONTROLSTATUSGRID_H
#define CONTROLSTATUSGRID_H

#include <QObject>
#include <QLabel>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QButtonGroup>
#include <QGridLayout>

class ControlStatusGrid : public QObject
{
    Q_OBJECT
public:
    ControlStatusGrid(QObject *parent = nullptr);

    QGridLayout* getGridLayout();
signals:

public slots:

private:
    int axis_status[4];

    QGridLayout gridLayout;

    QString normal_style = "font-size: 40px;""border-radius: 10px;""background-color: white;""color: black;";
    QString sv_off_style = "font-size: 40px;""border-radius: 10px;""background-color: lightgrey;""color: grey;";
    QString sv_fault_style = "font-size: 40px;""border-radius: 10px;""background-color: red;""color: white;";
    QString deactive_style = "font: bold;""border-radius: 5px;""background-color: lightgrey;""color: grey;";
    QString in_pos_style = "font: bold;""border-radius: 5px;""background-color: rgb(40, 200, 40);""color: rgb(240, 240, 240);";
    QString sen_on_style = "font: bold;""border-radius: 5px;""background-color: orange;""color: rgb(240, 240, 240);";

    QButtonGroup axisButtonGroup;
    QButtonGroup vpButtonGroup;

    QLabel inPosLabels[4];
    QLabel sensorLabels[4];

    QLabel posLabels[4];
    QLineEdit posLineEdits[4];
    QLabel posUnitLabels[4];
    QLabel velLabels[4];
    QLineEdit velLineEdits[4];
    QLabel velUnitLabels[4];
    QDoubleSpinBox vpSpinBox[4];
    QLabel vpUnitLabels[4];
};

#endif // CONTROLSTATUSGRID_H
