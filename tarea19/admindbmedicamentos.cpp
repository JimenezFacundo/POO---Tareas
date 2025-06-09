// AdminDBMedicamentos.cpp

#include "AdminDBMedicamentos.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

AdminDBMedicamentos* AdminDBMedicamentos::instancia = nullptr;

AdminDBMedicamentos::AdminDBMedicamentos() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("medicamentos.db");
}

AdminDBMedicamentos* AdminDBMedicamentos::getInstancia() {
    if (!instancia)
        instancia = new AdminDBMedicamentos();
    return instancia;
}

void AdminDBMedicamentos::conectar() {
    if (!db.open()) {
        qDebug() << "Error al conectar con la base de datos:" << db.lastError().text();
        return;
    }

    QSqlQuery query;
    QString crearTabla = R"(
        CREATE TABLE IF NOT EXISTS cajas_medicamentos (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            dosis_totales REAL NOT NULL
        )
    )";
    if (!query.exec(crearTabla)) {
        qDebug() << "Error creando tabla:" << query.lastError().text();
    }
}

float AdminDBMedicamentos::obtenerTotalDosis() {
    QSqlQuery query("SELECT SUM(dosis_totales) FROM cajas_medicamentos");
    if (query.next()) {
        return query.value(0).toFloat();
    }
    return 0.0;
}

bool AdminDBMedicamentos::insertarCaja(float dosis) {
    float totalActual = obtenerTotalDosis();
    if (totalActual + dosis > 1000.0) {
        return false;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO cajas_medicamentos (dosis_totales) VALUES (:dosis)");
    query.bindValue(":dosis", dosis);

    if (!query.exec()) {
        qDebug() << "Error al insertar caja:" << query.lastError().text();
        return false;
    }

    return true;
}

QList<CajaMedicamento> AdminDBMedicamentos::obtenerTodas() {
    QList<CajaMedicamento> lista;
    QSqlQuery query("SELECT id, dosis_totales FROM cajas_medicamentos");

    while (query.next()) {
        int id = query.value(0).toInt();
        float dosis = query.value(1).toFloat();
        lista.append(CajaMedicamento(id, dosis));
    }

    return lista;
}
