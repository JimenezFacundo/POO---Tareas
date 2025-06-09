#include "pintura.h"
#include <QPainter>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QWheelEvent>

Pintura::Pintura(QWidget* parent) : QWidget(parent) {
    colorActual = Qt::black;
    grosorActual = 3;
    setFocusPolicy(Qt::StrongFocus);
    setMouseTracking(true);
}

void Pintura::mousePressEvent(QMouseEvent* evento) {
    if (evento->buttons() == Qt::LeftButton) {
        trazoActual.clear();
        trazoActual.append(evento->pos());
    }
}

void Pintura::mouseMoveEvent(QMouseEvent* evento) {
    if (evento->buttons() == Qt::LeftButton) {
        trazoActual.append(evento->pos());
        update();  // Redibuja
    }
}

void Pintura::wheelEvent(QWheelEvent* evento) {
    int delta = evento->angleDelta().y();
    if (delta > 0 && grosorActual < 30)
        grosorActual++;
    else if ((delta < 0) && (grosorActual > 1))
        grosorActual--;
}

void Pintura::keyPressEvent(QKeyEvent* evento) {
    if (evento->key() == Qt::Key_R)
        colorActual = Qt::red;
    else if (evento->key() == Qt::Key_G)
        colorActual = Qt::green;
    else if (evento->key() == Qt::Key_B)
        colorActual = Qt::blue;
    else if (evento->key() == Qt::Key_Escape) {
        trazos.clear();
        colores.clear();
        grosores.clear();
        update();
    }
}

void Pintura::guardarTrazo() {
    if (!trazoActual.isEmpty()) {
        trazos.append(trazoActual);
        colores.append(colorActual);
        grosores.append(grosorActual);
        trazoActual.clear();
    }
}

void Pintura::mouseReleaseEvent(QMouseEvent* evento) {
    if (evento->button() == Qt::LeftButton) {
        guardarTrazo();
        update();
    }
}


void Pintura::paintEvent(QPaintEvent* evento) {
    QPainter painter(this);

    for (int i = 0; i < trazos.size(); i++) {
        painter.setPen(QPen(colores[i], grosores[i], Qt::SolidLine, Qt::RoundCap));
        for (int j = 1; j < trazos[i].size(); j++) {
            painter.drawLine(trazos[i][j - 1], trazos[i][j]);
        }
    }

    painter.setPen(QPen(colorActual, grosorActual, Qt::SolidLine, Qt::RoundCap));
    for (int j = 1; j < trazoActual.size(); j++) {
        painter.drawLine(trazoActual[j - 1], trazoActual[j]);
    }

}
