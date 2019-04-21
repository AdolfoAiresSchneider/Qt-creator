//---------------------
#include "listarcarros.h"
#include "ui_listarcarros.h"
#include <QStringList>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <iostream>
using namespace std;

ListarCarros::ListarCarros(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListarCarros)
{
    ui->setupUi(this);

    bia::CategoriaDoCarroDAO arqCategoria;
    this->categorias = arqCategoria.listar();

    bia::CarroDAO arqCarro;
    this->carros = arqCarro.listar();
    this->setCategorias();

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
}

void ListarCarros::setCategorias()
{
    QString aux ;
    for(std::map<bia::Id,bia::CategoriaDoCarro>::const_iterator it = this->categorias->begin();it!=this->categorias->end();it++)
    {
        aux += QString::number(it->first) + "-" +  (it->second).getCategoria();
        ui->comboBoxCategorias->addItem(aux);
        aux.clear();
    }
}

void ListarCarros::setCarros( QString categoria)
{
    QStringList lista = QString::fromStdString(categoria.toStdString()).split('-');
    uint idCategoria = lista[0].toInt();
    bia::Carro aux;
    int linha = 0;
    int row = 1;

    try{

        for(std::map<bia::Placa,bia::Carro>::const_iterator it = this->carros->begin();it!=this->carros->end();it++)
        {
            aux = it->second;
            if(aux.getSituacao() != bia::Carro::Disponivel ) continue;
            if(aux.getCategoria().getId() == idCategoria)
            {
                ui->tableWidget->setRowCount(row++);
                ui->tableWidget->setItem(linha,0,new QTableWidgetItem(aux.getModelo().getMarca().getMarca()));
                ui->tableWidget->setItem(linha,1,new QTableWidgetItem(aux.getModelo().getModelo()));
                ui->tableWidget->setItem(linha,2,new QTableWidgetItem(QString::number(aux.getKmRodados())));
                ui->tableWidget->setItem(linha,3,new QTableWidgetItem(aux.getPlaca().getPlaca()));
                linha++;
            }
        }
        if(linha == 0)
            throw QString("Sem carros disponiveis para esta categoria");

    }catch(QString & erro){
        QMessageBox::warning(this," ",erro);
    }catch(std::bad_alloc & erro){
        QMessageBox::warning(this," ",erro.what());
    }catch(...){
        QMessageBox::warning(this," ","Erro Desconhecido");
    }
}

ListarCarros::~ListarCarros()
{
    delete ui;
}

void ListarCarros::on_comboBoxCategorias_activated(const QString &arg1)
{
    this->setCarros(arg1);
}

void ListarCarros::on_tableWidget_clicked(const QModelIndex &index)
{
    try{

        *this->flag = true;
        * this->carro = this->carros->operator [](ui->tableWidget->item(index.row(),3)->text());

    }catch(QString & erro){
        QMessageBox::warning(this," ",erro);
    }catch(std::bad_alloc & erro){
        QMessageBox::warning(this," ",erro.what());
    }catch(...){
        QMessageBox::warning(this," ","Erro Desconhecido");
    }
}


void ListarCarros::on_pushButton_clicked()
{
    this->close();
}

void ListarCarros::on_pushButtonSelecionar_clicked()
{
    if (*this->flag)
        this->close();
    else
        QMessageBox::warning(this, "Erro", "Selecione o carro!");
}
