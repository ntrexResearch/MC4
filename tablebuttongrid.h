#ifndef TABLEBUTTONGRID_H
#define TABLEBUTTONGRID_H

#include <QObject>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QButtonGroup>
#include <QProgressBar>
#include "tabletab.h"

class TableButtonGrid : public QObject
{
    Q_OBJECT
public:
    TableButtonGrid(QObject *parent = nullptr);

    QGridLayout* getGridLayout();

private:
    QButtonGroup tableButtonGroup;
    QGridLayout gridLayout;
    QPushButton upPushButton;
    QPushButton downPushButton;
//    QPushButton addPushButton;
    QProgressBar saveProgressBar;
    QPushButton loadPushButton;
    QPushButton savePushButton;
    TableTab* tableTab[10];


signals:
    void updateTable(int);

public slots:
     void tableButton_released(int);

};

#endif // TABLEBUTTONGRID_H
