#include "cadastrof.h"
#include "ui_cadastrof.h"
#include "flig.h"
#include "findice.h"
#include "arquivo.h"
#include <fstream>
#include <QMessageBox>
using namespace std;

cadastroF::cadastroF(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cadastroF)
{
    ui->setupUi(this);
    funci = new Funcionario;
    ui->atualizarbut->hide();
}

void cadastroF::settela(const char *nome, const char *cpf, const char *cargo)
{
    ui->nome->setText(nome);
    ui->cpf->setText(cpf);
    ui->funcao->setText(cargo);
    ui->atualizarbut->show();
}



cadastroF::~cadastroF()
{
    delete ui;
}

void cadastroF::on_pushButton_2_clicked()
{
    this->hide();
}

void cadastroF::on_pushButton_clicked()
{
    try
    {
        Findice a;
        arquivo b;
        Funcionario aux;

        funci->setnome(ui->nome->text().toStdString().c_str());
        funci->setcontato(ui->contato->text().toLong());
        funci->setcpf(ui->cpf->text().toStdString().c_str());
        funci->setcargo(ui->funcao->text().toStdString().c_str());

        int c = a.gravarid(funci,b.Fgetqtda());

        if(c<0)
        {
           b.FgravarF(funci);
           QMessageBox::information(this," ","Cadastro efetuado com Sucesso");
        }
        else
        {
            b.Fler(&aux,c);
            if(aux.getv())
            {
                if(  QMessageBox::question(this," ","Funcionario já cadastrado, atualizar ?",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
                {
                      QMessageBox::information(this," ","Cadastro efetuado com Sucesso");
                      b.Fsobrescrever(funci,c);///c é a posiçao no arquivo original
                      a.removeid(funci->getcpf());
                      a.gravarid(funci,c);
                }
            }
            else
            {
                if(  QMessageBox::question(this," ","Funcionario deletado, atualizar ?",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
                {
                      QMessageBox::information(this," ","Recadastro efetuado com Sucesso");
                      funci->valida();
                      b.Fsobrescrever(funci,c);
                }
            }
        }
    }
    catch(const int b)
    {
        switch(b)
        {
            case 1:
                QMessageBox::warning(this," ","Nome não digitado!");
            break;
            case 2:
                QMessageBox::warning(this," ","Console não digitado!");
            break;
            case 3:
                QMessageBox::warning(this," ","Faixa etátia incorreta!");
            break;
            case 4:
                QMessageBox::warning(this," ","Genero não digitado!");
            break;
            case 5:
                QMessageBox::warning(this," ","Veifique o valor");
            break;
            case 6:
                QMessageBox::warning(this," ","Quantidade invalida!");
            break;
            case 7:
                QMessageBox::warning(this," ","Posição inexistente!");
            break;
            case 10:
                QMessageBox::warning(this," ","CPF invalido!");
            break;
        }
    }
    catch(const char b)
    {
        QMessageBox::information(this," ","Memoria insufuciente em disco ");
    }
    catch(...)
    {
         QMessageBox::information(this," ","Erro!");
    }
}

void cadastroF::on_Atualizar_clicked()
{
    return;
}
