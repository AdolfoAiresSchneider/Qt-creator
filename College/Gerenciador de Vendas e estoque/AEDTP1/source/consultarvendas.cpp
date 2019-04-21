#include "consultarvendas.h"
#include "ui_consultarvendas.h"
#include "arquivo.h"
#include <QMessageBox>
#include <indice.h>

consultarVendas::consultarVendas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::consultarVendas)
{
    ui->setupUi(this);
}

consultarVendas::~consultarVendas()
{
    delete ui;
}

void consultarVendas::on_pushButton_clicked()
{
///---------------------------------------
/// verificar tratamento de exceções
/// verificar quantidade real
/// verificar lista de widget
///
    Vindice id;
    arquivo arq;
    ui->listWidget->clear();
    int c = id.getposic(ui->setcod->text().toInt());
    if(c<0)
         QMessageBox::information(this," ","Venda nao encontrada");
    else
    {
        try
        {
            arq.Vler(&venda,c);
            char nome[30];
            venda.getvendedor(nome);

            ui->vendendir->setText(nome);
            ui->codigo->setText(QString::number(venda.getcod()));
            ui->Valortotal->setText(QString::number(venda.getvalor()));

            for (int i=0;i<venda.getqtd();i++)
            {
                venda.getnome(i,nome);
                QListWidgetItem *it = new QListWidgetItem(QString::fromLatin1(nome));
                ui->listWidget->insertItem(i,it);
            }
        }
        catch(const int a)
        {

            QMessageBox::warning(this,"","Código não encontrado!");
        }
    }


}

void consultarVendas::on_listWidget_itemClicked(QListWidgetItem *item)
{
    indice a;
    games game;
    arquivo q;
    char nome[30];
    int g;
    strcpy(nome,item->text().toStdString().c_str());//copiar do line edit para uma variavel
    g = a.getposic(nome);//retorna a posicao
    q.ler(&game,g);//ler o jogo do arquivo original no obj auxiliar
    aux tela;
    tela.setgame(&venda,item->listWidget()->row(item));
    tela.setGeometry(this->geometry());
    tela.exec();
    tela.show();
}

void consultarVendas::on_setcod_selectionChanged()
{
    ui->setcod->clear();
    ui->setcod->clear();

}

void consultarVendas::on_setcod_customContextMenuRequested(const QPoint &pos)
{

}

void consultarVendas::on_setcod_cursorPositionChanged(int arg1, int arg2)
{
}

void consultarVendas::on_setcod_textEdited(const QString &arg1)
{

}

void consultarVendas::on_pushButton_3_clicked()
{
    this->hide();
}

void consultarVendas::on_pushButton_2_clicked()
{
    Vindice aux;
    aux.setqtd(0);
    std::remove("vendas.dat");
    QMessageBox::information(this,"","Histórico de compras limpo!");

}
