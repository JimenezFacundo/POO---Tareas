QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sensorbenchmark
TEMPLATE = app

SOURCES += \
    main.cpp \
    sensor.cpp \
    sensorbenchmarkwidget.cpp

HEADERS += \
    sensor.h \
    sensorbenchmarkwidget.h
