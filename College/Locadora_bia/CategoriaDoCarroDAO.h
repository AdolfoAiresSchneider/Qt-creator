#ifndef CATEGORIADOCARRODAO_H
#define CATEGORIADOCARRODAO_H

#include <fstream>
#include <map>

#include <QString>
#include <QStringList>

#include "CategoriaDoCarro.h"


namespace bia
{
  class CategoriaDoCarroDAO
  {
  public:

    /// cria o arquivo, se nao existir
    CategoriaDoCarroDAO ();

    /// checa se existem categorias
    bool isEmpty () const;

    /// inclui uma categoria no final do arquivo
    void incluir (const CategoriaDoCarro& categoria);

    /// repoe todos os dados com os de \p categorias
    void incluir (const std::map < Id, CategoriaDoCarro >& categorias);

    /// exclui uma categoria com \p id
    void excluir (Id id);

    /// altera uma categoria
    /// \note: categoria com mesmo id antigo
    void alterar (const CategoriaDoCarro& categoria);

    /// retorna um map ALOCADO DINAMICAMENTE com todas categorias
    std::map < Id, CategoriaDoCarro >* listar() const;

    /// retorna uma categoria do carro com id \p id
    CategoriaDoCarro listar (Id id) const;

  };  /// \class bia

} /// \namespace bia

#endif // CATEGORIADOCARRODAO_H
