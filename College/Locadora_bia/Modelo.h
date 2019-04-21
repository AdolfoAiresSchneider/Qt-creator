#ifndef MODELO_H
#define MODELO_H

#include "Id.h"
#include "Marca.h"


namespace bia
{
  class Modelo
  {
  private:

    Id id;          // id
    QString modelo; // descricao/nome
    Marca marca;    // marca que pertence

  public:

    /// constroi com nada
    Modelo () :
      id(0),
      marca()
    {}

    /// constroi com \p id e \p marca
    Modelo (Id id, const QString& modelo, const Marca& marca) :
      id(id),
      modelo(modelo),
      marca(marca)
    {}

    /// seta o id \p id
    void setId (Id id)
    { this->id = id; }

    /// retorna o id
    Id getId () const
    { return id; }

    /// seta o modelo com \p modelo
    void setModelo (const QString& modelo)
    { this->modelo = modelo; }

    /// retorna o modelo
    QString getModelo () const
    { return modelo; }

    /// seta a marca \p marca
    void setMarca (const Marca& marca)
    { this->marca = marca; }

    /// retorna a marca
    Marca getMarca () const
    { return marca; }

  };  /// \class Modelo

} /// \namespace bia

#endif // MODELO_H
