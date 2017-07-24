#ifndef TABLETAB_H
#define TABLETAB_H

#include <QPushButton>
#include <QTableWidget>
#include <QGridLayout>
#include <QLabel>
#include <QTableWidgetItem>
#include "tab.h"

struct RowData {
    public:
        QString getInstruction() {return instruction;}
        QString getType() {return type;}
        QString getOffset1() {return offset1;}
        QString getOffset2() {return offset2;}
        QString getOption() {return option;}
        int getMode() {return mode;}

        void setInstruction(QString _instruction){instruction = _instruction;}
        void setType(QString _type) {type = _type;}
        void setOffset1(QString _offset1) {offset1 = _offset1;}
        void setOffset2(QString _offset2) {offset2 = _offset2;}
        void setOption(QString _option) {option = _option;}
        void setMode(int _mode) {mode = _mode;}
    private:
        QString instruction;
        QString type;
        QString offset1;
        QString offset2;
        QString option;
        int mode = 1;//default insert mode
};

class TableTab : public Tab
{
    Q_OBJECT
public:
    TableTab(QObject *parent = nullptr);
    void insertRowTable();
    QTableWidget* getTableWidget();
    static int getMaxTableSize();

protected:
    QLabel tableLabel;

private:
    QTableWidget gcodeTableWidget;

    static const int table_Size = 2000;
};

#endif // TABLETAB_H
