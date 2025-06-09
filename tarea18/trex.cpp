#include "trex.h"
#include <QPainter>
#include <QDebug>

TRex::TRex(QWidget *parent) : QWidget(parent)
{
    x = 50;
    y = 200;  // altura del "piso"
    velocidadY = 0;
    enSalto = false;
    agachado = false;

    setFixedSize(50, 50);  // tamaño del TRex
    move(x, y);

    // Timer para animar el salto
    timerSalto = new QTimer(this);
    connect(timerSalto, SIGNAL(timeout()), this, SLOT(slot_animarSalto()));
}

void TRex::saltar()
{
    if (!enSalto)
    {
        enSalto = true;
        velocidadY = -15;  // impulso inicial hacia arriba
        timerSalto->start(20);  // empieza la animación
    }
}

void TRex::slot_animarSalto()
{
    y += velocidadY;
    velocidadY += 1;  // gravedad

    if (y >= 200)
    {
        y = 200;
        enSalto = false;
        timerSalto->stop();
    }

    move(x, y);
    update();
}

void TRex::agacharse(bool activar)
{
    agachado = activar;
    update();
}

void TRex::adelantar()
{
    x += 10;
    move(x, y);
}

void TRex::frenar()
{
    x -= 10;
    if (x < 0)
        x = 0;
    move(x, y);
}

QRect TRex::obtenerRect() const
{
    return QRect(x, y, width(), height());
}

void TRex::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    // Dibujamos el TRex
    if (agachado)
        painter.fillRect(rect(), Qt::darkGreen);  // TRex agachado
    else
        painter.fillRect(rect(), Qt::green);      // TRex normal
}
