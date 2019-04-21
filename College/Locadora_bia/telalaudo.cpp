#include "telalaudo.h"
#include "ui_telalaudo.h"

TelaLaudo::TelaLaudo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TelaLaudo)
{
    ui->setupUi(this);
}

TelaLaudo::~TelaLaudo()
{
    delete ui;
}

void TelaLaudo::setTela()
{
    ui->textEdit->setText(*this->laudo);
}
