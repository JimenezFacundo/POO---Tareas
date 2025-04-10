#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include "poste.h"
#include <QVector>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QVector<Poste> postes;
    postes.append(Poste(10, 30.5));
    postes.append(Poste(5, 25.0));
    postes.append(Poste(7, 20.3));
    postes.append(Poste(12, 40.0));
    postes.append(Poste(6, 22.8));

    qDebug() << "Lista original:";
    for (const Poste &p : postes) {
        qDebug() << p.toString();
    }

    // Ordenamiento burbuja por altura
    for (int i = 0; i < postes.size() - 1; ++i) {
        for (int j = 0; j < postes.size() - 1 - i; ++j) {
            if (postes[j].getAltura() > postes[j + 1].getAltura()) {
                Poste temp = postes[j];
                postes[j] = postes[j + 1];
                postes[j + 1] = temp;
            }
        }
    }

    qDebug() << "\nLista ordenada:";
    for (const Poste &p : postes) {
        qDebug() << p.toString();
    }
}

Widget::~Widget()
{
    delete ui;
}
