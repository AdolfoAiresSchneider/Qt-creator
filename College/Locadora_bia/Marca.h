#ifndef MARCA_H
#define MARCA_H

#include <QString>

#include "Id.h"


namespace bia
{
  class Marca
  {
  private:

    Id id;
    QString marca;

  public:

    /// constroi com nada
    Marca () :
      id(0)
    {}

    /// constroi com \p id e \p marca
    Marca (Id id, QString marca) :
      id(id),
      marca(marca)
    {}

    /// seta o id \p id
    void setId (Id id)
    { this->id = id; }

    /// retorna o id
    Id getId () const
    { return id; }

    /// seta a marca com \p marca
    void setMarca (const QString& marca)
    { this->marca = marca; }

    /// retorna a marca
    QString getMarca () const
    { return marca; }

    /// compara os ids de duas marcas
    bool operator == (const Marca& m) const
    { return id == m.id; }

    bool operator != (const Marca& m) const
    { return !(*this == m); }

  };  /// \class Marca

} /// \namespace bia

#endif // MARCA_H
