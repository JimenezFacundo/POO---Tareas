#ifndef PINTURA_H
#define PINTURA_H

#include <QWidget>
#include <QVector>
#include <QPoint>
#include <QColor>

class Pintura : public QWidget {
    Q_OBJECT

public:
    Pintura(QWidget* parent = nullptr);  // También el constructor lleva *

protected:
    void paintEvent(QPaintEvent* evento) override;
    void mousePressEvent(QMouseEvent* evento) override;
    void mouseMoveEvent(QMouseEvent* evento) override;
    void wheelEvent(QWheelEvent* evento) override;
    void keyPressEvent(QKeyEvent* evento) override;
    void mouseReleaseEvent(QMouseEvent* evento) override;


private:
    QVector<QVector<QPoint>> trazos;
    QVector<QColor> colores;
    QVector<int> grosores;

    QVector<QPoint> trazoActual;
    QColor colorActual;
    int grosorActual;

    void guardarTrazo();
};

#endif // PINTURA_H
