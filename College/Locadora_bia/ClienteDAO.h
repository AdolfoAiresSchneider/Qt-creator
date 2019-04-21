#ifndef CLIENTEDAO_H
#define CLIENTEDAO_H
#include "Cliente.h"
#include "PessoaDAO.h"
#include <fstream>
#include <QString>
#include <QStringList>

class ClienteDAO
{
public:

    void incluir(bia::Cliente &C) const;

    void incluir(std::map<bia::Cpf::cpf_t,bia::Cliente> &M) const;

    std::map< bia::Cpf::cpf_t , bia::Cliente > * listar() const;

    bia::Cliente listar(const bia::Cpf::cpf_t &cpf)const;

    void atualizar(const bia::Cliente &C) const;

    void excluir(const bia::Cpf::cpf_t &cpf) const;

    ClienteDAO(){}
};

#endif // CLIENTEDAO_H
