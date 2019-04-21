#ifndef PLACA_H
#define PLACA_H

#include <QString>


namespace bia
{
  class Placa
  {
  private:

    QString placa;  // placa de um carro

  public:

    /// controi a placa com nada
    Placa()
    {}

    /// constroi a placa com \p placa
    Placa (const QString& placa) :
      placa(placa)
    {}

    /// sobreescreve a placa com \p placa
    void setPlaca (const QString& placa)
    { this->placa = placa; }

    /// retorn a placa
    QString getPlaca () const
    { return placa; }

  /// fator de ordenacao de placas
  /// \note: comparacao de QStrings
  /// \{

    bool operator == (const Placa& placa) const
    { return this->placa == placa.placa; }

    bool operator != (const Placa& placa) const
    { return this->placa != placa.placa; }

    bool operator < (const Placa& placa) const
    { return this->placa < placa.placa; }

    bool operator <= (const Placa& placa) const
    { return this->placa <= placa.placa; }

    bool operator > (const Placa& placa) const
    { return this->placa > placa.placa; }

    bool operator >= (const Placa& placa) const
    { return this->placa >= placa.placa; }

  /// \} fator de ordenacao

  };  /// \class Placa

} /// \namespace bia

#endif // PLACA_H
