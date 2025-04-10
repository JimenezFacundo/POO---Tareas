#ifndef POSTE_H
#define POSTE_H

#include <QString>

class Poste {
public:
    Poste(int altura, float diametro);

    int getAltura() const;
    float getDiametro() const;

    QString toString() const;

private:
    int altura;
    float diametro;
};

#endif // POSTE_H
