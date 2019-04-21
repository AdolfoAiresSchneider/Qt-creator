#include "Contato.h"
namespace agenda{//inicio
Contato::Contato(QString nome, QString endereco, long telefone, QString email):
    nome(nome),
    endereco(endereco),
    telefone(telefone),
    email(email)
{
}

Contato::Contato():
    nome(""),
    endereco(""),
    telefone(0),
    email("")
{

}

void Contato::montarObjeto(QString &str){
    try {
        QStringList strList = str.split(';');
        if(strList.length()!=4) throw ;
        nome = strList[0];
        endereco = strList[1];
        telefone = strList[2].toLong();
        email = strList[3];

    } catch (...) {
        throw QString("Erro no metodo materializar classe Contato");
    }
}

QString Contato::desmontarObjeto()const{
    QString saida = nome;
    saida += ";";
    saida += endereco;
    saida += ";";
    saida += QString::number(telefone);
    saida += ";";
    saida += email;
    return saida;
}

}//fim


