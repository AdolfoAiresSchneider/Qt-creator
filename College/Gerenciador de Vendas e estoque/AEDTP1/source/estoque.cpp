#include "estoque.h"
#include "ui_estoque.h"
#include "arquivo.h"

estoque::estoque(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::estoque)
{
    ui->setupUi(this);
    listv();
}

void estoque::listv()//função para imprimir na tela listwidget os nomes do indice
{
    indice m;
    arquivo b;
    games g;

    char nome[30];
    for(int i = 0;i<m.getqtda();i++)//listar todos os objetos no listwidget
    {
        m.getnome(nome,i);
        b.ler(&g,m.getposic(nome));
        if( g.getqtd()>0 )
        {
            QListWidgetItem *qlwi = new QListWidgetItem(QString::fromLatin1(nome));//item necessario para colocar na lista
            ui->listWidget->insertItem(i,qlwi);//qlwi é o item e i é a linha
        }
    }
}

void estoque::listv(char *a)
{
    indice m;
    arquivo b;
    games g;

    char nome[30];
    for(int i = 0;i<m.getqtda();i++)//listar todos os objetos no listwidget
    {

        m.getnome(nome,i);
        b.ler(&g,m.getposic(nome));

        if( (nome[0] == a[0] || nome[0] == a[0]+('A'-'a')) && g.getqtd()>0 )
        {
            QListWidgetItem *qlwi = new QListWidgetItem(QString::fromLatin1(nome));
            ui->listWidget->insertItem(i,qlwi);
        }
    }
}

estoque::~estoque()
{
    delete ui;
}

void estoque::on_listWidget_itemClicked(QListWidgetItem *item)
{
    try
    {
        indice a;
        games game;
        arquivo q;
        char nome[30];
        int g;

        strcpy(nome,item->text().toStdString().c_str());//copiar do line edit para uma variavel
        g = a.getposic(nome);//retorna a posicao
        q.ler(&game,g);//ler o jogo do arquivo original no obj auxiliar

    //-------------------------------------------------------------------------------------------------setar na tela quando clicar
        game.getnome(nome);
        ui->Nomeedit->setText(nome);
        ui->Codigoedit->setText(QString::number(game.getcod()));
        game.getconsole(nome);
        ui->consoleedit->setText(nome);
        ui->etariaedit->setText(QString::number(game.getetaria()));
        game.getgenero(nome);
        ui->generoedit->setText(nome);
        ui->qtdedit->setText(QString::number(game.getqtd()));
        ui->Valoredit->setText(QString::number(game.getvalor()));
    }
    catch(const char a)
    {
        QMessageBox::warning(this,"","Memoria insufuciente !");
    }
    catch(...)
    {
        QMessageBox::warning(this,"","Erro!");

    }
//-----------------------------------------------------------------------------------------------------------------------------
}

void estoque::on_pushButton_clicked()
{
    this->close();
    this->hide();
}

void estoque::on_lineEdit_returnPressed()
{
    //int c =1;
}

void estoque::on_bot_clicked()
{

    ui->listWidget->clear();
    listv();

}
void estoque::on_comboBox_activated(const QString &arg1)
{

    char l[2];
    strcpy(l,arg1.toStdString().c_str());
    l[0] = l[0]-('A'-'a');
    ui->listWidget->clear();
    listv(l);

}
