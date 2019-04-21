#ifndef VENDA_H
#define VENDA_H

#include <QString>

#include "Id.h"
#include "Placa.h"
#include "Cliente.h"
#include "Carro.h"

namespace bia
{
  class Venda
  {
  private:

    Id id;                // id da venda
    QString Descricao;       // motivo da venda
    double valorDaVenda;  // valor da venda
    bia::Carro   carro;       // placa do carro vendido
    bia::Cliente cliente; // cliente que compra o carro
  public:

    /// constroi com nada
    Venda() :
      id(0),
      valorDaVenda(0.0)
    {}

    void setCliente(const bia::Cliente &cliente)
    { this->cliente = cliente; }

    bia::Cliente getCliente() const
    {return this->cliente;}

    /// seta o id \p id
    void setId (Id id)
    { this->id = id; }

    /// retorna id
    Id getId () const
    { return id; }

    /// seta o motivo \p motivo
    void setDescricao (const QString& Descricao)
    { this->Descricao = Descricao; }

    /// retorna o motivo
    QString getDescricao() const
    { return Descricao; }

    /// seta o valor da venda
    void setValorDaVenda (double valor)
    { valorDaVenda = valor; }

    /// retorna o valor da venda
    double getValorDaVenda () const
    { return valorDaVenda; }

    /// seta a placa do carro vendido
    void setCarro (const bia::Carro& carro)
    { this->carro = carro; }

    /// retorna a placa do carro vendido
    bia::Carro getCarro () const
    { return this->carro; }

  };  /// \class Venda

} /// \namespace bia

#endif // VENDA_H
