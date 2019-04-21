#-------------------------------------------------
#
# Project created by QtCreator 2016-04-05T19:51:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjetoArquivoTexto
TEMPLATE = app


SOURCES += main.cpp\
        telaprincipal.cpp \
    Aluno.cpp \
    DadosDoArquivo.cpp \
    TemplateMethodOrdenacao.cpp \
    OrdenarPorNome.cpp \
    OrdenarPorMatricula.cpp \
    ordenarporanosemestrenome.cpp \
    ordenarporsituacaonome.cpp

HEADERS  += telaprincipal.h \
    Aluno.h \
    DadosDoArquivo.h \
    TemplateMethodOrdenacao.h \
    OrdenarPorNome.h \
    OrdenarPorMatricula.h \
    ordenarporanosemestrenome.h \
    ordenarporsituacaonome.h

FORMS    += telaprincipal.ui
