#include "cactus.h"
#include <QPainter>

Cactus::Cactus(QWidget *parent) : QWidget(parent)
{
    // Posición inicial
    x = 800;  // aparece en el borde derecho
    y = 200;  // piso (mismo nivel que TRex)

    setFixedSize(40, 60);  // tamaño de cactus
    move(x, y);
}

void Cactus::mover(int velocidad)
{
    x -= velocidad;
    move(x, y);

    // Si sale de la pantalla → eliminar
    if (x + width() < 0)
    {
        deleteLater();
    }

    update();
}

QRect Cactus::obtenerRect() const
{
    return QRect(x, y, width(), height());
}

void Cactus::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    // Dibujamos el cactus
    painter.fillRect(rect(), Qt::darkGreen);
}
