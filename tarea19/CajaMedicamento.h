// CajaMedicamento.h

#ifndef CAJAMEDICAMENTO_H
#define CAJAMEDICAMENTO_H

#include <QString>

class CajaMedicamento {
private:
    int id;
    float dosisTotales;

public:
    // Constructor para insertar una nueva caja
    CajaMedicamento(float dosis);

    // Constructor para cargar desde la base de datos
    CajaMedicamento(int id, float dosis);

    // Getters
    int getId() const;
    float getDosisTotales() const;

    // Operadores
    CajaMedicamento operator+(const CajaMedicamento& otra) const;
    bool operator==(const CajaMedicamento& otra) const;

    // Representación en texto
    QString toString() const;
};

#endif // CAJAMEDICAMENTO_H
