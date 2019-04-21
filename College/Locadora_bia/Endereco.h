#ifndef ENDERECO_H
#define ENDERECO_H
#include "QString"

namespace bia{
class Endereco
{
private:
    QString logradouro;
    QString bairro;
    int numero;
    int cep;
    QString cidade;

public:

    Endereco();

    Endereco(QString logradouro, QString bairro,int numero,int cep,QString cidade);

    void setLogradouro(QString logradouro)
    { this->logradouro = logradouro;}

    QString getLogradouro()
    {return logradouro;}

    void setBairro(QString bairro)
    {this->bairro =bairro; }

    QString getBairro()
    {return bairro;}

    void setNumero(int numero)
    {this->numero = numero;}

    int getNumero()
    {return numero;}

    void setCep(int cep)
    {this->cep = cep;}

    int getCep()
    {return cep;}

    void setCidade(QString cidade)
    {this->cidade = cidade;}

    QString getCidade()
    {return cidade;}
};
}

#endif // ENDERECO_H
