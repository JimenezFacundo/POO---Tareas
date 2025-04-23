#ifndef VOLUMENVENTANA_H
#define VOLUMENVENTANA_H

#include <QWidget>
#include <QSlider>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QString>

class VolumenVentana : public QWidget {
    Q_OBJECT

public:
    VolumenVentana(QWidget *parent = nullptr);

public slots:
    void updateWindowTitle(int value);

private:
    QSpinBox *spinBox;
    QSlider *slider;
    QHBoxLayout *layout;
};

#endif // VOLUMENVENTANA_H
