#include "MenuAluguel.h"
#include "ui_MenuAluguel.h"
#include <qicon.h>
#include "CondutorDAO.h"
#include "Condutor.h"
#include "listarcondutores.h"
#include "listarclientes.h"
#include <QMessageBox>
#include "AluguelDAO.h"
#include "listarcarros.h"
#include "AluguelDAO.h"
#include <QInputDialog>
#include <QDir>
#include <iostream>
#include "Laudo.h"
#include <QFileDialog>
#include <Laudo.h>
#include "telalaudo.h"

using namespace std;


MenuAluguel::MenuAluguel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuAluguel),Id("data/idAluguel")
{
    ui->setupUi(this);

    ui->botaoSair->setIcon(QIcon(QPixmap("../Locadora_bia/Imagens/close-icon.png")));
    ui->botaoNovo->setIcon(QIcon(QPixmap("../Locadora_bia/Imagens/add-icon.png")));
    ui->Ocorrencia->setIcon(QIcon(QPixmap("../Locadora_bia/Imagens/add-icon.png")));
    ui->botaoBuscar->setIcon(QIcon(QPixmap("../Locadora_bia/Imagens/search-icon.png")));
    ui->botaoEncerrarAluguel->setIcon(QIcon(QPixmap("../Locadora_bia/Imagens/remove-icon.png")));
    ui->botaoComfirmar->setIcon(QIcon(QPixmap("../Locadora_bia/Imagens/ok.png")));
    ui->botaoLaudo->setIcon(QIcon(QPixmap("../Locadora_bia/Imagens/arquivoImg.png")));


    bia::AluguelDAO arqAluguel;

    ui->botaoLaudo->setEnabled(false);
    ui->Ocorrencia->setEnabled(false);
    this->alugueis = arqAluguel.listar();
    this->setEditMode(false);
}

MenuAluguel::~MenuAluguel()
{
    delete ui;
}

void MenuAluguel::on_botaoNovo_clicked()
{
    this->setEditMode(true);
    ui->botaoSair->setText("Cancelar");
    ui->botaoEncerrarAluguel->setEnabled(false);
    ui->botaoLaudo->setEnabled(false);
    ui->Ocorrencia->setEnabled(false);
    ui->botaoLaudo->setEnabled(false);

}

void MenuAluguel::on_botaoSair_clicked()
{
    if(ui->botaoSair->text() == "Sair")
    {
        this->close();
    }
    else
    {
        this->setEditMode(false);
        ui->botaoSair->setText("Sair");
    }
}

// selecionar um condutor
void MenuAluguel::on_pushButtonSelecionarCondutor_clicked()
{
    try{

        bia::Condutor * condutor = new bia::Condutor;
        ListarCondutores Tela(this);
        bool flag=0;

        Tela.setCondutor(condutor,&flag);
        Tela.exec();

        if(flag)
        {
          this->aluguelAtual.setCondutor(*condutor);
          ui->lineEdit_Condutor->setText(this->aluguelAtual.getCondutor().getNome());
          this->aluguelAtual.setCondutor(*condutor);
        }

    }catch(QString & erro){
        QMessageBox::warning(this," ",erro);
    }catch(std::bad_alloc & erro){
        QMessageBox::warning(this," ",erro.what());
    }catch(...){
        QMessageBox::warning(this," ","Erro Desconhecido");
    }
}

// selecionar um cliente
void MenuAluguel::on_pushButtonSelecionarCLiente_clicked()
{
    try{

        bia::Cliente * cliente = new bia::Cliente ;
        ListarClientes Tela(this);
        bool flag = 0;

        Tela.setCliente(cliente,&flag);
        Tela.exec();
        if(flag)
        {
          this->aluguelAtual.setCliente(*cliente);
          ui->lineEdit_Cliente->setText(this->aluguelAtual.getCliente().getNome());
          this->aluguelAtual.setCliente(*cliente);
        }

    }catch(QString & erro){
        QMessageBox::warning(this," ",erro);
    }catch(std::bad_alloc & erro){
        QMessageBox::warning(this," ",erro.what());
    }catch(...){
        QMessageBox::warning(this," ","Erro Desconhecido");
    }
}

// Confirmar um aluguel
void MenuAluguel::on_botaoComfirmar_clicked()
{
    bia::CarroDAO arqCarro;
    bia::Carro carro;

        try{


            if(QMessageBox::question(this,"Tem Certeza?","Tem certeza ?") == QMessageBox::Yes )
            {
              int days = ui->dateEditDevolucao->date().toJulianDay() - ui->dateEditRetirada->date().toJulianDay() + 1;

              if(days <= 0)
                  throw QString("Datas invalidas");
              Id.getNovoId();
              this->validaDados();
              bia::AluguelDAO arqAluguel;
              carro = aluguelAtual.getCarro();
              carro.setSituacao(bia::Carro::Alugado);
              this->aluguelAtual.setCarro(carro);
              this->aluguelAtual.AtivaAluguel();
              this->aluguelAtual.setId(ui->lineEditCodigoAluguel->text().toInt());
              arqAluguel.incluir(this->aluguelAtual);
              this->setEditMode(false);
              this->alugueis->operator [](this->aluguelAtual.getIdentificador()) = this->aluguelAtual;
              ui->botaoSair->setText("Sair");
              arqCarro.alterar(carro);
              bia::Relatorio::append("Carro " + carro.getPlaca().getPlaca() + " alugado para " + this->aluguelAtual.getCliente().getNome() + ".");

            }

        }catch(QString & erro){
            QMessageBox::warning(this," ",erro);
        }catch(std::bad_alloc & erro){
            QMessageBox::warning(this," ",erro.what());
        }catch(...){
            QMessageBox::warning(this," ","Erro Desconhecido");
        }

}

//setar data
void MenuAluguel::on_calendarWidget_Retirada_activated(const QDate &date)
{
    ui->dateEditRetirada->setDate(date);
}

//setar data
void MenuAluguel::on_calendarWidget_activated(const QDate &date)
{
    ui->dateEditDevolucao->setDate(date);
}

//setar data
void MenuAluguel::on_calendarWidget_clicked(const QDate &date)
{
    ui->dateEditDevolucao->setDate(date);
}

//setar data
void MenuAluguel::on_calendarWidget_Retirada_clicked(const QDate &date)
{
    ui->dateEditRetirada->setDate(date);
}



void MenuAluguel::on_pushButtonEcolherCarro_clicked()
{
    try{

        bia::Carro * carro = new bia::Carro;
        bool flag = 0;
        ListarCarros Tela(this);
        Tela.setCarro(carro,&flag);
        Tela.exec();

        if(flag )
        {
          ui->lineEditCorCarro->setText(carro->getCor());
          ui->lineEditMarcaCarro->setText(carro->getModelo().getMarca().getMarca());
          ui->lineEditNomeCarro->setText(carro->getModelo().getModelo());
          ui->lineEditCategoria->setText(carro->getCategoria().getCategoria());
          ui->lineEditPlaca->setText(carro->getPlaca().getPlaca());

          if(ui->comboBox_Finaldade->currentText() == "Pessoal")
            ui->lineEditValorLocao->setText(QString::number(carro->getCategoria().getValorLocacaoPessoal()));
          else
            ui->lineEditValorLocao->setText(QString::number(carro->getCategoria().getValorLocacaoTrabalho()));

          this->aluguelAtual.setCarro(*carro);
          this->updateValorTotal();
          ui->label_7->setPixmap(QPixmap("cars/"+carro->getPlaca().getPlaca()));
          ui->label_7->setScaledContents(true);
        }

    }catch(QString & erro){
        QMessageBox::warning(this," ",erro);
    }catch(std::bad_alloc & erro){
        QMessageBox::warning(this," ",erro.what());
    }catch(...){
        QMessageBox::warning(this," ","Erro Desconhecido");
    }
}




void MenuAluguel::updateValor()
{
    if(ui->comboBox_Finaldade->currentIndex() == 0) return;
}

void MenuAluguel::setAluguelTela()
{
    ui->lineEditCategoria->setText(aluguelAtual.getCarro().getCategoria().getCategoria());
    ui->lineEditCorCarro->setText(aluguelAtual.getCarro().getCor());
    ui->lineEditMarcaCarro->setText(aluguelAtual.getCarro().getModelo().getMarca().getMarca());
    ui->lineEditNomeCarro->setText(aluguelAtual.getCarro().getModelo().getModelo());
    ui->lineEditPlaca->setText(aluguelAtual.getCarro().getPlaca().getPlaca());

    if(aluguelAtual.getFinalidade() == "Pessoal")
      ui->lineEditValorLocao->setText(QString::number(aluguelAtual.getCarro().getCategoria().getValorLocacaoPessoal()));
    else
      ui->lineEditValorLocao->setText(QString::number(aluguelAtual.getCarro().getCategoria().getValorLocacaoTrabalho()));

    ui->lineEdit_Cliente->setText(aluguelAtual.getCliente().getNome());
    ui->lineEdit_Condutor->setText(aluguelAtual.getCondutor().getNome());
    ui->dateEditDevolucao->setDate(aluguelAtual.getDataDevolucaoQdate());
    ui->dateEditRetirada->setDate(aluguelAtual.getDataRetiradaQdate());
    ui->lineEdit_Cliente->setText(this->aluguelAtual.getCliente().getNome());
    ui->comboBox_Finaldade->setItemText(0,aluguelAtual.getFinalidade());
    ui->lineEditCodigoAluguel->setText(QString::number(this->aluguelAtual.getIdentificador()));

}

void MenuAluguel::setSearchMode()
{
    this->setEditMode(false);
    ui->Ocorrencia->setEnabled(true);
    ui->botaoLaudo->setEnabled(true);
    ui->botaoEncerrarAluguel->setEnabled(true);
}

void MenuAluguel::validaDados()
{
    if(ui->lineEdit_Cliente->text().isEmpty())
        throw QString("Cliente não selecionado");
    if(ui->lineEdit_Condutor->text().isEmpty())
        throw QString("Condutor não selecionado");
    if(ui->lineEditNomeCarro->text().isEmpty())
        throw QString("Carro não selecionado");
    if(ui->dateEditDevolucao->date().isNull())
        throw QString("Data de devolucao invalida");
    if(ui->dateEditRetirada->date().isNull())
        throw QString("Data de retirada invalida");

}


void MenuAluguel::setEditMode(bool current)
{
    ui->botaoComfirmar->setEnabled(current);
    ui->pushButtonEcolherCarro->setEnabled(current);
    ui->pushButtonSelecionarCLiente->setEnabled(current);
    ui->pushButtonSelecionarCondutor->setEnabled(current);
    ui->comboBox_Finaldade->setEnabled(current);
    ui->dateEditDevolucao->setEnabled(current);
    ui->dateEditRetirada->setEnabled(current);
    ui->dateEditDevolucao->clear();
    ui->dateEditDevolucao->clear();
    ui->tabWidget->setEnabled(current);
    ui->botaoEncerrarAluguel->setEnabled(current);
    ui->botaoBuscar->setEnabled(!current);
    ui->comboBox_Finaldade->clear();
    this->aluguelAtual.setFinalidade("Pessoal");
    ui->comboBox_Finaldade->addItem("Pessoal");
    ui->comboBox_Finaldade->addItem("Trabalho");
    ui->lineEditCodigoAluguel->setText(QString::number(Id.getNovoId()));
    Id.removeUltimoId();

    this->LimparTela();


}

void MenuAluguel::on_botaoBuscar_clicked()
{
    int id = 0;

    try{
        id = QInputDialog::getInt(this,"Codigo do Aluguel","Codigo do Aluguel : ");
        if(this->alugueis->find(id) == this->alugueis->end())
        {
           ui->botaoEncerrarAluguel->setEnabled(false);
           throw QString(" Codigo de aluguel Invalidosk ! ");
        }
        this->aluguelAtual = this->alugueis->operator [](id);
        if(aluguelAtual.isAtivo() == false)
            throw QString(" Aluguel já foi encerrado !");

        this->setAluguelTela();
        ui->label_7->setPixmap(QPixmap("cars/"+ aluguelAtual.getCarro().getPlaca().getPlaca()));
        ui->label_7->setScaledContents(true);

        ui->Ocorrencia->setEnabled(true);
        ui->botaoLaudo->setEnabled(true);
        ui->botaoEncerrarAluguel->setEnabled(true);

    }catch(QString & erro){
        QMessageBox::warning(this," ",erro);
    }catch(std::bad_alloc & erro){
        QMessageBox::warning(this," ",erro.what());
    }catch(...){
        QMessageBox::warning(this," ","Erro Desconhecido");
    }
}

void MenuAluguel::on_botaoEncerrarAluguel_clicked()
{
    bia::AluguelDAO arqAluguel;
    bia::Carro carro;
    bia::CarroDAO arqCarro;

    try{
        if(QMessageBox::question(this,"Tem Certeza?","Tem certeza ?")  == QMessageBox::Yes)
        {
            this->aluguelAtual = this->alugueis->operator [](ui->lineEditCodigoAluguel->text().toInt());
            ui->botaoEncerrarAluguel->setEnabled(false);
            aluguelAtual.DesativaAluguel();
            this->alugueis->operator [](aluguelAtual.getIdentificador()) = aluguelAtual;
            arqAluguel.incluir(this->alugueis);
            this->setEditMode(false);
            int km = QInputDialog::getInt(this,"Kilometragem do carro","Digite a kilometragem atual do carro");
            carro = aluguelAtual.getCarro();
            carro.setSituacao(bia::Carro::Disponivel);
            carro.setKmRodados(km);
            arqCarro.alterar(carro);
            bia::Relatorio::append("Carro " + carro.getPlaca().getPlaca() + " alugado para " + this->aluguelAtual.getCliente().getNome() + " devolvido.");

        }
    }catch(QString & erro){
        QMessageBox::warning(this," ",erro);
    }catch(std::bad_alloc & erro){
        QMessageBox::warning(this," ",erro.what());
    }catch(...){
        QMessageBox::warning(this," ","Erro Desconhecido");
    }
}

void MenuAluguel::LimparTela()
{
    ui->lineEditCategoria->clear();
    ui->lineEditCorCarro->clear();
    ui->lineEditMarcaCarro->clear();
    ui->lineEditNomeCarro->clear();
    ui->lineEditPlaca->clear();
    ui->lineEditValorLocao->clear();
    ui->lineEdit_Cliente->clear();
    ui->lineEdit_Condutor->clear();
    ui->dateEditDevolucao->clear();
    ui->dateEditRetirada->clear();
}

void MenuAluguel::on_Ocorrencia_clicked()
{
    bia::OcorrenciaDAO arqOcorrencia;
    TelaOcorrencias Tela;
    try{

        bia::Ocorrencia ocorrencia;
        bool flag = 0;
        Tela.setOcorrenciaTela(&ocorrencia,&flag);
        Tela.exec();
        if(flag)
        {
          this->aluguelAtual.setOcorrencia(ocorrencia);
            arqOcorrencia.incluir(ocorrencia,this->aluguelAtual.getIdentificador());
        }
    }catch(QString & erro){
        QMessageBox::warning(this," ",erro);
    }catch(std::bad_alloc & erro){
        QMessageBox::warning(this," ",erro.what());
    }catch(...){
        QMessageBox::warning(this," ","Erro Desconhecido");
    }
}



void MenuAluguel::on_dateEditRetirada_dateChanged(const QDate &date)
{
    this->aluguelAtual.setDataRetirada(date);
    this->updateValorTotal();

}

void MenuAluguel::updateValorTotal()
{
    int days = ui->dateEditDevolucao->date().toJulianDay() - ui->dateEditRetirada->date().toJulianDay() + 1;
    if(days <= 0 || ui->lineEditMarcaCarro->text().isEmpty())
    {
      ui->lineEditValorTotal->setText(QString::number(0));
      return;
    }

    ui->lineEditValorTotal->setText(QString::number(this->aluguelAtual.getValorAlugel()));
}

void MenuAluguel::setCarImageTela(QString Placa)
{
    ui->label_7->setPixmap(QPixmap("cars/"+Placa));
    ui->label_7->setScaledContents(true);
}

void MenuAluguel::on_dateEditDevolucao_dateChanged(const QDate &date)
{
    this->aluguelAtual.setDataDevolucao(date);
    this->updateValorTotal();
}

void MenuAluguel::on_botaoLaudo_clicked()
{

    try{

        TelaLaudo Tela;
        bia::Laudo laudo = this->aluguelAtual.getLaudo();
        QString aux = laudo.getDescricao();
        Tela.setLaudo(&aux);
        Tela.setTela();
        Tela.exec();

    }catch(QString & erro){
        QMessageBox::warning(this," ",erro);
    }catch(std::bad_alloc & erro){
        QMessageBox::warning(this," ",erro.what());
    }catch(...){
        QMessageBox::warning(this," ","Erro Desconhecido");
    }
}

// setar a finalidade
void MenuAluguel::on_comboBox_Finaldade_activated(const QString &arg1)
{
    this->aluguelAtual.setFinalidade(arg1);
    if(ui->lineEditPlaca->text().isEmpty()) return;
    bia::Carro carro = this->aluguelAtual.getCarro();

    if(arg1 == "Pessoal")
        ui->lineEditValorLocao->setText(QString::number(carro.getCategoria().getValorLocacaoPessoal()));
    else
        ui->lineEditValorLocao->setText(QString::number(carro.getCategoria().getValorLocacaoTrabalho()));

    this->updateValorTotal();
}
