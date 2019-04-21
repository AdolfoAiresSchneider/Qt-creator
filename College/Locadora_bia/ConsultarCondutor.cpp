#include "ConsultarCondutor.h"
#include "ui_ConsultarCondutor.h"

ConsultarCondutor::ConsultarCondutor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConsultarCondutor)
{
    ui->setupUi(this);
}

ConsultarCondutor::~ConsultarCondutor()
{
    delete ui;
}
