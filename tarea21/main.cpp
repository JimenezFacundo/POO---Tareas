#include <QApplication>
#include "ventana.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Ventana v;
    v.show();
    return app.exec();
}
