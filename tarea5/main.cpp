#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QScreen>
#include <QFileDialog>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QLabel label;

    QString imagePath = QFileDialog::getOpenFileName(
        nullptr,
        "Seleccionar imagen"
        );

    QPixmap pixmap(imagePath);

    QScreen *screen = QGuiApplication::primaryScreen(); //devuelve un puntero al objeto QScreen
    QRect screenGeometry = screen->geometry(); //se encarga de obtener la geometría de la pantalla
    label.setPixmap(pixmap.scaled(screenGeometry.size(), Qt::KeepAspectRatio));

    label.showMaximized();

    return a.exec();
}
