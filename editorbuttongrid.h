#ifndef EDITORBUTTONGRID_H
#define EDITORBUTTONGRID_H

#include <QObject>
#include <QGridLayout>
#include <QPushButton>
#include <QButtonGroup>

class EditorButtonGrid : public QObject
{
    Q_OBJECT
public:
    EditorButtonGrid(QObject *parent = nullptr);
    QGridLayout* getGridLayout();

public slots:
    void editorButton_released(int);

signals:
    void editorButtonClicked(int);

private:
    QPushButton addPushButton;
    QPushButton insertPushButton;
    QButtonGroup editorButtonGroup;
    QGridLayout gridLayout;

};

#endif // EDITORBUTTONGRID_H
