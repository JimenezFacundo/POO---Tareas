#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>

class Formulario : public QWidget {
    Q_OBJECT

public:
    explicit Formulario(QWidget *parent = nullptr);
};

#endif // FORMULARIO_H
