#include "PlanetaryAge.h"
#include <QtWidgets/QApplication>

/*
 *****************************
 *   Author: David Hardy     *    
 *****************************
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PlanetaryAge w;

    w.setWindowTitle("Planetary Age Calculator");
    w.setWindowIcon(QIcon("planets.jpg"));
    w.show();

    return a.exec();
}
