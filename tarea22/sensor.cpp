#include "sensor.h"
#include <QRandomGenerator>

//constructor sensor
Sensor::Sensor() {
    valorActual = QRandomGenerator::global()->bounded(1024); // 0 a 1023
}

int Sensor::getValorBrutoOffline() const {
    return valorActual;
}

double Sensor::getValorNormalizadoOffline() const {
    return valorActual / 1023.0;
}
