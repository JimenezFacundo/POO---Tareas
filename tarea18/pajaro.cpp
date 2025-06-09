#include "pajaro.h"
#include <QPainter>
#include <QRandomGenerator>

Pajaro::Pajaro(QWidget *parent) : QWidget(parent)
{
    // Posición inicial
    x = 800;  // aparece en el borde derecho
    y = QRandomGenerator::global()->bounded(100, 300);  // altura aleatoria

    setFixedSize(50, 50);
    move(x, y);

    // Timer para mover el pájaro
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(slot_mover()));
    timer->start(30);  // velocidad de movimiento
}

void Pajaro::slot_mover()
{
    x -= 5;  // mover a la izquierda
    move(x, y);

    // Si sale de la pantalla → eliminar
    if (x + width() < 0)
    {
        timer->stop();
        deleteLater();
    }

    update();
}

QRect Pajaro::obtenerRect() const
{
    return QRect(x, y, width(), height());
}

void Pajaro::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    // Dibujamos el pájaro
    painter.fillRect(rect(), Qt::red);  // podés cambiar color si querés
}
