#include "widget.h"
#include "ui_widget.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Crear elementos manualmente (sin Qt Designer)
    spinDosis = new QDoubleSpinBox;
    spinDosis->setRange(0.1, 1000.0);
    spinDosis->setDecimals(1);
    spinDosis->setSingleStep(0.5);

    btnAgregar = new QPushButton("Agregar");
    btnSumar = new QPushButton("Sumar");
    btnComparar = new QPushButton("Comparar");

    listaCajas = new QListWidget;
    listaCajas->setSelectionMode(QAbstractItemView::MultiSelection);
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(spinDosis);
    layout->addWidget(btnAgregar);
    layout->addWidget(listaCajas);

    QHBoxLayout* botonesLayout = new QHBoxLayout;
    botonesLayout->addWidget(btnSumar);
    botonesLayout->addWidget(btnComparar);
    layout->addLayout(botonesLayout);

    setLayout(layout);
    setWindowTitle("Gestión de Medicamentos - APROSS");

    // Conexión a base de datos
    AdminDBMedicamentos::getInstancia()->conectar();
    cargarLista();

    // Conexión de botones
    connect(btnAgregar, SIGNAL(clicked()), this, SLOT(agregarCaja()));
    connect(btnSumar, SIGNAL(clicked()), this, SLOT(sumarCajas()));
    connect(btnComparar, SIGNAL(clicked()), this, SLOT(compararCajas()));
}

Widget::~Widget() {
    delete ui;
}

void Widget::cargarLista() {
    listaCajas->clear();
    QList<CajaMedicamento> cajas = AdminDBMedicamentos::getInstancia()->obtenerTodas();
    for (const CajaMedicamento& caja : cajas) {
        QListWidgetItem* item = new QListWidgetItem(caja.toString());
        item->setData(Qt::UserRole, caja.getId());
        listaCajas->addItem(item);
    }
}

void Widget::agregarCaja() {
    float dosis = spinDosis->value();
    if (!AdminDBMedicamentos::getInstancia()->insertarCaja(dosis)) {
        QMessageBox::warning(this, "Error", "No se puede agregar: excede el máximo de 1000 dosis.");
        return;
    }
    cargarLista();
}

void Widget::sumarCajas() {
    QList<QListWidgetItem*> seleccionados = listaCajas->selectedItems();
    if (seleccionados.size() != 2) {
        QMessageBox::information(this, "Atención", "Seleccioná exactamente 2 cajas para sumar.");
        return;
    }

    int id1 = seleccionados[0]->data(Qt::UserRole).toInt();
    int id2 = seleccionados[1]->data(Qt::UserRole).toInt();

    CajaMedicamento c1(0, 0), c2(0, 0);
    for (const CajaMedicamento& c : AdminDBMedicamentos::getInstancia()->obtenerTodas()) {
        if (c.getId() == id1) c1 = c;
        if (c.getId() == id2) c2 = c;
    }

    CajaMedicamento resultado = c1 + c2;
    if (!AdminDBMedicamentos::getInstancia()->insertarCaja(resultado.getDosisTotales())) {
        QMessageBox::warning(this, "Error", "La suma excede el límite de 1000 dosis.");
        return;
    }

    cargarLista();
}

void Widget::compararCajas() {
    QList<QListWidgetItem*> seleccionados = listaCajas->selectedItems();
    if (seleccionados.size() != 2) {
        QMessageBox::information(this, "Atención", "Seleccioná exactamente 2 cajas para comparar.");
        return;
    }

    int id1 = seleccionados[0]->data(Qt::UserRole).toInt();
    int id2 = seleccionados[1]->data(Qt::UserRole).toInt();

    CajaMedicamento c1(0, 0), c2(0, 0);
    for (const CajaMedicamento& c : AdminDBMedicamentos::getInstancia()->obtenerTodas()) {
        if (c.getId() == id1) c1 = c;
        if (c.getId() == id2) c2 = c;
    }

    qDebug() << "Comparación de cajas:" << c1.toString() << "=="
             << c2.toString() << "->" << (c1 == c2);
}
