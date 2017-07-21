#ifndef TABLEBUTTONGRID_H
#define TABLEBUTTONGRID_H

#include <QObject>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QButtonGroup>
#include <QProgressBar>

class TableButtonGrid : public QObject
{
    Q_OBJECT
public:
    TableButtonGrid(QObject *parent = nullptr);
    QGridLayout* getGridLayout();


public slots:
     void tableButton_released(int);


signals:
    void tableButtonClicked(int);

private:
    QButtonGroup tableButtonGroup;
    QGridLayout gridLayout;
    QPushButton upPushButton;
    QPushButton downPushButton;
    QProgressBar saveProgressBar;
    QPushButton loadPushButton;
    QPushButton savePushButton;
};

#endif // TABLEBUTTONGRID_H
