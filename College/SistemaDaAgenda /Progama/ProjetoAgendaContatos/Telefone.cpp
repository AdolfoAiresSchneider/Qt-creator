#include "Telefone.h"

namespace TP2{
Telefone::Telefone():
    idContato(0),
    DDI(0),
    DDD(0),
    numero(0)
{}
Telefone::Telefone(unsigned int idContato,unsigned int DDI,
         unsigned int DDD, unsigned int numero):
    idContato(idContato),
    DDI(DDI),
    DDD(DDD),
    numero(numero)
{}


}
