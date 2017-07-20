#ifndef EDITORMOTIONTAB_H
#define EDITORMOTIONTAB_H

#include "tab.h"
#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QSpinBox>
#include <QGroupBox>
#include <QLabel>
#include <QComboBox>


class EditorMotionTab : public Tab
{
    Q_OBJECT
public:
    EditorMotionTab(QObject *parent = nullptr);

private:
    static const int margin = 4;
    static const int space = 5;

    QComboBox optionComboBox;
    QLabel optionLabel;

    QGroupBox offset1GroupBox;
    QGridLayout offset1GridLayout;
    QLineEdit offset1LineEdits[4];
    QLabel axis1Labels[4];
    QLabel unit1Labels[4];

    QGroupBox offset2GroupBox;
    QGridLayout offset2GridLayout;
    QLineEdit offset2LineEdits[4];
    QLabel axis2Labels[4];
    QLabel unit2Labels[4];

    QLabel radiusLabel;
    QLineEdit radiusLineEdit;
    QLabel unit3Label;

    QLabel blendLabel;
    QSpinBox blendSpinBox;
    QLabel unit4Label;


    void initOptionComboBox();
    void initOffset1GroupBox();
    void initOffset2GroupBox();
    void initRadiusGroupBox();
    void initBlendGroupBox();

};

#endif // EDITORMOTION_H
