#ifndef PERSONA_H
#define PERSONA_H

#include <QString>
#include <QDebug>

class Persona {
private:
    QString nombre;
    static int contador; // Miembro estático

public:
    explicit Persona(const QString &nombre);
    void mostrar() const;

    static int totalPersonas(); // Método estático
};

#endif
