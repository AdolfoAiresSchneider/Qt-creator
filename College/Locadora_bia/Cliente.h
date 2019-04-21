#ifndef CLIENTE_H
#define CLIENTE_H
#include "Pessoa.h"

namespace bia{
class Cliente : public bia::Pessoa
{
private:
    long long cartaoDeCredito;

public:
    Cliente();

    Cliente(QString nome,QString email, long long rg,std::vector<bia::Telefone> &T,bia::Endereco &E, bia::Cpf &C,long long Cartao);

    void setCartaoDeCredito(long long cartaoDeCredito)
    { this->cartaoDeCredito = cartaoDeCredito; }

    long long getCartaoDeCredito()
    { return cartaoDeCredito; }

     bia::Cliente operator = (const bia::Pessoa& P);
};
}

#endif // CLIENTE_H
