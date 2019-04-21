#ifndef CONDUTORDAO_H
#define CONDUTORDAO_H
#include "Condutor.h"
#include <fstream>
#include "PessoaDAO.h"

class CondutorDAO
{
public:

    void incluir(bia::Condutor &C) const;

    void incluir(std::map<bia::Cnh::cnh_t,bia::Condutor> &M) const;

    void atualizar(const bia::Condutor &C) const;

    void excluir(const bia::Cnh::cnh_t & cnh) const;

    std::map<bia::Cnh::cnh_t,bia::Condutor> *listar() const;

    bia::Condutor listar(const bia::Cpf::cpf_t &cpf) const;

    CondutorDAO(){}
};

#endif // CONDUTORDAO_H
