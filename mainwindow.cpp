#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "xaxistab.h"
#include "yaxistab.h"
#include "zaxistab.h"
#include "haxistab.h"
#include "table1tab.h"
#include "table2tab.h"
#include "table3tab.h"
#include "table4tab.h"
#include "table5tab.h"
#include "table6tab.h"
#include "table7tab.h"
#include "table8tab.h"
#include "table9tab.h"
#include "table10tab.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setGeometry(100,100,1120,880);

    ui->scrollArea->setGeometry(10,10,1072,809);

    connectionTab = new ConnectionTab(ui->deviceTabWidget);
    axisTab[0] = new XAxisTab(ui->deviceTabWidget);
    axisTab[1] = new YAxisTab(ui->deviceTabWidget);
    axisTab[2] = new ZAxisTab(ui->deviceTabWidget);
    axisTab[3] = new HAxisTab(ui->deviceTabWidget);
    dioTab = new DIOTab(ui->deviceTabWidget);
    monitorTab = new MonitorTab(ui->deviceTabWidget);
    controlStatusGrid = new ControlStatusGrid(ui->controlTabWidget);

    jogTab = new JogTab(ui->controlTabWidget);
    controlMotionTab = new ControlMotionTab(ui->controlTabWidget);

    tableTab[0] = new Table1Tab(ui->tableTabWidget);
    tableTab[1] = new Table2Tab(ui->tableTabWidget);
    tableTab[2] = new Table3Tab(ui->tableTabWidget);
    tableTab[3] = new Table4Tab(ui->tableTabWidget);
    tableTab[4] = new Table5Tab(ui->tableTabWidget);
    tableTab[5] = new Table6Tab(ui->tableTabWidget);
    tableTab[6] = new Table7Tab(ui->tableTabWidget);
    tableTab[7] = new Table8Tab(ui->tableTabWidget);
    tableTab[8] = new Table9Tab(ui->tableTabWidget);
    tableTab[9] = new Table10Tab(ui->tableTabWidget);
    tableButtonGrid = new TableButtonGrid(ui->tableTabWidget);
    editorMotionTab = new EditorMotionTab(ui->editorTabWidget);

    ui->deviceTabWidget->addTab(connectionTab->getWidget(), "Connection");
    ui->deviceTabWidget->addTab(axisTab[0]->getWidget(), "X");
    ui->deviceTabWidget->addTab(axisTab[1]->getWidget(), "Y");
    ui->deviceTabWidget->addTab(axisTab[2]->getWidget(), "Z");
    ui->deviceTabWidget->addTab(axisTab[3]->getWidget(), "H");
    ui->deviceTabWidget->addTab(dioTab->getWidget(), "D.I/O");
    ui->deviceTabWidget->addTab(monitorTab->getWidget(), "Monitor");

    ui->tableTabWidget->addTab(tableTab[0]->getWidget(),"1");
    ui->tableTabWidget->addTab(tableTab[1]->getWidget(),"2");
    ui->tableTabWidget->addTab(tableTab[2]->getWidget(),"3");
    ui->tableTabWidget->addTab(tableTab[3]->getWidget(),"4");
    ui->tableTabWidget->addTab(tableTab[4]->getWidget(),"5");
    ui->tableTabWidget->addTab(tableTab[5]->getWidget(),"6");
    ui->tableTabWidget->addTab(tableTab[6]->getWidget(),"7");
    ui->tableTabWidget->addTab(tableTab[7]->getWidget(),"8");
    ui->tableTabWidget->addTab(tableTab[8]->getWidget(),"9");
    ui->tableTabWidget->addTab(tableTab[9]->getWidget(),"10");
    ui->tableButtonWidget->setLayout(tableButtonGrid->getGridLayout());

    ui->editorTabWidget->addTab(editorMotionTab->getWidget(),"Motion");
    //ui->editorButtonWidget->setLayout(editorButtonGrid->getGridLayout());

    ui->controlStatusWidget->setLayout(controlStatusGrid->getGridLayout());
    ui->controlTabWidget->addTab(jogTab->getWidget(), "Jog");
    ui->controlTabWidget->addTab(controlMotionTab->getWidget(), "Motion");

    //Emit signal when button is clicked
    QObject::connect(tableButtonGrid, SIGNAL(tableButtonClicked(int)), this, SLOT(tableButtonClicked(int)));
    QObject::connect(editorMotionTab, SIGNAL(editorButtonClicked(RowData)), this, SLOT(editorButtonClicked(RowData)));
    QObject::connect(ui->deviceTabWidget, SIGNAL(tabBarClicked(int)), this, SLOT(deviceTab_clicked(int)));
    QObject::connect(connectionTab, SIGNAL(updateAxisTab(QList<char>)), this, SLOT(updateAxisTab(QList<char>)));
    QObject::connect(connectionTab, SIGNAL(updateDigitalIOTab(QList<uint32_t>)), this, SLOT(updateDigitalIOTab(QList<uint32_t>)));
    QObject::connect(connectionTab, SIGNAL(updatePollingData(QList<uint32_t>)), this, SLOT(updatePollingData(QList<uint32_t>)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::deviceTab_clicked(int tab_id)
{
    switch (tab_id)
    {
    case 1:
    case 2:
    case 3:
    case 4:
        ConnectionTab::sendMessage("axi" + QString::number(tab_id));
        break;
    case 5:
        ConnectionTab::sendMessage("dio" + QString::number(tab_id));
    default:
        break;
    }
}

void MainWindow::updateAxisTab(QList<char> axiData)
{
    int size = axiData.size();
    uint8_t axis_data[size];
    uint32_t data[size / 4];

    for (int i = 0; i < axiData.size(); i++)
    {
        axis_data[i] = axiData[i];

        if (i % 4 == 3)
            data[i / 4] = *((uint32_t*) &axis_data[i - 3]);
    }

    axisTab[data[0] & 0x03]->refresh(data);
}

void MainWindow::updateDigitalIOTab(QList<uint32_t> dirData)
{
    dioTab->refreshSigRev(dirData[0]);
}

void MainWindow::updatePollingData(QList<uint32_t> polData)
{
    dioTab->refreshStatus(polData[9]);
}

void MainWindow::tableButtonClicked(int button_id)
{
    switch(button_id)
    {
    case 0://save
        qDebug()<<"save clicked";
        break;
    case 1://load
        qDebug()<<"load clicked";
        break;

    case 2://up
        tableTab[currentTabIndex]->getTableWidget()->setFocus();
        tableTab[currentTabIndex]->getTableWidget()->selectRow(
                    tableTab[currentTabIndex]->getTableWidget()->currentRow()-1);
        qDebug()<<"up clicked";
        break;
    case 3://down
        qDebug()<<"down clicked";
        tableTab[currentTabIndex]->getTableWidget()->setFocus();
        tableTab[currentTabIndex]->getTableWidget()->selectRow(
                    tableTab[currentTabIndex]->getTableWidget()->currentRow()+1);
        break;
    default:
        break;
    }
}

void MainWindow::editorButtonClicked(RowData rowData)
{
    qDebug()<<rowData.getInstruction();
    qDebug()<<rowData.getMode();
    if (rowData.getMode() == 0)//add mode
    {
        tableTab[currentTabIndex]-> getTableWidget()-> setFocus();
        if(tableTab[currentTabIndex]-> getTableWidget()-> rowCount() < TableTab::getMaxTableSize())
            tableTab[currentTabIndex]-> getTableWidget()-> insertRow(
                    tableTab[currentTabIndex]-> getTableWidget()-> rowCount());
        tableTab[currentTabIndex]->getTableWidget()->setItem(
                    tableTab[currentTabIndex]-> getTableWidget()-> rowCount()-1, 0,
                    new QTableWidgetItem(rowData.getInstruction()));
        tableTab[currentTabIndex]->getTableWidget()->setItem(
                    tableTab[currentTabIndex]-> getTableWidget()-> rowCount()-1, 1,
                    new QTableWidgetItem(rowData.getType()));
        tableTab[currentTabIndex]->getTableWidget()->setCurrentCell(
                    tableTab[currentTabIndex]->getTableWidget()->rowCount()-1, 0);
    }
//    switch(button_id)
//    {

//    case 0://
//        qDebug() << "parameter add button clicked";

//        tableTab[currentTabIndex]-> getTableWidget()-> setFocus();
//        if(tableTab[currentTabIndex]-> getTableWidget()-> rowCount() < TableTab::getMaxTableSize())
//            tableTab[currentTabIndex]-> getTableWidget()-> insertRow(
//                    tableTab[currentTabIndex]-> getTableWidget()-> rowCount());
//        tableTab[currentTabIndex]->getTableWidget()->setItem(
//                    tableTab[currentTabIndex]-> getTableWidget()-> rowCount()-1, 1, new QTableWidgetItem(rowData.getInstruction()));
//        break;
//    case 1:
//        qDebug() << "parameter insert button clicked";
//        tableTab[currentTabIndex]->getTableWidget()->setFocus();
//        if(tableTab[currentTabIndex]-> getTableWidget()-> rowCount() < TableTab::getMaxTableSize())
//            tableTab[currentTabIndex]->getTableWidget()->insertRow(
//                    tableTab[currentTabIndex]-> getTableWidget()-> currentRow()+1);
//        break;
//    case 2:
//        qDebug() << "single add button clicked";
//        break;
//    case 3:
//        qDebug() << "single insert button clicked";
//        break;
//    case 4:
//        qDebug() << "action add button clicked";
//        break;
//    case 5:
//        qDebug() << "action insert button clicked";
//        break;
//    case 6:
//        qDebug() << "motion add button clicked";
//        break;
//    case 7:
//        qDebug() << "motion insert button clicked";
//        break;

//    default:
//        break;

//    }
}

void MainWindow::on_tableTabWidget_tabBarClicked(int index)
{
    //Track the active table tab
    currentTabIndex = index;
}

//void MainWindow::
