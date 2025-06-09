#include "ventana.h"
#include "ui_ventana.h"
#include "boton.h"  // <--- importante incluirlo!

#include <QPainter>
#include <QLinearGradient>
#include <QDebug>

Ventana::Ventana(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ventana)
{
    ui->setupUi(this);

    // Conectar señales de clic
    connect(ui->boton1, SIGNAL(signal_clic()), this, SLOT(slot_botonClic()));
    connect(ui->boton2, SIGNAL(signal_clic()), this, SLOT(slot_botonClic()));
    connect(ui->boton3, SIGNAL(signal_clic()), this, SLOT(slot_botonClic()));
    connect(ui->boton4, SIGNAL(signal_clic()), this, SLOT(slot_botonClic()));
    connect(ui->boton5, SIGNAL(signal_clic()), this, SLOT(slot_botonClic()));


    // Conectar señales de clic
    ui->boton1->colorear(Boton::Rojo);
    ui->boton1->setTexto("Mi dentista");

    ui->boton2->colorear(Boton::Violeta);
    ui->boton2->setTexto("Visitas");

    ui->boton3->colorear(Boton::Azul);
    ui->boton3->setTexto("Técnicas de higiene");

    ui->boton4->colorear(Boton::Azul);
    ui->boton4->setTexto("Mi boca");

    ui->boton5->colorear(Boton::Verde);
    ui->boton5->setTexto("Hora de cepillarse");

}

Ventana::~Ventana()
{
    delete ui;
}

void Ventana::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    // Dibujar fondo agradable
    QLinearGradient grad(0, 0, width(), height());
    grad.setColorAt(0.0, QColor(255, 255, 0));  // Amarillo
    grad.setColorAt(1.0, QColor(0, 255, 255));  // Cyan

    painter.fillRect(rect(), grad);
}

void Ventana::slot_botonClic()
{
    // Mostrar mensaje en consola (puedes hacer lo que quieras acá)
    qDebug() << "Botón clickeado!";
}
