#ifndef TAB_H
#define TAB_H

#include <QObject>
#include <QWidget>
#include <QGridLayout>

class Tab : public QObject
{
public:
    Tab(QObject *parent = nullptr);

    QWidget* getWidget();

protected:
    QWidget widget;
    QGridLayout gridLayout;
};

#endif // TAB_H
