#include <QApplication>
#include "volumenventana.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    VolumenVentana ventana;
    ventana.setVisible(true);
    return a.exec();
}
