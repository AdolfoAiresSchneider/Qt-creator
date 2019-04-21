#include "TelaDeListagem.h"
#include "ui_TelaDeListagem.h"

TelaDeListagem::TelaDeListagem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TelaDeListagem)
{
    ui->setupUi(this);
}

TelaDeListagem::~TelaDeListagem()
{
    delete ui;
}

void TelaDeListagem::on_pushButtonVoltar_clicked()
{
    this->close();
}

void TelaDeListagem::on_pushButtonListar_clicked()
{// Botao de listagem
    try {
        agenda::ContatoPersistencia agendaContato("dados.txt");
        std::list<agenda::Contato> *lista = 0;
        lista = agendaContato.listagem();
        ui->tableWidgetListagem->setRowCount(0);
        //ui->tableWidgetListagem->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
        //ui->tableWidgetListagem->verticalHeader()->resizeSections(QHeaderView::ResizeToContents);
        while(!lista->empty()){
            agenda::Contato objeto = lista->front();
            lista->pop_front();
            //Montando a grid
            QTableWidgetItem *itemNome = new QTableWidgetItem(objeto.getNome());
            QTableWidgetItem *itemEndereco = new QTableWidgetItem(objeto.getEndereco());
            QTableWidgetItem *itemTelefone = new QTableWidgetItem(QString::number(objeto.getTelefone()));
            QTableWidgetItem *itemEmail = new QTableWidgetItem(objeto.getEmail());
            int linha = ui->tableWidgetListagem->rowCount();
            ui->tableWidgetListagem->insertRow(linha);
            ui->tableWidgetListagem->setItem(linha,0,itemNome);
            ui->tableWidgetListagem->setItem(linha,1,itemEndereco);
            ui->tableWidgetListagem->setItem(linha,2,itemTelefone);
            ui->tableWidgetListagem->setItem(linha,3,itemEmail);
        }
        delete lista;
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    } catch(...){
        QMessageBox::information(this,"ERRO","ERRO NA LISTAGEM");
    }
}
