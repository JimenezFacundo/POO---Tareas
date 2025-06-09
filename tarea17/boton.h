#ifndef BOTON_H
#define BOTON_H

#include <QWidget>
#include <QColor>

class Boton : public QWidget
{
    Q_OBJECT

public:
    explicit Boton(QWidget *parent = nullptr);

    enum Colores { Rojo, Violeta, Azul, Verde, Cyan };

    void colorear(Colores color);

    void setTexto(const QString &texto);  // <-- método para cambiar el texto


signals:
    void signal_clic();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    QColor colorActual;
    QString textoBoton;   // <-- para guardar el texto del botón
};

#endif // BOTON_H
