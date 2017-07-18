#ifndef JOGTAB_H
#define JOGTAB_H

#include "tab.h"
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QSpinBox>
#include <QGridLayout>
#include <QGraphicsDropShadowEffect>
#include <QButtonGroup>

class JogTab : public Tab
{
    Q_OBJECT

public:
    JogTab(QObject *parent = nullptr);

signals:

public slots:
    void jogButton_clicked(int);
    void jogButton_pressed(int);
    void jogButton_released(int);

private:
    QButtonGroup jogButtonGroup;
};

#endif // JOGTAB_H
