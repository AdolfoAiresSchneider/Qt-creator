#include "Cliente.h"


bia::Cliente::Cliente() :
    Pessoa()
{}

bia::Cliente::Cliente( QString nome, QString email, long long rg, std::vector<bia::Telefone> &T, bia::Endereco &E, bia::Cpf &C, long long Cartao):
    Pessoa(nome,email,rg,T,E,C),
    cartaoDeCredito(Cartao)
{}

bia::Cliente bia::Cliente::operator =(const bia::Pessoa &P)
{
    this->setCpf(P.getCpf());
    this->setEmail( P.getEmail() );
    this->setEndereco(P.getEndereco());
    this->setRg(P.getRg());
    this->setTelefones(P.getTelefones());
    this->setNome(P.getNome());
    return *this;
}
