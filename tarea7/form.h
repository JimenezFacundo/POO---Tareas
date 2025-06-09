#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QRandomGenerator>
#include <QLabel>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private slots:
    void verificarCaptcha();
    void enviarFormulario();

private:
    Ui::Form *ui;

    QLineEdit *lineEditLegajo;
    QLineEdit *lineEditNombre;
    QLineEdit *lineEditApellido;
    QLineEdit *lineEditCaptcha;
    QPushButton *btnAceptar;
    QPushButton *btnVerificarCaptcha;
    QLabel *labelCaptcha;

    int captcha;
};

#endif
