#include "ventana.h"
#include "ui_ventana.h"

Ventana::Ventana(const QString& nombre, const QString& ultimoIngreso, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ventana) {
    ui->setupUi(this);

    ui->labelNombre->setText(nombre);
    ui->labelIngreso->setText("Último ingreso: " + ultimoIngreso);
}

Ventana::~Ventana() {
    delete ui;
}
