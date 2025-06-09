#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void slot_login();

private:
    Ui::Login *ui;
    QSqlDatabase db;

    void cargarUltimoUsuario();
    QString calcularMD5(const QString &texto);

    void insertarUsuarioEjemplo();  // <--- AGREGÁS ESTA LÍNEA


};

#endif // LOGIN_H
