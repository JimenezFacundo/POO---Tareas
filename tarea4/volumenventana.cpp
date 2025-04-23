#include "volumenventana.h"

VolumenVentana::VolumenVentana(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Control de volumen");
    resize(300, 50);

    spinBox = new QSpinBox;
    slider = new QSlider(Qt::Horizontal);
    spinBox->setRange(0, 100);
    slider->setRange(0, 100);

    layout = new QHBoxLayout;
    layout->addWidget(spinBox);
    layout->addWidget(slider);
    setLayout(layout);

    connect(spinBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(updateWindowTitle(int)));
    connect(slider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));

    spinBox->setValue(15);
}

void VolumenVentana::updateWindowTitle(int value)
{
    setWindowTitle(QString("Volumen: %1").arg(value)); // %1 es un marcador el cual se reemplaza cuando .arg(value) cambia
}
