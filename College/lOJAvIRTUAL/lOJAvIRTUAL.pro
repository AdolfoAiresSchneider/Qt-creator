QT += core
QT -= gui

CONFIG += c++11

TARGET = lOJAvIRTUAL
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    produtos.cpp \
    pessoa.cpp \
    veiculos.cpp

HEADERS += \
    produtos.h \
    pessoa.h \
    veiculos.h
