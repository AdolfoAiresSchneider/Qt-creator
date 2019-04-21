#include "cadastro.h"
#include "ui_cadastro.h"
#include "games.h"
#include <QMessageBox>
#include "arquivo.h"
#include "indice.h"

cadastro::cadastro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cadastro)
{
    ui->setupUi(this);
    this->jogo=new games;
}

cadastro::~cadastro()
{
    delete ui;
     delete jogo;
}

void cadastro::on_pushButton_2_clicked()
{
    this->close();
}


void cadastro::on_pushButton_clicked()
{
    QMessageBox show;
    arquivo a;
    indice games;

    try
    {
            jogo->setnome( ui->Nomeedit->text().toStdString().c_str());
            jogo->setcod(ui->Codigoedit->text().toInt());
            jogo->setetaria(ui->etariaedit->text().toInt());
            jogo->setconsole(ui->consoleedit->text().toStdString().c_str());
            jogo->setgenero(ui->generoedit->text().toStdString().c_str());
            jogo->setvalor(ui->Valoredit->text().toFloat());
            jogo->setqtd(ui->qtdedit->text().toInt());

            int c = games.gravarid(jogo,a.getqtda());
            if(c < 0)
            {
               a.gravarF(jogo);
               show.information(this," ","Cadastro efetuado com Sucesso");
            }
            else//adicionar mais um
            {

                if( show.question(this," ","Game já cadastrado, atualizar ?",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
                {
                      a.sobrescrever(jogo,c);
                      show.information(this," ","Atualização efetuada com Sucesso");
                }
            }
   }
    catch(const int b)
    {
        switch(b)
        {
            case 1:
                show.warning(this," ","Nome não digitado!");
            break;
            case 2:
                show.warning(this," ","Console não digitado!");
            break;
            case 3:
                show.warning(this," ","Faixa etátia incorreta!");
            break;
            case 4:
                show.warning(this," ","Genero não digitado!");
            break;
            case 5:
                show.warning(this," ","Veifique o valor");
            break;
            case 6:
                show.warning(this," ","Quantidade invalida!");
            break;
            case 7:
                show.warning(this," ","Posição inexistente!");
            break;
        }
    }
    catch(const char b)
    {
         show.information(this," ","Memoria insufuciente em disco ");
    }
    catch(...)
    {
         show.information(this," ","Erro!");
    }
}
