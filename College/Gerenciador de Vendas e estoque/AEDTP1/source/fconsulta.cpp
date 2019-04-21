#include "fconsulta.h"
#include "ui_fconsulta.h"
#include "findice.h"
using namespace std;
#include <iostream>
#include "lig.h"
#include "arquivo.h"
#include <cstring>

Fconsulta::Fconsulta(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Fconsulta)
{
    ui->setupUi(this);
}

Fconsulta::~Fconsulta()
{
    delete ui;
}

void Fconsulta::on_sair_clicked()
{
    this->close();
}

void Fconsulta::on_procurar_clicked()
{
   try
   {
       Findice procura;
       Funcionario aux;
       arquivo func;
       int c;
       char aux2[30];

       c = procura.getposic(ui->cpfee->text().toLongLong());

       if(c<0)
           QMessageBox::information(this," ","Funcionario não encontrado");
       else
       {

          func.Fler(&aux,c);
          if(aux.getv())
          {
               ui->cpfedit->setText(QString::number(aux.getcpf()));
               aux.getcargo(aux2);
               ui->cargo->setText(aux2);
               ui->cpfedit->setText(QString::number(aux.getcpf()));
               ui->contato->setText(QString::number(aux.getcontato()));
               aux.getnome(aux2);
               ui->nome->setText(aux2);
          }
          else
          {
              QMessageBox::warning(this,"","Funcionario nao encontrado");

          }
       }

   }
    catch(const char b)
    {
        QMessageBox::warning(this,"","Memoria insufuciente !");
    }
    catch(...)
    {
        QMessageBox::warning(this,"","erro !");
    }
}

void Fconsulta::on_pushButton_clicked()////excluir um funcionario!!!!!!!!!!!!!!!!!!!!!!!!
{

    Findice funcionario;
    arquivo arq;
    Funcionario a;
    int c;


    c=funcionario.getposic(ui->cpfee->text().toLongLong());
    arq.Fler(&a,c);

    if(c>=0)
    {
        a.invalida();
        arq.Fsobrescrever(&a,c);
        ui->cargo->clear();
        ui->cpfedit->clear();
        ui->contato->clear();
        ui->nome->clear();
        QMessageBox::information(this,"","Funcionario deletado do sistema");

    }
    else
    {
        QMessageBox::warning(this,"","Funcionario nao encontrado!");
    }


}

void Fconsulta::on_update_clicked()
{

    ui->cpfedit->clearMask();

    if(ui->cpfedit->text().toLongLong() <= 0)
    {

        QMessageBox::warning(this,"","Digite um funcionário valido");
    }
    else
    {

        this->close();
        cadastroF tela;
        tela.settela(ui->nome->text().toStdString().c_str(),ui->cpfee->text().toStdString().c_str(),ui->cargo->text().toStdString().c_str());
        tela.exec();
        tela.show();
    }



}
