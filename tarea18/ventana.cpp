#include "ventana.h"
#include "ui_ventana.h"
#include "pajaro.h"
#include "cactus.h"

#include <QKeyEvent>
#include <QPainter>
#include <QDebug>

Ventana::Ventana(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ventana)
{
    ui->setupUi(this);
    setFixedSize(800, 400);  // tamaño fijo para el juego

    // Crear TRex
    trex = new TRex(this);

    // Timer principal
    timerPrincipal = new QTimer(this);
    connect(timerPrincipal, SIGNAL(timeout()), this, SLOT(slot_moverObstaculos()));
    timerPrincipal->start(20);  // velocidad de refresco

    // Timer para crear pájaros
    timerAparecerPajaro = new QTimer(this);
    connect(timerAparecerPajaro, SIGNAL(timeout()), this, SLOT(slot_agregarPajaro()));
    timerAparecerPajaro->start(5000);  // cada 5 seg

    gameOver = false;

    // Inicializamos contadores
    frameCounter = 0;
    contadorCactus = 0;
    velocidadCactus = 5;
}

Ventana::~Ventana()
{
    delete ui;
}

void Ventana::keyPressEvent(QKeyEvent *event)
{
    if (gameOver)
    {
        if (event->key() == Qt::Key_R)
        {
            reiniciarJuego();
        }
        return;
    }

    switch (event->key())
    {
    case Qt::Key_Space:
        trex->saltar();
        break;
    case Qt::Key_Down:
        trex->agacharse(true);
        break;
    case Qt::Key_Right:
        trex->adelantar();
        break;
    case Qt::Key_Left:
        trex->frenar();
        break;
    }
}

void Ventana::slot_moverObstaculos()
{
    // Aumentar velocidad con el tiempo
    frameCounter++;
    if (frameCounter % 500 == 0)  // cada 500 frames (~10 seg)
    {
        velocidadCactus++;
        qDebug() << "Velocidad actual de cactus: " << velocidadCactus;
    }

    // Mover cactus
    for (int i = cactus.size() - 1; i >= 0; --i)
    {
        Cactus *cactusItem = qobject_cast<Cactus*>(cactus[i]);
        if (cactusItem)
        {
            cactusItem->mover(velocidadCactus);
            if (cactusItem->geometry().x() + cactusItem->width() < 0)

            {
                cactus.removeAt(i);  // limpiar de la lista
            }
        }
    }

    // Detección de colisiones
    QRect trexRect = trex->obtenerRect();

    // Colisión con cactus
    for (QWidget *c : cactus)
    {
        Cactus *cactusItem = qobject_cast<Cactus*>(c);
        if (cactusItem && trexRect.intersects(cactusItem->obtenerRect()))
        {
            mostrarGameOver();
        }
    }

    // Colisión con pájaros
    for (QWidget *p : pajaros)
    {
        Pajaro *pajaro = qobject_cast<Pajaro*>(p);
        if (pajaro && trexRect.intersects(pajaro->obtenerRect()))
        {
            mostrarGameOver();
        }
    }

    // Agregar cactus cada cierto tiempo
    contadorCactus++;
    if (contadorCactus % 200 == 0)  // cada ~200 frames (~4 seg)
    {
        Cactus *c = new Cactus(this);
        cactus.append(c);
        c->show();
    }

    update();  // para repintar
}

void Ventana::slot_agregarPajaro()
{
    Pajaro *pajaro = new Pajaro(this);
    pajaros.append(pajaro);
    pajaro->show();
}

void Ventana::detectarColisiones()
{
    // (Ya está incluida la detección en slot_moverObstaculos)
    // No es necesario llamar aquí
}

void Ventana::mostrarGameOver()
{
    if (!gameOver)
    {
        gameOver = true;
        qDebug() << "GAME OVER!";
        timerPrincipal->stop();
        timerAparecerPajaro->stop();
    }
}

void Ventana::reiniciarJuego()
{
    // Limpiar pájaros
    for (QWidget *p : pajaros)
    {
        p->deleteLater();
    }
    pajaros.clear();

    // Limpiar cactus
    for (QWidget *c : cactus)
    {
        c->deleteLater();
    }
    cactus.clear();

    // Reset de variables
    gameOver = false;
    trex->move(50, 200);  // posición inicial del TRex

    // Reset de contadores
    frameCounter = 0;
    contadorCactus = 0;
    velocidadCactus = 5;

    // Reiniciar timers
    timerPrincipal->start(20);
    timerAparecerPajaro->start(5000);
}

void Ventana::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    // Si querés, podés dibujar fondo
    painter.fillRect(rect(), QColor(200, 200, 200));  // fondo gris claro

    // Si es Game Over, mostrar texto
    if (gameOver)
    {
        QFont font("Arial", 32, QFont::Bold);
        painter.setFont(font);
        painter.setPen(Qt::red);
        painter.drawText(rect(), Qt::AlignCenter, "GAME OVER!\nPresione R para reiniciar");
    }
}
