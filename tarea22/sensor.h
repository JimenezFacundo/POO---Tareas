#ifndef SENSOR_H
#define SENSOR_H

class Sensor {
private:
    int valorActual;

public:
    Sensor();

    // Método inline implícito
    int getValorBruto() const {
        return valorActual;
    }

    // Declaraciones de métodos offline
    int getValorBrutoOffline() const;
    inline double getValorNormalizado() const {
        return valorActual / 1023.0;
    }
    double getValorNormalizadoOffline() const;
};

#endif // SENSOR_H
