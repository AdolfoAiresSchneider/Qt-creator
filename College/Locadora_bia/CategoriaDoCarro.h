#ifndef CATEGORIADOCARRO_H
#define CATEGORIADOCARRO_H

#include <QString>

#include <Id.h>


namespace bia
{
  class CategoriaDoCarro
  {
  private:

    Id id;                          // id desta categoria
    QString categoria;              // descricao/nome
    double valorDeLocacaoPessoal;   // valor de locacao pessoal
    double valorDeLocacaoTrabalho;  // valor de locacao comercial

  public:

    /// controi com nada
    CategoriaDoCarro() :
      id(0),
      valorDeLocacaoPessoal(0.0),
      valorDeLocacaoTrabalho(0.0)
    {}

    /// constroi com \p id, \p categoria e \p valor*
    CategoriaDoCarro (Id id, const QString& categoria, double valorPessoal, double valorTrabalho) :
      id(id),
      categoria(categoria),
      valorDeLocacaoPessoal(valorPessoal),
      valorDeLocacaoTrabalho(valorTrabalho)
    {}

    /// repoe o id com \p id
    void setId (Id id)
    { this->id = id; }

    /// retorna o id
    Id getId () const
    { return id; }

    /// seta a categoria com \p categoria
    void setCategoria (const QString& categoria)
    { this->categoria = categoria; }

    /// retorna a categoria
    QString getCategoria () const
    { return categoria; }

    /// seta o valor de locacao pessoal com \p valor
    void setValorLocacaoPessoal (double valor)
    { valorDeLocacaoPessoal = valor; }

    /// retorna o valor da locacao pessoal
    double getValorLocacaoPessoal () const
    { return valorDeLocacaoPessoal; }

    /// seta o valor da locacao comercial
    void setValorLocacaoTrabalho(double valor)
    { valorDeLocacaoTrabalho = valor; }

    /// retorna o valor da locacao comercial
    double getValorLocacaoTrabalho () const
    { return valorDeLocacaoTrabalho; }

  };  /// \class CategoriaDoCarro

} /// \namespace bia

#endif // CATEGORIADOCARRO_H
