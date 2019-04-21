#include "aux.h"
#include "ui_aux.h"
#include <QMessageBox>
aux::aux(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aux)
{

    ui->setupUi(this);


}

void aux::setgame(CVenda *aux, int i)
{
    char nome[30];
    aux->vet[i].getnome(nome);
    ui->Nomeedit->setText(nome);
    ui->Codigoedit->setText(QString::number(aux->vet[i].getcod()));
    aux->vet[i].getconsole(nome);
    ui->consoleedit->setText(nome);
    ui->etariaedit->setText(QString::number(aux->vet[i].getetaria()));
    aux->vet[i].getgenero(nome);
    ui->generoedit->setText(nome);
    ui->qtdedit->setText(QString::number(aux->vet[i].getqtd()));
    ui->Valoredit->setText(QString::number(aux->vet[i].getvalor()));
}

aux::~aux()
{
    delete ui;
}
