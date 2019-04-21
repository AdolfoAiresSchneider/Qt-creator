#ifndef PESSOADAO_H
#define PESSOADAO_H
#include "Pessoa.h"
#include <fstream>
#include <QString>
#include <map>




class PessoaDAO
{
public:
    PessoaDAO(){}

    /// inclui um unico objeto Pessoa No Final do Arquivo
    void incluir(bia::Pessoa &P) const;

    /// sobreescreve todo o arquivo, atualizando-o
    void incluir(const std::map<bia::Cpf::cpf_t,bia::Pessoa> &M) const;

    /// obtem todas informacoes do arquivo e armazena em um map
    std::map<bia::Cpf::cpf_t,bia::Pessoa> * listar() const;

    /// atualiza dados de uma pessoa
    void atualizar(bia::Pessoa &P) const;

    /// exlui os dados de uma pessoa
    void excluir(const bia::Cpf::cpf_t &cpf) const;
};

#endif // PESSOADAO_H
