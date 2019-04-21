#-------------------------------------------------
#
# Project created by QtCreator 2017-05-05T10:49:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjetoAgendaContatos
TEMPLATE = app


SOURCES += main.cpp\
        telaprincipal.cpp \
    Telefone.cpp \
    Contato.cpp \
    crud.cpp \
    contatodao.cpp \
    enumtelefone.cpp

HEADERS  += telaprincipal.h \
    Telefone.h \
    Contato.h \
    crud.h \
    contatodao.h \
    enumtelefone.h

FORMS    += telaprincipal.ui
