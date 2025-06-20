#include <QCoreApplication>
#include "persona.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    Persona p1("Juan");
    Persona p2("Maria");
    Persona p3("Carlos");

    p1.mostrar();
    p2.mostrar();
    p3.mostrar();

    qDebug() << "Total de personas creadas:" << Persona::totalPersonas();

    return 0;
}
