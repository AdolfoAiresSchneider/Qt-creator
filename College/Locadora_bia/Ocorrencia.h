#ifndef OCORRENCIA_H
#define OCORRENCIA_H
#include <QString>

namespace bia{

class Ocorrencia // Evento inexperad que ocorreu com o carro ou com o condutor no periodo valido do aluguel
{

private:

    QString descricao;  /// Descrição do ocorrido
    double  valor;      /// Valor de prejuizo reacionado ao ocorrido

public:

    // construtor
    Ocorrencia(QString const & descricao,double valor):
        descricao(descricao),valor(valor){}

    // construtor
    Ocorrencia();

    // seta a descricao da ocorrencia
    void setDescricao(QString  const & descricao)
    {
      this->descricao = descricao;
    }

    // retorna a descricao da ocorrencia
    const QString & getDescricao() const
    {
      return this->descricao;
    }

    // retorna o valor da ocorrencia
    double getValor() const
    {
      return this->valor;
    }

    // seta o valor da ocorrencia
    void setValor(double const  & valor)
    {
        if(valor < 0 )
            throw QString("Valor Invalido para a ocorrencia");
        this->valor = valor;
    }
};

}

#endif // OCORRENCIA_H
