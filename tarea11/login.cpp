#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    connect(ui->pushButton,SIGNAL(pressed()),this, SLOT(validarUsuario()));
}

Login::~Login()
{
    delete ui;
}

void Login::validarUsuario()
{
    QString usario=ui->lineEditUsuario->text();
    QString clave=ui->lineEditClave->text();


    if (usario=="admin" && clave=="1234")
    {
        qDebug()<< "Usuario Ingresado Correctamente";
    }
    else
    {
        qDebug()<< "Usuario o Clave errones";
    }
}
