#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Ventana; }
QT_END_NAMESPACE

class Ventana : public QWidget {
    Q_OBJECT

public:
    explicit Ventana(const QString& nombre, const QString& ultimoIngreso, QWidget *parent = nullptr);
    ~Ventana();

private:
    Ui::Ventana *ui;
};
#endif // VENTANA_H
