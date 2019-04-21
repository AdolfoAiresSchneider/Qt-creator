#include "CadastrarModelo.h"
#include "ui_CadastrarModelo.h"

CadastrarModelo::CadastrarModelo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CadastrarModelo)
{
    ui->setupUi(this);
}

CadastrarModelo::~CadastrarModelo()
{
    delete ui;
}
