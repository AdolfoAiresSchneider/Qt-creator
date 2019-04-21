#include "Devolucao.h"
#include "ui_Devolucao.h"

Devolucao::Devolucao(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Devolucao)
{
    ui->setupUi(this);
}

Devolucao::~Devolucao()
{
    delete ui;
}
