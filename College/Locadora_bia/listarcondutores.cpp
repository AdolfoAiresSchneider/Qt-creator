//----

#include <QMessageBox>
#include "listarcondutores.h"
#include "ui_listarcondutores.h"
#include <QTableWidgetItem>
#include <iostream>

using namespace std;

ListarCondutores::ListarCondutores(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListarCondutores)
{
    ui->setupUi(this);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->procurar->setIcon(QIcon(QPixmap("../Locadora_bia/Imagens/search-icon.png")));

    CondutorDAO arqCondutores;
    this->condutores = arqCondutores.listar();
    this->listarContatosTela();
}

void ListarCondutores::listarContatosTela()
{
    bia::Cnh::cnh_t cnh;
    bia::Condutor aux;
    int linha = 0;
    ui->tableWidget->setRowCount(this->condutores->size());

    for(std::map<bia::Cnh::cnh_t,bia::Condutor>::const_iterator it = condutores->begin();it!=this->condutores->end();it++)
    {
        cnh = it->first;
        aux = it->second;
        ui->tableWidget->setItem(linha,0,new QTableWidgetItem(aux.getNome()));
        ui->tableWidget->setItem(linha,1, new QTableWidgetItem (QString::number(cnh)));

        linha++;
    }
}

ListarCondutores::~ListarCondutores()
{
    delete ui;
}

void ListarCondutores::on_pushButtonSelecionar_clicked()
{
    if(*flag)
    {
      this->close();
    }
    else
        QMessageBox::warning(this,"","Nenhum condutor escolhido");
}

void ListarCondutores::on_tableWidget_clicked(const QModelIndex &index)
{
    *condut = this->condutores->operator [](ui->tableWidget->item(index.row(),1)->text().toLongLong());
    *flag = 1;
}

void ListarCondutores::on_pushButton_clicked()
{

}

void ListarCondutores::on_pushButton_2_clicked()
{
    this->close();
}

void ListarCondutores::on_procurar_clicked()
{
    int cnh = ui->lineEditCnh->text().toInt();
    bia::Condutor c;

    if(this->condutores->find(cnh) != this->condutores->end())
    {
        ui->tableWidget->setRowCount(1);
        c = condutores->operator [](cnh);
        ui->tableWidget->setItem(0,0,new QTableWidgetItem(c.getNome()));
        ui->tableWidget->setItem(0,1,new QTableWidgetItem(QString::number(cnh)));
    }
    else
    {
        QMessageBox::warning(this,"","Cliente não econtrado");
        this->listarContatosTela();
    }
}
