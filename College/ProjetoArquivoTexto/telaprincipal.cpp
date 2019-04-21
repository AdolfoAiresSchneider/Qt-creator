#include "telaprincipal.h"
#include "ui_telaprincipal.h"

TelaPrincipal::TelaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TelaPrincipal),
    nomeDoArquivo("arq.txt")
{
    ui->setupUi(this);
}

TelaPrincipal::~TelaPrincipal()
{
    delete ui;
}

void TelaPrincipal::MostrarDadosNaTela(std::vector<TP2::Aluno>* dados)const{
    QString saida;
    for(int pos = 0; pos < dados->size(); pos++){
        TP2::Aluno alunoAux;
        alunoAux = dados->operator [](pos);
        saida += alunoAux.getMatricula();
        saida += " ; ";
        saida += alunoAux.getNome();
        saida += " ; ";
        saida += alunoAux.getSituacao();
        saida += "\n";
    }
    ui->textEditSaida->setText(saida);
}



void TelaPrincipal::on_pushButtonNome_clicked()
{
    try {
        TP2::OrdenarPorNome aux(nomeDoArquivo);
        std::vector<TP2::Aluno>* dados = 0;
        dados = aux.obterDadosOrdenado();
        this->MostrarDadosNaTela(dados);
        delete dados;
    } catch (QString &msgErro) {
        QMessageBox::information(this,"ERRO",msgErro);
    }
}

void TelaPrincipal::on_pushButtonGeral_clicked()
{
    try {
        TP2::DadosDoArquivo aux(nomeDoArquivo);
        std::vector<TP2::Aluno>* dados = 0;
        dados = aux.obterDadosDoArquivo();
        this->MostrarDadosNaTela(dados);
        delete dados;
    } catch (QString &msgErro) {
        QMessageBox::information(this,"ERRO",msgErro);
    }
}

void TelaPrincipal::on_pushButtonLimpar_clicked()
{
    ui->textEditSaida->clear();
}

void TelaPrincipal::on_pushButtonMatricula_clicked()
{
    try {
        TP2::OrdenarPorMatricula aux(nomeDoArquivo);
        std::vector<TP2::Aluno>* dados = 0;
        dados = aux.obterDadosOrdenado();
        this->MostrarDadosNaTela(dados);
        delete dados;
    } catch (QString &msgErro) {
        QMessageBox::information(this,"ERRO",msgErro);
    }

}

void TelaPrincipal::on_pushButton_anosemestrenome_clicked()
{
    try {
        TP2::OrdenarPorAnoSemestreNome aux(nomeDoArquivo);
        std::vector<TP2::Aluno>* dados = 0;
        dados = aux.obterDadosOrdenado();
        this->MostrarDadosNaTela(dados);
        delete dados;
    } catch (QString &msgErro) {
        QMessageBox::information(this,"ERRO",msgErro);
    }
}

void TelaPrincipal::on_pushButton_clicked()
{
    try {
        TP2::OrdenarPorSituacaoNome aux(nomeDoArquivo);
        std::vector<TP2::Aluno>* dados = 0;
        dados = aux.obterDadosOrdenado();
        this->MostrarDadosNaTela(dados);
        delete dados;
    } catch (QString &msgErro) {
        QMessageBox::information(this,"ERRO",msgErro);
    }
}
