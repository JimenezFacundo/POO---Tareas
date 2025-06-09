#include <QApplication>
#include "sensorbenchmarkwidget.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    SensorBenchmarkWidget widget;
    widget.show();

    return app.exec();
}
