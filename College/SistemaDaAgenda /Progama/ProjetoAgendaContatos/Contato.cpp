#include "Contato.h"
namespace TP2{

Contato::Contato():
    identificador(0),
    nomeCompleto(""),
    telefones(0)
{
    telefones = new std::vector<Telefone>();
}

Contato::Contato(int identificador, QString nomeCompleto, std::vector<Telefone> *telefones):
    identificador(identificador),
    nomeCompleto(nomeCompleto),
    telefones(telefones)
{
}


}
