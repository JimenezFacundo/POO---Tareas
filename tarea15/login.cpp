#include "login.h"
#include "ui_login.h"
#include "ventana.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QDateTime>
#include <QMessageBox>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login) {
    ui->setupUi(this);
    conectarDB();
}

Login::~Login() {
    delete ui;
}

void Login::conectarDB() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database.db");

    if (!db.open()) {
        QMessageBox::critical(this, "Error", "No se pudo conectar a la base de datos.");
        exit(1);
    }
}

void Login::mostrarError(const QString &mensaje) {
    ui->lblMensaje->setText(mensaje);
}

void Login::on_btnLogin_clicked() {
    QString nombre = ui->lineUsuario->text();
    QString clave = ui->lineClave->text();

    QSqlQuery query;
    query.prepare("SELECT id, ultimo_ingreso FROM usuarios WHERE nombre = ? AND contraseña = ?");
    query.addBindValue(nombre);
    query.addBindValue(clave);

    if (query.exec() && query.next()) {
        int id = query.value(0).toInt();
        QString ultimoIngreso = query.value(1).toString();

        // Actualizar la hora del último ingreso
        QString ahora = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        QSqlQuery update;
        update.prepare("UPDATE usuarios SET ultimo_ingreso = ? WHERE id = ?");
        update.addBindValue(ahora);
        update.addBindValue(id);
        update.exec();

        // Abrir nueva ventana
        Ventana* bienvenida = new Ventana(nombre, ultimoIngreso);
        bienvenida->show();
        this->close();
    } else {
        mostrarError("Usuario o contraseña incorrectos.");
    }
}
