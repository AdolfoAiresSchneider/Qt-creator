#ifndef CPF_H
#define CPF_H 1
#include <QString>

namespace bia
{
  class Cpf
  {
  public:

    typedef long long int cpf_t;

  private:

    cpf_t cpf;

  public:

    Cpf () :
      cpf(0)
    {}

    Cpf (cpf_t cpf) :
      cpf(cpf)
    {}

    cpf_t getCpf () const
    { return cpf; }

    void setCpf (const cpf_t cpf)
    {
      if (!valida(cpf))
        throw QString("Cpf::setCpf(cpf_t): cpf invalido");

      this->cpf = cpf;
    }

    static bool valida (const cpf_t cpf)
    {
      if (cpf <= 0 || cpf >= 99999999999LL)
        return false;

      int aux = cpf % 10;         // pega o ultimo digito
      cpf_t cpfTemp = cpf / 10;   // copia cpf sem o ultimo digito

      while (cpfTemp % 10 == aux) // verifica se todos os digitos sao iguais
        cpfTemp /= 10;            // remove o ultimo

      if (!cpfTemp)               // se ficou == 0
        return false;             // é invalido

      register int i;
      int sum;
      int digito;

      /* valida primeiro digito */
      sum = 0;
      cpfTemp = cpf / 100;      // pega os 9 primeiros
      for (i = 2; i <= 10; ++i) // multiplica pela posicao
      {
        sum += cpfTemp % 10 * i;
        cpfTemp /= 10;
      }

      digito = sum * 10 % 11;
      if (digito == 10)
        digito = 0;

      if (digito != cpf / 10 % 10)  // se for diferente:
        return false;               // invalido

      /* valida segundo digito */
      sum = 0;
      cpfTemp = cpf / 10;         // pega os 10 primeiros
      for (i = 2; i <= 11; ++i)   // multiplica pela posicao
      {
        sum += cpfTemp % 10 * i;
        cpfTemp /= 10;
      }

      digito = sum * 10 % 11;
      if (digito == 10)
        digito = 0;

      return digito == cpf % 10;  // se for diferente == invalido
    }

  };  /// \class Cpf

} /// \namespace bia

#endif // CPF_H
