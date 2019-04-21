#ifndef MARCADAO_H
#define MARCADAO_H

#include <fstream>
#include <map>

#include <QMessageBox>
#include <QString>
#include <QStringList>

#include "Marca.h"


namespace bia
{
  class MarcaDAO
  {
  public:

    /// cria o arquivo, se nao existir
    MarcaDAO ();

    /// checa se existem marcas
    bool isEmpty () const;

    /// inclui apenas uma marca no final do arquivo
    void incluir (const Marca& marca);

    /// sobrescreve todos os dados com os dados em \p marcas
    void incluir (const std::map < Id, Marca >& marcas);

    /// exclui apenas uma marca com id
    void excluir (Id id);

    /// atualiza uma marca
    /// \note: o id nao pode ter sido modificado
    void atualizar (const Marca& marca);

    /// retorna um map ALOCADO DINAMICAMENTE com todas as marcas
    std::map < Id, Marca >* listar () const;

    /// retorna uma marca com id \p id
    Marca listar (Id id) const;

  };  /// \class MarcaDAO

} /// \namespace bia

#endif // MARCADAO_H
