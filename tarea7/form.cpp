#include "form.h"
#include "ui_form.h"
#include <QMessageBox>
#include <QRandomGenerator>

Form::Form(QWidget *parent) : QWidget(parent), ui(new Ui::Form)
{
    ui->setupUi(this);
    this->setWindowTitle("Formulario");

    lineEditLegajo = ui->lineEditLegajo;
    lineEditNombre = ui->lineEditNombre;
    lineEditApellido = ui->lineEditApellido;
    lineEditCaptcha = ui->lineEditCaptcha;
    btnAceptar = ui->btnAceptar;
    btnVerificarCaptcha = ui->btnVerificarCaptcha;
    labelCaptcha = ui->labelCaptcha;

    // Generar un número aleatorio entre 1 y 1000
    captcha = QRandomGenerator::global()->bounded(1, 1001);
    labelCaptcha->setText(QString::number(captcha));

    btnAceptar->setEnabled(false);  // Deshabilitar el botón de Aceptar al inicio

    connect(btnVerificarCaptcha, &QPushButton::clicked, this, &Form::verificarCaptcha);
    connect(btnAceptar, &QPushButton::clicked, this, &Form::enviarFormulario);
}

Form::~Form()
{
    delete ui;
}

void Form::verificarCaptcha(){
    bool ok;
    int numeroIngresado = lineEditCaptcha->text().toInt(&ok);  // Convertir el texto a int

    if (!ok) {
        QMessageBox::warning(this, "Error", "Por favor ingrese un número válido.");
        return;
    }


    if (numeroIngresado == captcha) {
        QMessageBox::information(this, "Captcha correcto", "¡Captcha verificado correctamente!");

        btnAceptar->setEnabled(true);
    } else {
        captcha = QRandomGenerator::global()->bounded(1, 1001);
        labelCaptcha->setText(QString::number(captcha));

        QMessageBox::warning(this, "Captcha incorrecto", "El número ingresado no es correcto. Intenta de nuevo.");
        lineEditCaptcha->clear();
    }
}

void Form::enviarFormulario(){
    QString legajo = lineEditLegajo->text();
    QString nombre = lineEditNombre->text();
    QString apellido = lineEditApellido->text();

    QMessageBox::information(this, "Formulario enviado", "¡Formulario enviado correctamente!");

    this->close();
}
