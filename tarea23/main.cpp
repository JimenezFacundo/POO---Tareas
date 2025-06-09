#include <QCoreApplication>
#include "cuentabancaria.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    CuentaBancaria cuenta1(1000);
    CuentaBancaria cuenta2(500);

    cuenta1.mostrar();
    cuenta2.mostrar();

    cuenta1.depositar(300);
    cuenta2.depositar(700);

    qDebug() << "Despues de depositar..";
    cuenta1.mostrar();
    cuenta2.mostrar();

    if (compararSaldo(cuenta1, cuenta2)) {
        qDebug() << "la Cuenta 1 tiene mas saldo.";
    } else {
        qDebug() << "la Cuenta 2 tiene mas saldo o igual.";
    }

    return 0;
}
