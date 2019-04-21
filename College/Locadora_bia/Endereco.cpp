#include "Endereco.h"

bia::Endereco::Endereco() :
    logradouro(""),
    bairro(""),
    numero(0),
    cep(0),
    cidade("")
{ }

bia::Endereco::Endereco(QString logradouro, QString bairro, int numero, int cep, QString cidade) :
    logradouro(logradouro),
    bairro(bairro),
    numero(numero),
    cep(cep),
    cidade(cidade)
{}
