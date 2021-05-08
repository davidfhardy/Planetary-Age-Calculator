#include "PlanetaryAge.h"

PlanetaryAge::PlanetaryAge(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    // define grid
    grid = new QGridLayout(this);
    grid->setAlignment(Qt::AlignTop);
    grid->setHorizontalSpacing(10);

    // define frame
    frame = new QFrame();
    hline1 = new QFrame();
    hline2 = new QFrame();
    hline3 = new QFrame();
    frame->setFrameStyle(QFrame::Box);
    hline1->setFrameStyle(QFrame::HLine);
    hline2->setFrameStyle(QFrame::HLine);
    hline3->setFrameStyle(QFrame::HLine);
    grid->addWidget(frame, 0, 0);
    grid->addWidget(hline1, 2, 0);
    grid->addWidget(hline2, 2, 1);
    grid->addWidget(hline3, 2, 2);

    // define menu
    menubar = new QMenuBar();
    grid->setMenuBar(menubar);

    // define "File" tab in the menu bar
    menuFile = menubar->addMenu("&File");
    // add "Reset" action to restart the program
    QAction* reset = new QAction("&Reset", this);
    // add "Quit" action 
    QAction* quit = new QAction("&Quit", this);
    connect(reset, &QAction::triggered, this, &PlanetaryAge::Reset);
    connect(quit, &QAction::triggered, qApp, &QApplication::quit);
    menuFile->addAction(reset);
    menuFile->addAction(quit);


    // set shortcuts
    quit->setShortcut(tr("CTRL+Q"));
    reset->setShortcut(tr("CTRL+R"));

    // define "Edit" tab in menu bar
    menuEdit = menubar->addMenu("&Edit");
    menuEdit->addAction(reset);

    // define "Help" tab in menu bar
    menuHelp = menubar->addMenu("&Help");
    QAction* helpStuff = new QAction("Enter your birth information and press the calculate button!", this);
    menuHelp->addAction(helpStuff);


    // define labels for birth information
    headerLabel = new QLabel("Enter your birthday on Earth", this);
    dayLabel = new QLabel("Day:", this);
    monthLabel = new QLabel("Month:", this);
    yearLabel = new QLabel("Year:", this);
    grid->addWidget(headerLabel, 0, 0, Qt::AlignLeft);
    grid->addWidget(dayLabel, 1, 0, Qt::AlignLeft);
    grid->addWidget(monthLabel, 1, 1, Qt::AlignLeft);
    grid->addWidget(yearLabel, 1, 2, Qt::AlignLeft);

    // define spinboxes/inputs for birth information
    QStringList months = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
    dayInput = new QSpinBox;
    monthComboInput = new QComboBox;
    yearInput = new QSpinBox;
    monthComboInput->addItems(months);
    dayInput->setRange(1, 31);
    yearInput->setRange(1, 2020);   // max should be whatever the current year is
    yearInput->setValue(2000);      // set the default to be the year 2000
    grid->addWidget(dayInput, 1, 0, Qt::AlignHCenter);
    grid->addWidget(monthComboInput, 1, 1, Qt::AlignHCenter);
    grid->addWidget(yearInput, 1, 2, Qt::AlignHCenter);

    // define labels for planet
    planetsLabel = new QLabel("PLANETS", this);
    agesLabel = new QLabel("AGE", this);
    mercuryLabel = new QLabel("Mercury", this);
    venusLabel = new QLabel("Venus", this);
    marsLabel = new QLabel("Mars", this);
    jupiterLabel = new QLabel("Jupiter", this);
    saturnLabel = new QLabel("Saturn", this);
    uranusLabel = new QLabel("Uranus", this);
    neptuneLabel = new QLabel("Neptune", this);
    plutoLabel = new QLabel("Pluto", this);
    grid->addWidget(planetsLabel, 3, 0, Qt::AlignLeft);
    grid->addWidget(agesLabel, 3, 1, Qt::AlignHCenter);
    grid->addWidget(mercuryLabel, 4, 0, Qt::AlignLeft);
    grid->addWidget(venusLabel, 5, 0, Qt::AlignLeft);
    grid->addWidget(marsLabel, 6, 0, Qt::AlignLeft);
    grid->addWidget(jupiterLabel, 7, 0, Qt::AlignLeft);
    grid->addWidget(saturnLabel, 8, 0, Qt::AlignLeft);
    grid->addWidget(uranusLabel, 9, 0, Qt::AlignLeft);
    grid->addWidget(neptuneLabel, 10, 0, Qt::AlignLeft);
    grid->addWidget(plutoLabel, 11, 0, Qt::AlignLeft);

    // define pushbuttons
    mercuryPb = new QPushButton("Calculate", this);
    venusPb = new QPushButton("Calculate", this);
    marsPb = new QPushButton("Calculate", this);
    jupiterPb = new QPushButton("Calculate", this);
    saturnPb = new QPushButton("Calculate", this);
    uranusPb = new QPushButton("Calculate", this);
    neptunePb = new QPushButton("Calculate", this);
    plutoPb = new QPushButton("Calculate", this);
    allPb = new QPushButton("Calculate All", this);
    grid->addWidget(mercuryPb, 4, 0, Qt::AlignHCenter);
    grid->addWidget(venusPb, 5, 0, Qt::AlignHCenter);
    grid->addWidget(marsPb, 6, 0, Qt::AlignHCenter);
    grid->addWidget(jupiterPb, 7, 0, Qt::AlignHCenter);
    grid->addWidget(saturnPb, 8, 0, Qt::AlignHCenter);
    grid->addWidget(uranusPb, 9, 0, Qt::AlignHCenter);
    grid->addWidget(neptunePb, 10, 0, Qt::AlignHCenter);
    grid->addWidget(plutoPb, 11, 0, Qt::AlignHCenter);
    grid->addWidget(allPb, 12, 0, Qt::AlignCenter);

    // connect buttons
    connect(mercuryPb, &QPushButton::clicked, this, &PlanetaryAge::CalculateMercuryAge);
    connect(venusPb, &QPushButton::clicked, this, &PlanetaryAge::CalculateVenusAge);
    connect(marsPb, &QPushButton::clicked, this, &PlanetaryAge::CalculateMarsAge);
    connect(jupiterPb, &QPushButton::clicked, this, &PlanetaryAge::CalculateJupiterAge);
    connect(saturnPb, &QPushButton::clicked, this, &PlanetaryAge::CalculateSaturnAge);
    connect(uranusPb, &QPushButton::clicked, this, &PlanetaryAge::CalculateUranusAge);
    connect(neptunePb, &QPushButton::clicked, this, &PlanetaryAge::CalculateNeptuneAge);
    connect(plutoPb, &QPushButton::clicked, this, &PlanetaryAge::CalculatePlutoAge);
    connect(allPb, &QPushButton::clicked, this, &PlanetaryAge::CalculateAll);

    // define labels for the outputs
    mercuryOutput = new QLabel("0", this);
    venusOutput = new QLabel("0", this);
    marsOutput = new QLabel("0", this);
    jupiterOutput = new QLabel("0", this);
    saturnOutput = new QLabel("0", this);
    uranusOutput = new QLabel("0", this);
    neptuneOutput = new QLabel("0", this);
    plutoOutput = new QLabel("0", this);
    grid->addWidget(mercuryOutput, 4, 1, Qt::AlignCenter);
    grid->addWidget(venusOutput, 5, 1, Qt::AlignCenter);
    grid->addWidget(marsOutput, 6, 1, Qt::AlignCenter);
    grid->addWidget(jupiterOutput, 7, 1, Qt::AlignCenter);
    grid->addWidget(saturnOutput, 8, 1, Qt::AlignCenter);
    grid->addWidget(uranusOutput, 9, 1, Qt::AlignCenter);
    grid->addWidget(neptuneOutput, 10, 1, Qt::AlignCenter);
    grid->addWidget(plutoOutput, 11, 1, Qt::AlignCenter);

    setLayout(grid);
}

void PlanetaryAge::CalculateMercuryAge() {
    // convert age (years) into days, then divide this value
    // by the period of the planet (in days)
    // do this for all the terrestrial planets ONLY!
    int earthDays = (2020 - yearInput->value()) * 365;
    double period = 87.97;
    int age = earthDays / period;
    mercuryOutput->setText(QString::number(age));
}

void PlanetaryAge::CalculateVenusAge() {
    int earthDays = (2020 - yearInput->value()) * 365;
    double period = 224.7;
    int age = earthDays / period;
    venusOutput->setText(QString::number(age));
}

void PlanetaryAge::CalculateMarsAge() {
    int earthDays = (2020 - yearInput->value()) * 365;
    double period = 686.2;
    int age = earthDays / period;
    marsOutput->setText(QString::number(age));
}

void PlanetaryAge::CalculateJupiterAge() {
    // for the gaseous planets, divide the age by the 
    // period of the planet (in years)
    // do this for all the gaseous planets ONLY!
    int earthYears = 2020 - yearInput->value();
    double period = 11.86;
    int age = earthYears / period;
    jupiterOutput->setText(QString::number(age));
}

void PlanetaryAge::CalculateSaturnAge() {
    int earthYears = 2020 - yearInput->value();
    double period = 29.46;
    int age = earthYears / period;
    saturnOutput->setText(QString::number(age));
}

void PlanetaryAge::CalculateUranusAge() {
    int earthYears = 2020 - yearInput->value();
    double period = 84.01;
    int age = earthYears / period;
    uranusOutput->setText(QString::number(age));
}

void PlanetaryAge::CalculateNeptuneAge() {
    int earthYears = 2020 - yearInput->value();
    double period = 164.79;
    int age = earthYears / period;
    neptuneOutput->setText(QString::number(age));
}

void PlanetaryAge::CalculatePlutoAge() {
    int earthYears = 2020 - yearInput->value();
    double period = 248.59;
    int age = earthYears / period;
    plutoOutput->setText(QString::number(age));
}

void PlanetaryAge::CalculateAll() {
    CalculateMercuryAge();
    CalculateVenusAge();
    CalculateMarsAge();
    CalculateJupiterAge();
    CalculateSaturnAge();
    CalculateUranusAge();
    CalculateNeptuneAge();
    CalculatePlutoAge();
}

void PlanetaryAge::Reset() {
    dayInput->setValue(1);
    monthComboInput->setCurrentText("January");
    yearInput->setValue(2000);
    mercuryOutput->setText(QString::number(0));
    venusOutput->setText(QString::number(0));
    marsOutput->setText(QString::number(0));
    jupiterOutput->setText(QString::number(0));
    saturnOutput->setText(QString::number(0));
    uranusOutput->setText(QString::number(0));
    neptuneOutput->setText(QString::number(0));
    plutoOutput->setText(QString::number(0));
}
