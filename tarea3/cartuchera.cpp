#include "cartuchera.h"

#include <QDebug>

// Constructor por defecto
Cartuchera::Cartuchera() : color("Sin color"), capacidad(0) {
}

// Constructor con color y capacidad
Cartuchera::Cartuchera(QString color, int capacidad)
    : color(color), capacidad(capacidad) {
}

QString Cartuchera::getColor() {
    return this->color;
}

void Cartuchera::setColor(QString nuevoColor) {
    this->color = nuevoColor;
}

int Cartuchera::getCapacidad() {
    return this->capacidad;
}

void Cartuchera::setCapacidad(int nuevaCapacidad) {
    this->capacidad = nuevaCapacidad;
}

void Cartuchera::agregarUtensilio(QString utensilio) {
    this->utensilios.push_back(utensilio);
}

QVector<QString> Cartuchera::getUtensilios() {
    return this->utensilios;
}
