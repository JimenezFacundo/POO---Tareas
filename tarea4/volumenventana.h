#ifndef VOLUMENVENTANA_H
#define VOLUMENVENTANA_H

#include <QWidget>
#include <QSlider>
#include <QHBoxLayout>
#include <QString>

class VolumenVentana : public QWidget {
    Q_OBJECT

public:
    VolumenVentana(QWidget *parent = nullptr);

public slots:
    void updateWindowTitle(int value);

private:
    QSlider *slider;
    QHBoxLayout *layout;
};

#endif // VOLUMENVENTANA_H
