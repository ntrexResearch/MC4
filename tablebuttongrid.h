#ifndef TABLEBUTTONGRID_H
#define TABLEBUTTONGRID_H

#include <QObject>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QButtonGroup>


class TableButtonGrid : public QObject
{
    Q_OBJECT
public:
    TableButtonGrid(QObject *parent = nullptr);

    QGridLayout* getGridLayout();

private:
//QButtonGroup tableButtonGroup;
    QGridLayout gridLayout;

    QPushButton upPushButton;
};

#endif // TABLEBUTTONGRID_H
