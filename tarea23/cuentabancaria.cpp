#include "cuentabancaria.h"

CuentaBancaria::CuentaBancaria(int saldoInicial) : saldo(saldoInicial) {}

void CuentaBancaria::depositar(int monto) {
    saldo += monto;
}

void CuentaBancaria::mostrar() const {
    qDebug() << "Saldo actual:" << saldo;
}

bool compararSaldo(const CuentaBancaria &c1, const CuentaBancaria &c2) {
    return c1.saldo > c2.saldo;
}
