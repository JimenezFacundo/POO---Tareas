// ventana.cpp
#include "ventana.h"
#include "ui_ventana.h"

#include <QFileDialog>
#include <QFile>
#include <QDir>
#include <QRegularExpression>
#include <QUrl>
#include <QDebug>
#include <QFileInfo>
#include <QStandardPaths>

Ventana::Ventana(QWidget *parent)
    : QWidget(parent), ui(new Ui::Ventana), manager(new QNetworkAccessManager(this)) {
    ui->setupUi(this);


    connect(ui->downloadButton, SIGNAL(clicked()), this, SLOT(on_downloadButton_clicked()));
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(on_htmlDownloaded(QNetworkReply*)));

    // Establecer carpeta por defecto si no se elige
    destinationPath = QStandardPaths::writableLocation(QStandardPaths::DownloadLocation);
    ui->pathInput->setText(destinationPath);
}

Ventana::~Ventana() {
    delete ui;
}

void Ventana::on_browseButton_clicked() {
    QString dir = QFileDialog::getExistingDirectory(this, tr("Seleccionar carpeta de destino"));
    if (!dir.isEmpty()) {
        destinationPath = dir;
        ui->pathInput->setText(dir);
    }
}

void Ventana::on_downloadButton_clicked() {
    QString urlText = ui->urlInput->text().trimmed();
    if (urlText.isEmpty()) {
        qDebug() << "URL vacía";
        return;
    }

    if (destinationPath.isEmpty()) {
        qDebug() << "Carpeta de destino no seleccionada";
        return;
    }

    QUrl url(urlText);
    if (!url.isValid()) {
        qDebug() << "URL inválida:" << urlText;
        return;
    }

    QNetworkRequest request(url);
    manager->get(request);
}

void Ventana::on_htmlDownloaded(QNetworkReply *reply) {
    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "Error al descargar HTML:" << reply->errorString();
        reply->deleteLater();
        return;
    }

    QString html = reply->readAll();
    QStringList urls = extractUrlsFromHtml(html);

    qDebug() << "Encontradas" << urls.size() << "URLs";

    foreach (const QString &link, urls) {
        QUrl absoluteUrl = reply->url().resolved(QUrl(link));
        downloadResource(absoluteUrl);
    }

    reply->deleteLater();
}

QStringList Ventana::extractUrlsFromHtml(const QString &html) {
    QStringList found;
    QRegularExpression re("(?:src|href)=[\"']([^\"'#]+)[\"']");
    QRegularExpressionMatchIterator i = re.globalMatch(html);
    while (i.hasNext()) {
        QRegularExpressionMatch match = i.next();
        QString url = match.captured(1);
        if (!url.startsWith("data:")) {
            found << url;
        }
    }
    return found;
}

void Ventana::downloadResource(const QUrl &url) {
    QNetworkRequest request(url);
    QNetworkReply *resourceReply = manager->get(request);

    connect(resourceReply, &QNetworkReply::finished, [=]() {
        QByteArray data = resourceReply->readAll();
        QString filename = QFileInfo(url.path()).fileName();
        if (filename.isEmpty()) {
            filename = "index.html";
        }

        QString path = destinationPath + "/" + filename;
        QFile file(path);
        if (file.open(QIODevice::WriteOnly)) {
            file.write(data);
            file.close();
            qDebug() << "Descargado:" << path;
        } else {
            qDebug() << "No se pudo guardar el archivo:" << path;
        }

        resourceReply->deleteLater();
    });
}
