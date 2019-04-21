//----------------------
#include "listarclientes.h"
#include <qmessagebox.h>
#include <iostream>
#include "ui_listarclientes.h"
#include <map>
#include "Cpf.h"
#include <QTableWidgetItem>
using namespace std;

ListarClientes::ListarClientes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListarClientes)
{
    ui->setupUi(this);
    ClienteDAO arqClientes;
    this->clientes = arqClientes.listar();

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->procurar->setIcon(QIcon(QPixmap("../Locadora_bia/Imagens/search-icon.png")));

    this->ListarClientesTela();


}

void ListarClientes::ListarClientesTela()
{
    bia::Cpf::cpf_t cpf;
    bia::Cliente aux;
    int linha = 0;
    ui->tableWidget->setRowCount(clientes->size());

    for(std::map<bia::Cpf::cpf_t , bia::Cliente>::const_iterator it = clientes->begin();it!=this->clientes->end();it++)
    {

        cpf = it->first;
        aux = it->second;

        cout<<aux.getNome().toStdString()<<endl;

        ui->tableWidget->setItem(linha,0,new QTableWidgetItem(aux.getNome()));
        ui->tableWidget->setItem(linha,1,new QTableWidgetItem(QString::number(cpf)));

        linha++;

    }
}

ListarClientes::~ListarClientes()
{
    delete ui;
}


void ListarClientes::on_pushButtonSelecionar_clicked()
{
    if(*flag)
        this->close();
    else
        QMessageBox::warning(this,"","Nenhum cliente escolhido");
}

void ListarClientes::on_tableWidget_activated(const QModelIndex &index)
{
   *cliente = this->clientes->operator [](ui->tableWidget->item(index.row(),1)->text().toLongLong());
}

void ListarClientes::on_pushButton_2_clicked()
{
    this->close();
}

void ListarClientes::on_procurar_clicked()
{
    int cpf = ui->lineEditcpf->text().toInt();
    bia::Cliente c;

    if(this->clientes->find(cpf) != this->clientes->end())
    {
        ui->tableWidget->setRowCount(1);
        c = clientes->operator [](cpf);
        ui->tableWidget->setItem(0,0,new QTableWidgetItem(c.getNome()));
        ui->tableWidget->setItem(0,1,new QTableWidgetItem(QString::number(cpf)));
    }
    else
    {

        QMessageBox::warning(this,"","Cliente não econtrado");
        this->ListarClientesTela();
    }
}

void ListarClientes::on_tableWidget_clicked(const QModelIndex &index)
{
    *cliente = this->clientes->operator [](ui->tableWidget->item(index.row(),1)->text().toLongLong());
    *flag = 1;
}
