#ifndef TREX_H
#define TREX_H

#include <QWidget>
#include <QRect>
#include <QTimer>

class TRex : public QWidget
{
    Q_OBJECT

public:
    explicit TRex(QWidget *parent = nullptr);
    void saltar();
    void agacharse(bool activar);
    void adelantar();
    void frenar();
    QRect obtenerRect() const;

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void slot_animarSalto();

private:
    int x, y;
    int velocidadY;
    bool enSalto;
    bool agachado;
    QTimer *timerSalto;
};

#endif // TREX_H
