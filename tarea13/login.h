#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class Login : public QWidget {
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void onImageDownloaded(QNetworkReply *reply);
    void onLoginClicked();

private:
    QLineEdit *lineEditUser;
    QLineEdit *lineEditPass;
    QPushButton *btnLogin;
    QLabel *backgroundLabel;
    QNetworkAccessManager *manager;

    void setupUI();
    void descargarFondo();
};

#endif // LOGIN_H
