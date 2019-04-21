#ifndef ALUGUELDAO_H
#define ALUGUELDAO_H
#include "Aluguel.h"
#include <map>


namespace bia{


class AluguelDAO
{
public:

    AluguelDAO(){}

    /// inclui um aluguel no arquivo
    void incluir (Aluguel & aluguel);

    /// Inclui todos os alugueis
    void incluir (std::map<int,bia::Aluguel> * alugueis);

    /// retorna um map ALOCADO DINAMICAMENTE com todos os alugueis
    std::map < int , bia::Aluguel  > * listar () const;

    /// Retorna um aluguel correspondente a um id
    bia::Aluguel listar(int id) const;

};

}

#endif // ALUGUELDAO_H
