#include "widget.h"

#include <QVBoxLayout>
#include <QDebug>


Widget::Widget(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("Login");
    this->resize(300,150);

    QLabel *labelUsuario = new QLabel ("Usuario");
    lineEditUsuario= new QLineEdit();

    QLabel *labelClave = new QLabel ("Clave");
    lineEditClave= new QLineEdit();
    lineEditClave->setEchoMode(QLineEdit::Password);

    botonAceptar= new QPushButton("Ingresar");
    labelEstado= new QLabel();

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(labelUsuario);
    layout->addWidget(lineEditUsuario);
    layout->addWidget(labelClave);
    layout->addWidget(lineEditClave);
    layout->addWidget(botonAceptar);
    layout->addWidget(labelEstado);

    connect(botonAceptar, SIGNAL(clicked()), this, SLOT(validarUsuario()));
}

Widget::~Widget() {}
void Widget::validarUsuario()
{
    QString usuario= lineEditUsuario->text();
    QString clave= lineEditClave->text();

    if(usuario=="admin" && clave=="1234")
    {
        qDebug() << "Usuario Logueado Correctamente";
    }
    else
    {
       qDebug() << "Usuario o Clave Incorrectas";
    }
}
