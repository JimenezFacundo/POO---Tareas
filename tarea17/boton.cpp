#include "boton.h"
#include <QPainter>
#include <QMouseEvent>

Boton::Boton(QWidget *parent) : QWidget(parent)
{
    // Color por defecto
    colorActual = Qt::gray;
}

void Boton::colorear(Colores color)
{
    switch (color)
    {
    case Rojo:
        colorActual = QColor(255, 51, 51);  // rojo vibrante
        break;
    case Violeta:
        colorActual = QColor(153, 51, 255);  // violeta
        break;
    case Azul:
        colorActual = QColor(51, 102, 255);  // azul más suave
        break;
    case Verde:
        colorActual = QColor(51, 204, 102);  // verde esmeralda
        break;
    case Cyan:
        colorActual = QColor(0, 255, 255);   // cyan
        break;
    }
    update();
}

void Boton::setTexto(const QString &texto)
{
    textoBoton = texto;
    update();  // Redibujar
}


void Boton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Fondo
    painter.fillRect(rect(), colorActual);

    // Texto
    painter.setPen(Qt::white);  // Color del texto
    QFont font("Segoe UI", 16, QFont::Bold);  // Fuente similar a la de la imagen
    painter.setFont(font);

    painter.drawText(rect(), Qt::AlignVCenter | Qt::AlignHCenter, textoBoton);
}

void Boton::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        emit signal_clic();
    }
}
