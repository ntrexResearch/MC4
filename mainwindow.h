#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "connectiontab.h"
#include "axistab.h"
#include "diotab.h"
#include "monitortab.h"
#include "jogtab.h"
#include "motiontab.h"
#include "tabletab.h"
#include "controlstatusgrid.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void deviceTab_clicked(int);
    void updateAxisTab(QList<char>);
    void updateDigitalIOTab(QList<uint32_t>);
    void updatePollingData(QList<uint32_t>);

private:
    ConnectionTab* connectionTab;
    AxisTab* axisTab[4];
    DIOTab* dioTab;
    MonitorTab* monitorTab;
    ControlStatusGrid* controlStatusGrid;
    tableButtonGrid* tableButtonGrid;
    JogTab* jogTab;
    MotionTab* motionTab;
    TableTab* tableTab[10];

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
