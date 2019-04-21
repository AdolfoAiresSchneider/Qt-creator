#include "Telefone.h"

bia::Telefone::Telefone() :
    id(0),
    DDI(0),
    DDD(0),
    numero(0),
    tipo(tipo_null)
{}

bia::Telefone::Telefone(unsigned int id, unsigned int DDI, unsigned int DDD, unsigned int numero, bia::Telefone::Tipo tipo) :
    id(id),
    DDI(DDI),
    DDD(DDD),
    numero(numero),
    tipo(tipo)
{}

bia::Telefone::Telefone(unsigned int id, unsigned int DDI, unsigned int DDD, unsigned int numero, QString tipo) :
    id(id),
    DDI(DDI),
    DDD(DDD),
    numero(numero)
  { setTipo(tipo); }

QString bia::Telefone::getTipoStr() const
{
    if (tipo == tipo_null)
      return "Sem tipo";
    if (tipo == Comercial)
      return "Comercial";
    if (tipo == Residencial)
      return "Residencial";
    return "Celular";
}

void bia::Telefone::setTipo(QString tipo)
{
    if (tipo == "Comercial")
      this->tipo = Comercial;
    else if (tipo == "Residencial")
      this->tipo = Residencial;
    else if (tipo == "Celular")
      this->tipo = Celular;
    else this->tipo = tipo_null;
}
