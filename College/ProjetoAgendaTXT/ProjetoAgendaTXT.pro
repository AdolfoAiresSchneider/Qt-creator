#-------------------------------------------------
#
# Project created by QtCreator 2017-05-01T16:57:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjetoAgendaTXT
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Contato.cpp \
    ContatoPersistencia.cpp \
    Crud.cpp \
    TelaDeListagem.cpp \
    TransformarDados.cpp

HEADERS  += mainwindow.h \
    Contato.h \
    ContatoPersistencia.h \
    Crud.h \
    TelaDeListagem.h \
    TransformarDados.h

FORMS    += mainwindow.ui \
    TelaDeListagem.ui
