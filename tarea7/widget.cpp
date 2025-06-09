#include "widget.h"
#include "ui_widget.h"
#include <QString>
#include "form.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("Login");

    connect(ui->btnIngresar, &QPushButton::clicked, this, &Widget::verificarLogin);
    connect(ui->lineEditClave, &QLineEdit::returnPressed, this, &Widget::verificarLogin);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::verificarLogin(){
    QString usuario= ui->lineEditUsuario->text();
    QString clave= ui->lineEditClave->text();

    if(usuario=="admin" && clave=="1111"){
        Form*f= new Form();
        f->show();
        this->close();
    }
    else{
        ui->lineEditClave->clear();
        this->close();
    }
}
