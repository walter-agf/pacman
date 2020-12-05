#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    MainWindow w;
    w.setWindowTitle("PACMAN  -  Andres Felipe Giraldo Yusti  -  Juan Alejandro Gualteros Fonseca");
    w.show();
    return a.exec();
}
