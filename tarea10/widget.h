#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

class Widget : public QWidget
{
    Q_OBJECT

private slots:
    void validarUsuario();

private:
    QLineEdit *lineEditUsuario;
    QLineEdit *lineEditClave;
    QPushButton *botonAceptar;
    QLabel *labelEstado;

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};
#endif // WIDGET_H
