#include <QApplication>
#include <QWidget>
#include <QDebug>
#include <vector>
#include "instrumentos.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget window;
    window.setWindowTitle("Instrumentos");
    window.resize(400, 300);
    window.show();

    std::vector<Instrumento*> instrumentos;

    // Crear 5 instrumentos (ejemplo: 2 guitarras, 1 bateria, 2 teclados)
    instrumentos.push_back(new Guitarra());
    instrumentos.push_back(new Guitarra());
    instrumentos.push_back(new Bateria());
    instrumentos.push_back(new Teclado());
    instrumentos.push_back(new Teclado());

    // Mostrar marca de cada uno
    for(auto instr : instrumentos) {
        instr->verlo();
        instr->sonar();
    }

    // Liberar memoria
    for(auto instr : instrumentos) {
        delete instr;
    }
    instrumentos.clear();

    return a.exec();
}
