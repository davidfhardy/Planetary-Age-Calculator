#pragma once

#include <QtWidgets/QWidget>
#include "ui_PlanetaryAge.h"
#include "QGridLayout"
#include "QFrame"
#include "Qlabel"
#include "QPushButton"
#include "QSpinBox"
#include "QComboBox"
#include "QMenuBar"
#include "QMenu"
#include "QSlider"

class PlanetaryAge : public QWidget
{
    Q_OBJECT

public:
    PlanetaryAge(QWidget *parent = Q_NULLPTR);

    void CalculateMercuryAge();
    void CalculateVenusAge();
    void CalculateMarsAge();
    void CalculateJupiterAge();
    void CalculateSaturnAge();
    void CalculateUranusAge();
    void CalculateNeptuneAge();
    void CalculatePlutoAge();
    void CalculateAll();

    void Reset();

private:
    Ui::PlanetaryAgeClass ui;

    // grid
    QGridLayout* grid;

    // frame
    QFrame* frame;
    QFrame* hline1;
    QFrame* hline2;
    QFrame* hline3;

    // menu
    QMenuBar* menubar;
    QMenu* menuFile;
    QMenu* menuEdit;
    QMenu* menuHelp;

    // labels
    QLabel* headerLabel;
    QLabel* dayLabel;
    QLabel* monthLabel;
    QLabel* yearLabel;

    QLabel* planetsLabel;
    QLabel* agesLabel;
    QLabel* mercuryLabel;
    QLabel* venusLabel;
    QLabel* marsLabel;
    QLabel* jupiterLabel;
    QLabel* saturnLabel;
    QLabel* uranusLabel;
    QLabel* neptuneLabel;
    QLabel* plutoLabel;

    QLabel* mercuryOutput;
    QLabel* venusOutput;
    QLabel* marsOutput;
    QLabel* jupiterOutput;
    QLabel* saturnOutput;
    QLabel* uranusOutput;
    QLabel* neptuneOutput;
    QLabel* plutoOutput;

    // spin boxes and combo boxes
    QSpinBox* dayInput;
    QComboBox* monthComboInput;
    QSpinBox* yearInput;

    // push buttons
    QPushButton* mercuryPb;
    QPushButton* venusPb;
    QPushButton* marsPb;
    QPushButton* jupiterPb;
    QPushButton* saturnPb;
    QPushButton* uranusPb;
    QPushButton* neptunePb;
    QPushButton* plutoPb;
    QPushButton* allPb;
};
