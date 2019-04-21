#ifndef TELEFONE_H
#define TELEFONE_H
#include "QString"

namespace bia{
class Telefone
{

public:
    enum Tipo
    {
      tipo_null = 0,
      Residencial,
      Comercial,
      Celular
    };

private:
    unsigned int id;
    unsigned int DDI;
    unsigned int DDD;
    unsigned int numero;
    Tipo tipo;

public:

    Telefone ();

    Telefone (unsigned int id, unsigned int DDI, unsigned int DDD, unsigned int numero, Tipo tipo);

    Telefone (unsigned int id, unsigned int DDI, unsigned int DDD, unsigned int numero, QString tipo);

    Tipo getTipo () const
    { return tipo; }

    QString getTipoStr () const;

    unsigned int getId() const
    { return id; }

    unsigned int getDDI () const
    { return DDI; }

    unsigned int getDDD () const
    { return DDD; }

    unsigned int getNumero () const
    { return numero; }

    void setIdContato (unsigned int id)
    { this->id=id; }

    void setDDI (unsigned int DDI)
    { this->DDI = DDI; }

    void setDDD (unsigned int DDD)
    { this->DDD = DDD; }

    void setNumero (unsigned int numero)
    { this->numero = numero; }

    bool operator ==(bia::Telefone A)
    { return (this->DDD == A.DDD && this->DDI == A.DDI && this->numero == A.numero && this->id == A.id); }

    void setTipo (Tipo tipo)
    { this->tipo = tipo; }

    void setTipo (QString tipo);
};
}

#endif // TELEFONE_H
