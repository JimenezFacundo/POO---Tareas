// AdminDBMedicamentos.h

#ifndef ADMINDBMEDICAMENTOS_H
#define ADMINDBMEDICAMENTOS_H

#include "CajaMedicamento.h"
#include <QSqlDatabase>
#include <QList>

class AdminDBMedicamentos {
private:
    static AdminDBMedicamentos* instancia;
    QSqlDatabase db;

    // Constructor privado (singleton)
    AdminDBMedicamentos();

public:
    static AdminDBMedicamentos* getInstancia();

    void conectar();
    bool insertarCaja(float dosis);
    QList<CajaMedicamento> obtenerTodas();
    float obtenerTotalDosis();
};

#endif // ADMINDBMEDICAMENTOS_H
