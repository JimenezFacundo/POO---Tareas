#include "poste.h"

Poste::Poste(int altura, float diametro)
    : altura(altura), diametro(diametro) {}

int Poste::getAltura() const {
    return altura;
}

float Poste::getDiametro() const {
    return diametro;
}

QString Poste::toString() const {
    return QString("Altura: %1 m - Diámetro: %2 cm")
        .arg(altura)
        .arg(diametro);
}
