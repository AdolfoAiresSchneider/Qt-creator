#ifndef PESSOA_H
#define PESSOA_H
#include "QString"
#include "QDate"
#include "vector"
#include "Telefone.h"
#include "Endereco.h"
#include "Cpf.h"

namespace bia{
class Pessoa
{
private:
    QString nome;
    QString email;
    long long rg;
    std::vector<bia::Telefone> telefones;
    bia::Endereco endereco;
    bia::Cpf cpf;
public:

    void setNome(const QString &nome)
    {this->nome = nome;}

    QString getNome() const
    {return nome;}

    void setEmail(const QString &email)
    {this->email = email;}

    QString getEmail() const
    {return email;}

    void setRg(const int &rg)
    {this->rg = rg;}

    int getRg() const
    {return rg;}

    void setTelefones(const std::vector<bia::Telefone> &T)
    {this->telefones = T;}

    std::vector<bia::Telefone> getTelefones() const
    {return telefones;}

    void setEndereco(const bia::Endereco &E)
    {this->endereco = E;}

    bia::Endereco getEndereco() const
    {return endereco;}

    void setCpf(const bia::Cpf &C)
    {this->cpf = C;}

    bia::Cpf getCpf() const
    {return cpf;}

    Pessoa();
    Pessoa(QString nome,QString email, long long rg,std::vector<bia::Telefone> &T,bia::Endereco &E, bia::Cpf &C);

    /// Metodo Novo ___________________________________________
    void adicionaTelefone(bia::Telefone &T)
    {telefones.push_back(T);}

};
}
#endif // PESSOA_H
