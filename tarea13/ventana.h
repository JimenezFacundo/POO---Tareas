#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QLabel>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class Ventana : public QWidget {
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = nullptr);
    ~Ventana();

private slots:
    void onImageDownloaded(QNetworkReply *reply);

private:
    QLabel *imageLabel;
    QNetworkAccessManager *manager;

    void setupUI();
    void descargarImagen();
};

#endif // VENTANA_H
