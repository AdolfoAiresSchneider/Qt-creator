#include "contatodao.h"
#include "Telefone.h"
#include <iostream>



ContatoDAO::ContatoDAO(QString nomeaArqContatos, QString nomeaArqTelefones):
    nomeaArqContatos(nomeaArqContatos)
{

}

void ContatoDAO::incluir(TP2::Contato &obj) const
{
    std::ofstream arquivoContatos;
    arquivoContatos.open(nomeaArqContatos.toStdString().c_str(),
                                   std::ios::out|std::ios::app);
    if(!arquivoContatos.is_open()){
        throw QString("Arquivo de Agenda nao foi aberto - Metodo incluir");
    }

    QString aux = QString::number(obj.getIdentificador()) + ";" + obj.getNomeCompleto() + ";\n";
    arquivoContatos<<aux.toStdString();
    arquivoContatos.close();

   // ContatoDaoTelefone telefone("telefone.txt");


    /*std::ofstream arquivoTelefones;
    arquivoTelefones.open(nomeaArqTelefones.toStdString().c_str(), std::ios::out|std::ios::app);
    if(!arquivoTelefones.is_open()){
        throw QString("Arquivo de Agenda nao foi aberto - Metodo incluir");
    }



    std::vector<TP2::Telefone> const * const telefones = obj.getTelefone();
    for(int i = 0; i < (int)telefones->size();i++)
    {
        QString aux2;
        aux2 +=QString::number(telefones->at(i).getIdContato())+";"+QString::number(telefones->at(i).getDDI()) +";"+QString::number(telefones->at(i).getDDD())+":"+
                                                                                                       QString::number(telefones->at(i).getNumero());
        aux2 +=QString::number(telefones->at(i).getTipo())+"\n";
        arquivoTelefones<<aux2.toStdString();
    }
    arquivoTelefones.close();*/
}

std::vector<TP2::Contato> *ContatoDAO::listagem() const
{
}
