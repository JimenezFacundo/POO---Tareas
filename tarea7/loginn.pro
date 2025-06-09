QT += core gui widgets

TARGET = loginn
TEMPLATE = app

SOURCES += main.cpp \
           form.cpp \
           widget.cpp

HEADERS += form.h \
           widget.h

FORMS += form.ui

# Si tienes más archivos .cpp que usan Q_OBJECT, deben ser agregados aquí
