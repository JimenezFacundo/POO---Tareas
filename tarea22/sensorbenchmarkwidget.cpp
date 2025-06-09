#include "sensorbenchmarkwidget.h"
#include "sensor.h"
#include <QElapsedTimer>
#include <QDebug>

SensorBenchmarkWidget::SensorBenchmarkWidget(QWidget *parent)
    : QWidget(parent)
{
    Sensor sensor;
    const int numIteraciones = 10000000;
    int valorBruto;
    double valorNormalizado;

    QElapsedTimer timer;
    timer.start();
    for (int i = 0; i < numIteraciones; ++i) {
        valorBruto = sensor.getValorBruto();
    }
    qDebug() << "Tiempo getValorBruto(): " << timer.elapsed() << "ms";

    timer.restart();
    for (int i = 0; i < numIteraciones; ++i) {
        valorBruto = sensor.getValorBrutoOffline();
    }
    qDebug() << "Tiempo getValorBrutoOffline(): " << timer.elapsed() << "ms";

    timer.restart();
    for (int i = 0; i < numIteraciones; ++i) {
        valorNormalizado = sensor.getValorNormalizado();
    }
    qDebug() << "Tiempo getValorNormalizado(): " << timer.elapsed() << "ms";

    timer.restart();
    for (int i = 0; i < numIteraciones; ++i) {
        valorNormalizado = sensor.getValorNormalizadoOffline();
    }
    qDebug() << "Tiempo getValorNormalizadoOffline(): " << timer.elapsed() << "ms";
}
