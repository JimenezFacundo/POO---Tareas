#ifndef CARTUCHERA_H
#define CARTUCHERA_H

#include <QString>
#include <QVector>

class Cartuchera {
public:
    Cartuchera();
    Cartuchera(QString color, int capacidad);


    QString getColor();
    void setColor(QString nuevoColor);
    int getCapacidad();
    void setCapacidad(int nuevaCapacidad);
    void agregarUtensilio(QString utensilio);
    QVector<QString> getUtensilios();

private:
    QString color;
    int capacidad;
    QVector<QString> utensilios;
};

#endif // CARTUCHERA_H
