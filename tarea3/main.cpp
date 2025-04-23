#include <QCoreApplication>
#include <QVector>
#include <QString>
#include <QDebug>
#include "cartuchera.h"

size_t calcularTamanoEnMemoria(Cartuchera& cartuchera) {
    size_t tamano = sizeof(Cartuchera);
    tamano += cartuchera.getColor().size() * sizeof(QChar); // agrego el tamano del QString color
    tamano += sizeof(int); // agrego el tamano del entero capacidad
    for (QString utensilio : cartuchera.getUtensilios()) {
        tamano += utensilio.size() * sizeof(QChar); // agrego el tamano de cada QString utensilio
    }
    tamano += cartuchera.getUtensilios().capacity() * sizeof(QString*); // "capacity" metodo de vector
    return tamano;
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    QVector<Cartuchera> cartucheras;
    size_t memoriaUsadaBytes = 0;
    int contadorObjetos = 0;
    size_t limiteMemoriaBytes = 200 * 1024 * 1024; // 200 MB en bytes

    while (memoriaUsadaBytes < limiteMemoriaBytes) {
        Cartuchera nuevaCartuchera("Naranja", 8); // Creo una nueva cartuchera con 500 utencilios
        for (int i = 0; i < 500; ++i) {
            nuevaCartuchera.agregarUtensilio(QString("Utensilio Numero %1").arg(i));
        }
        cartucheras.push_back(nuevaCartuchera);
        memoriaUsadaBytes += calcularTamanoEnMemoria(cartucheras.back());
        contadorObjetos++;
        qDebug() << "Objetos agregados:" << contadorObjetos << ", Memoria estimada:" << memoriaUsadaBytes / (1024 * 1024) << "MB";
    }
    qDebug() << "\nSe agregaron" << contadorObjetos << "objetos Cartuchera (con 500 utensilios dentro) antes de alcanzar aproximadamente 200 MB de memoria estimada.";

}
