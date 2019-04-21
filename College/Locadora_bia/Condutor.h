#ifndef CONDUTOR_H
#define CONDUTOR_H
#include "Pessoa.h"
#include "Cnh.h"

namespace bia{
class Condutor : public bia::Pessoa
{
private:
    bia::Cnh cnh;

public:
    Condutor();

    Condutor(QString nome,QString email, long long rg,std::vector<bia::Telefone> &T,bia::Endereco &E, bia::Cpf &C,bia::Cnh cnh);

    void setCnh(bia::Cnh cnh)
    {this->cnh = cnh;}

    Cnh getCnh() const
    {return cnh;}

    bia::Condutor operator =( const bia::Pessoa & P);
};
}

#endif // CONDUTOR_H
