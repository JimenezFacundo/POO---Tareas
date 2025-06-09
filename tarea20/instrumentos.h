#ifndef INSTRUMENTOS_H
#define INSTRUMENTOS_H

#include <QObject>
#include <QString>
#include <QDebug>

// Clase base
class Instrumento : public QObject {
    Q_OBJECT
public:
    explicit Instrumento(QObject* parent = nullptr) : QObject(parent), marca("Yamaha") {}
    virtual ~Instrumento() {}

    virtual void sonar() = 0;

    virtual void verlo() {
        qDebug() << "Marca:" << marca;
    }

    QString getMarca() const { return marca; }
    void setMarca(const QString& m) { marca = m; }

protected:
    QString marca;
};

// Clase Electrico
class Electrico {
public:
    Electrico() : voltaje(220) {}
    virtual ~Electrico() {
        qDebug() << "Desenchufado";
    }
    int getVoltaje() const { return voltaje; }
    void setVoltaje(int v) { voltaje = v; }

private:
    int voltaje;
};

// Guitarra
class Guitarra : public Instrumento {
    Q_OBJECT
public:
    explicit Guitarra(QObject* parent = nullptr) : Instrumento(parent), cuerdas(6) {}
    void sonar() override {
        qDebug() << "Guitarra suena...";
    }
    int getCuerdas() const { return cuerdas; }
    void setCuerdas(int c) { cuerdas = c; }
    void verlo() override {
        qDebug() << "Marca:" << marca << "- Cuerdas:" << cuerdas;
    }

private:
    int cuerdas;
};

// Bateria
class Bateria : public Instrumento {
    Q_OBJECT
public:
    explicit Bateria(QObject* parent = nullptr) : Instrumento(parent), tambores(5) {}
    void sonar() override {
        qDebug() << "Batería suena...";
    }
    int getTambores() const { return tambores; }
    void setTambores(int t) { tambores = t; }
    void verlo() override {
        qDebug() << "Marca:" << marca << "- Tambores:" << tambores;
    }

private:
    int tambores;
};

// Teclado con herencia múltiple de Instrumento y Electrico
class Teclado : public Instrumento, public Electrico {
    Q_OBJECT
public:
    explicit Teclado(QObject* parent = nullptr) : Instrumento(parent), teclas(61) {}
    void sonar() override {
        qDebug() << "Teclado suena...";
    }
    int getTeclas() const { return teclas; }
    void setTeclas(int t) { teclas = t; }
    void verlo() override {
        qDebug() << "Marca:" << marca << "- Teclas:" << teclas << "- Voltaje:" << getVoltaje() << "V";
    }

private:
    int teclas;
};

#endif // INSTRUMENTOS_H
