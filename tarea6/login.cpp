#include "login.h"

Login::Login(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Login");

    QLabel *labelUsuario = new QLabel("Usuario:");
    QLabel *labelClave = new QLabel("Clave:");

    usuarioEdit = new QLineEdit();
    claveEdit = new QLineEdit();
    claveEdit->setEchoMode(QLineEdit::Password); // Mostrar asteriscos

    QPushButton *btnIngresar = new QPushButton("Ingresar");

    QGridLayout *layout = new QGridLayout();
    layout->addWidget(labelUsuario, 0, 0);
    layout->addWidget(usuarioEdit, 0, 1);
    layout->addWidget(labelClave, 1, 0);
    layout->addWidget(claveEdit, 1, 1);
    layout->addWidget(btnIngresar, 2, 1);

    setLayout(layout);

    connect(btnIngresar, &QPushButton::clicked, this, &Login::verificarLogin);
    connect(claveEdit, &QLineEdit::returnPressed, this, &Login::verificarLogin);
}

void Login::verificarLogin() {
    QString usuario = usuarioEdit->text();
    QString clave = claveEdit->text();

    if (usuario == "admin" && clave == "1111") {
        Formulario *formulario = new Formulario();
        formulario->show();
        this->close(); // Cierra la ventana de login
    } else {
        claveEdit->clear(); // Borra la clave si es incorrecta
    }
}
