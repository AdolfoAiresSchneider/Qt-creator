#include "CadastrarCondutor.h"
#include "ui_CadastrarCondutor.h"

CadastrarCondutor::CadastrarCondutor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CadastrarCondutor)
{
    ui->setupUi(this);
}

CadastrarCondutor::~CadastrarCondutor()
{
    delete ui;
}
