#include "login.h"
#include "ui_login.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QCryptographicHash>
#include <QDebug>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);


    connect(ui->pushButtonLogin, SIGNAL(clicked()), this, SLOT(slot_login()));
    connect(ui->lineEditPassword, SIGNAL(returnPressed()), ui->pushButtonLogin, SLOT(click()));

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("login.db");

    if (!db.open()) {
        ui->labelEstado->setText("Error al abrir la BD");
        return;
    }

    // <<< ACA CREAMOS LA TABLA SI NO EXISTE >>>
    QSqlQuery createTable;
    createTable.exec("CREATE TABLE IF NOT EXISTS usuarios ("
                     "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                     "usuario TEXT UNIQUE, "
                     "clave TEXT, "
                     "ultimo_login INTEGER DEFAULT 0)");

    // <<< ACA INSERTAMOS USUARIO DE EJEMPLO SI NO HAY NINGUNO >>>
    QSqlQuery checkQuery("SELECT COUNT(*) FROM usuarios");
    if (checkQuery.next() && checkQuery.value(0).toInt() == 0) {
        insertarUsuarioEjemplo();
    }

    cargarUltimoUsuario();
}




Login::~Login()
{
    delete ui;
}

void Login::slot_login()
{
    QString usuario = ui->lineEditUsuario->text();
    QString claveMD5 = calcularMD5(ui->lineEditPassword->text());

    QSqlQuery query;
    query.prepare("SELECT id FROM usuarios WHERE usuario = ? AND clave = ?");
    query.addBindValue(usuario);
    query.addBindValue(claveMD5);

    if (query.exec() && query.next()) {
        int userId = query.value(0).toInt();

        QSqlQuery updateQuery;
        updateQuery.prepare("UPDATE usuarios SET ultimo_login = 1 WHERE id = ?");
        updateQuery.addBindValue(userId);
        updateQuery.exec();

        QSqlQuery resetQuery;
        resetQuery.prepare("UPDATE usuarios SET ultimo_login = 0 WHERE id != ?");
        resetQuery.addBindValue(userId);
        resetQuery.exec();

        ui->labelEstado->setText("Login OK");
    } else {
        ui->labelEstado->setText("Usuario o clave incorrectos");
    }
}

void Login::insertarUsuarioEjemplo()
{
    QString usuario = "admin";
    QString claveMD5 = calcularMD5("admin");

    QSqlQuery query;
    query.prepare("INSERT INTO usuarios (usuario, clave) VALUES (?, ?)");
    query.addBindValue(usuario);
    query.addBindValue(claveMD5);

    if (query.exec()) {
        qDebug() << "Usuario de ejemplo insertado correctamente.";
    } else {
        qDebug() << "Error al insertar usuario de ejemplo:" << query.lastError().text();
    }
}


void Login::cargarUltimoUsuario()
{
    QSqlQuery query("SELECT usuario FROM usuarios WHERE ultimo_login = 1 LIMIT 1");
    if (query.next()) {
        QString lastUser = query.value(0).toString();
        ui->lineEditUsuario->setText(lastUser);
    }
}

QString Login::calcularMD5(const QString &texto)
{
    QByteArray hash = QCryptographicHash::hash(texto.toUtf8(), QCryptographicHash::Md5);
    return hash.toHex();
}
