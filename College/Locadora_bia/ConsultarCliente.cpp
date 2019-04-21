#include "ConsultarCliente.h"
#include "ui_ConsultarCliente.h"
#include <qicon.h>

ConsultarCliente::ConsultarCliente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConsultarCliente)
{
    ui->setupUi(this);
    ui->pushButtonPesquisar->setIcon(QIcon(QPixmap("../Locadora_bia/Imagens/search-icon.png")));
}

ConsultarCliente::~ConsultarCliente()
{
    delete ui;
}

void ConsultarCliente::on_pushButtonPesquisar_clicked()
{

}
