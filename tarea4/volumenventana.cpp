#include "volumenventana.h"

VolumenVentana::VolumenVentana(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Control de volumen");
    resize(300, 50);

    slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 100);

    layout = new QHBoxLayout;
    layout->addWidget(slider);
    setLayout(layout);

    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(updateWindowTitle(int)));
}

void VolumenVentana::updateWindowTitle(int value)
{
    setWindowTitle(QString("Volumen: %1").arg(value)); // %1 es un marcador el cual se reemplaza cuando .arg(value) cambia
}
