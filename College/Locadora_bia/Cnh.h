#ifndef CNH_H
#define CNH_H
#include "QDate"

namespace bia{
class Cnh
{
private:
    long long numero;
    QDate emissao;
    QDate expiracao;

public:

    typedef long long int cnh_t;

    void setCnh(long long numero)
    {this->numero = numero;}

    void setemissao(QDate emissao)
    {this->emissao = emissao;}

    void setexpiracao(QDate expiracao)
    {this->expiracao = expiracao;}

    long long getCnh()
    {return numero;}

    QDate getemissao()
    {return emissao;}

    QDate getexpiracao()
    {return expiracao;}


    Cnh();

    Cnh(long long numero,QDate emissao,QDate expiracao);
};
}

#endif // CNH_H
