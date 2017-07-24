#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "connectiontab.h"
#include "axistab.h"
#include "diotab.h"
#include "monitortab.h"
#include "jogtab.h"
#include "controlmotiontab.h"
#include "tabletab.h"
#include "editormotiontab.h"
#include "controlstatusgrid.h"
#include "tablebuttongrid.h"


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
    void tableButtonClicked(int);
    void editorButtonClicked(RowData);

private slots:
    void on_tableTabWidget_tabBarClicked(int index);

private:
    ConnectionTab* connectionTab;
    AxisTab* axisTab[4];
    DIOTab* dioTab;
    MonitorTab* monitorTab;
    ControlStatusGrid* controlStatusGrid;
    TableButtonGrid* tableButtonGrid;
    JogTab* jogTab;
    ControlMotionTab* controlMotionTab;
    EditorMotionTab* editorMotionTab;
    TableTab* tableTab[10];
    int currentTabIndex = 0;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
