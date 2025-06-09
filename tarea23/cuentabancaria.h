#ifndef CUENTABANCARIA_H
#define CUENTABANCARIA_H

#include <QDebug>

class CuentaBancaria {
private:
    int saldo;

public:
    explicit CuentaBancaria(int saldoInicial);

    void depositar(int monto);
    void mostrar() const;

    // Función amiga
    friend bool compararSaldo(const CuentaBancaria &c1, const CuentaBancaria &c2);
};

#endif // CUENTABANCARIA_H
