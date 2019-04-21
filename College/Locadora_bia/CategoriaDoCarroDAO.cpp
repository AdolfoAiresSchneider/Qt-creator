#include "CategoriaDoCarroDAO.h"

namespace bia
{
  CategoriaDoCarroDAO::CategoriaDoCarroDAO()
  {
    std::ifstream arquivo("data/categorias.dat");                   // abre o arquivo
    if (arquivo.is_open())                                          // verifica se existe
      arquivo.close();                                              // existe: pode fechar
    else
    {                                                               // nao existe
      std::ofstream arquivo("data/categorias.dat");                 // cria
      if (!arquivo.is_open())                                       // se falhou
        throw QString("Modelo: Nao foi possivel criar o arquivo");  // excecao
      arquivo.close();                                              // sucesso: pode fechar
    }
  }

  bool CategoriaDoCarroDAO::isEmpty() const
  {
    std::ifstream arquivo("data/categorias.dat");
    if (!arquivo.is_open())
      return true;

    arquivo.seekg(0, std::ios_base::end);
    int n = arquivo.tellg();
    arquivo.close();
    return !n;
  }

  void CategoriaDoCarroDAO::incluir(const CategoriaDoCarro &categoria)
  {
    std::ofstream arquivo("data/categorias.dat", std::ios_base::app);                                // abre o arquivo
    if (!arquivo.is_open())                                                                     // verifica se abriu
      throw QString("CategoriaDoCarroDAO::incluir(CategoriaDoCarro): falha ao abrir arquivo");  // nao abriu: excecao

    arquivo << categoria.getId() << ';'                                                         // salva id
            << categoria.getCategoria().toStdString() << ';'                                    // salva categoria
            << categoria.getValorLocacaoPessoal() << ';'                                        // salva valor pessoal
            << categoria.getValorLocacaoTrabalho() << '\n';                                     // salva valor trabalho

    arquivo.close();                                                                            // fecha arquivo
  }

  void CategoriaDoCarroDAO::incluir(const std::map<Id, CategoriaDoCarro> &categorias)
  {
    std::ofstream arquivo("data/categorias.dat");                                                                      // abre arquivo
    if (!arquivo.is_open())                                                                                       // checa se abriu
      throw QString("CategoriaDoCarroDAO::incluir(map): falha ao abrir arquivo");                                 // nao abriu: excecao

    for (std::map < Id, CategoriaDoCarro >::const_iterator it = categorias.begin(); it != categorias.end(); ++it) // loop todas categorias
      arquivo << it->first << ';'                                                                                 // salva id
              << it->second.getCategoria().toStdString() << ';'                                                   // salva categoria
              << it->second.getValorLocacaoPessoal() << ';'                                                       // salva valor pessoal
              << it->second.getValorLocacaoTrabalho() << '\n';                                                    // salva valor trabalho

    arquivo.close();                                                                                              // fecha arquivo
  }

  void CategoriaDoCarroDAO::excluir(Id id)
  {
    std::map < Id, CategoriaDoCarro >* categorias = this->listar();         // lista todas categorias

    try
    {
      categorias->erase(id);                                                // remove \p id
    }
    catch (std::exception&)
    {                                                                       // falhou:
      delete categorias;                                                    // libera memoria
      throw QString("CategoriaDoCarroDAO::excluir(Id): id nao encontrado"); // excecao
    }

    this->incluir(*categorias);                                             // atualiza dados
    delete categorias;                                                      // libera memoria
  }

  void CategoriaDoCarroDAO::alterar(const CategoriaDoCarro &categoria)
  {
    this->excluir(categoria.getId()); // exclui antigo
    this->incluir(categoria);         // seta o novo
  }

  std::map<Id, CategoriaDoCarro> *CategoriaDoCarroDAO::listar() const
  {
    std::ifstream arquivo("data/categorias.dat");                                  // abre o arquivo
    if (!arquivo.is_open())                                                   // checa se abriu
      throw QString("CategoriaDoCarroDAO::listar(): falha ao abrir arquivo"); // nao abriu: excecao

    std::map< Id, CategoriaDoCarro >* categorias = 0;                         // todas categorias

    try
    {
      categorias = new std::map< Id, CategoriaDoCarro >;                      // tenta alocar

      std::string str;                                                        // string para leitura
      CategoriaDoCarro categoria;                                             // categoria do carro
      QStringList qstrl;                                                      // lista para leitura

      std::getline(arquivo, str);                                             // le o 1º dado
      while (!arquivo.eof())                                                  // ate eof
      {
        qstrl = QString::fromStdString(str).split(';');                       // cria a lista
        if (qstrl.size() != 4)                                                // checa se tem todos os dados
          throw QString("CategoriaDoCarroDAO::listar(): erro de logica");     // nao tem: excecao

        categoria.setId(qstrl[0].toUInt());                                   // seta id
        categoria.setCategoria(qstrl[1]);                                     // seta categoria
        categoria.setValorLocacaoPessoal(qstrl[2].toDouble());                // seta valor pessoal
        categoria.setValorLocacaoTrabalho(qstrl[3].toDouble());               // seta valor comercial

        categorias->operator [](qstrl[0].toUInt()) = categoria;               // insere no map

        std::getline(arquivo, str);                                           // le o proximo dado
      }
    }
    catch (std::exception&)
    {                                                                         // falhou:
      arquivo.close();                                                        // fecha arquivo
      delete categorias;                                                      // libera memoria
      throw QString("CategoriaDoCarroDAO::listar(): std::exception");         // excecao
    }

    arquivo.close();                                                          // fecha arquivo
    return categorias;                                                        // retorna o map
  }

  CategoriaDoCarro CategoriaDoCarroDAO::listar(Id id) const
  {
    std::ifstream arquivo("data/categorias.dat");                               // abre o arquivo
    if (!arquivo.is_open())                                                     // checa se foi aberto
      throw QString("CategoriaDoCarroDAO::listar(Id): falha ao abrir arquivo"); // nao abriu: excecao

    CategoriaDoCarro categoria;                                                 // categoria para leitura
    std::string str;                                                            // string para leitura
    QStringList qstrl;                                                          // lista para leitura

    try
    {
      std::getline(arquivo, str);                                               // le o primeiro
      while (!arquivo.eof())                                                    // ate eof
      {
        qstrl = QString::fromStdString(str).split(';');                         // separa os dados
        if (qstrl.size() != 4)                                                  // checa se tem todos os dados
          throw QString("CategoriaDoCarroDAO::listar(Id): erro de logica");     // nao tem: excecao

        if (qstrl[0].toUInt() == id)                                            // checa se é esse
          break;                                                                // para a leitura

        std::getline(arquivo, str);                                             // le os outros
      }

      if (arquivo.eof())                                                        // chegou no eof: nao encontrou
        throw QString("CategoriaDoCarroDAO::listar(Id): id nao encontrado");    // excecao

      categoria.setId(qstrl[0].toUInt());                                       // seta id
      categoria.setCategoria(qstrl[1]);                                         // seta categoria
      categoria.setValorLocacaoPessoal(qstrl[2].toDouble());                    // seta valor pessoal
      categoria.setValorLocacaoTrabalho(qstrl[3].toDouble());                   // seta valor comercial
    }
    catch (std::exception&)
    {                                                                           // excecao stl:
      arquivo.close();                                                          // fecha arquivo
      throw QString("CategoriaDoCarroDAO::listar(Id): std::exception");         // excecao
    }
    catch (QString&)
    {                                                                           // excecao:
      arquivo.close();                                                          // fecha o arquivo
      throw;                                                                    // excecao
    }

    arquivo.close();                                                            // fecha o arquivo
    return categoria;                                                           // retorna a categoria
  }

} /// \namespace bia
