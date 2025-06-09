#include <QApplication>
#include "pintura.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Pintura ventana;
    ventana.resize(800, 600);
    ventana.show();
    return app.exec();
}
