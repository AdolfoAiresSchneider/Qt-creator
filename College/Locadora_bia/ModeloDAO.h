#ifndef MODELODAO_H
#define MODELODAO_H

#include <fstream>
#include <map>

#include <QStringList>

#include "MarcaDAO.h"
#include "Modelo.h"


namespace bia
{
  class ModeloDAO
  {
    std::fstream arquivo; // arquivo de modelos

  public:

    /// cria arquivo, se não existir
    ModeloDAO ();

    /// inclui apenas um modelo no final do arquivo
    void incluir (const Modelo& modelo);

    /// sobreescreve todos os dados com os dados em \p modelos
    void incluir (const std::map < Id, Modelo >& modelos);

    /// exclui um modelo com \p id
    void excluir (Id id);

    /// atualiza um modelo
    void atualizar (const Modelo& modelo);

    /// retorna um map ALOCADO DINAMICAMENTE com todos os modelos
    std::map < Id, Modelo >* listar () const;

    /// retorna um map ALOCADO DINAMICAMENTE com modelos da marca \p id
    std::map < Id, Modelo >* listarMarca (Id id) const;

    /// retorna um modelo com id \p id
    Modelo listar (Id id) const;

  };  /// \class

} /// \namespace bia

#endif // MODELODAO_H
