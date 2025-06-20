#include "formulario.h"

Formulario::Formulario(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Formulario");

    QLabel *legajoLabel = new QLabel("Legajo:");
    QLabel *nombreLabel = new QLabel("Nombre:");
    QLabel *apellidoLabel = new QLabel("Apellido:");

    QLineEdit *legajoEdit = new QLineEdit();
    QLineEdit *nombreEdit = new QLineEdit();
    QLineEdit *apellidoEdit = new QLineEdit();

    QPushButton *btnAceptar = new QPushButton("Aceptar");

    QGridLayout *layout = new QGridLayout();
    layout->addWidget(legajoLabel, 0, 0);
    layout->addWidget(legajoEdit, 0, 1);
    layout->addWidget(nombreLabel, 1, 0);
    layout->addWidget(nombreEdit, 1, 1);
    layout->addWidget(apellidoLabel, 2, 0);
    layout->addWidget(apellidoEdit, 2, 1);
    layout->addWidget(btnAceptar, 3, 1);

    setLayout(layout);
}
