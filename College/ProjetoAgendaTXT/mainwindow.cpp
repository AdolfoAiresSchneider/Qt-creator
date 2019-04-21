#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonIncluir_clicked()
{
    try {
        QString nome = ui->lineEditNome->text();
        QString endereco = ui->lineEditEndereco->text();
        long telefone = ui->lineEditTelefone->text().toLong();
        QString email = ui->lineEditEmail->text();
        agenda::Contato objetoContato(nome,endereco,telefone,email);
        agenda::ContatoPersistencia agendaContato("dados.txt");
        agendaContato.incluir(objetoContato);
        this->limparTela();
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::limparTela()const{
    ui->lineEditNome->clear();
    ui->lineEditEndereco->clear();
    ui->lineEditTelefone->clear();
    ui->lineEditEmail->clear();
}

void MainWindow::on_pushButtonExcluir_clicked()
{
    try {
        QString nome = ui->lineEditNome->text();
        agenda::ContatoPersistencia agendaContato("dados.txt");
        agendaContato.excluir(nome);
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButtonListar_clicked()
{
    TelaDeListagem telaListagem;
    telaListagem.setModal(true);
    telaListagem.exec();
}

void MainWindow::on_pushButtonAlterar_clicked()
{
    try {
        QString nome = ui->lineEditNome->text();
        QString endereco = ui->lineEditEndereco->text();
        long telefone = ui->lineEditTelefone->text().toLong();
        QString email = ui->lineEditEmail->text();
        agenda::Contato objetoContato(nome,endereco,telefone,email);
        agenda::ContatoPersistencia agendaContato("dados.txt");
        agendaContato.alterar(objetoContato);
        this->limparTela();
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}
