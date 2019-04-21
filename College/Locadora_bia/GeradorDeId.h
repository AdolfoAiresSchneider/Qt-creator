#ifndef GERADORDEID_H
#define GERADORDEID_H

#include <fstream>

#include <QString>

#include "Id.h"


namespace bia
{
  class GeradorDeId
  {
  private:

    Id idAtual;
    QString nomeArquivo;

  public:

    /// abre o arquivo \p nomeDoArquivo e pega o id dele
    /// se nao existe cria e seta com 0
    GeradorDeId(const QString& nomeDoArquivo)
    {
      nomeArquivo = nomeDoArquivo;

      std::ifstream arquivo(nomeDoArquivo.toStdString().c_str());
      uint id = 0;                                                              // id do arquivo: inicia com 0

      if (arquivo.is_open())                                                    // se abriu
      {
        arquivo >> id;                                                          // le o id
        arquivo.close();
      }
      else
      {                                                                         // nao abriu:
        std::ofstream criaArquivo(nomeDoArquivo.toStdString().c_str());         // cria um arquivo
        criaArquivo.close();                                                    // fecha
      }

      idAtual.setId(id);                                                        // seta o id do arquivo
    }

    /// grava o ultimo id usado e fecha o arquivo
    ~GeradorDeId ()
    {
      std::ofstream arquivo(nomeArquivo.toStdString().c_str());
      arquivo << idAtual; // grava no arquivo
      arquivo.close();    // fecha o arquivo
    }

    /// retorna o ultimo id utilizado
    Id getIdAtual () const
    { return idAtual; }

    /// atualiza e retorna um novo id
    Id getNovoId ()
    {
      idAtual.setId(idAtual.getId() + 1); // avanca o id
      return idAtual;                     // retorna
    }

    /// volta um id para tras
    /// \note: usar apenas quando o id nao for utilizado
    void removeUltimoId ()
    { idAtual.setId(idAtual.getId() - 1); } // volta o id

  };  /// \class GeradorDeId

} /// \namespace bia

#endif // GERADORDEID_H
