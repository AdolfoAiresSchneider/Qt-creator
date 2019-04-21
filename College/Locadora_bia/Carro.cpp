#include "Carro.h"

namespace bia
{
  QString toQString(const Carro::Situacao situacao)
  {
    if (situacao == Carro::Null)
      return "Null";
    if (situacao == Carro::Alugado)
      return "Alugado";
    if (situacao == Carro::Vendido)
      return "Vendido";
    if (situacao == Carro::Disponivel)
      return "Disponivel";

    throw QString("Situacao::toQString(Situacao): default alcancado");
  }

  Carro::Situacao toSituacao(const QString& situacao)
  {
    if (situacao == "Null")
      return Carro::Null;
    if (situacao == "Alugado")
      return Carro::Alugado;
    if (situacao == "Vendido")
      return Carro::Vendido;
    if (situacao == "Disponivel")
      return Carro::Disponivel;

    throw QString("toSituacao(QString): situacao invalida");
  }

} /// \namespace bia
