#include "tab.h"

Tab::Tab(QObject *parent) : QObject(parent)
{

}

QWidget* Tab::getWidget()
{
    return &widget;
}
