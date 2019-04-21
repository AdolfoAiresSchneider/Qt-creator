#ifndef CARRODAO_H
#define CARRODAO_H

#include <fstream>
#include <map>

#include <QString>
#include <QStringList>

#include "Carro.h"
#include "CategoriaDoCarroDAO.h"
#include "ModeloDAO.h"
#include "Placa.h"


namespace bia
{
  class CarroDAO
  {
  public:

    /// cria o arquivo, se nao existir
    CarroDAO ();

    /// inclui um carro no final do arquivo
    void incluir (const Carro& carro);

    /// repoe todos com os dados em \p carros
    void incluir (const std::map < Placa, Carro >& carros);

    /// exclui um carro com \p placa
    void excluir (const Placa& placa);

    /// altera os dados de um carro
    /// \note: a placa deve ser a mesma
    void alterar (const Carro& carro);

    /// retorna um map ALOCADO DINAMICAMENTE com todos os carros
    std::map < Placa, Carro >* listar () const;

    /// retorna um carro com a placa \p placa
    Carro listar (const Placa& placa) const;

  };  /// \class CarroDAO

} /// \namespace bia

#endif // CARRODAO_H
