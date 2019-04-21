#ifndef CARRO_H
#define CARRO_H

#include <QString>

#include "CategoriaDoCarro.h"
#include "Marca.h"
#include "Modelo.h"
#include "Placa.h"


namespace bia
{
  class Carro
  {
  public:

    /// Situacao do carro no momento
    enum Situacao
    {
      Null = 0,   // null
      Alugado,    // carro alugado
      Vendido,    // carro vendido
      Disponivel  // carro disponivel

    };  /// \enum Situacao

  private:

    Situacao situacao;            // situacao do carro
    CategoriaDoCarro categoria;   // categoria do carro
    Modelo modelo;                // modelo do carro
    int kmRodados;                // qtde de km rodados
    QString cor;                  // cor do carro
    Placa placa;                  // placa do carro

  public:

    /// constroi com nada
    Carro() :
      situacao(Null),
      kmRodados(0)
    {}

    /// controi com \p ...
    Carro(const Situacao& situacao,
          const CategoriaDoCarro& categoria,
          const Modelo& modelo,
          int kmRodados,
          const QString& cor,
          const Placa& placa) :
      situacao(situacao),
      categoria(categoria),
      modelo(modelo),
      kmRodados(kmRodados),
      cor(cor),
      placa(placa)
    {}

    /// seta a situacao com \p situacao
    void setSituacao (Situacao situacao)
    { this->situacao = situacao; }

    /// retorna a situacao do carro
    Situacao getSituacao () const
    { return situacao; }

    /// seta a categoria com \p categoria
    void setCategoria (const CategoriaDoCarro& categoria)
    { this->categoria = categoria; }

    /// retorna a categoria
    CategoriaDoCarro getCategoria () const
    { return categoria; }

    /// seta o modelo com \p modelo
    void setModelo (const Modelo& modelo)
    { this->modelo = modelo; }

    /// retorna o modelo
    Modelo getModelo () const
    { return modelo; }

    /// seta a qtde de km rodados com \p kmRodados
    void setKmRodados (int kmRodados)
    { this->kmRodados = kmRodados; }

    /// retorna a qtde de km rodados
    int getKmRodados () const
    { return kmRodados; }

    /// seta a cor com \p cor
    void setCor (const QString& cor)
    { this->cor = cor; }

    /// retorna a cor
    QString getCor () const
    { return cor; }

    /// seta a placa com \p placa
    void setPlaca (const Placa& placa)
    { this->placa = placa; }

    /// retorna a placa
    Placa getPlaca () const
    { return placa; }

  };  /// \class Carro


  /// retorna uma QString descrevendo a situacao do carro
  QString toQString (const Carro::Situacao situacao);

  /// retorna uma situacao do carro de uma marca na QString
  Carro::Situacao toSituacao (const QString& situacao);

} /// \namespace bia

#endif // CARRO_H
