#ifndef PAJARO_H
#define PAJARO_H

#include <QWidget>
#include <QTimer>
#include <QRect>

class Pajaro : public QWidget
{
    Q_OBJECT

public:
    explicit Pajaro(QWidget *parent = nullptr);
    QRect obtenerRect() const;

signals:
    void signal_colision();

private slots:
    void slot_mover();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QTimer *timer;
    int x, y;
};

#endif // PAJARO_H
