#include "relatoriogerencial.h"
#include "ui_relatoriogerencial.h"

RelatorioGerencial::RelatorioGerencial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RelatorioGerencial)
{
    ui->setupUi(this);
}

RelatorioGerencial::~RelatorioGerencial()
{
    delete ui;
}
