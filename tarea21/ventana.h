#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QStringList>

namespace Ui {
class Ventana;
}

class Ventana : public QWidget {
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = nullptr);
    ~Ventana();

private slots:
    void on_browseButton_clicked();
    void on_downloadButton_clicked();
    void on_htmlDownloaded(QNetworkReply *reply);
    void downloadResource(const QUrl &url);

private:
    Ui::Ventana *ui;
    QNetworkAccessManager *manager;
    QString destinationPath;

    QStringList extractUrlsFromHtml(const QString &html);
};

#endif // VENTANA_H
