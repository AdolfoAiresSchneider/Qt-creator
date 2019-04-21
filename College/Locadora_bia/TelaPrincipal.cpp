#include "TelaPrincipal.h"
#include "ui_TelaPrincipal.h"
#include "MenuCliente.h"
#include "ConsultarCliente.h"
#include "ConsultarAlugueis.h"
#include "MenuCondutor.h"
#include "MenuCliente.h"
#include "MenuMarca.h"
#include "MenuVenda.h"




TelaPrincipal::TelaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TelaPrincipal)
{
    ui->setupUi(this);

    system ("mkdir -p data");  // cria a pasta "data"
    system ("mkdir -p cars");  // cria a pasta "data"
}

TelaPrincipal::~TelaPrincipal()
{
    delete ui;
}

void TelaPrincipal::on_botaoCliente_clicked()
{
    MenuCliente tela(this);
    this->hide();
    tela.exec();
    this->show();
}


void TelaPrincipal::on_botaoCarro_clicked()
{
    this->hide();
    MenuCarro tela(this);
    tela.setModal(true);
    tela.exec();
    this->move(tela.pos());
    this->show();
}

void TelaPrincipal::on_botaoAlugar_clicked()
{  try{

        MenuAluguel tela(this);
        this->hide();
        tela.exec();
        this->show();

    }catch(QString & erro){
        QMessageBox::warning(this," ",erro);
    }catch(std::bad_alloc & erro){
        QMessageBox::warning(this," ",erro.what());
    }catch(...){
        QMessageBox::warning(this," ","Erro Desconhecido");
    }
}

void TelaPrincipal::on_botaoCondutor_clicked()
{
    ConsultarCliente tela(this);
    this->hide();
    tela.exec();
    this->move(tela.pos());
    this->show();
}

void TelaPrincipal::on_botaoConsultarAlugueis_clicked()
{
    try{

        ConsultarAlugueis tela(this);
        this->hide();
        tela.exec();
        this->move(tela.pos());
        this->show();

    }catch(QString & erro){
        QMessageBox::warning(this," ",erro);
    }catch(std::bad_alloc & erro){
        QMessageBox::warning(this," ",erro.what());
    }catch(...){
        QMessageBox::warning(this," ","Erro Desconhecido");
    }
}


void TelaPrincipal::on_botaoCadastrarCondutor_clicked()
{
    MenuCondutor tela(this);
    this->hide();
    tela.exec();
    this->move(tela.pos());
    this->show();
}

void TelaPrincipal::on_botaoMarcas_clicked()
{
  MenuMarca tela(this);
  this->hide();
  tela.exec();
  this->move(tela.pos());
  this->show();
}

void TelaPrincipal::on_botaoModelos_clicked()
{
  MenuModelo tela(this);
  this->hide();
  tela.exec();
  this->move(tela.pos());
  this->show();
}

void TelaPrincipal::on_botaoCategoria_clicked()
{
  MenuCategoria tela(this);
  this->hide();
  tela.exec();
  this->move(tela.pos());
  this->show();
}


void TelaPrincipal::on_botaoVenda_clicked()
{
    try{
        MenuVenda tela(this);
        this->hide();
        tela.exec();
        this->show();
    }catch(QString & erro){
        QMessageBox::warning(this," ",erro);
    }catch(std::bad_alloc & erro){
        QMessageBox::warning(this," ",erro.what());
    }catch(...){
        QMessageBox::warning(this," ","Erro Desconhecido");
    }
}
