#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QTimer>
#include "trex.h"

namespace Ui {
class Ventana;
}

class Ventana : public QWidget
{
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = nullptr);
    ~Ventana();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private slots:
    void slot_moverObstaculos();
    void slot_agregarPajaro();

private:
    Ui::Ventana *ui;
    TRex *trex;
    QList<QWidget*> cactus;
    QList<QWidget*> pajaros;
    QTimer *timerPrincipal;
    QTimer *timerAparecerPajaro;
    bool gameOver;

    int frameCounter;
    int contadorCactus;
    int velocidadCactus;


    void detectarColisiones();
    void mostrarGameOver();
    void reiniciarJuego();
};

#endif // VENTANA_H
