#include "login.h"
#include "ventana.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include <QPalette>
#include <QBrush>
#include <QImage>

Login::Login(QWidget *parent) : QWidget(parent) {
    setupUI();

    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onImageDownloaded(QNetworkReply*)));

    descargarFondo();
}

Login::~Login() {}

void Login::setupUI() {
    this->resize(400, 300);
    this->setWindowTitle("Login");

    backgroundLabel = new QLabel(this);
    backgroundLabel->setGeometry(0, 0, 400, 300);
    backgroundLabel->lower();

    lineEditUser = new QLineEdit(this);
    lineEditUser->setPlaceholderText("Usuario");

    lineEditPass = new QLineEdit(this);
    lineEditPass->setPlaceholderText("Contraseña");
    lineEditPass->setEchoMode(QLineEdit::Password);

    btnLogin = new QPushButton("Iniciar sesión", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addStretch();
    layout->addWidget(lineEditUser);
    layout->addWidget(lineEditPass);
    layout->addWidget(btnLogin);
    layout->addStretch();

    setLayout(layout);

    connect(btnLogin, SIGNAL(clicked()), this, SLOT(onLoginClicked()));
}

void Login::descargarFondo() {
    QUrl url("https://picsum.photos/800/600");
    QNetworkRequest request(url);
    manager->get(request);
}

void Login::onImageDownloaded(QNetworkReply *reply) {
    QImage image;
    if (image.loadFromData(reply->readAll())) {
        QPalette palette;
        palette.setBrush(this->backgroundRole(), QBrush(image.scaled(this->size(), Qt::KeepAspectRatioByExpanding)));
        this->setPalette(palette);
        this->setAutoFillBackground(true);
    }
    reply->deleteLater();
}

void Login::onLoginClicked() {
    QString user = lineEditUser->text();
    QString pass = lineEditPass->text();

    if (user == "admin" && pass == "1234") {
        this->hide();
        Ventana *v = new Ventana;
        v->showFullScreen();
    } else {
        QMessageBox::warning(this, "Error", "Usuario o contraseña incorrectos");
    }
}
