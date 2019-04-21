#include "telaprincipal.h"
#include "ui_telaprincipal.h"
#include "contatodao.h"

TelaPrincipal::TelaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TelaPrincipal)
{
    ui->setupUi(this);
}

TelaPrincipal::~TelaPrincipal()
{
    delete ui;
}

void TelaPrincipal::on_pushButtonTeste_clicked()
{
    try {
        ContatoDAO asd("asd.txt","Telefones.txt");
        //***********************
        //Teste Objeto Telefone
        //***********************
        TP2::Telefone objTelefone1;
        objTelefone1.setIdContato(1);
        objTelefone1.setDDI(55);
        objTelefone1.setDDD(62);
        objTelefone1.setTipo(Residencial);
        objTelefone1.setNumero(12345);
        TP2::Telefone objTelefone2(1,55,62,54321);
        QString saida = "TESTE DOS OBJETOS TELEFONES \n";
        saida += "Telefone1: " + QString::number(objTelefone1.getIdContato());
        saida += ", " + QString::number(objTelefone1.getDDI());
        saida += ", " + QString::number(objTelefone1.getDDD());
        saida += ", " + QString::number(objTelefone1.getNumero());
        saida += "\n";
        saida += "Telefone2: " + QString::number(objTelefone2.getIdContato());
        saida += ", " + QString::number(objTelefone2.getDDI());
        saida += ", " + QString::number(objTelefone2.getDDD());
        saida += ", " + QString::number(objTelefone2.getNumero());
        saida += "\n\n";

        //***********************
        //Teste Objeto Contato
        //***********************

        TP2::Contato objContado;
        objContado.setIdentificador(1);
        objContado.setNomeCompleto("JOSE DAS COVE");
        std::vector<TP2::Telefone> *pt = new std::vector<TP2::Telefone>();

        pt->push_back(objTelefone1);
        pt->push_back(objTelefone2);
        pt->push_back(TP2::Telefone(1,11,11,11111));
        //TP2::Telefone t1 = pt->at(0);
        //TP2::Telefone t2 = pt->at(1);
        //TP2::Telefone t3 = pt->at(2);

        saida += "TESTE DOS OBJETOS TELEFONES DA VECTOR \n";
        saida += "Telefone1: " + QString::number(pt->at(0).getIdContato());
        saida += ", " + QString::number(pt->at(0).getDDI());
        saida += ", " + QString::number(pt->at(0).getDDD());
        saida += ", " + QString::number(pt->at(0).getNumero());
        saida += "\n";
        saida += "Telefone2: " + QString::number(pt->at(1).getIdContato());
        saida += ", " + QString::number(pt->at(1).getDDI());
        saida += ", " + QString::number(pt->at(1).getDDD());
        saida += ", " + QString::number(pt->at(1).getNumero());
        saida += "\n";
        saida += "Telefone3: " + QString::number(pt->at(2).getIdContato());
        saida += ", " + QString::number(pt->at(2).getDDI());
        saida += ", " + QString::number(pt->at(2).getDDD());
        saida += ", " + QString::number(pt->at(2).getNumero());
        saida += "\n\n";

        // ate aqui testado

        // Enviando Vector de Telefone para o Contato
        objTelefone2.setTipo(Trabalho);
        objContado.setTelefones(pt);
        asd.incluir(objContado);
        //Teste dos dados do Objeto Contato
        saida += "Dados Vindos do Contato \n";
        saida += "Identificador: " + QString::number(objContado.getIdentificador()) + "\n";
        saida += "Nome Completo: " + objContado.getNomeCompleto() + "\n";
        std::vector<TP2::Telefone> const * const pt2 = objContado.getTelefone();
        TP2::Telefone tAux = pt2->at(0);
        saida += "TESTE DOS OBJETOS TELEFONES DA VECTOR DO CONTATO \n";
        saida += "Telefone1: " + QString::number(tAux.getIdContato());
        saida += ", " + QString::number(tAux.getDDI());
        saida += ", " + QString::number(tAux.getDDD());
        saida += ", " + QString::number(tAux.getNumero());
        saida += "\n";

       tAux = pt2->at(1);
        saida += "Telefone2: " + QString::number(tAux.getIdContato());
        saida += ", " + QString::number(tAux.getDDI());
        saida += ", " + QString::number(tAux.getDDD());
        saida += ", " + QString::number(tAux.getNumero());
        saida += "\n";

        tAux = pt2->at(2);
        saida += "Telefone3: " + QString::number(tAux.getIdContato());
        saida += ", " + QString::number(tAux.getDDI());
        saida += ", " + QString::number(tAux.getDDD());
        saida += ", " + QString::number(tAux.getNumero());
        saida += "\n\n";


        ui->textEditSaida->setText(saida);
    } catch (...) {
        QMessageBox::information(this,"ERRO","Erro no teste");
    }
}
