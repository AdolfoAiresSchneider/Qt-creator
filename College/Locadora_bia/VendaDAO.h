#ifndef VENDADAO_H
#define VENDADAO_H
#include "Venda.h"
#include "Carro.h"
#include "CarroDAO.h"
#include "Cliente.h"
#include "ClienteDAO.h"
#include <map>

namespace bia {
class VendaDAO
{
public:
    VendaDAO(){}

    void incluir (bia::Venda & venda);

    /// Inclui todos as vendas
    void incluir (std::map<int,bia::Venda> * Vendas);

    /// retorna um map ALOCADO DINAMICAMENTE com todas as vendas
    std::map < int , bia::Venda  > * listar () const;

    /// Retorna uma venda correspondente a um id
    bia::Venda listar(const int &id) const;
};
}
#endif // VENDADAO_H
