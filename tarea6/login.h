#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include "formulario.h"

class Login : public QWidget {
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);

private slots:
    void verificarLogin();

private:
    QLineEdit *usuarioEdit;
    QLineEdit *claveEdit;
};

#endif // LOGIN_H
