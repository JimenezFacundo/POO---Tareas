#include "ventana.h"

#include <QApplication>
#include <QWidget>

int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    Ventana ventana;
    ventana.resize(800,600);
    ventana.setWindowTitle("Aplicacion qt");
    ventana.show();

    return a.exec();
}
