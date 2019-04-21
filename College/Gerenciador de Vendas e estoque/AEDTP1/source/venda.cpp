#include "venda.h"
#include "ui_venda.h"
#include "indice.h"
#include "arquivo.h"
#include <QTableWidgetItem>
#include <QStringList>
#include <QMessageBox>
#include <QMenu>
#include <QMenuBar>
#include <iostream>
#include "fconsulta.h"
#include "ui_fconsulta.h"
#include "findice.h"
using namespace std;
#include <iostream>
#include "lig.h"
#include "arquivo.h"
#include <cstring>



venda::venda(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::venda)
{
    ui->setupUi(this);

    soma =0;
    qtd = 0;
    p=0;

    meuMenu = new QMenu();
    QAction *remover = new QAction("remover",this);
    meuMenu->addAction(remover);
    connect(remover, SIGNAL(triggered()), this, SLOT(cliqueiNaTabela())); //Quando clicar em remover a função cliqueiNaTabela será chamada
    ui->tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tableWidget, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(on_tableWidget_customContextMenuRequested(QPoint))); //ativando a tabela para chamar a função on_tabl... quando o usuário clicar com o botão direito do mouse em cima da tabela
}


venda::~venda()
{
    delete ui;
    delete meuMenu;
}

void venda::on_fim_clicked()///quando venda finalizada a relação dos games sao diminuidas do estoque
{
    Findice funcionario;
    Vindice vind;
    CVenda Venda;
    Funcionario aux;
    arquivo a;
    int c;

    c = funcionario.getposic(ui->cpfedit->text().toLongLong());

    if(c >= 0)
    {
        a.Fler(&aux,c);
        if(aux.getv())
        {
            if(qtd <= 0)
            {
                QMessageBox::warning(this,"","Nenhum produto adicionado à venda!");
            }
            else
            {
                if(  QMessageBox::question(this," ","Confirmar venda ?",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
                {           
                            arquivo c;
                            indice a;
                            int i;
                            char nome[30];

                            aux.getnome(nome);
                            Venda.setvalor(this->soma);
                            Venda.setcod(c.Vgetqtda()+999);
                            Venda.setqtd(p);
                            Venda.setvendedor(nome);
                            vind.gravarid(&Venda,c.Vgetqtda());

                            for(i=0;i<p;i++)//for para atualizar no estoque
                            {
                                v[i].getnome(nome);
                                c.sobrescrever(&v[i],a.getposic(nome));
                            }
                            for(i=0;i<p;i++)///for para colocar na venda
                            {
                                v2[i]=v[i];
                                v2[i].setqtd(ui->tableWidget->item(i,1)->text().toInt());
                                Venda.setgame(&v2[i],i);
                            }

                            QMessageBox::information(this," ","Venda Concluída!");
                            QMessageBox::information(this,"Codigo da venda ",QString::number(c.Vgetqtda()+999));
                            c.VgravarF(&Venda);
                            this->hide();
                }
            }
        }
        else
        {
            QMessageBox::warning(this,"","Funcionario não encontrado. Impossivel completar a venda!");

        }
    }
    else
    {
        QMessageBox::warning(this,"","Funcionario não encontrado. Impossivel completar a venda!");

    }

}

void venda::on_adicionar_clicked()
{
    try
        {
            indice a;
            games b;
            arquivo c;
            int d;
            char nome[30];

            strcpy(nome,ui->nomeedit->text().toStdString().c_str());
            d = a.getposic(nome);
            if(qtd <= 13)
            {
                if(d >= 0)///verifica se o jogo existe
                {
                    c.ler(&b,d);

                    if(b.getqtd() >= ui->qtdedit->text().toInt())///verifica se existe games suficientes para a venda
                    {

                        int q = getposic(ui->nomeedit->text().toStdString().c_str());

                        if(q>=0)//verifica se ja esta na lista de compra para adicionar apenas qtd
                        {
                            if(b.getqtd() >= ui->qtdedit->text().toInt() + v[q].getqtd())///verifica se a qtd é suficiente somando tudo
                            {
                                if(v[q].getqtd()-ui->qtdedit->text().toInt() < 0)
                                {
                                    QMessageBox::information(this," "," Quandidade insuficiente");
                                }
                                else
                                {
                                    v[q].setqtd(v[q].getqtd()-ui->qtdedit->text().toInt());///coloca no vetor de atualização, ou seja o que sobra em qtd
                                    QTableWidgetItem *item3 = new QTableWidgetItem(QString::number(b.getqtd()-v[q].getqtd()));///tudo menos o que sobra resulta no que quero
                                    ui->tableWidget->setItem(q,1,item3);
                                    soma = soma + b.getvalor();
                                    ui->lineEdit->setText(QString::number(soma));
                                }
                            }
                            else///entra aqui se a qtd nao for suficiente
                            {

                                QMessageBox::information(this," "," Quandidade insuficiente");
                            }
                        }
                        else///se nao estiver na lista, apenas coloca nela
                        {
                             ui->tableWidget->insertRow(qtd);
                             QTableWidgetItem *item1 = new QTableWidgetItem(nome);
                             QTableWidgetItem *item2 = new QTableWidgetItem(QString::number(ui->qtdedit->text().toInt()));
                             QTableWidgetItem *item3 = new QTableWidgetItem(QString::number(b.getvalor()*ui->qtdedit->text().toInt()));
                             soma = soma + b.getvalor()*ui->qtdedit->text().toInt();
                             ui->tableWidget->setItem(qtd,0,item1);
                             ui->tableWidget->setItem(qtd,1,item2);
                             ui->tableWidget->setItem(qtd,2,item3);
                             ui->lineEdit->setText(QString::number(soma));
                             b.setqtd(b.getqtd()-ui->qtdedit->text().toInt());
                             v[p] = b;
                             p++;
                             qtd++;
                        }

                    }
                    else
                    {
                        QMessageBox::information(this," "," Quandidade insuficiente ");
                    }
                }
                else
                {
                    QMessageBox::warning(this,"","Game nao encontrado");
                }
                ///////////////////////////////////////////////////////////nao deixar de colocar proibido menor q 0
          }
          else
            {
                QMessageBox::warning(this,"","O limite de uma venda sao 10 produtos !");
            }
    }
    catch(const char v)
    {
        QMessageBox::warning(this,"","Erro de memoria");
    }
    catch(...)
    {
        QMessageBox::warning(this,"","Quantidate de games insuficiente");
    }
}

void venda::on_tableWidget_customContextMenuRequested(const QPoint &pos)
{

    if (pos.y() < (25*ui->tableWidget->rowCount())){ //25 = tamanho fixo da altura de cada linha da tabela, rowCount = número de linhas da tabela
        meuMenu->move(this->x() + ui->tableWidget->x() + pos.x() + 20, this->y() + 55 + ui->tableWidget->y() + pos.y());  //move o menu para o mesmo lugar do cursor do mouse
        meuMenu->show();
    }
}

void venda::cliqueiNaTabela()
{
    indice a;
    games b;
    arquivo c;

    QMessageBox::information(this,"","Removendo o game " + ui->tableWidget->item(ui->tableWidget->currentRow(), 0)->text());
    qtd--;
    char nomes[30];
    strcpy(nomes,ui->tableWidget->item(ui->tableWidget->currentRow(), 0)->text().toStdString().c_str());
    c.ler(&b,a.getposic(nomes));
    removerobjv(&b);
    soma = soma - b.getvalor() * ui->tableWidget->item(ui->tableWidget->currentRow(), 1)->text().toInt();
    ui->lineEdit->setText(QString::number(soma));
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());

}
void venda::removerobjv(games *p) //tirar o produto da relação de venda, ou seja nao tirar do arquivo, ou seja tirar do vetor de atualização e de venda
{
    int i;
    char nome1[30],nome2[30];

    p->getnome(nome1);
    i=0;
    do
    {
        v[i].getnome(nome2);
        i++;

    }while( strcmp(nome1,nome2) != 0 );

    this->p--;

    for(i=i-1;i<this->p;i++)
    {
        v[i] = v[i+1];
    }
}

void venda::on_fim_2_clicked()
{
    this->close();
}

int venda::getposic(const char *nome1)
{
    char nome2[30];
    int i=0;
    do
    {
        v[i].getnome(nome2);
        i++;

    }while( strcmp(nome1,nome2) != 0 && i<=p );

    if(i>p)
        return -1;
    return i-1;
}

