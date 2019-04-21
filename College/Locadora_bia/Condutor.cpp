#include "Condutor.h"

bia::Condutor::Condutor():
    Pessoa(),
    cnh()
{}

bia::Condutor::Condutor(QString nome, QString email, long long rg, std::vector<bia::Telefone> &T, bia::Endereco &E, bia::Cpf &C, bia::Cnh cnh):
    Pessoa(nome,email,rg,T,E,C),
    cnh(cnh)
{}

bia::Condutor bia::Condutor::operator =(const bia::Pessoa &P)
{
    this->setCpf(P.getCpf());
    this->setEmail( P.getEmail() );
    this->setEndereco(P.getEndereco());
    this->setRg(P.getRg());
    this->setTelefones(P.getTelefones());
    this->setNome(P.getNome());
    return *this;
}
