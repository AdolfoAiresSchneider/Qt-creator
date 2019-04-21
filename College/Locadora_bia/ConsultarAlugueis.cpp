#include "ConsultarAlugueis.h"
#include "ui_ConsultarAlugueis.h"
#include "QTableWidgetItem"
#include "QMessageBox"
#include "MenuAluguel.h"


ConsultarAlugueis::ConsultarAlugueis(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConsultarAlugueis)
{
    ui->setupUi(this);
    ui->tableWidget_Alugueis->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_Alugueis->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->pushButtonPesquisar->setIcon(QIcon(QPixmap("../Locadora_bia/Imagens/search-icon.png")));
    bia::AluguelDAO arqAluguel;
    this->alugueis = arqAluguel.listar();
    this->listarAlugueisTela();
}

ConsultarAlugueis::~ConsultarAlugueis()
{
    delete ui;
}

void ConsultarAlugueis::on_pushButtonPesquisar_clicked()
{
    this->listarAlugueisTela(ui->lineEdit_CodigoAluguel->text());
}


void ConsultarAlugueis::listarAlugueisTela(QString nome)
{
    bia::Aluguel aux;
    int linha  = 0;

    for(std::map<int,bia::Aluguel>::const_iterator it = this->alugueis->begin();it!=this->alugueis->end();it++)
    {
        aux = it->second;
        if(aux.isAtivo() &&( aux.getCliente().getNome() == nome || aux.getCondutor().getNome() == nome))
        {
            ui->tableWidget_Alugueis->setRowCount(linha+1);
            ui->tableWidget_Alugueis->setItem(linha,0,new QTableWidgetItem(QString::number(aux.getIdentificador())));
            ui->tableWidget_Alugueis->setItem(linha,1,new QTableWidgetItem(aux.getCliente().getNome()));
            ui->tableWidget_Alugueis->setItem(linha,2,new QTableWidgetItem(aux.getCondutor().getNome()));
            ui->tableWidget_Alugueis->setItem(linha,3,new QTableWidgetItem(aux.getDataRetirada()));
            ui->tableWidget_Alugueis->setItem(linha,4,new QTableWidgetItem(aux.getDataDevolucao()));
            ui->tableWidget_Alugueis->setItem(linha,5,new QTableWidgetItem(QString::number(aux.getValorAlugel())));
            linha++;
        }
    }
    if(linha == 0 )
    {
        QMessageBox::warning(this,"","Nome nao encontrado !! ");
        this->listarAlugueisTela();
    }

}


void ConsultarAlugueis::listarAlugueisTela()
{
    bia::Aluguel aux;
    int linha  = 0;

    for(std::map<int,bia::Aluguel>::const_iterator it = this->alugueis->begin();it!=this->alugueis->end();it++)
    {
        aux = it->second;
        if(aux.isAtivo())
        {
            ui->tableWidget_Alugueis->setRowCount(linha+1);
            ui->tableWidget_Alugueis->setItem(linha,0,new QTableWidgetItem(QString::number(aux.getIdentificador())));
            ui->tableWidget_Alugueis->setItem(linha,1,new QTableWidgetItem(aux.getCliente().getNome()));
            ui->tableWidget_Alugueis->setItem(linha,2,new QTableWidgetItem(aux.getCondutor().getNome()));
            ui->tableWidget_Alugueis->setItem(linha,3,new QTableWidgetItem(aux.getDataRetirada()));
            ui->tableWidget_Alugueis->setItem(linha,4,new QTableWidgetItem(aux.getDataDevolucao()));
            ui->tableWidget_Alugueis->setItem(linha,5,new QTableWidgetItem(QString::number(aux.getValorAlugel())));
            linha++;
        }
    }
}


void ConsultarAlugueis::on_tableWidget_Alugueis_clicked(const QModelIndex &index)
{
    MenuAluguel Tela;
    bia::Aluguel aux = this->alugueis->operator [](ui->tableWidget_Alugueis->item(index.row(),0)->text().toInt());

    try{

        if(QMessageBox::question(this,"","Deseja vizualizar as informações deste aluguel ?") == QMessageBox::Yes)
        {
            Tela.setAtributeAluguel(&aux);
            Tela.setSearchMode();
            Tela.setCarImageTela(aux.getCarro().getPlaca().getPlaca());
            Tela.setAluguelTela();
            this->close();
            Tela.exec();

        }

    }
    catch(QString & erro){
        QMessageBox::warning(this," ",erro);
    }catch(std::bad_alloc & erro){
        QMessageBox::warning(this," ",erro.what());
    }catch(...){
        QMessageBox::warning(this," ","Erro Desconhecido");
    }
}
