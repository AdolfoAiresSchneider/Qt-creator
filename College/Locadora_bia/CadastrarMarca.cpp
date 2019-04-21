#include "CadastrarMarca.h"
#include "ui_CadastrarMarca.h"

CadastrarMarca::CadastrarMarca(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CadastrarMarca)
{
    ui->setupUi(this);
}

CadastrarMarca::~CadastrarMarca()
{
    delete ui;
}
