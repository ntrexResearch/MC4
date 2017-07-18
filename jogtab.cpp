#include "jogtab.h"
#include <QWidget>
#include "connectiontab.h"

JogTab::JogTab(QObject *parent) : Tab(parent)
{
    for (int i = 0; i < 4; i++)
    {
        QPushButton* goPushButton = new QPushButton();
        QPushButton* plusPushButton = new QPushButton();
        QPushButton* minusPushButton = new QPushButton();
        QPushButton* homePushButton = new QPushButton();

        jogButtonGroup.addButton(goPushButton, i + 0);
        jogButtonGroup.addButton(plusPushButton, i + 1);
        jogButtonGroup.addButton(minusPushButton, i + 2);
        jogButtonGroup.addButton(homePushButton, i + 3);

        goPushButton->setFixedSize(60, 60);
        plusPushButton->setFixedSize(60, 60);
        minusPushButton->setFixedSize(60, 60);
        homePushButton->setFixedSize(60, 60);

        goPushButton->setIcon(QIcon(":/images/play.jpg"));
        plusPushButton->setIcon(QIcon(":/images/plus.jpg"));
        minusPushButton->setIcon(QIcon(":/images/minus.jpg"));
        homePushButton->setIcon(QIcon(":/images/home.jpg"));

        goPushButton->setIconSize(QSize(55, 55));
        plusPushButton->setIconSize(QSize(55, 55));
        minusPushButton->setIconSize(QSize(55, 55));
        homePushButton->setIconSize(QSize(55, 55));

        gridLayout.addWidget(goPushButton, i, 0);
        gridLayout.addWidget(plusPushButton, i, 1);
        gridLayout.addWidget(minusPushButton, i, 2);
        gridLayout.addWidget(homePushButton, i, 3);
    }

    gridLayout.setMargin(5);
    gridLayout.setHorizontalSpacing(0);
    gridLayout.setVerticalSpacing(20);
    widget.setLayout(&gridLayout);

    connect(&jogButtonGroup, SIGNAL(buttonClicked(int)), this, SLOT(jogButton_clicked(int)));
    connect(&jogButtonGroup, SIGNAL(buttonPressed(int)), this, SLOT(jogButton_pressed(int)));
    connect(&jogButtonGroup, SIGNAL(buttonReleased(int)), this, SLOT(jogButton_released(int)));
}

void JogTab::jogButton_clicked(int button_id)
{
    int axis_id = button_id / 4;

    QString message;

    QString idStr = QString::number(axis_id + 1);

    switch (button_id % 4)
    {
    case 0:

        break;
    case 1:

        break;
    case 2:

        break;
    case 3:

        break;
    default:
        return;
    }

    ConnectionTab::sendMessage(message);
}

void JogTab::jogButton_pressed(int button_id)
{
    int axis_id = button_id / 4;

    QString message;

    QString idStr = QString::number(axis_id + 1);

    switch (button_id % 4)
    {
    case 1:

        break;
    case 2:

        break;
    default:
        return;
    }

    ConnectionTab::sendMessage(message);
}

void JogTab::jogButton_released(int button_id)
{
    int axis_id = button_id / 4;

    QString message;

    QString idStr = QString::number(axis_id + 1);

    switch (button_id % 4)
    {
    case 1:
        button_id++;
    case 2:

        break;
    default:
        return;
    }

    ConnectionTab::sendMessage(message);
}
