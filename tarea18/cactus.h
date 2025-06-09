#ifndef CACTUS_H
#define CACTUS_H

#include <QWidget>
#include <QRect>

class Cactus : public QWidget
{
    Q_OBJECT

public:
    explicit Cactus(QWidget *parent = nullptr);
    void mover(int velocidad);
    QRect obtenerRect() const;

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int x, y;
};

#endif // CACTUS_H
