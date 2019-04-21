#ifndef TELEFONE_H
#define TELEFONE_H
#include "enumtelefone.h"

//Teste: ok
namespace TP2{
class Telefone
{
private:
    unsigned int idContato;
    unsigned int DDI;
    unsigned int DDD;
    unsigned int numero;
    EnumTelefone tipo;
public:
    Telefone();
    Telefone(unsigned int idContato,unsigned int DDI, unsigned int DDD, unsigned int numero);
    unsigned int getIdContato()const{return idContato;}
    unsigned int getDDI()const{return DDI;}
    unsigned int getDDD()const{return DDD;}
    unsigned int getNumero()const{return numero;}
    unsigned int getTipo()const{return tipo;}

    void setIdContato(unsigned int idContato){this->idContato=idContato;}
    void setDDI(unsigned int DDI){this->DDI = DDI;}
    void setDDD(unsigned int DDD){this->DDD = DDD;}
    void setNumero(unsigned int numero){this->numero = numero;}
    void setTipo(EnumTelefone t){tipo = t;}
};

}
#endif // TELEFONE_H
