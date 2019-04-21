#include "MarcaDAO.h"

namespace bia
{
  MarcaDAO::MarcaDAO()
  {
    std::ifstream arquivo("data/marcas.dat");                       // abre o arquivo
    if (arquivo.is_open())                                          // verifica se existe
      arquivo.close();                                              // existe: pode fechar
    else
    {                                                               // nao existe
      std::ofstream arquivo("data/marcas.dat");                     // cria
      if (!arquivo.is_open())                                       // se falhou
        throw QString("Modelo: Nao foi possivel criar o arquivo");  // excecao
      arquivo.close();                                              // sucesso: pode fechar
    }
  }

  bool MarcaDAO::isEmpty() const
  {
    std::ifstream arquivo("data/marcas.dat");
    if (!arquivo.is_open())
      return true;

    arquivo.seekg(0, std::ios_base::end);
    int n = arquivo.tellg();
    arquivo.close();
    return !n;
  }

  void MarcaDAO::incluir(const Marca &marca)
  {
    std::ofstream arquivo("data/marcas.dat", std::ios_base::app);                   // abre o arquivo
    if (!arquivo.is_open())                                                         // checa se foi aberto
      throw QString("MarcaDAO::incluir(const Marca&): falha ao abrir arquivo");     // nao abriu: excecao

    arquivo << marca.getId() << ";"                                                 // grava id
            << marca.getMarca().toStdString() << "\n";                              // grava marca

    arquivo.close();                                                                // fecha o arquivo
  }

  void MarcaDAO::incluir(const std::map<Id, Marca> &marcas)
  {
    std::ofstream arquivo("data/marcas.dat");                                                   // abre o arquivo
    if (!arquivo.is_open())                                                                     // checa se foi aberto
      throw QString("MarcaDAO::incluir(const map&): falha ao abrir arquivo");                   // excecao

    for (std::map < Id, Marca >::const_iterator it = marcas.begin(); it != marcas.end(); ++it)  // varre todos os dados
      arquivo << it->first << ';'                                                               // grava id
              << it->second.getMarca().toStdString() << '\n';                               // grava marca

    arquivo.close();                                                                            // fecha arquivo
  }

  void MarcaDAO::excluir(Id id)
  {
    std::map < Id, Marca >* marcas = this->listar();            // pega os dados ALOCADOS DINAMICAMENTE

    try
    {
      marcas->erase(id);                                        // remove o id
    }
    catch (...)
    {                                                           // falhou:
      delete marcas;                                            // libera memoria
      throw QString("MarcaDAO::excluir(Id): falha ao excluir"); // excecao
    }

    incluir(*marcas);                                           // atualiza todos os dados
    delete marcas;                                              // libera memoria
  }

  void MarcaDAO::atualizar(const Marca &marca)
  {
    excluir(marca.getId()); // exclui a antiga marca do mesmo id
    incluir(marca);         // insere o novo atualizado
  }

  std::map<Id, Marca> *MarcaDAO::listar() const
  {
    std::ifstream arquivo("data/marcas.dat");                                       // abre o arquivo
    if (!arquivo.is_open())                                                         // checa se foi aberto
      throw QString("MarcaDAO::listar(): falha ao abrir arquivo");                  // nao abriu: excecao

    std::map < Id, Marca >* marcas = 0;                                             // map para as marcas

    try
    {
      marcas = new std::map < Id, Marca >;                                          // tenta alocar

      std::string desc;                                                             // marca do arquivo
      QStringList qstrl;
      Marca marca;

      std::getline(arquivo, desc);
      while (!arquivo.eof())                                                        // ate eof
      {
        qstrl = QString::fromStdString(desc).split(';');
        if (qstrl.size() != 2)
          throw QString("MarcaDAO::listar(): Erro de lógica: size != 2");

        marca.setId(qstrl[0].toUInt());
        marca.setMarca(qstrl[1]);
        marcas->operator [](qstrl[0].toUInt()) = marca;                             // insere no map

        std::getline(arquivo, desc);                                                // le o proximo
      }
    }
    catch (std::exception&)
    {                                                                               // falhou:
      arquivo.close();                                                              // fecha o arquivo
      throw QString("MarcaDAO::listar(): std::exception");                          // excecao
    }

    arquivo.close();                                                                // fecha o arquivo
    return marcas;                                                                  // retorna o map
  }

  Marca MarcaDAO::listar(Id id) const
  {
    std::ifstream arquivo("data/marcas.dat");                         // abre o arquivo
    if (!arquivo.is_open())                                           // verifica se foi aberto
      throw QString("MarcaDAO::listar(Id): falha ao abrir arquivo");  // nao abriu: excecao

    try
    {
      std::string desc;                                               // marca para leitura
      QStringList qstrl;

      std::getline(arquivo, desc);                                    // le a marca
      while (!arquivo.eof())                                          // ate eof
      {
        qstrl = QString::fromStdString(desc).split(';');
        if (qstrl.size() != 2)
          throw QString("MarcaDAO::listar(Id): size != 2");

        if (qstrl[0].toUInt() == id)                                  // verifica se é esse
          break;                                                      // é esse: para
        std::getline(arquivo, desc);                                  // le a marca
      }

      if (arquivo.eof())                                              // eof: nao achou
        throw QString("MarcaDAO::listar(Id): id nao encontrado");     // excecao

      arquivo.close();                                                // fecha arquivo
      return Marca(qstrl[0].toUInt(), qstrl[1]);                      // retorna a marca
    }
    catch (std::exception&)
    {                                                                 // excecao stl:
      arquivo.close();                                                // fecha o arquivo
      throw QString("MarcaDAO::listar(Id): std::exception");          // excecao
    }
    catch (QString&)
    {                                                                 // excecao do prog:
      arquivo.close();                                                // fecha arquivo
      throw;                                                          // excecao
    }
  }

} /// \namespace bia
