#include "ModeloDAO.h"


namespace bia
{
  ModeloDAO::ModeloDAO()
  {
    std::ifstream arquivo("data/modelos.dat");                      // abre o arquivo
    if (arquivo.is_open())                                          // verifica se existe
      arquivo.close();                                              // existe: pode fechar
    else
    {                                                               // nao existe
      std::ofstream arquivo("data/modelos.dat");                    // cria
      if (!arquivo.is_open())                                       // se falhou
        throw QString("Modelo: Nao foi possivel criar o arquivo");  // excecao
      arquivo.close();                                              // sucesso: pode fechar
    }
  }

  void ModeloDAO::incluir(const Modelo &modelo)
  {
    std::ofstream arquivo("data/modelos.dat", std::ios_base::app);          // abre o arquivo
    if (!arquivo.is_open())                                                 // checa se abriu
      throw QString("ModeloDAO::incluir(Modelo&): falha ao abrir arquivo"); // nao abriu: excecao

    arquivo << modelo.getId() << ';'                                        // grava id
            << modelo.getModelo().toStdString() << ';'                      // grava modelo
            << modelo.getMarca().getId() << '\n';                           // grava marca

    arquivo.close();                                                        // fecha o arquivo
  }

  void ModeloDAO::incluir(const std::map<Id, Modelo> &modelos)
  {
    std::ofstream arquivo("data/modelos.dat");                                                    // abre o arquivo
    if (!arquivo.is_open())                                                                       // checa se abriu
      throw QString("ModeloDAO::incluir(map&): falha ao abrir arquivo");                          // nao abriu: excecao

    for (std::map < Id, Modelo >::const_iterator it = modelos.begin(); it != modelos.end(); ++it) // varre todos os modelos
      arquivo << it->first << ';'                                                                 // grava id
              << it->second.getModelo().toStdString() << ';'                                      // grava modelo
              << it->second.getMarca().getId() << '\n';                                           // grava marca

    arquivo.close();                                                                              // fecha o arquivo
  }

  void ModeloDAO::excluir(Id id)
  {
    std::map < Id, Modelo >* modelos = this->listar();          // pega todos os modelos ALOCADOS DINAMICAMENTE

    try
    {
      modelos->erase(id);                                       // remove o id
    }
    catch (std::exception&)
    {                                                           // falhou:
      delete modelos;                                           // libera memoria
      throw QString("ModeloDAO::excluir(Id): std::exception");  // excecao
    }

    incluir(*modelos);                                          // atualiza dados do arquivo
    delete modelos;                                             // libera memoria
  }

  void ModeloDAO::atualizar(const Modelo &modelo)
  {
    excluir(modelo.getId());  // exclui o modelo antigo
    incluir(modelo);          // inclui o novo atualizado
  }

  std::map<Id, Modelo> *ModeloDAO::listar() const
  {
    std::ifstream arquivo("data/modelos.dat");                                // abre o arquivo
    if (!arquivo.is_open())                                                   // checa se abriu
      throw QString("ModeloDAO::listar(): falha ao abrir arquivo");           // nao abriu: excecao

    std::map < Id, Modelo >* modelos = 0;                                     // map de modelos

    try
    {
      modelos = new std::map < Id, Modelo >;                                  // tenta alocar

      MarcaDAO marcaDao;                                                      // dao para pegar dados

      std::string str;                                                        // string para leitura
      QStringList qstrl;                                                      // lista para leitura
      Modelo modelo;                                                          // modelo para leitura

      std::getline(arquivo, str);                                             // le o 1º id
      while (!arquivo.eof())                                                  // ate eof
      {
        qstrl = QString::fromStdString(str).split(';');                       // cria lista
        if (qstrl.size() != 3)                                                // checa se tem todos os dados
          throw QString("ModeloDAO::listar(): erro de logica");               // excecao

        modelo.setId(qstrl[0].toUInt());                                      // seta o id
        modelo.setModelo(qstrl[1]);                                           // seta o modelo
        modelo.setMarca(marcaDao.listar(qstrl[2].toUInt()));                  // seta a marca

        modelos->operator [](qstrl[0].toUInt()) = modelo;                     // insere no map
        std::getline(arquivo, str);                                           // le o proximo
      }
    }
    catch (std::exception&)
    {                                                                         // falhou:
      delete modelos;                                                         // libera memoria
      arquivo.close();                                                        // fecha arquivo
      throw QString("ModeloDao::listar(): std::exception");                   // excecao
    }
    catch (QString&)
    {                                                                         // falhou:
      delete modelos;                                                         // libera memoria
      arquivo.close();                                                        // fecha arquivo
      throw;                                                                  // excecao
    }

    arquivo.close();
    return modelos;                                                           // retorna o map
  }

  std::map<Id, Modelo> *ModeloDAO::listarMarca(Id id) const
  {
    std::ifstream arquivo("data/modelos.dat");                                // abre o arquivo
    if (!arquivo.is_open())                                                   // checa se abriu
      throw QString("ModeloDAO::listar(): falha ao abrir arquivo");           // nao abriu: excecao

    std::map < Id, Modelo >* modelos = 0;                                     // map de modelos

    try
    {
      modelos = new std::map < Id, Modelo >;                                  // tenta alocar

      MarcaDAO marcaDao;                                                      // dao para pegar dados

      std::string str;                                                        // string para leitura
      QStringList qstrl;                                                      // lista para leitura
      Modelo modelo;                                                          // modelo para leitura

      std::getline(arquivo, str);                                             // le o 1º id
      while (!arquivo.eof())                                                  // ate eof
      {
        qstrl = QString::fromStdString(str).split(';');                       // cria lista
        if (qstrl.size() != 3)                                                // checa se tem todos os dados
          throw QString("ModeloDAO::listar(): erro de logica");               // excecao

        if (qstrl[2].toUInt() == id)                                          // checa se é da marca \p id
        {
          modelo.setId(qstrl[0].toUInt());                                    // seta o id
          modelo.setModelo(qstrl[1]);                                         // seta o modelo
          modelo.setMarca(marcaDao.listar(qstrl[2].toUInt()));                // seta a marca

          modelos->operator [](qstrl[0].toUInt()) = modelo;                   // insere no map
        }

        std::getline(arquivo, str);                                           // le o proximo
      }
    }
    catch (std::exception&)
    {                                                                         // falhou:
      delete modelos;                                                         // libera memoria
      arquivo.close();                                                        // fecha arquivo
      throw QString("ModeloDao::listar(): std::exception");                   // excecao
    }
    catch (QString&)
    {                                                                         // falhou:
      delete modelos;                                                         // libera memoria
      arquivo.close();                                                        // fecha arquivo
      throw;                                                                  // excecao
    }

    arquivo.close();
    return modelos;                                                           // retorna o map
  }

  Modelo ModeloDAO::listar(Id id) const
  {
    std::ifstream arquivo("data/modelos.dat");                                        // abre o arquivo
    if (!arquivo.is_open())                                                           // checa se abriu
      throw QString("ModeloDAO::listar(Id): falha ao abrir arquivo");                 // nao abriu: excecao

    try
    {
      MarcaDAO marcaDao;                                                              // dao para marcas
      std::string str;                                                                // string para leitura
      QStringList qstrl;                                                              // lista para leitura

      std::getline(arquivo, str);                                                     // le o primeiro
      while (!arquivo.eof())                                                          // ate eof
      {
        qstrl = QString::fromStdString(str).split(';');                               // separa os dados
        if (qstrl.size() != 3)                                                        // checa se tem todos os dados
          throw QString("ModeloDAO::listar(): erro de logica");                       // excecao

        if (qstrl[0].toUInt() == id)                                                  // checa se é esse
          break;                                                                      // é esse: para a leitura

        std::getline(arquivo, str);                                                   // le os outros
      }

      if (arquivo.eof())                                                              // eof: nao achou
        throw QString("ModeloDAO::listar(Id): id nao encontrado");                    // excecao

      arquivo.close();                                                                // fecha arquivo
      return Modelo(qstrl[0].toUInt(), qstrl[1], marcaDao.listar(qstrl[2].toUInt())); // retorna o modelo
    }
    catch (std::exception&)
    {                                                                                 // excecao stl:
      arquivo.close();                                                                // fecha arquivo
      throw QString("ModeloDAO::listar(Id): std::exception");                         // excecao
    }
    catch (QString&)
    {                                                                                 // excecao prog:
      arquivo.close();                                                                // fecha arquivo
      throw;                                                                          // excecao
    }
  }

} /// \namespace bia
