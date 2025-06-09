#include "persona.h"

int Persona::contador = 0;

Persona::Persona(const QString &nombre) : nombre(nombre) {
    contador++;
}

void Persona::mostrar() const {
    qDebug() << "Nombre:" << nombre;
}

int Persona::totalPersonas() {
    return contador;
}
