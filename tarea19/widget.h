#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QListWidget>
#include "AdminDBMedicamentos.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget {
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void agregarCaja();
    void sumarCajas();
    void compararCajas();

private:
    Ui::Widget *ui;

    QDoubleSpinBox* spinDosis;
    QPushButton* btnAgregar;
    QPushButton* btnSumar;
    QPushButton* btnComparar;
    QListWidget* listaCajas;

    void cargarLista();
};

#endif // WIDGET_H
