#include "ventana.h"
#include <QVBoxLayout>
#include <QImage>
#include <QPixmap>

Ventana::Ventana(QWidget *parent) : QWidget(parent) {
    setupUI();

    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onImageDownloaded(QNetworkReply*)));

    descargarImagen();
}

Ventana::~Ventana() {}

void Ventana::setupUI() {
    this->setWindowTitle("Ventana Principal");

    imageLabel = new QLabel(this);
    imageLabel->setAlignment(Qt::AlignCenter);
    imageLabel->setScaledContents(false);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(imageLabel);
    this->setLayout(layout);
}

void Ventana::descargarImagen() {
    QUrl url("https://picsum.photos/id/40");
    QNetworkRequest request(url);
    manager->get(request);
}

void Ventana::onImageDownloaded(QNetworkReply *reply) {
    QImage image;
    if (image.loadFromData(reply->readAll())) {
        imageLabel->setPixmap(QPixmap::fromImage(image).scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    reply->deleteLater();
}
