#include "tablebuttongrid.h"
//#include <QGraphicsDropShadowEffect>

TableButtonGrid::TableButtonGrid(QObject *parent) : QObject(parent)
{
//    QGraphicsDropShadowEffect* gdse = new QGraphicsDropShadowEffect();

//    gdse->setBlurRadius(5);
//    gdse->setOffset(0);
//    gdse->setColor(QColor(0,0,0));

//    gridLayout.addWidget(&upPushButton,0,0);



}


QGridLayout* TableButtonGrid::getGridLayout()
{
    return &gridLayout;
}
