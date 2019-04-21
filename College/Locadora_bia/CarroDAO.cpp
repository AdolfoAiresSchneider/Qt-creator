#include "CarroDAO.h"

namespace bia
{
  CarroDAO::CarroDAO()
  {
    std::ifstream arquivo("data/carros.dat");                     // abre o arquivo
    if (arquivo.is_open())                                        // verifica se existe
      arquivo.close();                                            // existe: pode fechar
    else
    {                                                             // nao existe:
      std::ofstream arquivo("data/carros.dat");                   // cria
      if (!arquivo.is_open())                                     // verifica se foi criado
        throw QString("Carro: Nao foi possivel criar o arquivo"); // nao criou: excecao
      arquivo.close();                                            // fecha o arquivo
    }
  }

  void CarroDAO::incluir(const Carro& carro)
  {
    std::ofstream arquivo("data/carros.dat", std::ios_base::app);         // abre o arquivo
    if (!arquivo.is_open())                                               // checa se abriu
      throw QString("CarroDAO::incluir(Carro): falha ao abrir arquivo");  // nao abriu: excecao

    arquivo << carro.getPlaca().getPlaca().toStdString() << ';'           // salva placa
            << toQString(carro.getSituacao()).toStdString() << ';'        // salva situacao
            << carro.getCategoria().getId() << ';'                        // salva categoria
            << carro.getModelo().getId() << ';'                           // salva modelo
            << carro.getKmRodados() << ';'                                // salva km rodados
            << carro.getCor().toStdString() << '\n';                      // salva cor

    arquivo.close();                                                      // fecha arquivo
  }

  void CarroDAO::incluir(const std::map<Placa, Carro>& carros)
  {
    std::ofstream arquivo("data/carros.dat");                                                     // abre arquivo
    if (!arquivo.is_open())                                                                       // checa se abriu
      throw QString("CarroDAO::incluir(map): falha ao abrir arquivo");                            // nao abriu: excecao

    for (std::map < Placa, Carro >::const_iterator it = carros.begin(); it != carros.end(); ++it) // loop todos carros
      arquivo << it->first.getPlaca().toStdString() << ';'                                        // salva placa
              << toQString(it->second.getSituacao()).toStdString() << ';'                         // salva situacao
              << it->second.getCategoria().getId() << ';'                                         // salva categoria
              << it->second.getModelo().getId() << ';'                                            // salva modelo
              << it->second.getKmRodados() << ';'                                                 // salva km rodados
              << it->second.getCor().toStdString() << '\n';                                       // salva cor

    arquivo.close();                                                                              // fecha arquivo
  }

  void CarroDAO::excluir(const Placa& placa)
  {
    std::map < Placa, Carro >* carros = this->listar();                 // lista todos os carros

    try
    {
      carros->erase(placa);                                             // remove o carro com \p placa
    }
    catch (std::exception&)
    {                                                                   // falhou:
      delete carros;                                                    // libera memoria
      throw QString("CarroDAO::excluir(Placa): placa nao encontrada");  // excecao
    }

    this->incluir(*carros);                                             // atualiza dados
    delete carros;                                                      // libera memoria
  }

  void CarroDAO::alterar(const Carro& carro)
  {
    this->excluir(carro.getPlaca());  // exclui antigo
    this->incluir(carro);             // seta novo
  }

  std::map<Placa, Carro>*CarroDAO::listar() const
  {
    std::ifstream arquivo("data/carros.dat");                             // abre arquivo
    if (!arquivo.is_open())                                               // checa se abriu
      throw QString("CarroDAO::listar(): falha ao abrir arquivo");        // nao abriu: excecao

    Carro carro;                                                          // carro para leitura
    CategoriaDoCarroDAO categoriaDao;                                     // dao para leitura
    ModeloDAO modeloDao;                                                  // dao para leitura
    std::string str;                                                      // string para leitura
    QStringList qstrl;                                                    // lista para leitura
    std::map < Placa, Carro >* carros = 0;                                // map de carros

    try
    {
      carros = new std::map < Placa, Carro >;                             // aloca

      std::getline(arquivo, str);                                         // le 1º dado
      while (!arquivo.eof())                                              // ate eof
      {
        qstrl = QString::fromStdString(str).split(';');                   // lista os dados
        if (qstrl.size() != 6)                                            // checa se tem todos os dados
          throw QString("CarroDAO::listar(): Erro de logica: size != 6"); // nao tem todos os dados: excecao

        carro.setPlaca(qstrl[0]);                                         // seta a placa
        carro.setSituacao(toSituacao(qstrl[1]));                          // seta a situacao
        carro.setCategoria(categoriaDao.listar(qstrl[2].toUInt()));       // seta a categoria
        carro.setModelo(modeloDao.listar(qstrl[3].toInt()));              // seta o modelo
        carro.setKmRodados(qstrl[4].toInt());                             // seta a qtde de km rodados
        carro.setCor(qstrl[5]);                                           // seta a cor

        carros->operator [](qstrl[0]) = carro;                            // salva no map

        std::getline(arquivo, str);                                       // le o proximo dado
      }
    }
    catch (std::exception&)
    {                                                                     // stl falhou:
      arquivo.close();                                                    // fecha arquivo
      delete carros;                                                      // libera memoria
      throw QString("CarroDAO::listar(): std::exception");                // excecao
    }
    catch (QString&)
    {                                                                     // prog falhou:
      arquivo.close();                                                    // fecha arquivo
      delete carros;                                                      // libera memoria
      throw;                                                              // excecao
    }

    arquivo.close();                                                      // fecha arquivo
    return carros;                                                        // retorna map
  }

  Carro CarroDAO::listar(const Placa &placa) const
  {
    std::ifstream arquivo("data/carros.dat");                                   // abre o arquivo
    if (!arquivo.is_open())                                                     // verifica se abriu
      throw QString("CarroDAO::listar(const Placa&): falha ao abrir arquivo");  // nao abriu: excecao

    Carro carro;                                                                // carro para leitura
    std::string str;                                                            // string para leitura
    QStringList qstrl;                                                          // lista para leitura

    try
    {
      std::getline(arquivo, str);                                               // le o primeiro
      while (!arquivo.eof())                                                    // ate eof
      {
        qstrl = QString::fromStdString(str).split(';');                         // separa os dados
        if (qstrl.size() != 6)                                                  // checa se tem todos os dados
          throw QString("CarroDAO::listar(): Erro de logica: size != 6");       // nao tem todos os dados: excecao

        if (qstrl[0] == placa.getPlaca())                                       // verifica se é esse
          break;                                                                // para while

        std::getline(arquivo, str);                                             // nao é: le o proximo
      }

      if (arquivo.eof())                                                        // eof: nao achou
        throw QString("CarroDAO::listar(const Placa&): placa nao encontrada");  // excecao

      CategoriaDoCarroDAO categoriaDao;
      ModeloDAO modeloDao;

      carro.setPlaca(qstrl[0]);                                                 // seta a placa
      carro.setSituacao(toSituacao(qstrl[1]));                                  // seta a situacao
      carro.setCategoria(categoriaDao.listar(qstrl[2].toUInt()));               // seta a categoria
      carro.setModelo(modeloDao.listar(qstrl[3].toInt()));                      // seta o modelo
      carro.setKmRodados(qstrl[4].toInt());                                     // seta a qtde de km rodados
      carro.setCor(qstrl[5]);                                                   // seta a cor
    }
    catch (std::exception&)
    {                                                                           // excecao stl:
      arquivo.close();                                                          // fecha arquivo
      throw QString("CarroDAO::listar(const Placa&): std::exception");          // excecao
    }
    catch (QString&)
    {                                                                           // excecao do programa:
      arquivo.close();                                                          // fecha arquivo
      throw;                                                                    // excecao
    }

    arquivo.close();                                                            // fecha arquivo
    return carro;                                                               // retorna o carro
  }

} /// \namespace bia
