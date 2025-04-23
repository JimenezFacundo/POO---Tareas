#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QScreen>
#include <QFileDialog>
#include <QTimer> // necesario para que se cierre a los 3 segundos

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QLabel label;

    QString imagePath = QFileDialog::getOpenFileName(nullptr,"Seleccionar imagen");

    QPixmap pixmap(imagePath);

    QScreen *screen = QGuiApplication::primaryScreen(); //devuelve un puntero al objeto QScreen
    QRect screenGeometry = screen->geometry(); //se encarga de obtener la geometría de la pantalla
    label.setPixmap(pixmap.scaled(screenGeometry.size(), Qt::KeepAspectRatio));

    label.showMaximized();


    //temporizador para cerrarse en 3 segundos luego de que se abra
    QTimer::singleShot(3000, &a, &QApplication::quit);

    return a.exec();
}
