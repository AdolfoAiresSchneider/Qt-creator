#ifndef CONTATO_H
#define CONTATO_H
#include<QString>
#include<TransformarDados.h>
#include<QStringList>

namespace agenda{//inicio
class Contato:public TransformarDados
{
private:
    QString nome;
    QString endereco;
    long telefone;
    QString email;
public:
    Contato(QString nome, QString endereco, long telefone, QString email);
    Contato();
    QString getNome()const{return nome;}
    QString getEndereco()const{return endereco;}
    long getTelefone()const{return telefone;}
    QString getEmail()const{return email;}

    void setNome(QString nome){this->nome = nome;}
    void setEndereco(QString endereco){this->endereco = endereco;}
    void setTelefone(long telefone){this->telefone = telefone;}
    void setEmail(QString email){this->email = email;}

    void montarObjeto(QString &str);
    QString desmontarObjeto()const;

};
}//fim
#endif // CONTATO_H
