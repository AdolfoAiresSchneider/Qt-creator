#ifndef LAUDO_H
#define LAUDO_H
#include <qstring.h>

namespace bia
{
class Laudo // Laudo de um aluguel
{

private:


    QString descricao;      /// Descrição da ocorrencia


public:

    // construtor
    Laudo(QString const & descricao):
        descricao(descricao){}

    // construtor
    Laudo(){}

    // seta a descricao das ocorrencias de um aluguel
    void setDescricao(QString descricao)
    {
      this->descricao = descricao;
    }

    // retorna a descricao
    QString getDescricao() const
    {
      return this->descricao;
    }

};

}

#endif // LAUDO_H
