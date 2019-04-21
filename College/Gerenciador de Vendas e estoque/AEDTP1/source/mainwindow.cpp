#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cadastro.h"
#include "arquivo.h"
#include "consulta.h"
#include "ui_consulta.h"
#include "fconsulta.h"
#include "findice.h"
#include <cstdio>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->progressBar->setValue(0);
    ui->progressBar->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->hide();
    cadastro janelak;
    janelak.setGeometry(this->geometry());
    janelak.exec();
    this->setGeometry(janelak.geometry());
    this->show();
}

void MainWindow::on_venda_clicked()
{
    this->hide();
    venda janelav;
    janelav.setGeometry(this->geometry());
    janelav.exec();
    this->setGeometry(janelav.geometry());
    this->show();
}

void MainWindow::on_Consulta_clicked()
{
    consulta obj;
    obj.setGeometry(this->geometry());
    this->hide();
    obj.exec();
    this->setGeometry(obj.geometry());
    this->show();

}

void MainWindow::on_Consulta_3_clicked()
{
    estoque n;
    this->hide();
    n.setGeometry(this->geometry());
    n.exec();
    n.show();
    this->setGeometry(n.geometry());
    this->show();
}

void MainWindow::on_Consulta_2_clicked()
{
    cadastroF obj;
    this->hide();
    obj.setGeometry(this->geometry());
    obj.exec();
    obj.show();
    this->setGeometry(obj.geometry());
    this->show();
}

void MainWindow::on_Consulta_4_clicked()
{
    Fconsulta obj;
    this->hide();
    obj.setGeometry(this->geometry());
    obj.exec();
    obj.show();
    this->setGeometry(obj.geometry());
    this->show();

}

void MainWindow::on_pushButton_2_clicked()
{


    arquivo arq;
    Findice indice;
    Funcionario funci;
    int i,j;

    arq.criararq();
    ui->progressBar->show();
    ui->progressBar->setValue(0);

    for(i=0,j=0 ; i < arq.Fgetqtda() ; i++)
    {
       arq.Fler(&funci,i);

       ui->progressBar->setValue((i+1)*(100/arq.Fgetqtda()));

        if(funci.getv())//verifica se e valido ou não
        {
            arq.gravaraux(&funci);
            indice.modposicao(funci.getcpf(),j);///função que modifica no indice
            j++;
        }
        else
        {
            indice.removeid(funci.getcpf());///função que retira do indice
        }
    }

    ui->progressBar->setValue(100);

    std::remove("Funcionario.dat");
    system( "mv arqaux.dat Funcionario.dat" );
    QMessageBox::information(this,"","Limpeza da lixeira completa");
    ui->progressBar->setValue(0);
    ui->progressBar->hide();
}

void MainWindow::on_venda_2_clicked()
{
    this->hide();
    consultarVendas a;
    a.setGeometry(this->geometry());
    a.exec();
    a.show();
    this->setGeometry(a.geometry());
    this->show();
}
