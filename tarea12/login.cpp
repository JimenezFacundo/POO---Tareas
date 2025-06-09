#include "login.h"
#include "ui_login.h"
#include <QDebug>
#include <QString>
#include <QUrl>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>

Login::Login(QWidget *parent) : QWidget(parent), ui(new Ui::Login)
{
    ui->setupUi(this);
    manager = new QNetworkAccessManager(this);
    ui->leUsuario->setFocus();
    ui->qtemplabel->setText("");

    connect(ui->pbValidar, SIGNAL(pressed()), this, SLOT(slot_validar()));
    connect(ui->leClave, SIGNAL(returnPressed()), this, SLOT(slot_validar()));

    obtenerClima();
}

Login::~Login()
{
    delete ui;
}

void Login::obtenerClima()
{
    QUrl url("http://api.weatherapi.com/v1/current.json?key=3a6126c9f1ee4358823223119251405&q=cordoba,argentina");
    QNetworkRequest request(url);

    QNetworkReply *reply = manager->get(request);

    connect(reply, &QNetworkReply::finished, this, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray response = reply->readAll();
            QJsonDocument jsonDoc = QJsonDocument::fromJson(response);
            QJsonObject jsonObj = jsonDoc.object();

            QString temp = QString::number(jsonObj["current"].toObject()["temp_c"].toDouble());
            QString condition = jsonObj["current"].toObject()["condition"].toObject()["text"].toString();

            QString textoClima = "Temp: " + temp + "°C - " + condition;

            ui->qtemplabel->setText(textoClima);
            qDebug() << textoClima;

        } else {
            qDebug() << "Error al obtener clima:" << reply->errorString();
        }
        reply->deleteLater();
    });
}

void Login::slot_validar()
{
    const QString USUARIO_VALIDO = "admin";
    const QString CLAVE_VALIDA = "1234";

    if (ui->leUsuario->text() == USUARIO_VALIDO && ui->leClave->text() == CLAVE_VALIDA)  {
        qDebug() << "Usuario valido";
        qDebug() << "Login Exitoso";
        this->close();
    }
    else {
        qDebug() << "Usuario no valido";
    }
}
