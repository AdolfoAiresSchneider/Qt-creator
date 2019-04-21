#include "Pessoa.h"

bia::Pessoa::Pessoa():
    nome(""),
    email(""),
    rg(0),
    cpf(0)
{}

bia::Pessoa::Pessoa( QString nome, QString email, long long rg, std::vector<bia::Telefone> &T, bia::Endereco &E, bia::Cpf &C):
    nome(nome),
    email(email),
    rg(rg),
    telefones(T),
    endereco(E),
    cpf(C)
{}
